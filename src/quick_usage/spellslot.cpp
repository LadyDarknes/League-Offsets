#include <stdint.h>
#include <iostream>
#include <math.h>

struct Vec3 { float x, y, z; };

struct SpellSlot {
    void** vtable;
    char pad[0x24];
    int level;          // +0x28
    float cd_expire;    // +0x30
    char pad2[0x30];
    int charges;        // +0x64
    float charge_cd;    // +0x68
};

typedef void(__fastcall* CastSpell_t)(SpellSlot*, int, uint32_t, Vec3*, Vec3*, uint32_t);

void CastSpell(void* spell_book, int slot, uint32_t target_id = 0, Vec3* pos = nullptr) {
    if (!spell_book) return;
    SpellSlot* spell = (*(SpellSlot***)((char*)spell_book + 0xAE0))[slot];
    if (spell) ((CastSpell_t)spell->vtable[4])(spell, slot, target_id, &Vec3{0,0,0}, pos ? pos : &Vec3{0,0,0}, 0);
}

bool CanCast(void* spell_book, int slot, float time) {
    SpellSlot* s = spell_book ? (*(SpellSlot***)((char*)spell_book + 0xAE0))[slot] : nullptr;
    return s && s->level > 0 && s->cd_expire <= time && (s->charges > 0 || s->charge_cd <= time);
}

Vec3 GetPrediction(Vec3 target, Vec3 vel, float delay, float speed, Vec3 src) {
    float t = delay + (speed > 0 ? (sqrtf(powf(target.x-src.x,2)+powf(target.z-src.z,2))/speed) : 0);
    return { target.x + vel.x * t, target.y, target.z + vel.z * t };
}

struct CombatStats {
    char pad[0x1C];
    float ap, ad; int level; // 1C, 24, 28
    char pad2[0x1D8];
    float as_mod; // 1A8
};

void PrintStats(void* hero) {
    if (auto* s = *(CombatStats**)((char*)hero + 0x49E8))
        std::cout << "AD: " << s->ad << " LVL: " << s->level << "\n";
}

void* GetUnitByNetID(uintptr_t base, uint32_t netid) {
    struct Node { Node *l, *p, *r; char c, s, pad[6]; uint32_t k; char p2[4]; void* v; };
    auto* head = *(Node**)(*(char**)(base + 0x1E76C80) + 0x40);
    for (auto* c = head->p; c && c != head && !c->s; c = (netid < c->k ? c->l : c->r))
        if (c->k == netid) return c->v;
    return nullptr;
}
