# League of Offsets — Comprehensive List

This document contains the primary offsets for the current version of the game.

## Globals

| Name | Offset | Description |
| :--- | :--- | :--- |
| **LocalPlayer** | `0x1EDB378` | Pointer to the local player object |
| **HeroManager** | `0x1E9D0D8` | Manager for all champions in the game |
| **r3dRenderer** | `0x1F7CD08` | Global renderer singleton |
| **ChatClient** | `0x1ED6E88` | Handles chat history and UI |
| **HudInstance** | `0x1E9D148` | Global GUI and user input control |
| **MissileManager** | `0x1E9D048` | Manager for all projectiles |
| **BlueMinionManager** | `0x1EA0240` | Blue team (100) minion list manager |
| **RedMinionManager** | `0x1EA0248` | Red team (200) minion list manager |
| **r3dRenderLayer** | `0x1F7AA08` | Core rendering layer object pointer |
| **SwapChain** | `0x1F7B178` | Direct3D11 swap chain wrapper pointer |

## Combat Stats (Reflection)

These offsets are relative to the **Stats Sub-structure** which is located at `[AIBaseClient + 0x4428]`.

| Property Name | Offset (Hex) | Absolute (Base + Offset) | Description |
| :--- | :--- | :--- | :--- |
| **mLevel** | `0x28` | `0x4450` | Champion Level |
| **mBaseAD** | `0x24` | `0x444C` | Base Attack Damage |
| **mFlatADMod** | `0x1DC` | `0x4604` | Bonus Attack Damage (Flat) |
| **mFlatAPMod** | `0x1C` | `0x4444` | Ability Power (Flat) |
| **mAttackSpeedMod** | `0x1A8` | `0x45D0` | Attack Speed Multiplier |
| **mAttackRange** | `0x5C` | `0x4484` | Basic Attack Range |
| **mCrit** | `0x1C8` | `0x45F0` | Critical Strike Chance |
| **mArmor** | `0x118` | `0x4540` | Total Armor |
| **mBonusArmor** | `0x174` | `0x459C` | Bonus Armor |
| **mSpellBlock** | `0x180` | `0x45A8` | Magic Resist |
| **mBonusSpellBlock** | `0x200` | `0x4628` | Bonus Magic Resist |
| **mMoveSpeed** | `0x24C` | `0x4674` | Movement Speed |
| **mCombatType** | `0x204` | `0x462C` | Ranged (2) / Melee (1) |
| **oBuffManager** | `0x28F0` | `0x6D18` | Active Buff list pointer |
| **oFacing** | `0x1C0` | `0x45E8` | Look / facing direction vector |

## Primary Functions

| Name | RVA | Description |
| :--- | :--- | :--- |
| **CanCast** | `0x2C50A0` | Checks if a spell slot can be cast |
| **GetObjectByID** | `0x54EF70` | Retrieves object from ObjectManager by ID/Index |
| **NavMesh::CreatePath** | `0x2309B0` | Computes movement path on the NavGrid |
| **OnNewPath** | `0x2E5960` | Triggered when a new path is created |

## Missile Struct (MissileClient)

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **CasterNetID** | `0x30` | `DWORD` | Network ID of the unit that fired the missile |
| **TargetNetID** | `0x34` | `DWORD` | Network ID of the target unit |
| **StartPos** | `0x24` | `Vector3` | Starting position |
| **EndPos** | `0x30` | `Vector3` | Destination position |
| **Speed** | `0x410` | `float` | Travel speed |

## Network & Identity

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **NetworkID** | `0xBC` | `DWORD` | Unique global ID |
| **nIndex** | `0x8` | `WORD` | Index in the EntityList |
| **nTeamID** | `0x259` | `byte` | Team ID (100 Blue, 200 Red) |
| **oPosition** | `0x25C` | `Vector3` | World position |
| **oPlayerStatsComponent** | `0x2A8` | `pointer` | Component containing player stats (summoner name) |
| **oCharacterDataStack** | `0x1288` | `pointer` | Character data stack component (champion name) |

## Camera (HudInstance + 0x18)

| Name | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **Position** | `0x25C` | `Vector3` | Camera World Position |
| **Rotation** | `0x18` | `Vector3` | Camera Rotation (Yaw, Pitch, Roll) |
| **fieldOfView** | `0x749A00` | `float` | Camera Field of View in degrees |
| **nearClip** | `0x44` | `float` | Near clipping plane |
| **farClip** | `0x4C` | `float` | Far clipping plane |

