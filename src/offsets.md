# League of (removed) — Scripting Offsets

This document records the global addresses, function entry points, and internal structure member offsets reversed from the League of Removed binary.

| Field | Value |
| ----- | ----- |
| SHA-256 | `42DBD44CAA08B20102BED923A22BE1386EE5370EDB90DA90F4EC0F93821DFF79` |
| MD5 | `4090434E4ADCE3F9689E4D92EA92FBCE` |
| CRC32 | `E17A5127` |
| Compiler | Visual C++ |
| Format | Portable executable for AMD64 (PE) |
| Imagebase | 7FF7E6B90000|
| Timestamp | 6A2B43A1 (Thu Jun 11 23:24:17 2026) |

---

## Global Offsets

| Name | RVA | Address | Description |
| ---- | --- | ------- | ----------- |
| `LocalPlayer` | `0x1eb2020` | `0x7ff7e8a42020` | Local player champion object |
| `HeroManager` | `0x1e76da0` | `0x7ff7e8a06da0` | List of all hero game objects |
| `ViewPort` | `0x1e79d20` | `0x7ff7e8a09d20` | Camera viewport configuration |
| `GameTime` | `0x1e855a0` | `0x7ff7e8a155a0` | Floating-point match game time in seconds |
| `EntityList` | `0x238aec` | `0x7ff7e6dc8aec` | Main game object array |
| `ObjectManager` | `0x1e76c80` | `0x7ff7e8a06c80` | Hash map of network-registered entities |
| `MissileManager` | `0x1e76d10` | `0x7ff7e8a06d10` | List of active active spell projectiles |
| `NavGrid` | `0x1e79cc0` | `0x7ff7e8a09cc0` | 2D pathfinding and cell height map grid |
| `HudInstance` | `0x1e76e08` | `0x7ff7e8a06e08` | GUI and user input controller |
| `r3dRenderer` | `0x1f4c598` | `0x7ff7e8adc598` | Render engine singleton |
| `NetInstance` | `0x1e76c90` | `0x7ff7e8a06c90` | Game client communication network layer |
| `NetClient` | `0x1e76c78` | `0x7ff7e8a06c78` | Ping/latency network structure |
| `UnderMouseObj` | `0x1e79f78` | `0x7ff7e8a09f78` | Current entity highlighted under mouse cursor |
| `ChatClient` | `0x1f38088` | `0x7ff7fadb8088` | Game chat history and UI controller |
| `g_QuestManager` | `0x1e94130` | `0x7ff7fad14130` | Global manager for narrative/stat quests |
| `g_RoleQuestKey` | `0x1e933f0` | `0x7ff7fad133f0` | Component registry key for Role Bound quests |
| `g_RoleBoundQuestController` | `0x1e90fe0` | `0x7ff7fad10fe0` | Controller handling RoleBound buttons & state |
| `g_RoleBoundRegistry` | `0x1e99498` | `0x7ff7fad19498` | Registry holding RoleBound configurations |

---

## Function Entries

| Name | RVA | Address | Description |
| ---- | --- | ------- | ----------- |
| `IssueOrderCore` | `0x290940` | `0x7ff7e6e20940` | Core action handler (move, attack, interact) |
| `WorldToScreen` | `0x12f6a90` | `0x7ff7e7e86a90` | Projects 3D world positions to 2D screen space |
| `GetBoundingRadius` | `0x27eb60` | `0x7ff7e6e0eb60` | Returns physical collision radius of GameObject |
| `GetAttackWindup` | `0x5725a0` | `0x7ff7e71025a0` | Calculates current champion auto-attack windup duration |
| `GetAttackDelay` | `0x5726b0` | `0x7ff7e71026b0` | Calculates basic attack cooldown based on AS |
| `GetCollisionFlags` | `0x1243ca0` | `0x7ff7e7dd3ca0` | Retrieves terrain collision byte at coordinates |
| `IsTurret` | `0x2b79d0` | `0x7ff7e6e479d0` | Returns true if the entity is an active defense tower |
| `IsAlive` | `0x2b79d0` | `0x7ff7e6e479d0` | Returns true if target HP > 0 |
| `IsVisible` | `0xb7e050` | `0x7ff7f99fe050` | Returns true if entity is visible — checks +0x168/+0x169/+0x16A |
| `GameObject::IsType` | `0x28f150` | `0x7ff7e6e1f150` | Helper function to check classification flags (TypeFlags) |
| `SpellBook::GetSpellSlot` | `0x966d50` | `0x7ff7f97e6d50` | Retrieves SpellSlot* from the array at SpellBook + 0xAE0 |
| `SpellSlot::GetCooldown` | `0x932c70` | `0x7ff7e74c2c70` | Calculates remaining cooldown time for a spell slot |
| `SpellSlot::Cast` | `0x747f70` | `0x7ff7e72d7f70` | Triggers a spell cast request (vtable[4]) |
| `BuffManagerClient::OnBuffAdd` | `0x93dfb0` | `0x7ff7e74cdfb0` | Inserts a buff into client container |
| `BuffManagerClient::OnBuffRemove` | `0x93eb00` | `0x7ff7e74ceb00` | Evicts/destroys a buff in client container |
| `RoleBound::Init` | `0x10fbdb0` | `0x7ff7e7c8bdb0` | Registers the custom RoleBound system |
| `QuestProgress::Calculate` | `0x51e700` | `0x7ff7e70ae700` | Processes a quest entry to compute requirement & tier |
| `QuestProgress::GetQuestValue` | `0x5237e0` | `0x7ff7e70b37e0` | Queries quest values dynamically |
| `QuestProgress::LookupMap` | `0x5092b0` | `0x7ff7f93892b0` | Performs map lookup for quest definitions |
| `ComponentRegistry::Lookup` | `0x1189220` | `0x7ff7e7d19220` | Generic component registry lookup function |

---

## Structure Offsets (Scripting-Essential)

### 1. GameObject & Character Components
- **`Position`:** `GameObject + 0x25C` (604) [Type: `Vec3` — X=`+0x25C`, Y=`+0x260`, Z=`+0x264`]
- **`TeamID`:** `GameObject + 0x259` (601) [Type: `uint8_t` — 1=Blue, 0=Red]
- **`IsVisible`:** `GameObject + 0x168` (360) [Type: `bool` × 3 — see below]
- **`StatusFlags`:** `GameObject + 0xF8` (248) [Type: `uint32_t*` — lea getter]
- **`TypeFlags` Obfuscated Field:** `GameObject + 0x4C` (76) (XOR-obfuscated classification bitmask)
- **`Name`:** `GameObject + 0x68` (104) [Type: `std::string` — MSVC layout]
- **`HP`:** `GameObject + 0x1080` (4224) [Type: `float`]
- **`HPMax`:** `GameObject + 0x10A8` (4264) [Type: `float`]
- **`Mana`:** `GameObject + 0x360` (864) [Type: `float`]
- **`ManaMax`:** `GameObject + 0x388` (904) [Type: `float`]
- **`ManaEnabled`:** `GameObject + 0x3B0` (944) [Type: `bool`]
- **`Level`:** `GameObject + 0x4D58` (19800) [Type: `int`]
- **`Armor`:** `GameObject + 0x4F38` (20280) [Type: `float`]
- **`MagicResist`:** `GameObject + 0x4CB8` (19640) [Type: `float`]
- **`MoveSpeed`:** `GameObject + 0x5000` (20480) [Type: `float`]
- **`AllShield`:** `GameObject + 0x1120` (4384) [Type: `float`]
- **`PhysicalShield`:** `GameObject + 0x1148` (4424) [Type: `float`]
- **`MagicalShield`:** `GameObject + 0x1170` (4464) [Type: `float`]
- **`SpellBook` Component:** `GameObject + 0x3128` (12584)
- **`BuffManager` Wrapper:** `GameObject + 0x2B0` (688) (Calling `vtable[21]` returns the `BuffManagerClient*` pointer)
- **`BuffManagerClient` Direct Pointer:** `AIBaseClient + 0x28F0` (10480) (Direct pointer without wrapper calls)
- **`Quest Component Handle/Cache`:** `GameObject + 0xE0` (224) (Contains generic component pointers array/map)
- **`AIManager` Ptr:** `*(QWORD*)(GameObject + 0x4070)` (16496) — IDA confirmed: `cmp qword ptr [rcx+4070h], 0`
- **`HeroInventoryClient` Wrapper:** `GameObject + 0x4230` (16944) (inventory wrapper — not AIManager)
- **`JungleTypeOffset`:** `GameObject + 0x4484` (17540) (Jungle creep classification type ID)
- **`NetVisibilityObjectClient` Component:** `GameObject + 0x308` (776) (Visibility component; contains the team mask at `+0x30C` where bit 0 is Blue team fog and bit 1 is Red team fog)

### Visibility bytes (IsVisible)
- **`+0x168`** — primary visibility flag (stale/cached if unit is in fog of war)
- **`+0x169`** — team visibility flag (stale/cached if unit is in fog of war)
- **`+0x16A`** — alternate visibility source
- **`+0x30C`** — robust team visibility bitmask (updated directly by network packets, guards against client caching bugs)
  - Bit 0: Blue Team (1 = in fog, 0 = visible)
  - Bit 1: Red Team (1 = in fog, 0 = visible)
  - Logic: `(vis_mask & (1 << team_bit)) == 0`

### 2. `SpellBook` & `SpellSlot`
- **`SpellSlots` Array:** `SpellBook + 0xAE0` (2784) (Array of 64 pointers to `SpellSlot` structures)
- **`ActiveSpellCast` Pointer:** `SpellBook + 0xAD8` (2776)
- **`SpellSlot::Level`:** `SpellSlot + 0x28` (40) [Type: `int`]
- **`SpellSlot::CooldownExpirationTime`:** `SpellSlot + 0x30` (48) [Type: `float`]
- **`SpellSlot::Charges` / Ammo:** `SpellSlot + 0x64` (100) [Type: `int`]
- **`SpellSlot::ChargeCooldownExpirationTime`:** `SpellSlot + 0x68` (104) [Type: `float`]
- **`SpellSlot::GetSpellData()`:** `vtable[3]` of `SpellSlot` (offset `0x18`)
- **`SpellSlot::Cast()`:** `vtable[4]` of `SpellSlot` (offset `0x20`)
- **`SpellData::Name`:** `SpellData + 0x28` (40) [Type: `std::string`]
- **`SpellData::SlotIndex`:** `SpellData + 0x28` (40) / offset `+40` on target structure [Type: `int`]

### 3. `BuffManager` & `BuffInstance`
- **`BuffList` Vector Start:** `BuffManagerClient + 0x90` (144) [Type: `std::vector<std::shared_ptr<BuffInstance>>`, element size `16` bytes]
- **`BuffList` Vector End:** `BuffManagerClient + 0x98` (152)
- **`BuffInstance::GetBuffData()`:** `BuffInstance + 0x40` (64) [Type: `BuffData*`]
- **`BuffData::Name`:** `BuffData + 0x08` (8) [Type: `const char*`]
- **`BuffInstance::StartTime`:** `BuffInstance + 0x8C` (140) [Type: `float`]
- **`BuffInstance::EndTime`:** `BuffInstance + 0x90` (144) [Type: `float`]
- **`BuffInstance::Stacks` / Count:** `BuffInstance + 0x94` (148) [Type: `byte`]

### 4. `AIManager` Component (Navigation)
- **`AIManager` Ptr:** `*(QWORD*)(GameObject + 0x4070)` → `navInner = *(QWORD*)(AIManager + 0x40)` → `navPath = navInner + 0x45C`
- **`TargetPosition`:** `AIManager + 0x34` [Type: `Vec3`]
- **`Velocity`:** `AIManager + 0x318` [Type: `Vec3`]
- **`IsMoving`:** `AIManager + 0x31C` [Type: `bool`]
- **`PathStart`:** `AIManager + 0x330` [Type: `Vec3`]
- **`PathEnd`:** `AIManager + 0x33C` [Type: `Vec3`]
- **`SegmentsCount`:** `AIManager + 0x350` [Type: `int`]
- **`DashSpeed`:** `AIManager + 0x360` [Type: `float`]
- **`IsDashing`:** `AIManager + 0x384` [Type: `bool`]
- **`ServerPos`:** `AIManager + 0x474` [Type: `Vec3`]
- **`IsMovingFlag`:** `GameObject + 0x452` (1106) [Type: `bool`]
- **`PathBufferSelector`:** `GameObject + 0x478` (1144) [Type: `bool`]

### NavPath Struct (navInner + 0x45C)
- **`CurrentNodeIndex`:** `NavPath + 0x00` [Type: `int`]
- **`WaypointArray`:** `NavPath + 0x28` [Type: `Vec3*` — each entry 12 bytes]
- **`WaypointCount`:** `NavPath + 0x30` [Type: `int`]

### 5. `HeroInventoryClient` Component (Inventory)
- **`SlotInfo` Array:** `HeroInventoryClient + 0x10` [Type: `ItemSlot[7]` array]
- **`ItemSlot::ItemData`:** `ItemSlot + 0x38` [Type: `ItemData*`]
- **`ItemSlot::Stacks`:** `ItemSlot + 0x64` [Type: `int`]
- **`ItemData::ItemID`:** `ItemData + 0xB4` [Type: `int`]

### 6. `HudInstance` (Camera & UI Layout)
- **`Camera` Pointer:** `HudInstance + 0x18` (24)
- **`CameraZoom`:** `Camera + 0x324` (804) [Type: `float`]
- **`CameraZoomLimits`:** `Camera + 0x310` (784) [Type: `float`]
- **`SelectedObjNetId`:** `HudInstance + 0x28` (40) [Type: `uint32_t`]
- **`MouseWorldPos`:** `HudInstance + 0x34` (52) [Type: `Vec3`]
- **`ChatOpen` Wrapper:** `HudInstance + 0x10` (16)

### 7. `QuestEntry` Structure
- **`QuestEntry` Size (Stride):** `0x18` bytes
- **`QuestEntry::QuestDef`:** `QuestEntry + 0x00` [Type: `void*` pointer to quest definition]
- **`QuestEntry::QuestType`:** `QuestEntry + 0x08` [Type: `uint8_t` / stat type ID]
- **`QuestEntry::Mode`:** `QuestEntry + 0x09` [Type: `uint8_t` mode/behavior flag]
- **`QuestEntry::QuestTier`:** `QuestEntry + 0x0C` [Type: `uint32_t` current tier index]
- **`QuestEntry::Target`:** `QuestEntry + 0x10` [Type: `uint32_t` threshold / requirement limit]
