# League of Offsets — Comprehensive List

This document contains the primary offsets for the current version of the game.

## Globals

| Name | Offset | Description |
| :--- | :--- | :--- |
| **LocalPlayer** | `0x1EB2020` | Pointer to the local player object |
| **HeroManager** | `0x1E76DA0` | Manager for all champions in the game |
| **r3dRenderer** | `0x1F4C598` | Global renderer singleton |
| **ChatClient** | `0x1EAE6A0` | Handles chat history and UI |
| **HudInstance** | `0x1E76E08` | Global GUI and user input control |
| **MissileManager** | `0x1E76D10` | Manager for all projectiles |
| **BlueMinionManager** | `0x1E29D68` | Blue team (100) minion list manager |
| **RedMinionManager** | `0x1E29D70` | Red team (200) minion list manager |

## Combat Stats (Reflection)

These offsets are relative to the **Stats Sub-structure** which is located at `[AIBaseClient + 0x49E8]`.

| Property Name | Offset (Hex) | Absolute (Base + Offset) | Description |
| :--- | :--- | :--- | :--- |
| **mLevel** | `0x28` | `0x4A10` | Champion Level |
| **mBaseAD** | `0x24` | `0x4A0C` | Base Attack Damage |
| **mFlatADMod** | `0x1DC` | `0x4BC4` | Bonus Attack Damage (Flat) |
| **mFlatAPMod** | `0x1C` | `0x4A04` | Ability Power (Flat) |
| **mAttackSpeedMod** | `0x1A8` | `0x4B90` | Attack Speed Multiplier |
| **mAttackRange** | `0x5C` | `0x4A44` | Basic Attack Range |
| **mCrit** | `0x1C8` | `0x4BB0` | Critical Strike Chance |
| **mArmor** | `0x118` | `0x4B00` | Total Armor |
| **mBonusArmor** | `0x174` | `0x4B5C` | Bonus Armor |
| **mSpellBlock** | `0x180` | `0x4B68` | Magic Resist |
| **mBonusSpellBlock** | `0x200` | `0x4BE8` | Bonus Magic Resist |
| **mMoveSpeed** | `0x24C` | `0x4C34` | Movement Speed |
| **mCombatType** | `0x204` | `0x4BEC` | Ranged (2) / Melee (1) |

## Missile Struct (MissileClient)

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **CasterNetID** | `0x48` | `DWORD` | Network ID of the unit that fired the missile |
| **TargetNetID** | `0x4C` | `DWORD` | Network ID of the target unit |
| **StartPos** | `0x24` | `Vector3` | Starting position |
| **EndPos** | `0x30` | `Vector3` | Destination position |
| **Speed** | `0x410` | `float` | Travel speed |

## Network & Identity

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **NetworkID** | `0x10` | `DWORD` | Unique global ID |
| **nIndex** | `0x8` | `WORD` | Index in the EntityList |
| **nTeamID** | `0x259` | `byte` | Team ID (100 Blue, 200 Red) |
| **oPosition** | `0x25C` | `Vector3` | World position |

## Camera (HudInstance + 0x18)

| Name | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **Position** | `0x10` | `Vector3` | Camera World Position |
| **Rotation** | `0x40` | `Vector3` | Camera Rotation (Yaw, Pitch, Roll) |
| **fieldOfView** | `0x1DC` | `float` | Camera Field of View in degrees |
| **nearClip** | `0x1F4` | `float` | Near clipping plane |
| **farClip** | `0x1F8` | `float` | Far clipping plane |

