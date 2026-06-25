if somebody need another pattern/offsets that I never write down, please contact me from Discord: swansizz, or create an issue!


| Name                    | AOB Pattern                                                           |
| ----------------------- | --------------------------------------------------------------------- |
| **LocalPlayer**         | `48 8B 0D ? ? ? ? 4C ? ? 74 ? 49`                                     |
| **HeroManager**         | `48 8B 0D ? ? ? ? 0F 85 ? ? ? ? 83`                                   |
| **ViewPort**            | `48 8B 3D ? ? ? ? 80 78 22 00 74`                                     |
| **GameTime**            | `F3 0F 5C 35 ? ? ? ? 0F 28 F8`                                        |
| **EntityList**          | `0F B6 4C 24 ? 48 8B 05 ? ? ? ? 48 69 D1 D8 01 00 00`                 |
| **ObjectManager**       | `48 8B 0D ? ? ? ? 8B 10 E8`                                           |
| **MissileManager**      | `48 8B 0D ? ? ? ? 48 8D 55 ? E8`                                      |
| **BlueMinionManager**   | `8B 40 08 39 03 75 0E 48 8B 0D ? ? ? ?`                               |
| **RedMinionManager**    | `EB 22 E8 ? ? ? ? 8B 40 08 39 03 75 0E 48 8B 0D ? ? ? ?`              |
| **NavGrid**             | `48 8B 05 ? ? ? ? 0F 28 DA`                                           |
| **HudInstance**         | `48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 49 ? 48 8D`                     |
| **r3dRenderer**         | `4C 8B 3D ? ? ? ? 48 03 ? 49`                                         |
| **NetInstance**         | `48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 C0 74 ? 80 78`                     |
| **NetClient** (GetPing) | `48 8B 05 ? ? ? ? 0F B6 15 ? ? ? ? 48 85 C0 41 0F 95 C1`              |
| **ConnSlotSentinel**    | `0F B6 15 ? ? ? ? 48 85 C0 41 0F 95 C1`                               |
| **TimingTable**         | `48 8D 05 ? ? ? ? 48 69 D1`                                           |
| **SpellCastMap**        | `48 8B 05 ?? ?? ?? ?? 48 8B 88 ?? ?? ?? ?? 48 85 C9 74`               |
| **UnderMouseObj**       | `48 89 0D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 01 33 D2`                    |
| **MouseScreenVec2**     | `48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B 01`               |
| **CastSpellFlag**       | `C6 05 ? ? ? ? ? E8 ? ? ? ? 8B 50 ?`                                  |
| **IssueOrderFlag**      | `C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 48 8B 84 24`  |
| **GameClient**          | `48 8B 05 ? ? ? ? 48 8B F2 83 78 10 02`                               |
| **ChatClient**          | `48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 1D ? ? ? ? EB ? 48 8B 0D` |
| **r3dRenderLayer**      | `48 8B 1D ? ? ? ? 80 BB 84 00 00 00 00`                               |
| **SwapChain**           | `48 8B 05 ? ? ? ? 48 85 C0 75 0E 48 8B 0D ? ? ? ? 48 8B 01 48 FF 60 28 C3` |
| **QuestProgressFn**     | `48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 1D ? ? ? ? 4C 8B F2` |
| **QuestValueFn**        | `48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 8B 41 ? 0F B6 DA`          |
| **ComponentLookupFn**   | `48 89 6C 24 ? 56 41 54 41 57 48 83 EC ? 48 8B 2D`                    |
| **RoleBoundInit**       | `48 83 EC ? 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? 48 83 C4 ? E9 ? ? ? ?` |

---

## Functions — AOB Patterns

| Name                                  | AOB Pattern                                                                              | Notes                                           |
| ------------------------------------- | ---------------------------------------------------------------------------------------- | ----------------------------------------------- |
| **IssueOrderCore**                    | `4C 89 4C 24 ? 4C 89 44 24 ? 88 54 24 ? 55`                                              | Function entry                                  |
| **IssueOrderCore** (caller ctx)       | `89 05 ? ? ? ? E8 ? ? ? ? 8D 43`                                                         | Resolve E8 to get fn addr                       |
| **IssueOrderPacketWrapper**           | `E8 ? ? ? ? 80 BD ? ? ? ? ? 74 ? 4C 8B 8D ? ? ? ? 4C 8B C7`                              | Final packet-wrapper call inside IssueOrderCore |
| **WorldToScreen** (fn entry)          | `48 83 EC ? F3 0F 10 02 48 8D 41 ? F3 0F 10 4A`                                          | Function body                                   |
| **WorldToScreen** (caller ctx)        | `E8 ? ? ? ? F3 0F 10 44 24 ? F3 41 0F 11 06`                                             | Resolve E8                                      |
| **WorldToScreen** (caller ctx 2)      | `E8 ? ? ? ? 48 8B 5C 24 ? 44 0F 28 44 24`                                                | Resolve E8                                      |
| **ProjectAndClip**                    | `48 89 5C 24 ? 57 48 83 EC ? 48 8B BC 24 ? ? ? ? 48 8D 05`                               | Sub of WorldToScreen                            |
| **TransformVec3**                     | `48 83 EC ? 48 8B 44 24 ? 4C 8B D1`                                                      | Innermost math sub                              |
| **GetBoundingRadius**                 | `40 53 48 83 EC ? 48 83 B9 ? ? ? ? 00 48 8B D9 0F 29 74 24 20`                           | Function entry                                  |
| **GetBoundingRadius** (caller)        | `E8 ?? ?? ?? ?? 0F 28 F0 48 8B 07`                                                       | Resolve E8                                      |
| **GetAttackWindup**                   | `48 89 5C 24 ?? 48 89 74 24 ?? 57 48 83 EC 60 48 8B 01 8B DA 0F 29 74 24 ??`             | Function entry                                  |
| **GetAttackDelay** (caller ctx)       | `E8 ? ? ? ? 33 C0 F3 0F 11 83 ? ? ? ?`                                                   | Resolve E8                                      |
| **GetAttackDelay** (outer)            | `F3 0F 10 89 ? ? ? ? E9`                                                                 | Find wrapper                                    |
| **GetAttackDelay** (inner decryption) | `48 8B C4 48 81 EC ? ? ? ? 44 0F 29 40 ? 44 0F 29 60`                                    | XMM decryption loop                             |
| **GetCollisionFlags**                 | `48 83 EC 28 48 8B D1 48 8B 0D ? ? ? ? 48 8B 49 08`                                      | Function entry                                  |
| **GetSubObjAiMgr**                    | `E8 ? ? ? ? 48 85 C0 74 ? F3 0F 10 70`                                                   | Caller ctx                                      |
| **GetSpellCastInfo** (caller ctx)     | `E8 ?? ?? ?? ?? 48 85 C0 74 ?? 0F B6 40 ?? 84 C0`                                        | Resolve E8                                      |
| **GetSpellSlot** (body)               | `48 63 C2 48 8B 84 C1 ?? ?? ?? ?? C3`                                                    | Unique body                                     |
| **GetSpellSlot** (entry check)        | `83 FA ? 77 ? 48 63 C2 48 8B 84 C1`                                                      | Function start                                  |
| **SpellSlot::GetLevel**               | `CC CC CC CC CC 8B 41 28 C3`                                                             | Prefix: CC CC CC CC CC, Offset: +5              |
| **SpellSlot::GetCooldown**            | `40 53 48 83 EC 40 48 8B D9 0F 29 74 24 30 48 8B 0D ? ? ? ? 0F 29`                       | Function entry                                  |
| **SpellSlot::Cast**                    | `48 89 5C 24 08 57 48 83 EC 20 48 8B 01 0F B6 DA FF 90 98 00 00 00`                      | Virtual function table [4]                      |
| **BuffManagerClient::OnBuffAdd**       | `40 55 53 56 48 8D 6C 24 B9 48 81 EC E0 00 00 00 48 8B 01 48 8B F2`                      | Core buff add function                          |
| **BuffManagerClient::OnBuffRemove**    | `40 53 57 41 57 48 83 EC 40 48 8B 41 20 41 8B D9 4C 8B 49 18 49 2B C1`                   | Core buff remove function                       |
| **QuestProgress::Calculate**           | `48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 1D ? ? ? ? 4C 8B F2` | Calculates quest tier, target, and progress     |
| **QuestProgress::GetQuestValue**       | `48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 8B 41 ? 0F B6 DA`                             | Retrieves quest progress value                  |
| **ComponentRegistry::Lookup**          | `48 89 6C 24 ? 56 41 54 41 57 48 83 EC ? 48 8B 2D`                                       | Generic component lookup by key                 |
| **RoleBound::Init**                    | `48 83 EC ? 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? 48 83 C4 ? E9 ? ? ? ?` | RoleBound type registration initialization      |
| **GetMapID**                          | `E8 ? ? ? ? 4C 89 7C 24 40 48 8D 4C 24 70`                                               | Caller ctx                                      |
| **GetFirstObject**                    | `48 83 EC ? 48 8B 51 ? 8B 41 ? 48 8D 0C C2`                                              | Function entry                                  |
| **GetNextObject**                     | `0F B7 42 ? 44 8B 41`                                                                    | Function entry                                  |
| **GetPing** (fn entry)                | `48 83 EC ? 0F B6 81 ? ? ? ? 3A 05`                                                      | Function start                                  |
| **GetPing** (caller ctx — unique)     | `E8 ?? ?? ?? ?? 8B F8 39 03`                                                             | Best unique caller                              |
| **GetPing** (caller ctx 2)            | `E8 ? ? ? ? 8B F0 39 43`                                                                 | —                                               |
| **GetPing** (caller ctx 3)            | `E8 ? ? ? ? 8B C0 4C 8D 15`                                                              | —                                               |
| **GetPing** (caller ctx 4)            | `E8 ? ? ? ? 8B C0 0F 57 C9`                                                              | —                                               |
| **GetPing** (caller ctx 5)            | `E8 ? ? ? ? 8B F8 EB ? 33 FF 48 8D 15`                                                   | —                                               |
| **GetPing** (caller ctx 6)            | `E8 ? ? ? ? 66 89 44 24 ? 48 8D 54 24`                                                   | —                                               |
| **GetPing inner thunk**               | `48 8B 09 48 8B 09 E9 ? ? ? ? CC CC CC CC CC 48 89 5C 24`                                | Double-deref thunk                              |
| **GetPing skip-list fn**              | `48 89 6C 24 ? 48 89 74 24 ? 41 56 48 83 EC ? 48 8B 69 ? 4C 8D 71`                       | Sorted list lookup                              |
| **SpellCastMap hash fn**              | `48 83 EC ? 4C 8B D2 4C 8B D9`                                                           | Bucket index fn                                 |
| **SpellCastMap key cmp**              | `8B 41 ? 39 42 ? 75 ? 48 8B 01`                                                          | strcmp + hash check                             |
| **CastSpellWrapper**                  | `48 89 48 ? 55 56 57 41 54 41 55`                                                        | Internal-call fn                                |
| **CastSpellTarget**                   | `48 8B C4 48 89 50 ? 48 89 48 ? 55 56 41 54 41 55 41 56 48 8D A8 ? ? ? ? 48 81 EC A0 01 00 00` | Target-based cast fn                             |
| **CastSpellPosition**                 | `48 8B C4 4C 89 48 ? 48 89 48 ? 55 53`                                                   | Position-based cast fn                           |
| **PrintChat**                         | `40 53 55 56 57 41 54 41 55 41 56 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 60 4C 8B E1 0F 57 C0 33 FF` | Function entry |
| **IsHero**                            | `E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 48 8B CB E8 ? ? ? ? 84 C0 74 ? 48 8B`                    | Caller ctx                                      |
| **IsTurret** (fn entry)               | `40 53 48 83 EC 20 48 8B D9 48 85 C9 74 27`                                              | Function entry                                  |
| **IsTurret** (caller ctx)             | `E8 ?? ?? ?? ?? 84 C0 74 ?? 48 8B 83 ?? ?? ?? ?? 48 8D 8B`                               | Resolve E8                                      |
| **IsBuilding** (caller ctx)           | `E8 ?? ?? ?? ?? 84 C0 0F 85 ?? ?? ?? ?? 48 8B CB E8 ?? ?? ?? ?? 84 C0 0F 84 ?? ?? ?? ??` | Resolve E8                                      |
| **IsAlive** (fn entry)              | `40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 38 01 00 00 84 C0 74 ? 48 8D 8B A8 02 00 00 48 8B 01 FF 50 10 84 C0 75` | Function entry |
| **IsAlive** (caller ctx)            | `E8 ? ? ? ? 84 C0 74 ? 48 8B 83 ? ? ? ? 48 8D 8B`                        | Caller ctx |
| **IsVisible** (fn entry)            | `48 83 EC 38 80 B9 6C 01 00 00 00 0F 29 74 24 ? 0F 28 ? 7F ? 80 B9 ? ? 00 00 00`          | Checks primary visibility byte at +0x16C |
| **IsVisible** (disasm confirmed)    | `80 B9 6C 01 00 00 00`                                                   | `cmp byte ptr [rcx+16Ch], 0` — first byte of fn |
| **GameObject::IsType**              | `40 56 48 83 EC 10 0F B6 41 ? 4C 8D 41 4C`                               | Helper function to check classification flags   |
| **GetAIManager** (fn entry)         | `48 8B 89 70 40 00 00 48 85 C9 74`                                       | Reads `[rcx+4070h]` and checks null |
| **NavPath waypoints** (read ctx)    | `48 8B 40 28 48 8D 04 C0`                                                | WaypointArray read from NavPath+0x28 |
| **ClientMainLoop**                    | `48 83 EC 48 80 3D ? ? ? ? 00 48 89 5C 24 50`                                            | Frame update main loop                          |
| **OnWndProc**                         | `48 89 5C 24 18 55 56 57 48 8D 6C 24 B9 48 81 EC C0 00 00 00 48 8B 05 ? ? ? ?`           | Windows message procedure                       |
| **OnProcessSpell**                    | `40 55 56 48 81 EC 88 00 00 00 48 83 79 28 00`                                           | Triggered on spell cast request                 |
| **OnSpellImpact**                     | `48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 30 49 8B 01`                                  | Triggered when spell hits/impacts               |
| **OnDoCast**                          | `40 56 57 48 83 EC 28 48 8B F2 48 8B F9 8B 51 08 48 3B D6 0F 84 ? ? ? ? 48 89 5C 24 40 48 89 6C 24 48 76 45 48 69 EA B0 00 00 00` | Triggered when spell is executed/sent |
| **OnStopCast**                        | `40 53 56 57 48 83 EC 40 F3 0F 10 81 E4 00 00 00`                                        | Triggered when spell cast is cancelled          |
| **OnCreateObject**                    | `48 89 5C 24 18 56 48 83 EC 30 80 B9 EC 01 00 00 00`                                     | Triggered when new GameObject is created        |
| **OnDeleteObject**                    | `40 53 48 83 EC 20 33 D2 48 8B D9 E8 ? ? ? ? 48 8B 0D`                                  | `AIHeroClient::OnDestroyUnit` — PKT_S2C handler |
| **OnPlayAnimation**                   | `48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 8B 52 20 48 8B 4B 18`                    | `AIBaseClient::OnPlayAnimation` — PKT_S2C handler |
| **GetModelInstance**                  | `48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 8B 52 ? 48 8B 4B`                        | Alias of OnPlayAnimation                        |
| **RemapBoneIndex**                    | `48 89 5C 24 ? 55 56 57 41 54 41 57 48 8D AC 24 ? ? ? ? B8 60 25 00 00`                  | Map bone name hash to bone index                |
| **MinimapMoveSelf**                   | `83 FA 01 0F 85 ? ? ? ? 4C 8B DC`                                                       | `evtPlayerMoveMinimap` handler                  |
| **MinimapHudInit**                    | `48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC 00 02 00 00` | `TacticalMap` (Minimap HUD) constructor        |
| **UpdateCamera**                      | `48 89 5C 24 18 55 56 57 48 8D 6C 24 ? 48 81 EC`                                         | Synchronizes settings with camera               |
| **fieldOfView (settings)**            | `48 8D 15 ? ? ? ? 48 89 4C 24 ? 41 B9 3C 00 00 00`                                       | Setting registration for camera FOV             |
| **CanCast**                           | `40 53 48 83 EC ? 48 8B D9 48 85 C9 74 ? 48 8B`                                          | Checks if spell slot can be cast                |
| **GetObjectByID**                     | `48 85 D2 74 ? 48 8B 41 20 48 8D`                                                        | Resolves Object by NetID / Index                |
| **NavMesh::CreatePath**               | `48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC`                                | Pathfinding and path generation                 |
| **OnNewPath**                         | `48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 54`                       | Triggered on new movement path                  |
| **CharacterDataStack::Push**          | `48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 50 48 8B F2 48 8B F9 49 8B D0`                 | Push character data (change model/skin)         |
| **CharacterDataStack::Update**        | `4C 8B DC 55 57 48 8B EC 48 83 EC 78 48 8B 41 40 48 8B F9 48 85 C0`                       | Update character model/skin                     |

---

## GameObject Struct Offsets

| Name                | Offset   | Type           | Description                 |
| ------------------- | -------- | -------------- | --------------------------- |
| OFF_POS             | `0x25C`  | Vec3 (float×3) | **Position.X** — IDA confirmed via distance fn |
| OFF_POS_Y           | `0x260`  | float          | Position.Y |
| OFF_POS_Z           | `0x264`  | float          | Position.Z |
| OFF_TEAM            | `0x259`  | uint8          | 100=Blue, 200=Red — `movzx [r15+259h]` |
| OFF_VISIBLE_0       | `0x168`  | bool           | Primary visibility — `cmp [rcx+168h],0` |
| OFF_VISIBLE_FOG     | `0x169`  | bool           | Fog-of-war bit (0 = visible) |
| OFF_VISIBLE_ALT     | `0x16A`  | bool           | Alternate visibility source |
| OFF_HP              | `0x1080` | float          | Current health              |
| OFF_HP_MAX          | `0x10A8` | float          | Max health                  |
| OFF_MANA            | `0x360`  | float          | Current mana/resource       |
| OFF_MANA_MAX        | `0x388`  | float          | Max mana/resource           |
| OFF_MANA_ENABLED    | `0x3B0`  | bool           | Primary resource enabled    |
| OFF_LEVEL           | `0x4D58` | int            | Champion level (mLevelRef)  |
| OFF_NAME            | `0x68`   | std::string    | Character name string       |
| OFF_MOVE_SPEED      | `0x5000` | float          | Movement speed              |
| OFF_ARMOR           | `0x4F38` | float          | Physical defense (armor)    |
| OFF_MAGIC_RES       | `0x4CB8` | float          | Magic resistance            |
| OFF_ALL_SHIELD      | `0x1120` | float          | Total shield                |
| OFF_PHYS_SHIELD     | `0x1148` | float          | Physical damage shield      |
| OFF_MAG_SHIELD      | `0x1170` | float          | Magical damage shield       |
| OFF_AS_MULTIPLIER   | `0x17B0` | float          | Attack speed multiplier     |
| OFF_ATK_RANGE       | `0x17FC` | float          | Attack range                |
| OFF_BOUNDING_RADIUS | `0x6F8`  | float          | Bounding / collision radius |
| OFF_SPELLBOOK       | `0x3128` | QWORD*         | SpellBook pointer           |
| OFF_AIMANAGER_PTR   | `0x4070` | QWORD*         | AIManager ptr — `cmp qword ptr [rcx+4070h],0` |
| OFF_HEROCLIENT_PTR  | `0x4230` | QWORD*         | HeroInventoryClient wrapper (NOT AIManager) |

## HeroManager Struct Offsets

| Name              | Offset | Type   | Description                       |
| ----------------- | ------ | ------ | --------------------------------- |
| OFF_HEROMGR_LIST  | `0x8`  | QWORD* | Pointer to champion pointer array |
| OFF_HEROMGR_COUNT | `0x10` | uint32 | Number of champions               |

## Camera / Viewport Offsets (camEnt and camMgr)

| Name              | Offset        | On     | Type      | Description            |
| ----------------- | ------------- | ------ | --------- | ---------------------- |
| OFF_VIEW_MTX      | `0x1E4` (484) | camEnt | float[16] | View / rotation matrix |
| OFF_PROJ_MTX      | `0x224` (548) | camEnt | float[16] | Projection matrix      |
| camMgr → camEnt   | `0x2F8`       | camMgr | QWORD*    | Camera entity pointer  |
| camMgr → viewport | `0x300`       | camMgr | int[4]    | Left/Top/Right/Bottom  |
| OFF_CAM_POS       | `0x10`        | cam    | Vector3   | Camera position        |
| OFF_CAM_ROT       | `0x40`        | cam    | Vector3   | Camera rotation        |
| OFF_CAM_FOV       | `0x1DC`       | cam    | float     | Field of View          |
| OFF_CAM_NEAR_CLIP | `0x1F4`       | cam    | float     | Near Camera Clip       |
| OFF_CAM_FAR_CLIP  | `0x1F8`       | cam    | float     | Far Camera Clip        |

## SpellBook / SpellSlot Offsets

|Name|Offset|Type|Description|
|---|---|---|---|
|OFF_SB_SLOT_ARR|`0xAE0`|QWORD*[64]|Spell slot pointer array|
|OFF_SB_DELAY_PCT|`0x308`|float|Delay percent in SpellSlot|
|SPELLSLOT_MAX_IDX|`0x3F` (63)|—|Max valid slot index|

## CharacterData Offsets

|Name|Offset|Type|Description|
|---|---|---|---|
|OFF_CHARDATA_CAST_TIME|`0x9C4`|float|Base cast time|
|OFF_CHARDATA_DELAY_SCALE|`0x9C8`|float|Delay scale factor|

## GetPing Struct Offsets

|Name|Offset|Type|Description|
|---|---|---|---|
|OFF_A1_CONN_SLOT|`0x423`|uint8|NetClient connection slot index|
|OFF_A1_TREE_LINK|`0x0C8`|QWORD*|Timing tree root pointer|
|OFF_NODE_NEXT_LEFT|`0x000`|QWORD*|Skip-list: follow when key ≥ target|
|OFF_NODE_NEXT_RIGHT|`0x010`|QWORD*|Skip-list: follow when key < target|
|OFF_NODE_END_FLAG|`0x019`|uint8|Non-zero = sentinel/end|
|OFF_NODE_KEY|`0x020`|QWORD|Send-timestamp key|
|OFF_NODE_DATA|`0x028`|—|Data region base (node+40)|
|OFF_DATA_RTT_A|`328`|double|Recv-side RTT component|
|OFF_DATA_RTT_B|`344`|double|Send-side RTT component|
|TIMING_STRIDE_QWORDS|`33`|—|QWORDs per timing-table slot|

## SpellCastInfo HashMap Offsets

|Name|Offset|Type|Description|
|---|---|---|---|
|HASHMAP_OFF_SENTINEL|`0x70` (14×8)|QWORD*|End-of-list sentinel node ptr|
|HASHMAP_OFF_BUCKETS|`0x80` (16×8)|QWORD*|Bucket array pointer|
|HASHMAP_OFF_MASK|`0x98` (19×8)|QWORD|Bucket count mask (count−1)|
|NODE_OFF_NEXT|`0x8`|QWORD*|Next node in bucket chain|
|NODE_OFF_KEY_STR|`0x10`|QWORD*|Pointer to key string|
|NODE_OFF_KEY_HASH|`0x18`|DWORD|Hash seed|
|NODE_OFF_VALUE|`0x20`|QWORD*|SpellCastInfo object pointer|

## NavGrid Offsets

|Name|Offset|Type|Description|
|---|---|---|---|
|OFF_NAV_WIDTH|`0x710`|int|Map width in cells|
|OFF_NAV_HEIGHT|`0x714`|int|Map height in cells|
|OFF_NAV_ORIGIN|`0xF4`|Vec3|Grid origin world position|
|OFF_NAV_CELLSIZE|`0x71C`|float|Cell size (inverse)|
|OFF_NAV_DATA|`0x118`|QWORD*|Cell data array (stride 0x10)|

## TFT-Specific Offsets

Actualy I am not sure about them because, I didnt look those since 3 month or sth!

| Name                | Offset        | Type  | Description                          |
| ------------------- | ------------- | ----- | ------------------------------------ |
| OFF_TFT_ENTITY_SIZE | `0x1D8` (472) | —     | Bytes per player entry in EntityList |
| OFF_TFT_GOLD        | `0x2830`      | float | Player gold                          |
| OFF_TFT_EXP         | `0x4CE8`      | float | Player XP                            |
| OFF_TFT_LEVEL       | `0x4D10`      | int   | Player level                         |
|                     |               |       |                                      |

## Prediction — NavPath Struct AOB Patterns
| Name | AOB Pattern | Notes |
| ---- | ----------- | ----- |
| **GetAIManager ptr** | `48 8B 89 70 40 00 00 48 85 C9 74` | `mov rcx,[rcx+4070h]` + null check |
| **NavAgent deref** | `48 8B 40 28 48 85 C0` | `mov rax,[rax+28h]` from AIManager |
| **NavPath base** | `48 8D B0 5C 04 00 00` | `lea rsi,[rax+45Ch]` — path struct offset |
| **WaypointArray** | `48 8B 40 28 48 8D 04 C0` | `[navPath+0x28]` = float* array |
| **WaypointCount** | `8B 40 30` | `mov eax,[rax+30h]` from NavPath |
| **CurrentNodeIdx** | `8B 08` | `mov ecx,[rax]` from NavPath base |
| **DistanceSq fn** | `F3 0F 10 81 5C 02 00 00` | Reads Position.X at +0x25C — unique |
| **IsVisible fn** | `48 83 EC 38 80 B9 6C 01 00 00 00 0F 29 74 24 ? 0F 28 ? 7F ? 80 B9 ? ? 00 00 00` | Checks primary visibility byte at +0x16C |
| **EntityList stride** | `48 69 ?? D8 01 00 00` | `imul reg, 472` — entity slot multiply |

---

> Please note that while AI was used to structure and name the table, the reversing process and data verification are entirely my own work!
