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
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `StatusFlags` | `0x14` | `20` | `sub_7FF7F91E7AB0` |
| `mIsTargetable` | `0x1C` | `28` | `sub_7FF7F914EEB0` |
| `mIsTargetableToTeamFlags` | `0x30` | `48` | `sub_7FF7F91E7040` |
| `BerserkInstigator` | `0x34` | `52` | `sub_7FF7F91E7690` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## AIHero

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `ManaCost_Ex6` | `0x14` | `20` | `sub_7FF7F91E7AB0` |
| `mLevelRef` | `0x24` | `36` | `sub_7FF7F91E7070` |
| `mPARState` | `0x28` | `40` | `sub_7FF7F90D2970` |
| `mFlatPhysicalDamageMod` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `mFlatBaseSpellBlockMod` | `0x30` | `48` | `sub_7FF7F91E7040` |
| `mIsTargetableToTeamFlags` | `0x34` | `52` | `sub_7FF7F91E7690` |
| `ManaCost_Ex4` | `0x38` | `56` | `sub_7FF7F90D35C0` |
| `mAbilityHasteMod` | `0x3C` | `60` | `sub_7FF7F91E8BC0` |
| `mFlatMagicDamageMod` | `0x44` | `68` | `sub_7FF7F91E7AF0` |
| `mIncomingHealingAllied` | `0x48` | `72` | `sub_7FF7F91E8130` |
| `mFlatArmorPenetration` | `0x4C` | `76` | `sub_7FF7F91E7120` |
| `ManaCost_Ex5` | `0x54` | `84` | `sub_7FF7F91E7620` |
| `mGold` | `0x60` | `96` | `sub_7FF7F914C380` |
| `mMediumPipBitField` | `0x64` | `100` | `sub_7FF7F91E8C60` |
| `mHPMaxPenalty` | `0x68` | `104` | `sub_7FF7F90D6910` |
| `mFlatBubbleRadiusMod` | `0x70` | `112` | `sub_7FF7F91E7430` |
| `mFlatMagicPenetration` | `0x74` | `116` | `sub_7FF7F91E7420` |
| `ManaCost_Ex8` | `0x78` | `120` | `sub_7FF7F91E7130` |
| `mAttackRange` | `0x7C` | `124` | `sub_7FF7F91E9AF0` |
| `mExp` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mIncomingDamage` | `0x8C` | `140` | `sub_7FF7F91E7630` |
| `mHP` | `0x90` | `144` | `sub_7FF7F90D9080` |
| `mFlatBaseArmorMod` | `0x98` | `152` | `sub_7FF7F91E96B0` |
| `mFlatBaseHPPoolMod` | `0x9C` | `156` | `sub_7FF7F90D7040` |
| `mChampSpecificHealth` | `0xA4` | `164` | `sub_7FF7F91E7AE0` |
| `mPAREnabled` | `0xA8` | `168` | `sub_7FF7F91E9CC0` |
| `SlotEvolveAvailability0` | `0xAC` | `172` | `sub_7FF7F9091340` |
| `ManaCost_Ex13` | `0xC4` | `196` | `sub_7FF7F91E9200` |
| `mCrit` | `0xCC` | `204` | `sub_7FF7F91E8720` |
| `mBaseGoldGivenOnDeath` | `0xD0` | `208` | `sub_7FF7F908AA70` |
| `mBaseAttackDamageSansPercentScale` | `0xD4` | `212` | `sub_7FF7F91E8FB0` |
| `mBonusSpellBlock` | `0xD8` | `216` | `sub_7FF7F91E8C70` |
| `mGoldTotal` | `0xF0` | `240` | `sub_7FF7F91EA6F0` |
| `mIsTargetable` | `0xF4` | `244` | `sub_7FF7F91E7670` |
| `StatusFlags` | `0xF8` | `248` | `sub_7FF7F90D25D0` |
| `SlotEvolveAvailability1` | `0xFC` | `252` | `sub_7FF7F91E8FC0` |
| `ManaCost_Ex3` | `0x104` | `260` | `sub_7FF7F91E8700` |
| `mArmor` | `0x108` | `264` | `sub_7FF7F91E9BE0` |
| `mPercentAbilityHasteMod` | `0x110` | `272` | `sub_7FF7F908E890` |
| `mHPRegenRate` | `0x114` | `276` | `sub_7FF7F91E9C00` |
| `mFlatMagicReduction` | `0x11C` | `284` | `sub_7FF7F91E9CB0` |
| `mAllShield` | `0x124` | `292` | `sub_7FF7F91EA5A0` |
| `mAutobuildItemId` | `0x130` | `304` | `sub_7FF7F91EAD80` |
| `ReplicatedSecondWordSpellCanCastBitsLower1` | `0x134` | `308` | `sub_7FF7F91EADE0` |
| `mSAREnabled` | `0x13C` | `316` | `sub_7FF7F91EA750` |
| `mBaseAbilityDamage` | `0x148` | `328` | `sub_7FF7F91EA6B0` |
| `mLargePipBitField` | `0x14C` | `332` | `sub_7FF7F91EADB0` |
| `mCombatType` | `0x150` | `336` | `sub_7FF7F91E86F0` |
| `mFlags` | `0x160` | `352` | `sub_7FF7F9892F80` |
| `BerserkInstigator` | `0x174` | `372` | `sub_7FF7F91E8710` |
| `mNumNeutralMinionsKilled` | `0x17C` | `380` | `sub_7FF7F91E9BD0` |
| `mStopShieldFade` | `0x180` | `384` | `sub_7FF7F91E9FB0` |
| `ManaCost_Ex14` | `0x184` | `388` | `sub_7FF7C6043B20` |
| `ManaCost_Ex12` | `0x188` | `392` | `sub_7FF7F91EAD90` |
| `mReplicatedSpellCanCastBitsUpper1` | `0x18C` | `396` | `sub_7FF7F91EA700` |
| `ManaCost_Ex10` | `0x190` | `400` | `sub_7FF7F91EB3E0` |
| `ManaCost_Ex0` | `0x198` | `408` | `sub_7FF7F91E9CA0` |
| `mBaseHPRegenRate` | `0x19C` | `412` | `sub_7FF7F91E8760` |
| `ManaCost_Ex1` | `0x1A4` | `420` | `sub_7FF7F91E9C50` |
| `SlotEvolveAvailability3` | `0x1A8` | `424` | `CDockSite::GetPaneList` |
| `ManaCost_0` | `0x1B0` | `432` | `sub_7FF7F91E9C90` |
| `mReplicatedSpellCanCastBitsLower1` | `0x1B4` | `436` | `sub_7FF7F91E7610` |
| `mInputLocks` | `0x1B8` | `440` | `sub_7FF7F91EA690` |
| `ManaCost_Ex2` | `0x1BC` | `444` | `sub_7FF7F91E9F90` |
| `mEvolvePoints` | `0x1CC` | `460` | `sub_7FF7F91EA5E0` |
| `ManaCost_2` | `0x1D8` | `472` | `sub_7FF7F91E7650` |
| `mBaseAttackDamage` | `0x1E4` | `484` | `sub_7FF7F91E8740` |
| `ManaCost_Ex11` | `0x1EC` | `492` | `sub_7FF7F91E9DC0` |
| `SlotEvolveAvailability2` | `0x1F0` | `496` | `sub_7FF7C60456E0` |
| `mFlatCastRangeMod` | `0x1F8` | `504` | `sub_7FF7F9145390` |
| `mDodge` | `0x1FC` | `508` | `sub_7FF7F91EA610` |
| `mFlatBaseAttackDamageMod` | `0x200` | `512` | `sub_7FF7F91E9C80` |
| `ManaCost_Ex7` | `0x208` | `520` | `sub_7FF7F91EA300` |
| `ManaCost_Ex15` | `0x20C` | `524` | `sub_7FF7F91E8780` |
| `mSARState` | `0x214` | `532` | `sub_7FF7F91EA8C0` |
| `mBonusArmor` | `0x21C` | `540` | `sub_7FF7F91E9C40` |
| `ManaCost_Ex9` | `0x228` | `552` | `sub_7FF7F91E7640` |
| `mCritDamageMultiplier` | `0x230` | `560` | `sub_7FF7F91E8C80` |
| `mSkillUpLevelDeltaReplicate` | `0x234` | `564` | `sub_7FF7F91EA710` |
| `mAttackSpeedMod` | `0x240` | `576` | `sub_7FF7F91E86E0` |
| `ManaCost_3` | `0x244` | `580` | `sub_7FF7F91E7600` |
| `ManaCost_1` | `0x248` | `584` | `sub_7FF7F91E9BB0` |

## AIMinionCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `mSARState` | `0x24` | `36` | `sub_7FF7F91E7070` |
| `mIsTargetable` | `0x40` | `64` | `sub_7FF7F91E7380` |
| `mFollowTargetNetID` | `0x60` | `96` | `sub_7FF7F914C380` |
| `StatusFlags` | `0x64` | `100` | `sub_7FF7F91E8C60` |
| `mPARState` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mPAREnabled` | `0x98` | `152` | `sub_7FF7F91E96B0` |
| `mSAREnabled` | `0xC8` | `200` | `sub_7FF7F91E8FA0` |
| `mIsTargetableToTeamFlags` | `0xCC` | `204` | `sub_7FF7F91E8720` |
| `mStopShieldFade` | `0x100` | `256` | `sub_7FF7F91E6F80` |

## AITurretCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `mStopShieldFade` | `0x24` | `36` | `sub_7FF7F91E7070` |
| `mIsTargetableToTeamFlags` | `0x44` | `68` | `sub_7FF7F91E7AF0` |
| `StatusFlags` | `0x50` | `80` | `sub_7FF7F91E8770` |
| `mPalisadesCount` | `0x74` | `116` | `sub_7FF7F91E7420` |
| `mMaxPalisadesCount` | `0x8C` | `140` | `sub_7FF7F91E7630` |
| `mIsTargetable` | `0x98` | `152` | `sub_7FF7F91E96B0` |

## Barracks

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x1C` | `28` | `sub_7FF7F914EEB0` |
| `mIsTargetable` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `StatusFlags` | `0x30` | `48` | `sub_7FF7F91E7040` |
| `mIsTargetableToTeamFlags` | `0x38` | `56` | `sub_7FF7F90D35C0` |

## BarracksDampenerCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `StatusFlags` | `0x14` | `20` | `sub_7FF7F91E7AB0` |
| `mIsTargetableToTeamFlags` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `mIsTargetable` | `0x40` | `64` | `sub_7FF7F91E7380` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## HQCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `StatusFlags` | `0x30` | `48` | `sub_7FF7F91E7040` |
| `mIsTargetable` | `0x38` | `56` | `sub_7FF7F90D35C0` |
| `mIsTargetableToTeamFlags` | `0x40` | `64` | `sub_7FF7F91E7380` |

