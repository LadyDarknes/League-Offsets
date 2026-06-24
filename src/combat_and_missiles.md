# League of Offsets — Combat Stats (Reflection)

These offsets are relative to the **Stats Sub-structure** which is located at `[GameObject + 0x4428]`

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
| **mSpellBlock** | `0x180` | `0x45A8` | Magic Resist (ai generated)|
| **mBonusSpellBlock** | `0x200` | `0x4628` | Bonus Magic Resist |
| **mMoveSpeed** | `0x24C` | `0x4674` | Movement Speed |
| **mCombatType** | `0x204` | `0x462C` | Ranged (2) / Melee (1) |

---

# Missile Struct Fields (MissileClient)

These are used for tracking skillshots and projectiles.

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **CasterNetID** | `0x30` | `DWORD` | Network ID of the unit that fired the missile |
| **TargetNetID** | `0x34` | `DWORD` | Network ID of the target unit (if targeted) |
| **StartPos** | `0x24` | `Vector3` | Starting position of the missile |
| **EndPos** | `0x30` | `Vector3` | Destination position |
| **CurrentPos** | `0x25C` | `Vector3` | Inherited from GameObject |
| **Speed** | `0x410` | `float` | Travel speed (ai generated) |

---

# Network Identity (GameObject)

| Field | Offset | Type | Description |
| :--- | :--- | :--- | :--- |
| **NetworkID** | `0xBC` | `DWORD` | Unique global ID for the object |
| **nIndex** | `0x8` | `WORD` | Index in the EntityList / ObjectManager |
| **nTeamID** | `0x259` | `byte` | Team ID (100 Blue, 200 Red, 300 Neutral) |
