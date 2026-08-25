#pragma once
#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include "../offsets.hpp"

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

inline uint32_t GetDecryptedNetworkID(uintptr_t gameObject) {
    if (!gameObject) return 0;
    
    uintptr_t sub_obj = gameObject + Offsets::Standard::GameObject::oPlayerStatsComponent; 
    uintptr_t* vtable = *(uintptr_t**)sub_obj;
    if (!vtable) return 0;
    
    typedef uint32_t*(__fastcall* GetNetIDFn_t)(uintptr_t);
    GetNetIDFn_t get_netid = (GetNetIDFn_t)vtable[5];
    
    uint32_t* pNetID = get_netid(sub_obj);
    if (pNetID) return *pNetID;
    return 0;
}

typedef __int64(__fastcall* GetBoneMatrixFn)(void* model_instance, Matrix44* out_matrix, int bone_index);
inline bool GetHeadPosition(uintptr_t game_object, Vec3& out_head_pos) {
    if (!game_object) return false;

    void* model_instance = *(void**)(game_object + Offsets::Standard::AIBaseClient::oModelInstance);
    if (!model_instance) return false;

    GetBoneMatrixFn GetBoneMatrix = (GetBoneMatrixFn)(Offsets::ImageBase + Offsets::Functions::RemapBoneIndex);

    Matrix44 bone_matrix;
    int head_bone_index = 6; 

    GetBoneMatrix(model_instance, &bone_matrix, head_bone_index);

    out_head_pos.x = bone_matrix.m[3][0];
    out_head_pos.y = bone_matrix.m[3][1];
    out_head_pos.z = bone_matrix.m[3][2];

    if (out_head_pos.x == 0.0f && out_head_pos.y == 0.0f) {
        out_head_pos = *(Vec3*)(game_object + Offsets::Standard::GameObject::oPosition);
        out_head_pos.y += 180.0f;
    }

    return true;
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

struct LeagueEngine {
    uintptr_t base;
    LeagueEngine(uintptr_t image_base = Offsets::ImageBase) : base(image_base) {}

    typedef bool(__fastcall* is_type_t)(void*, uint32_t);
    bool IsType(void* obj, uint32_t flag) {
        if (!obj) return false;
        auto fn = (is_type_t)(base + Offsets::Functions::GameObject__IsType);
        return fn(obj, flag);
    }

    std::vector<void*> GetActiveEntities() {
        std::vector<void*> out;
        struct Node { void* l; void* p; void* r; char c, s, pad[6]; uint32_t k; char p2[4]; void* v; };
        auto* obj_mgr = *(char**)(base + Offsets::Globals::ObjectManager);
        if (!obj_mgr) return out;
        Node* head = *(Node**)(obj_mgr + Offsets::Standard::ObjectManager::TreeHead);
        if (!head || !head->p || head->p == head) return out;
        
        auto traverse = [&](auto self, Node* n) -> void {
            if (!n || n == head || n->s) return;
            self(self, (Node*)n->l);
            if (n->v) out.push_back(n->v);
            self(self, (Node*)n->r);
        };
        traverse(traverse, (Node*)head->p);
        return out;
    }

    std::vector<void*> GetChampions() {
        std::vector<void*> heroes;
        void* mgr = *(void**)(base + Offsets::Globals::HeroManager);
        if (mgr) {
            void** list = *(void***)((char*)mgr + 0x08);
            uint32_t count = *(uint32_t*)((char*)mgr + 0x10);
            for (uint32_t i = 0; i < count; i++)
                if (list[i]) heroes.push_back(list[i]);
        }
        return heroes;
    }

    std::vector<void*> GetMinions() {
        std::vector<void*> minions;
        std::vector<void*> entities = GetActiveEntities();
        for (void* obj : entities) {
            if (obj && IsType(obj, 0x800)) { // 0x800 = TypeMinion
                minions.push_back(obj);
            }
        }
        return minions;
    }

    std::vector<void*> GetJungleMonsters() {
        std::vector<void*> monsters;
        std::vector<void*> entities = GetActiveEntities();
        for (void* obj : entities) {
            if (obj && IsType(obj, 0x800)) {
                uint8_t team_id = *(uint8_t*)((char*)obj + Offsets::Standard::GameObject::oTeamID);
                if (team_id != 100 && team_id != 200) {
                    monsters.push_back(obj);
                }
            }
        }
        return monsters;
    }

    typedef bool(__fastcall* IssueOrderCore_t)(void*, uint32_t, Vec3*, void*, bool, bool, bool);
    void IssueOrder(int type, Vec3* pos, void* target = nullptr) {
        void* hud = *(void**)(base + Offsets::Globals::HudInstance);
        if (!hud) return;
        void* logic = *(void**)((char*)hud + 0x24);
        if (logic) {
            auto fn = (IssueOrderCore_t)(base + Offsets::Functions::IssueOrderCore);
            fn(logic, type, pos, target, false, false, true);
        }
    }

    void PrintChat(const char* text, int color = 0xFFFFFF) {
        typedef void(__fastcall* PrintChat_t)(void*, MsvcString*, int);
        void* client = *(void**)(base + Offsets::Globals::ChatClient);
        MsvcString msg(text);
        if (client) {
            auto fn = (PrintChat_t)(base + Offsets::Functions::PrintChat);
            fn(client, &msg, color);
        }
    }

    void CastSpell(void* spell_book, int slot, uint32_t target_netid = 0, Vec3* pos = nullptr) {
        if (!spell_book) return;
        void* local_player = *(void**)(base + Offsets::Globals::LocalPlayer);
        if (!local_player) return;
        void* spell_slot = (*(void***)((char*)spell_book + Offsets::Standard::SpellBook::oSpellSlots))[slot];
        if (!spell_slot) return;

        *reinterpret_cast<uint8_t*>(base + Offsets::Globals::CastSpellFlag) = 1;

        if (pos) {
            typedef void(__fastcall* CastSpellPos_t)(void*, void*, int, Vec3*, Vec3*, uint32_t);
            auto cast_pos_fn = (CastSpellPos_t)(base + Offsets::Functions::CastSpellPosition);
            Vec3 start_pos = *(Vec3*)((char*)local_player + Offsets::Standard::GameObject::oPosition);
            cast_pos_fn(spell_book, spell_slot, slot, pos, &start_pos, target_netid);
        } else {
            void* spell_data = *reinterpret_cast<void**>(reinterpret_cast<char*>(spell_slot) + Offsets::Standard::SpellSlot::oSpellData);
            void* spell_name_ptr = spell_data ? (reinterpret_cast<char*>(spell_data) + 8) : nullptr;

            typedef void(__fastcall* CastSpellTarget_t)(void*, void*, int, void*, uint32_t, char, char);
            auto cast_target_fn = (CastSpellTarget_t)(base + Offsets::Functions::CastSpellTarget);
            cast_target_fn(spell_book, spell_slot, slot, spell_name_ptr, target_netid, 0, 0);
        }
    }

    bool IsCCd(void* obj, float game_time) {
        if (!obj) return false;
        void* buff_mgr = *(void**)((char*)obj + Offsets::Standard::AIBaseClient::oBuffManager);
        if (!buff_mgr) return false;
        void** list_start = *(void***)((char*)buff_mgr + Offsets::Standard::BuffManager::oBuffArrayStart);
        void** list_end = *(void***)((char*)buff_mgr + Offsets::Standard::BuffManager::oBuffArrayEnd);
        if (!list_start || !list_end) return false;

        for (void** it = list_start; it < list_end; ++it) {
            void* buff = *it;
            if (!buff) continue;

            float start = *reinterpret_cast<float*>((char*)buff + Offsets::Standard::BuffEntry::oStartTime);
            float end = *reinterpret_cast<float*>((char*)buff + Offsets::Standard::BuffEntry::oEndTime);
            if (game_time < start || game_time > end) continue;

            void** vtable = *(void***)buff;
            if (!vtable || !vtable[2]) continue;

            auto get_type = reinterpret_cast<uint8_t(__fastcall*)(void*)>(vtable[2]);
            uint8_t type = get_type(buff);

            // Stun=5, Silence=7, Taunt=8, Snare=12, Fear=22, Charm=23, Suppression=25, etc.
            if (type == 5 || type == 7 || type == 8 || type == 9 || type == 10 ||
                type == 11 || type == 12 || type == 22 || type == 23 || type == 25 ||
                type == 29 || type == 30 || type == 31 || type == 32 || type == 33 ||
                type == 34 || type == 35) {
                return true;
            }
        }
        return false;
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
        if (oOnProcessSpell) {
            oOnProcessSpell(spellbook, cast_info);
        }
    }
}
