#pragma once
#include <cstdint>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
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

struct ScreenCoord {
    float x, y;
    bool onScreen;
};

// Example engine wrapper showing how to access the essential core offsets
class LeagueEngine {
public:
    uintptr_t base;

    LeagueEngine(uintptr_t image_base = Offsets::ImageBase) : base(image_base) {}

    // Template memory reader (implement with RPM or driver)
    template <typename T>
    T Read(uintptr_t address) {
        T value{};
        // Memory read implementation here
        return value;
    }

    // 1. LocalPlayer
    uintptr_t GetLocalPlayer() {
        return Read<uintptr_t>(base + Offsets::Globals::LocalPlayer);
    }

    // 2. GameTime
    float GetGameTime() {
        return Read<float>(base + Offsets::Globals::GameTime);
    }

    // 3. Entity Position & Stats
    Vec3 GetPosition(uintptr_t entity) {
        return Read<Vec3>(entity + Offsets::GameObject::Position);
    }

    float GetHealth(uintptr_t entity) {
        return Read<float>(entity + Offsets::GameObject::Health);
    }

    float GetMaxHealth(uintptr_t entity) {
        return Read<float>(entity + Offsets::GameObject::MaxHealth);
    }

    uint8_t GetTeam(uintptr_t entity) {
        return Read<uint8_t>(entity + Offsets::GameObject::Team);
    }

    uint32_t GetNetworkID(uintptr_t entity) {
        return Read<uint32_t>(entity + Offsets::GameObject::NetworkID);
    }

    // 4. HeroManager / MinionManager Iteration
    std::vector<uintptr_t> GetChampions() {
        std::vector<uintptr_t> list;
        uintptr_t mgr = Read<uintptr_t>(base + Offsets::Globals::HeroManager);
        if (!mgr) return list;

        uintptr_t array_ptr = Read<uintptr_t>(mgr + Offsets::Manager::List);
        uint32_t count = Read<uint32_t>(mgr + Offsets::Manager::Count);

        for (uint32_t i = 0; i < count; ++i) {
            uintptr_t hero = Read<uintptr_t>(array_ptr + (i * sizeof(uintptr_t)));
            if (hero) list.push_back(hero);
        }
        return list;
    }
};
