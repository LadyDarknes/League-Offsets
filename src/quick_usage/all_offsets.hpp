#pragma once
#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

// those offsets might be wrong, check offsets.hpp

struct Vec3 {
    float x, y, z;
    float dist2d(const Vec3& o) const {
        float dx = x - o.x;
        float dz = z - o.z;
        return sqrtf(dx * dx + dz * dz);
    }
};

struct MsvcString {
    union { char buf[16]; char* ptr; } u;
    uint64_t len, cap;
    MsvcString() : len(0), cap(15) { u.buf[0] = '\0'; }
    MsvcString(const char* s) : len(strlen(s)), cap(15) {
        if (len > 15) { u.ptr = _strdup(s); cap = len; }
        else strcpy_s(u.buf, s);
    }
    ~MsvcString() { if (cap > 15) free(u.ptr); }
    const char* c_str() const { return cap > 15 ? u.ptr : u.buf; }
};

struct CameraData {
    float viewMtx[16];
    float projMtx[16];
    float camPos[3];
    int vpLeft, vpTop, vpRight, vpBottom;
    bool valid = false;
};

struct ScreenCoord {
    float x, y;
    bool onScreen;
};

struct SpellData {
    char padding_0[0x28];
    MsvcString spell_name;
    // SpellData + 0x28, 
    // you can find the spell name here:
    // https://raw.communitydragon.org/latest/game/data/characters/character_name/character_name.bin.json
    // write character name here to your character name, for example: https://raw.communitydragon.org/latest/game/data/characters/ahri/ahri.bin.json
    // Then you can find the spell name in the spells array.
};

struct SpellSlotInfo {
    char padding_0[0x8];
    SpellData* spell_data;
};




struct SpellCastInfo {
    char padding_0[0x8];
    uint32_t slot_index;

    char padding_1[0x18];
    Vec3 start_pos;
    Vec3 end_pos;
    Vec3 cast_pos;
    uint32_t caster_netid;
    uint32_t target_netid;
    char padding_2[0x38];
    SpellSlotInfo* slot_info;
    char padding_3[0x10];
    float windup_time;
};

struct SpellSlot {
    void** vtable;
    char pad[0x24];
    int level;
    float cd_expire;
    char pad2[0x30];
    int charges;
    float charge_cd;
};

struct CombatStats {
    char pad[0x1C];
    float ap, ad; int level;
    char pad2[0x1D8];
    float as_mod;
};

void ProcessEntitiesExample(uintptr_t base_addr) 
{
    is_type_t is_type = (is_type_t)(base_addr + 0x263150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    void* local_player = *(void**)(base_addr + 0x1EA0528);
    uint8_t local_team = local_player ? *(uint8_t*)((char*)local_player + 0x259) : 100;
    uint32_t team_bit = (local_team == 100) ? 0 : 1;

    for (void* obj : entities) 
    {
        if (!obj) continue;

        bool is_hero = is_type(obj, 0x1000);
        bool is_minion = is_type(obj, 0x800);
        bool is_turret = is_type(obj, 0x2000);

        if (!is_hero && !is_minion && !is_turret) continue;

        float hp = *(float*)((char*)obj + 0x1080);
        float hp_max = *(float*)((char*)obj + 0x10A8);
        if (hp <= 0.0f) continue;

        MsvcString* name_str = (MsvcString*)((char*)obj + 0x68);
        const char* name = name_str->c_str();

        uint8_t team_id = *(uint8_t*)((char*)obj + 0x259);

        Vec3 pos = *(Vec3*)((char*)obj + 0x25C);

        uint32_t vis_mask = *(uint32_t*)((char*)obj + 0x30C);
        bool is_visible = (vis_mask & (1 << team_bit)) == 0;

        float mana = *(float*)((char*)obj + 0x360);
        float mana_max = *(float*)((char*)obj + 0x388);
        bool mana_enabled = *(bool*)((char*)obj + 0x3B0);

        int level = *(int*)((char*)obj + 0x4D58);

        float armor = *(float*)((char*)obj + 0x4F38);
        float mr = *(float*)((char*)obj + 0x4CB8);
        float move_speed = *(float*)((char*)obj + 0x5000);

        float all_shield = *(float*)((char*)obj + 0x1120);
        float phys_shield = *(float*)((char*)obj + 0x1148);
        float mag_shield = *(float*)((char*)obj + 0x1170);

        void* ai_mgr_wrapper = *(void**)((char*)obj + 0x4070);
        if (ai_mgr_wrapper) 
        {
            void* ai_mgr = *(void**)((char*)ai_mgr_wrapper + 0x28);
            void* nav_inner = *(void**)((char*)ai_mgr_wrapper + 0x40);
            if (ai_mgr && nav_inner) 
            {
                bool is_moving = *(bool*)((char*)nav_inner + 0x320);
                bool is_dashing = *(bool*)((char*)nav_inner + 0x348);
                float dash_speed = *(float*)((char*)nav_inner + 0x3E0);
                Vec3 target_pos = *(Vec3*)((char*)ai_mgr + 0x24);
                Vec3 velocity = *(Vec3*)((char*)ai_mgr + 0x18);
                Vec3 server_pos = *(Vec3*)((char*)ai_mgr + 0x08);

                void* nav_path = (char*)nav_inner + 0x490;
                int current_node_idx = *(int*)((char*)nav_path + 0x00);
                int waypoint_count = *(int*)((char*)nav_path + 0x30);
                Vec3* waypoints = *(Vec3**)((char*)nav_path + 0x28);
            }
        }
    }


inline bool W2S(const CameraData& cam, const Vec3& w, ScreenCoord& out) {
    if (!cam.valid) return false;
    float dx = w.x - cam.camPos[0], dy = w.y - cam.camPos[1], dz = w.z - cam.camPos[2];
    const float* V = cam.viewMtx; const float* P = cam.projMtx;
    float vx = dx * V[0] + dy * V[4] + dz * V[8]  + V[12];
    float vy = dx * V[1] + dy * V[5] + dz * V[9]  + V[13];
    float vz = dx * V[2] + dy * V[6] + dz * V[10] + V[14];
    float vw = dx * V[3] + dy * V[7] + dz * V[11] + V[15];
    float cx = vx * P[0] + vy * P[4] + vz * P[8]  + vw * P[12];
    float cy = vx * P[1] + vy * P[5] + vz * P[9]  + vw * P[13];
    float cz = vx * P[2] + vy * P[6] + vz * P[10] + vw * P[14];
    float cw = vx * P[3] + vy * P[7] + vz * P[11] + vw * P[15];
    if (cw <= 0.001f) return false;
    float inv = 1.0f / cw;
    out.x = (cx * inv + 1.0f) * static_cast<float>(cam.vpRight - cam.vpLeft) * 0.5f + static_cast<float>(cam.vpLeft);
    out.y = (1.0f - cy * inv) * static_cast<float>(cam.vpBottom - cam.vpTop) * 0.5f + static_cast<float>(cam.vpTop);
    out.onScreen = (out.x >= 0.0f && out.x <= static_cast<float>(cam.vpRight) && out.y >= 0.0f && out.y <= static_cast<float>(cam.vpBottom));
    return out.onScreen;
}

inline void* GetUnitByNetID(uintptr_t base, uint32_t netid) {
    struct Node { Node *l, *p, *r; char c, s, pad[6]; uint32_t k; char p2[4]; void* v; };
    auto* head = *(Node**)(*(char**)(base + 0x1E76C80) + 0x40);
    for (auto* c = head->p; c && c != head && !c->s; c = (netid < c->k ? c->l : c->r))
        if (c->k == netid) return c->v;
    return nullptr;
}

struct LeagueEngine {
    uintptr_t base;
    LeagueEngine(uintptr_t image_base) : base(image_base) {}

    void ReadAIMgr(void* obj) {
        void* wrapper = *(void**)((char*)obj + 0x4070);
        if (!wrapper) return;
        void* ai_mgr = *(void**)((char*)wrapper + 0x28);
        void* nav_inner = *(void**)((char*)wrapper + 0x40);
        if (ai_mgr && nav_inner) {
            bool is_moving = *(bool*)((char*)nav_inner + 0x320);
            bool is_dashing = *(bool*)((char*)nav_inner + 0x348);
            float Dashspeed = *(float*)((char*)nav_inner + 0x3E0);
            Vec3 target_pos = *(Vec3*)((char*)ai_mgr + 0x24);
            Vec3 dst = *(Vec3*)((char*)ai_mgr + 0x24);
            void* path = (char*)nav_inner + 0x490;
            Vec3 path_start = *(Vec3*)((char*)nav_inner + 0x328);
            Vec3 path_end = *(Vec3*)((char*)nav_inner + 0x338);
            int current_node_idx = *(int*)((char*)path + 0x00);
            int waypoint_count = *(int*)((char*)path + 0x30);
            Vec3* waypoints = *(Vec3**)((char*)path + 0x28);
        }
    }

    void ReadBuffs(void* obj) {
        void* buff_mgr = *(void**)((char*)obj + 0x28F0);
        if (buff_mgr) {
            void* list_start = *(void**)((char*)buff_mgr + 0x90);
            void* list_end = *(void**)((char*)buff_mgr + 0x98);
        }
    }
    typedef bool(__fastcall* IssueOrder_t)(void*, int, Vec3*, void*, bool, bool, bool);
   
    void IssueOrder(uintptr_t base, int type, Vec3 pos, void* target = nullptr) {
        auto* hud = *(char**)(base + 0x1E76E08);
        auto* logic = *(void**)(hud + 0x24); // HudInputLogic
        if (logic) ((IssueOrder_t)(base + 0x290920))(logic, type, &pos, target, 0, 0, 1);
    }
    // stop 1
    // moveTo 2
    // AttackUnit 3
    // AttackMove 4

    std::vector<void*> GetActiveEntities() {
        std::vector<void*> out;
        struct Node { Node *l, *p, *r; char c, s, pad[6]; uint32_t k; char p2[4]; void* v; };
        auto* obj_mgr = *(char**)(base + 0x1E76C80);
        if (!obj_mgr) return out;
        Node* head = *(Node**)(obj_mgr + 0x40);
        if (!head || !head->p || head->p == head) return out;
        
        auto traverse = [&](auto self, Node* n) -> void {
            if (!n || n == head || n->s) return;
            self(self, n->l);
            if (n->v) out.push_back(n->v);
            self(self, n->r);
        };
        traverse(traverse, head->p);
        return out;
    }

    std::vector<void*> GetChampions() {
        std::vector<void*> heroes;
        void* mgr = *(void**)(base + 0x1E76DA0);
        if (mgr) {
            void** list = *(void***)((char*)mgr + 0x08);
            uint32_t count = *(uint32_t*)((char*)mgr + 0x10);
            for (uint32_t i = 0; i < count; i++)
                if (list[i]) heroes.push_back(list[i]);
        }
        return heroes;
    }
    std::vector<void*> GetMinions(uintptr_t base_addr) {
    std::vector<void*> minions;
    is_type_t is_type = (is_type_t)(base_addr + 0x28F150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    for (void* obj : entities) 
    {
        if (obj && is_type(obj, 0x800)) // TypeMinion = 0x800, others are TypeHero = 0x1000, TypeTurret = 0x2000
        { 
            minions.push_back(obj);
        }
    }
    return minions;
    }

    std::vector<void*> GetJungleMonsters(uintptr_t base_addr) {
    // Common Neutral/Jungle Monster Names (accessible at GameObject + 0x68):
    // - Baron Nashor: "SRU_Baron"
    // - Rift Herald: "SRU_Herald"
    // - Red Brambleback (Red Buff): "SRU_Red"
    // - Blue Sentinel (Blue Buff): "SRU_Blue"
    // - Scuttle Crab: "Sru_Crab"
    // - Dragon: "SRU_Dragon" (Elements: SRU_Dragon_Fire, SRU_Dragon_Water, SRU_Dragon_Earth, SRU_Dragon_Air, SRU_Dragon_Elder, SRU_Dragon_Chemtech, SRU_Dragon_Hextech)
    std::vector<void*> monsters;
    is_type_t is_type = (is_type_t)(base_addr + 0x28F150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    for (void* obj : entities) 
    {
        if (obj && is_type(obj, 0x800)) // Minion type
        { 
            uint8_t team_id = *(uint8_t*)((char*)obj + 0x259);
            if (team_id != 100 && team_id != 200) // Neutral (not Blue 100 or Red 200)
            { 
                monsters.push_back(obj);
            }
        }
    }
    return monsters;
    }




    bool IsType(void* obj, uint32_t flag) {
        typedef bool(__fastcall* is_type_t)(void*, uint32_t);
        return ((is_type_t)(base + 0x28F150))(obj, flag);
    }

    void IssueOrder(int type, Vec3* pos, void* target = nullptr) {
        typedef bool(__fastcall* IssueOrderCore_t)(void*, uint32_t, Vec3*, void*, bool, bool, bool);
        void* hud = *(void**)(base + 0x1E76E08);
        if (!hud) return;
        void* logic = *(void**)((char*)hud + 0x24);
        if (logic) ((IssueOrderCore_t)(base + 0x290940))(logic, type, pos, target, false, false, true);
    }

    bool IsUnitVisible(void* obj, void* local_player) {
        if (!obj || !local_player) return false;
        uint8_t team = *(uint8_t*)((char*)local_player + 0x259);
        uint32_t team_bit = (team == 100) ? 0 : 1;
        uint32_t mask = *(uint32_t*)((char*)obj + 0x30C);
        return (mask & (1 << team_bit)) == 0;
    }
    void UpdateCamera(uintptr_t base_addr) {
    void* hud = *(void**)(base_addr + 0x1E76E08); // HudInstance global
    if (!hud) return;

    void* cam = *(void**)((char*)hud + 0x18); // Camera pointer
    if (!cam) return;

    Vec3 cam_pos = *(Vec3*)((char*)cam + 0x08);
    Vec3 cam_rot = *(Vec3*)((char*)cam + 0x18);
    float fov = *(float*)((char*)cam + 0x3C);
    float near_clip = *(float*)((char*)cam + 0x44);
    float far_clip  = *(float*)((char*)cam + 0x4C);
    float zoom      = *(float*)((char*)cam + 0x324);
    float min_zoom  = *(float*)((char*)cam + 0x310);
    bool attached = *(bool*)((char*)cam + 0x28);
    float move_speed = *(float*)((char*)cam + 0x2C);
    float look_speed = *(float*)((char*)cam + 0x34);

    Vec3* cam_pos_ptr = (Vec3*)((char*)cam + 0x08);
    cam_pos_ptr->x = 7500.0f;
    cam_pos_ptr->y = 200.0f;
    cam_pos_ptr->z = 7500.0f;

    bool fog_enabled      = *(bool*)((char*)cam + 0x5A);
    bool outline_select   = *(bool*)((char*)cam + 0x54);
    bool outline_hover    = *(bool*)((char*)cam + 0x56);
    bool floating_text    = *(bool*)((char*)cam + 0x58);
    float navgrid_offset  = *(float*)((char*)cam + 0x5C);
}

    void PrintChat(const char* text, int color = 0xFFFFFF) {
        typedef void(__fastcall* PrintChat_t)(void*, MsvcString*, int);
        void* client = *(void**)(base + 0x1EAE6A0);
        MsvcString msg(text);
        if (client) ((PrintChat_t)(base + 0x112C8E0))(client, &msg, color);
    }

    void* LookupQuest(void* obj, void* key) {
        typedef void*(__fastcall* lookup_t)(void*, void*);
        return ((lookup_t)(base + 0x1189220))((char*)obj + 0xE0, key);
    }

    void CastSpell(void* spell_book, int slot, uint32_t target_id = 0, Vec3* pos = nullptr) {
        if (!spell_book) return;
        SpellSlot* spell = (*(SpellSlot***)((char*)spell_book + 0xAE0))[slot];
        typedef void(__fastcall* CastSpell_t)(SpellSlot*, int, uint32_t, Vec3*, Vec3*, uint32_t);
        if (spell) ((CastSpell_t)spell->vtable[4])(spell, slot, target_id, &Vec3{0,0,0}, pos ? pos : &Vec3{0,0,0}, 0);
    }

    bool CanCast(void* spell_book, int slot, float time) {
        SpellSlot* s = spell_book ? (*(SpellSlot***)((char*)spell_book + 0xAE0))[slot] : nullptr;
        return s && s->level > 0 && s->cd_expire <= time && (s->charges > 0 || s->charge_cd <= time);
    }

    void CheckActiveSpell(void* obj) {
        void* sb = *(void**)((char*)obj + 0x3128);
        if (!sb) return;
        SpellCastInfo* cast = *(SpellCastInfo**)((char*)sb + 0xAD8);
        if (cast && cast->slot_info && cast->slot_info->spell_data) {
            std::cout << "Casting: " << cast->slot_info->spell_data->spell_name.c_str() << "\n";
        }
    }
};

namespace Hooks {
    typedef void(__fastcall* OnProcessSpell_t)(void*, SpellCastInfo*);
    inline OnProcessSpell_t oOnProcessSpell = nullptr;

    inline void __fastcall hkOnProcessSpell(void* spellbook, SpellCastInfo* cast_info) {
        if (spellbook && cast_info && cast_info->slot_info && cast_info->slot_info->spell_data) {
            const char* name = cast_info->slot_info->spell_data->spell_name.c_str();
            std::cout << "OnProcessSpell: " << name << "\n";
        }
        oOnProcessSpell(spellbook, cast_info);
    }

    inline void Initialize(uintptr_t base, void* process_spell_detour) {
        // Hooks installation entry helper
        // CreateHook((LPVOID)(base + 0x984D20), process_spell_detour, (LPVOID*)&oOnProcessSpell);
    }
}
