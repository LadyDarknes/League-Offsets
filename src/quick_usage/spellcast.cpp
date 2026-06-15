// SpellCast Usage Example — ActiveSpellCast, GetSpellCastInfo, and OnProcessSpell
// This file demonstrates how to retrieve spell casting info and handle spell cast hooks.
// ALso a lot of code generated with ai, I check them they are working!!!!

#include <stdint.h>
#include <string.h>
#include <iostream>

// ============================================================================
// 1. Data Structures & Layouts
// ============================================================================

struct Vec3 { 
    float x, y, z; 
};

// MSVC std::string layout used by the League of Legends client
struct MsvcString {
    union {
        char buffer[16];
        char* pointer;
    };
    uint64_t length;
    uint64_t capacity;

    const char* c_str() const {
        return capacity > 15 ? pointer : buffer;
    }
};

struct SpellData {
    char padding_0[0x28];
    MsvcString spell_name; // SpellData + 0x28 (e.g. "AlphaStrike", "EzrealMysticShot")
};

struct SpellSlotInfo {
    char padding_0[0x8];
    SpellData* spell_data; // SpellSlotInfo + 0x08
};

// SpellCastInfo struct describing an active spell cast or process spell event
struct SpellCastInfo {
    char padding_0[0x8];
    uint32_t slot_index;      // +0x08 (0 = Q, 1 = W, 2 = E, 3 = R, 4 = D, 5 = F)
    char padding_1[0x18];
    Vec3 start_pos;           // +0x24 (Caster position at start of cast)
    Vec3 end_pos;             // +0x30 (Target/Destination position)
    Vec3 cast_pos;            // +0x3C (Direction or cursor cast position)
    uint32_t caster_netid;    // +0x48 (Network ID of the caster champion)
    uint32_t target_netid;    // +0x4C (Network ID of target unit, if targeted)
    char padding_2[0x38];
    SpellSlotInfo* slot_info; // +0x88 (Contains SpellData pointer for name/slot index)
    char padding_3[0x10];
    float windup_time;        // +0xA0 (Attack windup or spell cast delay before execution)
};

// Simplified GameObject layout
struct GameObject {
    // Other GameObject fields...
    
    // SpellBook component is at GameObject + 0x3128
    static void* GetSpellBook(GameObject* obj) {
        if (!obj) return nullptr;
        return *(void**)((char*)obj + 0x3128);
    }
};

// Simplified SpellBook layout
struct SpellBook {
    char padding_0[0x18];
    GameObject* owner;        // SpellBook + 0x18 (Points back to the casting GameObject)
    
    // Other SpellBook fields...
    // ...
    
    // ActiveSpellCast pointer is at SpellBook + 0xAD8
    static SpellCastInfo* GetActiveSpellCast(void* spell_book) {
        if (!spell_book) return nullptr;
        return *(SpellCastInfo**)((char*)spell_book + 0xAD8);
    }
};


// ============================================================================
// 2. Offsets (Resolved from offsets.hpp & IDA Pro)
// ============================================================================
namespace Offsets {
    constexpr uintptr_t ImageBase = 0x7FF7E6B90000;
    
    namespace Globals {
        constexpr uintptr_t SpellCastMap = 0x1E9F6C0; // Global SpellCastMap pointer
    }
    
    namespace Functions {
        constexpr uintptr_t GetSpellCastInfo = 0x652CA0; // GetSpellCastInfo function RVA
        constexpr uintptr_t OnProcessSpell = 0x984D20;   // OnProcessSpell callback RVA
    }
}


// ============================================================================
// 3. Concept 1: Checking ActiveSpellCast (Direct Memory Reading)
// ============================================================================
// Use this to check if a specific game object (e.g. LocalPlayer or Enemy) is 
// currently casting a spell. If ActiveSpellCast is non-null, a cast is active.
void CheckActiveSpell(GameObject* champion) {
    if (!champion) return;

    void* spell_book = GameObject::GetSpellBook(champion);
    if (!spell_book) return;

    // Read ActiveSpellCast pointer (SpellBook + 0xAD8)
    SpellCastInfo* active_cast = SpellBook::GetActiveSpellCast(spell_book);
    if (active_cast) {
        if (active_cast->slot_info && active_cast->slot_info->spell_data) {
            const char* spell_name = active_cast->slot_info->spell_data->spell_name.c_str();
            std::cout << "[ActiveSpell] Caster is casting: " << spell_name 
                      << " | Slot: " << active_cast->slot_index 
                      << " | Windup: " << active_cast->windup_time << "s\n";
        }
    } else {
        std::cout << "[ActiveSpell] Champion is not currently casting any spell.\n";
    }
}


// ============================================================================
// 4. Concept 2: Querying SpellCastInfo via GetSpellCastInfo Function
// ============================================================================
// The game client stores spell configurations and casting history in a global map.
// We can call the client's internal `GetSpellCastInfo` function to look up spell cast
// properties by passing a spell name key.
typedef SpellCastInfo*(__fastcall* GetSpellCastInfo_t)(void* spell_cast_map, MsvcString* spell_name);

SpellCastInfo* QuerySpellCastInfo(const char* name) {
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    
    // 1. Get the global SpellCastMap
    void** spell_cast_map_ptr = (void**)(base + Offsets::Globals::SpellCastMap);
    if (!spell_cast_map_ptr || !*spell_cast_map_ptr) return nullptr;
    void* spell_cast_map = *spell_cast_map_ptr;

    // 2. Resolve the function pointer
    GetSpellCastInfo_t GetSpellCastInfo = (GetSpellCastInfo_t)(base + Offsets::Functions::GetSpellCastInfo);

    // 3. Create the MSVC string key containing the target spell name
    MsvcString spell_name_key;
    if (strlen(name) > 15) {
        spell_name_key.pointer = _strdup(name);
        spell_name_key.capacity = strlen(name);
    } else {
        strcpy_s(spell_name_key.buffer, name);
        spell_name_key.capacity = 15;
    }
    spell_name_key.length = strlen(name);

    // 4. Call the function
    SpellCastInfo* info = GetSpellCastInfo(spell_cast_map, &spell_name_key);

    // Free string resource if it was allocated on heap
    if (spell_name_key.capacity > 15) {
        free(spell_name_key.pointer);
    }

    return info;
}


// ============================================================================
// 5. Concept 3: Hooking OnProcessSpell (Event Interception)
// ============================================================================
// `OnProcessSpell` is a member function of `SpellBook` that triggers whenever a spell
// or auto-attack request starts processing.
// Hooking this function lets us intercept spells instantly (useful for Evade scripts).

typedef void(__fastcall* OnProcessSpell_t)(void* spell_book, SpellCastInfo* cast_info);
OnProcessSpell_t oOnProcessSpell = nullptr;

void __fastcall hkOnProcessSpell(void* spell_book, SpellCastInfo* cast_info) {
    // Call original function first to avoid disrupting the game logic
    oOnProcessSpell(spell_book, cast_info);

    if (!spell_book || !cast_info) return;

    // 1. Extract the caster GameObject from SpellBook + 0x18
    GameObject* caster = *(GameObject**)((char*)spell_book + 0x18);
    if (!caster) return;

    // 2. Extract Spell details
    if (cast_info->slot_info && cast_info->slot_info->spell_data) {
        const char* name = cast_info->slot_info->spell_data->spell_name.c_str();
        
        std::cout << "[Hooked OnProcessSpell] Event Intercepted:\n";
        std::cout << " - Spell Name: " << name << "\n";
        std::cout << " - Slot Index: " << cast_info->slot_index << "\n";
        std::cout << " - Start Position: (" << cast_info->start_pos.x << ", " << cast_info->start_pos.y << ", " << cast_info->start_pos.z << ")\n";
        std::cout << " - Target Position: (" << cast_info->end_pos.x << ", " << cast_info->end_pos.y << ", " << cast_info->end_pos.z << ")\n";
        std::cout << " - Caster Network ID: " << cast_info->caster_netid << "\n";
        std::cout << " - Target Network ID: " << cast_info->target_netid << "\n";
        std::cout << " - Windup Time: " << cast_info->windup_time << "s\n";
    }
}
