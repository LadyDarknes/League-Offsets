<h1 align="center">League — Core Offset & Pattern Database</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Patch-26.20-blue?style=flat-square" alt="Patch" />
  <img src="https://img.shields.io/badge/Architecture-x64%20PE-lightgrey?style=flat-square" alt="Arch" />
  <img src="https://img.shields.io/badge/Tool-IDA%20Pro%209.4-orange?style=flat-square" alt="Tool" />
  <img src="https://img.shields.io/badge/Status-Tested%20%26%20Verified-brightgreen?style=flat-square" alt="Status" />
  <img src="https://img.shields.io/badge/Design-Essential%20%26%20Lightweight-success?style=flat-square" alt="Design" />
</p>

<p align="center">
  <strong>Star For Support ⭐</strong><br>
  Curated, verified, and reverse-engineered x64 PE offsets, AOB signatures, and memory layouts for League of Legends.<br>
  <em>Focused strictly on core essential components to guarantee minimal maintenance and zero bloat across patch cycles.</em>
</p>

---

## 🏗️ Build Info

| Field | Value |
| :--- | :--- |
| **Patch** | **26.20** |
| **Target Binary** | `League of Legends.exe` · x64 PE |
| **Compiler** | Microsoft Visual C++ |
| **Default ImageBase** | `0x7FF69A1B0000` |
| **Reversing Engine** | Hex-Rays Decompiler & IDA Pro 9.4 |
| **Verification State** | 100% In-Engine Assembly Verified |

---

## 🗺️ Memory & Offset Architecture Tree

<p align="center">
  <img src="assets/offset_tree.png" alt="Memory & Offset Architecture Tree" width="100%" />
</p>

---

## 📌 Verified Core Offsets

### 1. Global Singletons & Managers (`Offsets::Globals`)

| Identifier | RVA Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| `LocalPlayer` | `0x1CC6FD8` | `uintptr_t` | Pointer to the local player champion object |
| `HeroManager` | `0x1C88FB0` | `uintptr_t` | Manager containing all active champion objects |
| `MinionManager` | `0x1C8C440` | `uintptr_t` | Manager containing lane minions, super minions & jungle camps |
| `TurretManager` | `0x1C91BE0` | `uintptr_t` | Manager containing active turrets, inhibitors & nexus |
| `ObjectManager` | `0x1C88FF0` | `uintptr_t` | AllUnits pool manager containing all entities |
| `GameClient` | `0x1C8C428` | `uintptr_t` | Game client instance (game state & connection status) |
| `GameTime` | `0x1C95618` | `float` | Current match elapsed game time in seconds |
| `ViewPort` | `0x1C8C418` | `uintptr_t` | Viewport & projection matrix instance for WorldToScreen |
| `HudInstance` | `0x1C89020` | `uintptr_t` | Global GUI, camera pointer (`+0x18`) & input manager |
| `NavGrid` | `0x1C8C3B0` | `uintptr_t` | Navigation mesh and pathfinding grid |
| `MissileManager` | `0x1C8C450` | `uintptr_t` | Active spell projectile manager |
| `ChampionManager` | `0x1CAA520` | `uintptr_t` | Champion data & character resource manager |

---

### 2. Core Functions & Hooks (`Offsets::Functions`)

| Function | RVA Offset | Signature / Purpose |
| :--- | :--- | :--- |
| `TranslateString` | `0xF7F7B0` | Riot string localization & key translation lookup |
| `GetGoldRedirect` | `0x214870` | Resolves target entity for redirected kill gold attribution |
| `CDSPush` | `0x238310` | CharacterDataStack push function (model/skin modification) |
| `CDSUpdate` | `0x21C1E0` | CharacterDataStack update & re-render trigger |

---

### 3. GameObject & Entity Fields (`Offsets::GameObject`)

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| `NetworkID` | `0x78` | `uint32_t` | Unique 32-bit entity network identifier |
| `Position` | `0x15C` | `Vec3` | 3D World position (X, Y, Z) |
| `Team` | `0x158` | `uint8_t` | Team ID (`100` = Blue, `200` = Red, `300` = Neutral) |
| `Visible` | `0x208` | `bool` | Entity visibility state byte |
| `Name` | `0x3890` | `char[16]` | Internal model / character name string |
| `AttackRange` | `0xFDC` | `float` | Base auto-attack range (`GetAttackRange`) |
| `BuffManager` | `0x25E8` | `uintptr_t` | Inline active buff controller |
| `MinionType` | `0x4B39` | `uint8_t` | Minion classification sub-byte |
| `CharacterDataStack` | `0x3638` | `uintptr_t` | Character model/skin stack pointer |

---

### 4. Health & Shield Obfuscation Architecture (`Obfuscated<float>`)

> [!NOTE]
> Riot encapsulates vital gameplay stats inside `0x28` (40 byte) `Obfuscated<float>` blocks.
> When `IsObfuscationEnabled()` is inactive (standard state in normal game loops), the engine directly reads the raw `float` at `+0x00`. External readers can read the unencrypted raw float directly without calling decryption routines.

```
Obfuscated<float> Memory Stride (0x28 bytes):
┌────────────────────────┬──────────────────┬────────────────────────┐
│  +0x00: Raw Float      │  +0x18: Decrypt  │  +0x20: Obfuscated     │
│  (Unencrypted Value)   │  Context Ptr     │  Key / Slot            │
└────────────────────────┴──────────────────┴────────────────────────┘
```

| Property | Unencrypted Raw Float (`+0x00`) | Obfuscated Slot (`+0x20`) | Description |
| :--- | :--- | :--- | :--- |
| **Health** | **`0x910`** | `0x930` | Current entity health |
| **MaxHealth** | **`0x938`** | `0x958` | Maximum entity health |
| **AllShield** | **`0x9B0`** | `0x9D0` | Physical / universal shield value |
| **MagicShield** | **`0xA00`** | `0xA20` | Magical shield value |

---

### 5. Manager Memory Layout (`Offsets::Manager`)

Applicable to `HeroManager`, `MinionManager`, and `TurretManager`:

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| `List` | `0x08` | `uintptr_t*` | Pointer to dynamic contiguous array of entity pointers |
| `Count` | `0x10` | `uint32_t` | Active entity count currently tracked |

---

## 🔎 Verified AOB Signatures

| Target | Pattern | Op Offset | Instr Len | RIP-Rel |
| :--- | :--- | :---: | :---: | :---: |
| **LocalPlayer** | `48 8B 1D ? ? ? ? 48 8B CE 48 89 35 ? ? ? ? 48 8B 06 FF 90 68 01 00 00` | 13 | 17 | `true` |
| **HeroManager** | `48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 89 0D ? ? ? ? 48 8D 05 ? ? ? ? 33 F6 48 89 01 48 8D 05 ? ? ? ? 48 89 71 08` | 18 | 22 | `true` |
| **MinionManager** | `48 8B 0D ? ? ? ? 48 83 B8 C0 00 00 00 00` | 3 | 7 | `true` |
| **TurretManager** | `48 8B 0D ? ? ? ? 48 8D 4C 24 70` | 3 | 7 | `true` |
| **ObjectManager** | `48 89 05 ? ? ? ? 48 8D 4B ? 48 89 70 08 48 89 70 10` | 3 | 7 | `true` |
| **GameClient** | `48 8B 05 ? ? ? ? 83 78 08 02 44 0F 44` | 3 | 7 | `true` |
| **GameTime** | `F3 0F 5C 35 ? ? ? ? 0F 28 F8` | 4 | 8 | `true` |
| **ViewPort** | `48 8B 35 ? ? ? ? 48 8D 4C 24 ? F3 0F 10 46` | 3 | 7 | `true` |
| **HudInstance** | `48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 49 ? 48 8D` | 3 | 7 | `true` |
| **NavGrid** | `48 8B 05 ? ? ? ? 0F 28 DA` | 3 | 7 | `true` |
| **ChampionManager**| `48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50` | 3 | 7 | `true` |

---

## 📁 Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.hpp            ← Clean, modern C++ header ready for direct inclusion
│   ├── offsets.json           ← Complete JSON dump of resolved RVAs, structs & signatures
│   └── quick_usage/           
│       └── all_offsets.hpp    ← Lightweight reference implementation & engine wrapper
├── dump/
│   └── ida_dumper.py          ← Python script to auto-resolve & sync offsets in IDA Pro
└── assets/
    └── offset_tree.png        ← Visual memory & architecture dependency diagram
```

---

## 🚀 Quick Usage Example

```cpp
#include "src/offsets.hpp"

// 1. Resolve LocalPlayer
uintptr_t localPlayer = Read<uintptr_t>(imageBase + Offsets::Globals::LocalPlayer);

// 2. Read Entity Fields
Vec3 pos = Read<Vec3>(localPlayer + Offsets::GameObject::Position);
float health = Read<float>(localPlayer + Offsets::GameObject::Health); // 0x910
float attackRange = Read<float>(localPlayer + Offsets::GameObject::AttackRange);

// 3. Iterate Champions (HeroManager)
uintptr_t heroMgr = Read<uintptr_t>(imageBase + Offsets::Globals::HeroManager);
if (heroMgr) {
    uintptr_t arrayPtr = Read<uintptr_t>(heroMgr + Offsets::Manager::List);
    uint32_t count = Read<uint32_t>(heroMgr + Offsets::Manager::Count);
    for (uint32_t i = 0; i < count; ++i) {
        uintptr_t hero = Read<uintptr_t>(arrayPtr + (i * sizeof(uintptr_t)));
        if (hero) {
            // Process champion...
        }
    }
}
```

---

## 📬 Contact & Contributions

* **Discord:** `swansizz`
* Found a broken pattern or new RVA shift? Open an [Issue](../../issues) or submit a Pull Request.
