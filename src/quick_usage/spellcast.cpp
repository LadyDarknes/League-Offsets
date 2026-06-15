#include <stdint.h>
#include <string.h>
#include <iostream>
#include <windows.h>

struct Vec3 { 
    float x, y, z; 
};

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
    MsvcString spell_name; // SpellData + 0x28
    // SpellData + 0x28, 
    // you can find the spell name here:
    // https://raw.communitydragon.org/latest/game/data/characters/character_name/character_name.bin.json
    // write character name here to your character name, for example: https://raw.communitydragon.org/latest/game/data/characters/ahri/ahri.bin.json
    // Then you can find the spell name in the spells array.
};

struct SpellSlotInfo {
    char padding_0[0x8];
    SpellData* spell_data; // SpellSlotInfo + 0x08
};

struct SpellCastInfo {
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

struct GameObject {
    static void* GetSpellBook(GameObject* obj) {
        if (!obj) return nullptr;
        return *(void**)((char*)obj + 0x3128); // SpellBook offset
    }
};

struct SpellBook {
    static SpellCastInfo* GetActiveSpellCast(void* spell_book) {
        if (!spell_book) return nullptr;
        return *(SpellCastInfo**)((char*)spell_book + 0xAD8); // ActiveSpellCast offset
    }
};

namespace Offsets {
    constexpr uintptr_t SpellCastMap = 0x1E9F6C0;
    constexpr uintptr_t GetSpellCastInfo = 0x652CA0;
    constexpr uintptr_t OnProcessSpell = 0x984D20;
}

// 1. Reading ActiveSpellCast (SpellBook + 0xAD8)
void CheckActiveSpell(GameObject* champion) {
    if (!champion) return;

    void* spell_book = GameObject::GetSpellBook(champion);
    if (!spell_book) return;

    SpellCastInfo* active_cast = SpellBook::GetActiveSpellCast(spell_book);
    if (active_cast && active_cast->slot_info && active_cast->slot_info->spell_data) {
        const char* name = active_cast->slot_info->spell_data->spell_name.c_str();
        std::cout << "Casting: " << name << " | Slot: " << active_cast->slot_index << "\n";
    }
}

// 2. Querying SpellCastInfo via GetSpellCastInfo function
typedef SpellCastInfo*(__fastcall* GetSpellCastInfo_t)(void* spell_cast_map, MsvcString* spell_name);

SpellCastInfo* QuerySpellCastInfo(const char* name) {
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    void** map_ptr = (void**)(base + Offsets::SpellCastMap);
    if (!map_ptr || !*map_ptr) return nullptr;

    GetSpellCastInfo_t GetSpellCastInfo = (GetSpellCastInfo_t)(base + Offsets::GetSpellCastInfo);

    MsvcString key;
    if (strlen(name) > 15) {
        key.pointer = _strdup(name);
        key.capacity = strlen(name);
    } else {
        strcpy_s(key.buffer, name);
        key.capacity = 15;
    }
    key.length = strlen(name);

    SpellCastInfo* info = GetSpellCastInfo(*map_ptr, &key);

    if (key.capacity > 15) {
        free(key.pointer);
    }
    return info;
}

// 3. Hooking OnProcessSpell 
typedef void(__fastcall* OnProcessSpell_t)(void* spell_book, SpellCastInfo* cast_info);
OnProcessSpell_t oOnProcessSpell = nullptr;

void __fastcall hkOnProcessSpell(void* spell_book, SpellCastInfo* cast_info) {
    oOnProcessSpell(spell_book, cast_info);

    if (!spell_book || !cast_info) return;

    // SpellBook + 0x18 points back to the casting GameObject
    GameObject* caster = *(GameObject**)((char*)spell_book + 0x18);
    if (!caster) return;

    if (cast_info->slot_info && cast_info->slot_info->spell_data) {
        const char* name = cast_info->slot_info->spell_data->spell_name.c_str();
        std::cout << "Spell Hooked: " << name << " casted by NetID: " << cast_info->caster_netid << "\n";
    }
}
