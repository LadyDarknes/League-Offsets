# League of (removed) — Dynamic Reflection Offsets

leverage it to dynamically extract member variable offsets for core classes like AIHero, AIMinionCommon, AITurretCommon, etc.

## How Offsets are Resolved

Each getter function is extremely simple and returns the address of the member variable relative to the class instance pointer (rcx)

getters compile down to a single instruction adjusting rcx by the offset:
```assembly
lea rax, [rcx + offset]
retn
```
For example, decompiling the getter for mGold:
```c
__int64 __fastcall sub_7FF7C5EE6240(__int64 a1)
{
  return a1 + 96; // 96 = 0x60
}
```
 the member offset of mGold is 0x60 (96)

## Class Instance Adjustment Offset
```assembly
mov     rax, [rcx+10h]    ; Load getter function
lea     rcx, [rdx+49E8h]  ; Adjust class pointer (base game object -> stats sub-structure)
jmp     rax               ; Jump to getter
```
$$\text{Absolute Offset} = \text{Adjustment Offset} + \text{Field Offset}$$

(the base game object pointer)

## AIGenericCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `0x20` | `32` | `sub_7FF7E6E99CD0` |
| `StatusFlags` | `0x5C` | `92` | `sub_7FF7E6E99CF0` |
| `mIsTargetable` | `0x64` | `100` | `sub_7FF7E6E9C0D0` |
| `mIsTargetableToTeamFlags` | `0x3C` | `60` | `sub_7FF7E6E9BED0` |
| `BerserkInstigator` | `0x44` | `68` | `sub_7FF7E6E99FE0` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## AIHero

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `0xEC` | `236` | `sub_7FF7E6E99D20` |
| `ActionState2` | `0x164` | `356` | `sub_7FF7E6E99CE0` |
| `ManaCost_Ex6` | `0x1B4` | `436` | `sub_7FF7E6E9D8F0` |
| `mLevelRef` | `0x28` | `40` | `sub_7FF7E6E9B670` |
| `mPARState` | `0x214` | `532` | `sub_7FF7E6E9E960` |
| `mFlatPhysicalDamageMod` | `0x1DC` | `476` | `sub_7FF7E6E9C190` |
| `mFlatBaseSpellBlockMod` | `0x180` | `384` | `sub_7FF7E6E9C0F0` |
| `mIsTargetableToTeamFlags` | `0x130` | `304` | `sub_7FF7E6E9CC30` |
| `ManaCost_Ex4` | `0x184` | `388` | `sub_7FF7E6E9D8D0` |
| `mAbilityHasteMod` | `0x224` | `548` | `sub_7FF7E6E99BD0` |
| `mFlatMagicDamageMod` | `0x1C` | `28` | `sub_7FF7E6E9C110` |
| `mIncomingHealingAllied` | `0x38` | `56` | `sub_7FF7E6E9B620` |
| `mFlatArmorPenetration` | `0x148` | `328` | `sub_7FF7E6E9C0C0` |
| `ManaCost_Ex5` | `0x124` | `292` | `sub_7FF7E6E9D8E0` |
| `mGold` | `0x16C` | `364` | `sub_7FF7E6E9C400` |
| `mMediumPipBitField` | `0x84` | `132` | `sub_7FF7E6E9A320` |
| `mHPMaxPenalty` | `0xD4` | `212` | `sub_7FF7E6E9C5E0` |
| `mFlatBubbleRadiusMod` | `0xF0` | `240` | `sub_7FF7E6E9C120` |
| `mFlatMagicPenetration` | `0x17C` | `380` | `sub_7FF7E6E9C160` |
| `ManaCost_Ex8` | `0x23C` | `572` | `sub_7FF7E6E9D910` |
| `mAttackRange` | `0x5C` | `92` | `sub_7FF7E6E99CF0` |
| `mExp` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mIncomingDamage` | `0x1AC` | `428` | `sub_7FF7E6E9C8E0` |
| `mHP` | `0x90` | `144` | `sub_7FF7F90D9080` |
| `mFlatBaseArmorMod` | `0x9C` | `156` | `sub_7FF7E6E15560` |
| `mFlatBaseHPPoolMod` | `0x154` | `340` | `sub_7FF7E6E9C0E0` |
| `mChampSpecificHealth` | `0x1B0` | `432` | `sub_7FF7E6E9B630` |
| `mPAREnabled` | `0x15C` | `348` | `sub_7FF7E6E9E950` |
| `SlotEvolveAvailability0` | `0x210` | `528` | `sub_7FF7E6E9EF40` |
| `ManaCost_Ex13` | `0x190` | `400` | `sub_7FF7E6E9D890` |
| `mCrit` | `0x1C8` | `456` | `sub_7FF7E6E9B980` |
| `mBaseGoldGivenOnDeath` | `0x228` | `552` | `sub_7FF7E6E9A7E0` |
| `mBaseAttackDamageSansPercentScale` | `0x114` | `276` | `sub_7FF7E6E9A7D0` |
| `mBonusSpellBlock` | `0x200` | `512` | `sub_7FF7E6E9B130` |
| `mGoldTotal` | `0xA0` | `160` | `sub_7FF7E6E9C5C0` |
| `mIsTargetable` | `0x248` | `584` | `sub_7FF7E6E9CC10` |
| `StatusFlags` | `0x150` | `336` | `sub_7FF7E6E9F140` |
| `SlotEvolveAvailability1` | `0x14C` | `332` | `sub_7FF7E6E9EF50` |
| `ManaCost_Ex3` | `0x88` | `136` | `sub_7FF7E6E99D00` |
| `mArmor` | `0x118` | `280` | `sub_7FF7E6E9A180` |
| `mPercentAbilityHasteMod` | `0x58` | `88` | `sub_7FF7E6E9B650` |
| `mHPRegenRate` | `0xFC` | `252` | `sub_7FF7E6E9C1A0` |
| `mFlatMagicReduction` | `0x1A0` | `416` | `sub_7FF7E6E9C170` |
| `mAllShield` | `0x20C` | `524` | `sub_7FF7E6E99FC0` |
| `mAutobuildItemId` | `0x1CC` | `460` | `sub_7FF7E6E9A640` |
| `ReplicatedSecondWordSpellCanCastBitsLower1` | `0x7C` | `124` | `sub_7FF7E6E9B640` |
| `mSAREnabled` | `0x1E0` | `480` | `sub_7FF7E6E9ED90` |
| `mBaseAbilityDamage` | `0x108` | `264` | `sub_7FF7E6E9A7A0` |
| `mLargePipBitField` | `0x40` | `64` | `sub_7FF7E6E99D40` |
| `mCombatType` | `0x204` | `516` | `sub_7FF7E6E9B970` |
| `mFlags` | `0x1D0` | `464` | `sub_7FF7E6E9C0B0` |
| `BerserkInstigator` | `0x198` | `408` | `sub_7FF7E6E9A800` |
| `mNumNeutralMinionsKilled` | `0x54` | `84` | `sub_7FF7E6E9B120` |
| `mStopShieldFade` | `0x208` | `520` | `sub_7FF7E6E9F150` |
| `ManaCost_Ex14` | `0x1EC` | `492` | `sub_7FF7E6E9D8A0` |
| `ManaCost_Ex12` | `0x19C` | `412` | `sub_7FF7E6E9D880` |
| `mReplicatedSpellCanCastBitsUpper1` | `0xBC` | `188` | `sub_7FF7E6E9B9A0` |
| `ManaCost_Ex10` | `0x80` | `128` | `sub_7FF7E6E9A630` |
| `ManaCost_Ex0` | `0x94` | `148` | `sub_7FF7E6E9C150` |
| `mBaseHPRegenRate` | `0xE8` | `232` | `sub_7FF7E6E9A7F0` |
| `ManaCost_Ex1` | `0xAC` | `172` | `sub_7FF7E6E9C130` |
| `SlotEvolveAvailability3` | `0xB4` | `180` | `sub_7FF7E6E9EB40` |
| `ManaCost_0` | `0x170` | `368` | `sub_7FF7E6E9D850` |
| `mReplicatedSpellCanCastBitsLower1` | `0x238` | `568` | `sub_7FF7E6E9EC90` |
| `mInputLocks` | `0x1A4` | `420` | `sub_7FF7E6E9C910` |
| `ManaCost_Ex2` | `0x194` | `404` | `sub_7FF7E6E9D8C0` |
| `mEvolvePoints` | `0xDC` | `220` | `sub_7FF7E6E9C070` |
| `ManaCost_2` | `0x168` | `360` | `sub_7FF7E6E9D860` |
| `mBaseAttackDamage` | `0x24` | `36` | `sub_7FF7E6E9A7B0` |
| `ManaCost_Ex11` | `0xE4` | `228` | `sub_7FF7E6E9C900` |
| `SlotEvolveAvailability2` | `0x120` | `288` | `sub_7FF7E6E9EF60` |
| `mFlatCastRangeMod` | `0x138` | `312` | `sub_7FF7E6E9C140` |
| `mDodge` | `0x140` | `320` | `sub_7FF7E6E9BEC0` |
| `mFlatBaseAttackDamageMod` | `0x68` | `104` | `sub_7FF7E6E14AE0` |
| `ManaCost_Ex7` | `0x1C0` | `448` | `sub_7FF7E6E9D900` |
| `ManaCost_Ex15` | `0xE0` | `224` | `sub_7FF7E6E9D8B0` |
| `mSARState` | `0x60` | `96` | `sub_7FF7E6E13150` |
| `mBonusArmor` | `0x174` | `372` | `sub_7FF7E6E9B110` |
| `ManaCost_Ex9` | `0xD8` | `216` | `sub_7FF7E6E9C2A0` |
| `mCritDamageMultiplier` | `0x10C` | `268` | `sub_7FF7E6E9B990` |
| `mSkillUpLevelDeltaReplicate` | `0x14` | `20` | `sub_7FF7E6E9A000` |
| `mAttackSpeedMod` | `0x1A8` | `424` | `sub_7FF7E6E9A610` |
| `ManaCost_3` | `0x220` | `544` | `sub_7FF7E6E9D870` |
| `ManaCost_1` | `0xF8` | `248` | `sub_7FF7E6DAC720` |

## AIMinionCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `0x5C` | `92` | `sub_7FF7E6E99CF0` |
| `mSARState` | `0x88` | `136` | `sub_7FF7E6E99D00` |
| `mIsTargetable` | `0x1C` | `28` | `sub_7FF7E6E9C110` |
| `mFollowTargetNetID` | `0x10` | `16` | `sub_7FF7E6E99FB0` |
| `StatusFlags` | `0xF4` | `244` | `sub_7FF7E6E9EB30` |
| `mPARState` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mPAREnabled` | `0x90` | `144` | `sub_7FF7E6E18740` |
| `mSAREnabled` | `0xE0` | `224` | `sub_7FF7E6E9D8B0` |
| `mIsTargetableToTeamFlags` | `0x78` | `120` | `sub_7FF7E6E9CC40` |
| `mStopShieldFade` | `0x74` | `116` | `sub_7FF7E6E9C5D0` |

## AITurretCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `0x88` | `136` | `sub_7FF7E6E99D00` |
| `mStopShieldFade` | `0x24` | `36` | `sub_7FF7F91E7070` |
| `mIsTargetableToTeamFlags` | `0x2C` | `44` | `sub_7FF7E6E9B660` |
| `StatusFlags` | `0x60` | `96` | `sub_7FF7E6E13150` |
| `mPalisadesCount` | `0x94` | `148` | `sub_7FF7E6E9C150` |
| `mMaxPalisadesCount` | `0x50` | `80` | `sub_7FF7E6E9A620` |
| `mIsTargetable` | `0x64` | `100` | `sub_7FF7E6E9C0D0` |

## Barracks

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x1C` | `28` | `sub_7FF7F914EEB0` |
| `mIsTargetable` | `0x64` | `100` | `sub_7FF7E6E9C0D0` |
| `StatusFlags` | `0x18` | `24` | `sub_7FF7E6DAC780` |
| `mIsTargetableToTeamFlags` | `0x30` | `48` | `sub_7FF7E6E99FF0` |

## BarracksDampenerCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `StatusFlags` | `0x2C` | `44` | `sub_7FF7E6E9B660` |
| `mIsTargetableToTeamFlags` | `0x10` | `16` | `sub_7FF7E6E99FB0` |
| `mIsTargetable` | `0x64` | `100` | `sub_7FF7E6E9C0D0` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## HQCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `StatusFlags` | `0x14` | `20` | `sub_7FF7E6E9A000` |
| `mIsTargetable` | `0x64` | `100` | `sub_7FF7E6E9C0D0` |
| `mIsTargetableToTeamFlags` | `0x38` | `56` | `sub_7FF7E6E9B620` |

