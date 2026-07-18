#pragma once
#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include "../offsets.hpp"

// those offsets might be wrong, check offsets.hpp

struct Vec3 {
    float x, y, z;
    float dist2d(const Vec3& o) const {
        float dx = x - o.x;
        float dz = z - o.z;
        return sqrtf(dx * dx + dz * dz);
    }
};

struct Matrix44 {
    float m[4][4];
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


uint32_t GetDecryptedNetworkID(uintptr_t gameObject) {
    if (!gameObject) return 0;
    
    // GameObject + oPlayerStatsComponent
    uintptr_t sub_obj = gameObject + Offsets::Standard::GameObject::oPlayerStatsComponent; 
    uintptr_t* vtable = *(uintptr_t**)sub_obj;
    if (!vtable) return 0;
    
    // vtable[5] (index 5, offset 0x28 / 40) virtual function
    typedef uint32_t*(__fastcall* GetNetIDFn_t)(uintptr_t);
    GetNetIDFn_t get_netid = (GetNetIDFn_t)vtable[5];
    
    
    uint32_t* pNetID = get_netid(sub_obj);
    if (pNetID) return *pNetID; // Function called and uint32_t NetworkID read from returned address
    return 0;
}

typedef __int64(__fastcall* GetBoneMatrixFn)(void* model_instance, Matrix44* out_matrix, int bone_index);
bool GetHeadPosition(uintptr_t game_object, Vec3& out_head_pos) {
    if (!game_object) return false;

    void* model_instance = *(void**)(game_object + Offsets::Standard::AIBaseClient::oModelInstance);
    if (!model_instance) return false;

    uintptr_t bone_array = *(uintptr_t*)((char*)model_instance + 0x28);  // maybe 20???
    if (!bone_array) return false;

    GetBoneMatrixFn GetBoneMatrix = (GetBoneMatrixFn)(Offsets::ImageBase + Offsets::Functions::RemapBoneIndex);

    Matrix44 bone_matrix;
    // '6' or '8' is head
    int head_bone_index = 6; 

    GetBoneMatrix(model_instance, &bone_matrix, head_bone_index);

    //  (X, Y, Z) 
    out_head_pos.x = bone_matrix.m[3][0];
    out_head_pos.y = bone_matrix.m[3][1];
    out_head_pos.z = bone_matrix.m[3][2];

    if (out_head_pos.x == 0.0f && out_head_pos.y == 0.0f) {
        out_head_pos = *(Vec3*)(game_object + Offsets::Standard::GameObject::oPosition); // oPosition fall-back
        out_head_pos.y += 180.0f;
    }

    return true;
}

void ProcessEntitiesExample(uintptr_t base_addr) 
{
    is_type_t is_type = (is_type_t)(base_addr + 0x263150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    void* local_player = *(void**)(base_addr + 0x1EA0528);
    uint8_t local_team = local_player ? *(uint8_t*)((char*)local_player + Offsets::Standard::GameObject::oTeamID) : 100;
    uint32_t team_bit = (local_team == 100) ? 0 : 1;

    for (void* obj : entities) 
    {
        if (!obj) continue;

        bool is_hero = is_type(obj, 0x1000);
        bool is_minion = is_type(obj, 0x800);
        bool is_turret = is_type(obj, 0x2000);

        if (!is_hero && !is_minion && !is_turret) continue;

        float hp = *(float*)((char*)obj + 0x1060);
        float hp_max = *(float*)((char*)obj + 0x1088);
        if (hp <= 0.0f) continue;

        const char* champ_name = "";
        if (is_hero) {
            char* charDataStack = (char*)obj + Offsets::Standard::AIBaseClient::oCharacterDataStack;
            void** charVtable = *(void***)charDataStack;
            if (charVtable) {
                typedef const char*(__fastcall* GetCharacterNameFn_t)(void*);
                GetCharacterNameFn_t get_name = (GetCharacterNameFn_t)charVtable[17];
                champ_name = get_name(charDataStack);
            }
        } else {
            MsvcString* name_str = (MsvcString*)((char*)obj + 0x68);
            champ_name = name_str->c_str();
        }
        const char* summoner_name = "";
        if (is_hero) {
            char* statsComponent = *(char**)((char*)obj + Offsets::Standard::GameObject::oPlayerStatsComponent);
            if (statsComponent) {
                MsvcString* nameStr = (MsvcString*)(statsComponent + 0x80);
                summoner_name = nameStr->c_str();
            }
        }

        uint8_t team_id = *(uint8_t*)((char*)obj + Offsets::Standard::GameObject::oTeamID);

        Vec3 pos = *(Vec3*)((char*)obj + Offsets::Standard::GameObject::oPosition);

        uint32_t vis_mask = *(uint32_t*)((char*)obj + 0x30C);
        bool is_visible = (vis_mask & (1 << team_bit)) == 0;

        float mana = *(float*)((char*)obj + 0x360);
        float mana_max = *(float*)((char*)obj + 0x388);
        bool mana_enabled = *(bool*)((char*)obj + 0x3B0);

        int level = *(int*)((char*)obj + 0x4D70);

        float armor = *(float*)((char*)obj + 0x2078);
        float mr = *(float*)((char*)obj + 0x20C8);
        float move_speed = *(float*)((char*)obj + 0x2168);

        float all_shield = *(float*)((char*)obj + 0x1100);
        float phys_shield = *(float*)((char*)obj + 0x1128);
        float mag_shield = *(float*)((char*)obj + 0x1150);

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
        // buff manager is embedded at obj+0x2E58 (vtable); buff vector at obj+0x2F00/0x2F08
        void* list_start = *(void**)((char*)obj + 0x2F00);
        void* list_end = *(void**)((char*)obj + 0x2F08);
        (void)list_start; (void)list_end;
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
            uint8_t team_id = *(uint8_t*)((char*)obj + Offsets::Standard::GameObject::oTeamID);
            if (team_id != 100 && team_id != 200) // Neutral (not Blue 100 or Red 200)
            { 
                monsters.push_back(obj);
            }
        }
    }
    return monsters;
    }
    void camera(uintptr_t baseAddress) {
    uintptr_t hudInstanceAddr = *reinterpret_cast<uintptr_t*>(baseAddress + 0x1E76E08);
    if (!hudInstanceAddr) return;
    uintptr_t cameraPtr = *reinterpret_cast<uintptr_t*>(hudInstanceAddr + 0x18);
    if (!cameraPtr) return;
    Vector3 camPos = *reinterpret_cast<Vector3*>(cameraPtr + 0x10);
    Vector3 camRot = *reinterpret_cast<Vector3*>(cameraPtr + 0x40);
    float currentFOV = *reinterpret_cast<float*>(cameraPtr + 0x1DC);
    float nearClip = *reinterpret_cast<float*>(cameraPtr + 0x1F4);
    float farClip = *reinterpret_cast<float*>(cameraPtr + 0x1F8);
    std::cout << "[+] Camera Position: X: " << camPos.x << ", Y: " << camPos.y << ", Z: " << camPos.z << "\n";
    std::cout << "[+] Camera FOV: " << currentFOV << " (default: 45.0)\n";
    // zoom hack:
     *reinterpret_cast<float*>(cameraPtr + 0x1DC) = 55.0f; 
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
        uint8_t team = *(uint8_t*)((char*)local_player + Offsets::Standard::GameObject::oTeamID);
        uint32_t team_bit = (team == 100) ? 0 : 1;
        uint32_t mask = *(uint32_t*)((char*)obj + 0x30C);
        return (mask & (1 << team_bit)) == 0;
    }
    void UpdateCamera(uintptr_t base_addr) {
    void* hud = *(void**)(base_addr + 0x1E76E08); // HudInstance global
    if (!hud) return;

    void* cam = *(void**)((char*)hud + 0x18); // Camera pointer
    if (!cam) return;

    Vec3 cam_pos = *(Vec3*)((char*)cam + 0x10);
    Vec3 cam_rot = *(Vec3*)((char*)cam + 0x40);
    float fov = *(float*)((char*)cam + 0x1DC);
    float near_clip = *(float*)((char*)cam + 0x1F4);
    float far_clip  = *(float*)((char*)cam + 0x1F8);
    float zoom      = *(float*)((char*)cam + 0x324);
    float min_zoom  = *(float*)((char*)cam + 0x310);
    bool attached = *(bool*)((char*)cam + 0x28);
    float move_speed = *(float*)((char*)cam + 0x0C);
    float look_speed = *(float*)((char*)cam + 0x34);

    Vec3* cam_pos_ptr = (Vec3*)((char*)cam + 0x10);
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

    uint32_t GetDecryptedNetworkID(void* gameObject) {
        if (!gameObject) return 0;
        void* sub_obj = (char*)gameObject + 0x2A8;
        void** vtable = *(void***)sub_obj;
        if (!vtable) return 0;
        typedef uint32_t*(__fastcall* GetNetIDFn_t)(void*);
        GetNetIDFn_t get_netid = (GetNetIDFn_t)vtable[5];
        uint32_t* pNetID = get_netid(sub_obj);
        return pNetID ? *pNetID : 0;
    }

    void CastSpell(void* spell_book, int slot, uint32_t target_netid = 0, Vec3* pos = nullptr) {
        if (!spell_book) return;
        void* local_player = *(void**)(base + Offsets::Globals::LocalPlayer);
        if (!local_player) return;
        void* spell_slot = (*(void***)((char*)spell_book + 0xAE0))[slot];
        if (!spell_slot) return;

        // Set CastSpellFlag = 1 before casting (resets to 0 inside function call)
        *reinterpret_cast<uint8_t*>(base + Offsets::Globals::CastSpellFlag) = 1;

        if (pos) {
            // CastSpellPosition
            // Arguments: SpellBook, SpellSlot, slotIndex, targetPos, startPos, targetNetworkID
            typedef void(__fastcall* CastSpellPos_t)(void*, void*, int, Vec3*, Vec3*, uint32_t);
            auto cast_pos_fn = (CastSpellPos_t)(base + Offsets::Functions::CastSpellPosition);
            Vec3 start_pos = *(Vec3*)((char*)local_player + 0x25C);
            cast_pos_fn(spell_book, spell_slot, slot, pos, &start_pos, target_netid);
        } else {
            // CastSpellTarget
            // Arguments: SpellBook, SpellSlot, slotIndex, spellNamePtr, targetNetworkID, unused1, unused2
            void* spell_data = *reinterpret_cast<void**>(reinterpret_cast<char*>(spell_slot) + 0x128);
            void* spell_name_ptr = spell_data ? (reinterpret_cast<char*>(spell_data) + 8) : nullptr;

            typedef void(__fastcall* CastSpellTarget_t)(void*, void*, int, void*, uint32_t, char, char);
            auto cast_target_fn = (CastSpellTarget_t)(base + Offsets::Functions::CastSpellTarget);
            cast_target_fn(spell_book, spell_slot, slot, spell_name_ptr, target_netid, 0, 0);
        }
    }

    bool CanCast(void* spell_book, int slot, float time) {
        SpellSlot* s = spell_book ? (*(SpellSlot***)((char*)spell_book + 0xAE0))[slot] : nullptr;
        return s && s->level > 0 && s->cd_expire <= time && (s->charges > 0 || s->charge_cd <= time);
    }

    void CheckActiveSpell(void* obj) {
        void* sb = (char*)obj + 0x3108; // spellbook component is embedded, not a pointer
        if (!sb) return;
        SpellCastInfo* cast = *(SpellCastInfo**)((char*)sb + 0xAD8);
        if (cast && cast->slot_info && cast->slot_info->spell_data) {
            std::cout << "Casting: " << cast->slot_info->spell_data->spell_name.c_str() << "\n";
        }
    }

    bool IsCCd(void* obj, float game_time) {
        if (!obj) return false;
        // buff manager embedded at oBuffManager; vector at +0xA8/+0xB0 rel. to it (unit+0x2F00/0x2F08)
        char* buff_mgr = (char*)obj + Offsets::Standard::AIBaseClient::oBuffManager;
        void** list_start = *(void***)(buff_mgr + 0xA8);
        void** list_end = *(void***)(buff_mgr + 0xB0);
        if (!list_start || !list_end) return false;

        for (void** it = list_start; it < list_end; it += 2) { // entry stride 0x10: { buffPtr, nameHash }
            void* buff = *it;
            if (!buff) continue;

            // ponytail: buff active check using start and end times
            float start = *reinterpret_cast<float*>((char*)buff + 0x18);
            float end = *reinterpret_cast<float*>((char*)buff + 0x1C);
            if (game_time < start || game_time > end) continue;

            void** vtable = *(void***)buff;
            if (!vtable || !vtable[2]) continue;

            auto get_type = reinterpret_cast<uint8_t(__fastcall*)(void*)>(vtable[2]);
            uint8_t type = get_type(buff);

            // ponytail: verified CC BuffType values (Stun=5, Silence=7, Taunt=8, Snare=12, Fear=22, Charm=23, Suppression=25, etc.)
            if (type == 5 || type == 7 || type == 8 || type == 9 || type == 10 ||
                type == 11 || type == 12 || type == 22 || type == 23 || type == 25 ||
                type == 29 || type == 30 || type == 31 || type == 32 || type == 33 ||
                type == 34 || type == 35) {
                return true;
            }
        }
        return false;
    }

    bool GetSpellCastGeometry(void* obj, Vec3& out_start, Vec3& out_end, float& out_windup, uint32_t& out_target_netid) {
        if (!obj) return false;
        void* sb = (char*)obj + 0x3108; // spellbook component is embedded, not a pointer
        if (!sb) return false;
        auto* cast = *reinterpret_cast<SpellCastInfo**>((char*)sb + Offsets::Standard::SpellBook::oActiveSpellCast);
        if (!cast) return false;
        out_start = cast->start_pos;
        out_end = cast->end_pos;
        out_windup = cast->windup_time;
        out_target_netid = cast->target_netid;
        return true;
    }

    bool GetChargedSpellInfo(void* spell_book, int slot, int& out_charge_level, float& out_charge_start_time) {
        if (!spell_book) return false;
        void** slots = *(void***)((char*)spell_book + Offsets::Standard::SpellBook::oSpellSlots);
        if (!slots || !slots[slot]) return false;
        void* s = slots[slot];
        out_charge_level = *reinterpret_cast<int*>((char*)s + Offsets::Standard::SpellSlot::oChargeLevel);
        out_charge_start_time = *reinterpret_cast<float*>((char*)s + Offsets::Standard::SpellSlot::oChargeStartTime);
        return true;
    }

    Vec3 GetFacingDirection(void* obj) {
        if (!obj) return { 0, 0, 0 };
        return *reinterpret_cast<Vec3*>((char*)obj + Offsets::Standard::AIBaseClient::oFacing);
    }

    bool IsObjectValid(void* obj) {
        if (!obj) return false;
        bool is_deleted = *reinterpret_cast<bool*>((char*)obj + Offsets::Standard::GameObject::oIsDeleted);
        if (is_deleted) return false;

        uint16_t index = *reinterpret_cast<uint16_t*>((char*)obj + Offsets::Standard::GameObject::oIndex);
        typedef void*(__fastcall* GetObjectByIDFn)(uint32_t);
        auto get_obj_by_id = reinterpret_cast<GetObjectByIDFn>(base + Offsets::Functions::GetObjectByID);
        return get_obj_by_id(index) == obj;
    }

    bool CreatePath(const Vec3& start, const Vec3& end, std::vector<Vec3>& out_path) {
        void* nav_mesh = *reinterpret_cast<void**>(base + Offsets::Globals::NavGrid);
        if (!nav_mesh) return false;

        typedef bool(__fastcall* CreatePathFn)(void*, const Vec3*, const Vec3*, std::vector<Vec3>*);
        auto create_path_fn = reinterpret_cast<CreatePathFn>(base + Offsets::Functions::NavMesh__CreatePath);
        return create_path_fn(nav_mesh, &start, &end, &out_path);
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
