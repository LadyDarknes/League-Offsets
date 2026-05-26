# League of Legends — Scripting Offsets

This document records the global addresses, function entry points, and internal structure member offsets reversed from the League of Legends binary.

| Field | Value |
| ----- | ----- |
| SHA-256 | `AD9A3C2B9F1FAAE9BC013C4598F74EA3EB1B16FC90EF7FB2FB496E771803E390` |
| MD5 | `CAE7B6864A09A08974E229CDF43A339A` |
| CRC32 | `3540AE51` |
| Compiler | Visual C++ |
| Format | Portable executable for AMD64 (PE) |
| Imagebase | `7FF7C5CD0000` |
| Timestamp | 6A0507E6 (Wed May 13 23:23:18 2026) |

---

## Global Offsets

| Name | RVA | Address | Description |
| ---- | --- | ------- | ----------- |
| `LocalPlayer` | `0x1e73448` | `0x7ff7c7b43448` | Local player champion object |
| `HeroManager` | `0x1e3a418` | `0x7ff7c7b0a418` | List of all hero game objects |
| `ViewPort` | `0x1e4e870` | `0x7ff7c7b1e870` | Camera viewport configuration |
| `GameTime` | `0x1e49ac0` | `0x7ff7c7b19ac0` | Floating-point match game time in seconds |
| `EntityList` | `0x1e3a430` | `0x7ff7c7b0a430` | Main game object array |
| `ObjectManager` | `0x1e3a3c0` | `0x7ff7c7b0a3c0` | Hash map of network-registered entities |
| `MissileManager` | `0x1e3a480` | `0x7ff7c7b0a480` | List of active active spell projectiles |
| `NavGrid` | `0x1e3e3f0` | `0x7ff7c7b0e3f0` | 2D pathfinding and cell height map grid |
| `HudInstance` | `0x1e3a560` | `0x7ff7c7b0a560` | GUI and user input controller |
| `r3dRenderer` | `0x1f0b248` | `0x7ff7c7bdb248` | Render engine singleton |
| `NetInstance` | `0x1e3a3d0` | `0x7ff7c7b0a3d0` | Game client communication network layer |
| `NetClient` | `0x1e3a3b8` | `0x7ff7c7b0a3b8` | Ping/latency network structure |
| `UnderMouseObj` | `0x1e3e690` | `0x7ff7c7b0e690` | Current entity highlighted under mouse cursor |
| `ChatClient` | `0x1f09da8` | `0x7ff7c7bd9da8` | Game chat history and UI controller |
| `g_QuestManager` | `0x1e66440` | `0x7ff7c7b36440` | Global manager for narrative/stat quests |
| `g_RoleQuestKey` | `0x1e66700` | `0x7ff7c7b36700` | Component registry key for Role Bound quests |
| `g_RoleBoundQuestController` | `0x1e411d8` | `0x7ff7c7b111d8` | Controller handling RoleBound buttons & state |
| `g_RoleBoundRegistry` | `0x1e6c5b8` | `0x7ff7c7b3c5b8` | Registry holding RoleBound configurations |

---

## Function Entries

| Name | RVA | Address | Description |
| ---- | --- | ------- | ----------- |
| `IssueOrderCore` | `0x2bf6c0` | `0x7ff7c5f8f6c0` | Core action handler (move, attack, interact) |
| `WorldToScreen` | `0x12c9c20` | `0x7ff7c6f99c20` | Projects 3D world positions to 2D screen space |
| `GetBoundingRadius` | `0x2a3f20` | `0x7ff7c5f73f20` | Returns physical collision radius of GameObject |
| `GetAttackWindup` | `0x55d3e0` | `0x7ff7c622d3e0` | Calculates current champion auto-attack windup duration |
| `GetAttackDelay` | `0x55d4e0` | `0x7ff7c622d4e0` | Calculates basic attack cooldown based on AS |
| `GetCollisionFlags` | `0x12170b0` | `0x7ff7c6ee70b0` | Retrieves terrain collision byte at coordinates |
| `IsTurret` | `0x32e100` | `0x7ff7c5ffe100` | Returns true if the entity is an active defense tower |
| `IsAlive` | `0x30a040` | `0x7ff7c5fda040` | Returns true if target HP > 0 |
| `IsVisible` | `0x4e1340` | `0x7ff7c61b1340` | Returns true if entity is visible — checks `+0x168/+0x169/+0x16A` |
| `GameObject::IsType` | `0x2bc530` | `0x7ff7c5f8c530` | Helper function to check classification flags (TypeFlags) |
| `SpellBook::GetSpellSlot` | `0x98c480` | `0x7ff7c665c480` | Retrieves `SpellSlot*` from the array at `SpellBook + 0xAE0` |
| `SpellSlot::GetCooldown` | `0x92cc40` | `0x7ff7c65fcc40` | Calculates remaining cooldown time for a spell slot |
| `SpellSlot::Cast` | `0x70ac00` | `0x7ff7c63dac00` | Triggers a spell cast request (`vtable[4]`) |
| `BuffManagerClient::OnBuffAdd` | `0x93fb00` | `0x7ff7c660fb00` | Inserts a buff into client container |
| `BuffManagerClient::OnBuffRemove` | `0x9405c0` | `0x7ff7c66105c0` | Evicts/destroys a buff in client container |
| `RoleBound::Init` | `0x10efa0` | `0x7ff7c5ddefa0` | Registers the custom `RoleBound` system |
| `QuestProgress::Calculate` | `0x520550` | `0x7ff7c61f0550` | Processes a quest entry to compute requirement & tier |
| `QuestProgress::GetQuestValue` | `0x529c70` | `0x7ff7c61f9c70` | Queries quest values dynamically |
| `QuestProgress::LookupMap` | `0x51ad70` | `0x7ff7c61ead70` | Performs map lookup for quest definitions |
| `ComponentRegistry::Lookup` | `0x115d9c0` | `0x7ff7c6e2d9c0` | Generic component registry lookup function |

---

## Structure Offsets (Scripting-Essential)

### 1. GameObject & Character Components
- **`Position`:** `GameObject + 0x25C` (604) [Type: `Vec3` — X=`+0x25C`, Y=`+0x260`, Z=`+0x264`]
- **`TeamID`:** `GameObject + 0x259` (601) [Type: `uint8_t` — 100=Blue, 200=Red]
- **`IsVisible`:** `GameObject + 0x168` (360) [Type: `bool` × 3 — see below]
- **`StatusFlags`:** `GameObject + 0xF8` (248) [Type: `uint32_t*` — lea getter]
- **`TypeFlags` Obfuscated Field:** `GameObject + 0x4C` (76) (XOR-obfuscated classification bitmask)
- **`SpellBook` Component:** `GameObject + 0x3128` (12584)
- **`BuffManager` Wrapper:** `GameObject + 0x2B0` (688) (Calling `vtable[21]` returns the `BuffManagerClient*` pointer)
- **`BuffManagerClient` Direct Pointer:** `AIBaseClient + 0x28F0` (10480) (Direct pointer without wrapper calls)
- **`Quest Component Handle/Cache`:** `GameObject + 0xE0` (224) (Contains generic component pointers array/map)
- **`AIManager` Ptr:** `*(QWORD*)(GameObject + 0x4070)` (16496) — IDA confirmed: `cmp qword ptr [rcx+4070h], 0`
- **`HeroInventoryClient` Wrapper:** `GameObject + 0x4230` (16944) (inventory wrapper — not AIManager)
- **`JungleTypeOffset`:** `GameObject + 0x4484` (17540) (Jungle creep classification type ID)

### Visibility bytes (IsVisible)
- **`+0x168`** — primary visibility flag
- **`+0x169`** — fog-of-war bit (0 = visible)
- **`+0x16A`** — alternate visibility source
- Logic: `(+0x168 || +0x16A) && !+0x169`

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
