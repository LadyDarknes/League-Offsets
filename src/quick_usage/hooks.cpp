#include <stdint.h>
#include <windows.h>
#include <iostream>

struct Vec3 { float x, y, z; };

struct MsvcString 
{
    union 
    {
        char buffer[16];
        char* pointer;
    };
    uint64_t length;
    uint64_t capacity;

    const char* c_str() const 
    {
        return capacity > 15 ? pointer : buffer;
    }
};

struct SpellData 
{
    char padding_0[0x28];
    MsvcString spell_name; 
    // SpellData + 0x28, 
    // you can find the spell name here:
    // https://raw.communitydragon.org/latest/game/data/characters/character_name/character_name.bin.json
    // write character name here to your character name, for example: https://raw.communitydragon.org/latest/game/data/characters/ahri/ahri.bin.json
    // Then you can find the spell name in the spells array.
};

struct SpellSlotInfo 
{
    char padding_0[0x8];
    SpellData* spell_data; // SpellSlotInfo + 0x08
};

struct SpellCastInfo 
{
    char padding_0[0x8];
    uint32_t slot_index;      // +0x08 (0=Q, 1=W, 2=E, 3=R, 4=D, 5=F)
    char padding_1[0x18];
    Vec3 start_pos;           // +0x24
    Vec3 end_pos;             // +0x30
    Vec3 cast_pos;            // +0x3C
    uint32_t caster_netid;    // +0x48
    uint32_t target_netid;    // +0x4C
    char padding_2[0x38];
    SpellSlotInfo* slot_info; // +0x88
    char padding_3[0x10];
    float windup_time;        // +0xA0
};

// Hook typedefs
typedef void(__fastcall* ClientMainLoop_t)(void* thisptr);
typedef LRESULT(__stdcall* OnWndProc_t)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
typedef void(__fastcall* OnProcessSpell_t)(void* spellbook, SpellCastInfo* cast_info);
typedef void(__fastcall* OnSpellImpact_t)(void* spellbook, SpellCastInfo* cast_info);
typedef void(__fastcall* OnDoCast_t)(void* spellbook, SpellCastInfo* cast_info);
typedef void(__fastcall* OnStopCast_t)(void* spellbook, bool stop_animation, bool execute_cast);
typedef void(__fastcall* OnCreateObject_t)(void* obj, unsigned int net_id);

// Original function pointers
ClientMainLoop_t oClientMainLoop = nullptr;
OnWndProc_t oOnWndProc = nullptr;
OnProcessSpell_t oOnProcessSpell = nullptr;
OnSpellImpact_t oOnSpellImpact = nullptr;
OnDoCast_t oOnDoCast = nullptr;
OnStopCast_t oOnStopCast = nullptr;
OnCreateObject_t oOnCreateObject = nullptr;

void __fastcall hkClientMainLoop(void* thisptr) 
{
    oClientMainLoop(thisptr);
}

LRESULT __stdcall hkOnWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
    if (msg == WM_KEYDOWN && wparam == VK_INSERT) 
    {
        return 1; // Block key
    }
    return oOnWndProc(hwnd, msg, wparam, lparam);
}

void __fastcall hkOnProcessSpell(void* spellbook, SpellCastInfo* cast_info) 
{
    if (spellbook && cast_info && cast_info->slot_info && cast_info->slot_info->spell_data) {
        const char* spell_name = cast_info->slot_info->spell_data->spell_name.c_str();
        // Evade or cooldown logic here
    }
    oOnProcessSpell(spellbook, cast_info);
}

void __fastcall hkOnDoCast(void* spellbook, SpellCastInfo* cast_info) {
    if (spellbook && cast_info) {
        // Windup finished, projectile spawned
    }
    oOnDoCast(spellbook, cast_info);
}

void __fastcall hkOnStopCast(void* spellbook, bool stop_animation, bool execute_cast) {
    oOnStopCast(spellbook, stop_animation, execute_cast);
}

void __fastcall hkOnCreateObject(void* obj, unsigned int net_id) {
    oOnCreateObject(obj, net_id);
}

template <typename T>
bool CreateHookHelper(uintptr_t target_rva, uintptr_t base_address, LPVOID detour, T** original) {
    uintptr_t target_address = base_address + target_rva;
    // MH_CreateHook((LPVOID)target_address, detour, (LPVOID*)original);
    // MH_EnableHook((LPVOID)target_address);
    return true; 
}

void InitializeScriptingHooks(uintptr_t base_address) {
    // MH_Initialize();

    CreateHookHelper(0x5EEC00, base_address, hkClientMainLoop, &oClientMainLoop);
    CreateHookHelper(0x5F0780, base_address, hkOnWndProc, &oOnWndProc);
    CreateHookHelper(0x984D20, base_address, hkOnProcessSpell, &oOnProcessSpell);
    CreateHookHelper(0x97D6E0, base_address, hkOnSpellImpact, &oOnSpellImpact);
    CreateHookHelper(0x97F2F0, base_address, hkOnDoCast, &oOnDoCast);
    CreateHookHelper(0x985460, base_address, hkOnStopCast, &oOnStopCast);
    CreateHookHelper(0x55B330, base_address, hkOnCreateObject, &oOnCreateObject);
}
