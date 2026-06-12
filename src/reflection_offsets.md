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
| `ActionState2` | `0x20` | `32` | `AIGenericCommon__ActionState2_getter` |
| `StatusFlags` | `0x5C` | `92` | `AIGenericCommon__StatusFlags_getter` |
| `mIsTargetable` | `0x64` | `100` | `AIGenericCommon__mIsTargetable_getter` |
| `mIsTargetableToTeamFlags` | `0x3C` | `60` | `AIGenericCommon__mIsTargetableToTeamFlags_getter` |
| `BerserkInstigator` | `0x44` | `68` | `AIGenericCommon__BerserkInstigator_getter` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## AIHero

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `0xEC` | `236` | `AIHero__ActionState_getter` |
| `ActionState2` | `0x164` | `356` | `AIHero__ActionState2_getter` |
| `ManaCost_Ex6` | `0x1B4` | `436` | `AIHero__ManaCost_Ex6_getter` |
| `mLevelRef` | `0x28` | `40` | `AIHero__mLevelRef_getter` |
| `mPARState` | `0x214` | `532` | `AIHero__mPARState_getter` |
| `mFlatPhysicalDamageMod` | `0x1DC` | `476` | `AIHero__mFlatPhysicalDamageMod_getter` |
| `mFlatBaseSpellBlockMod` | `0x180` | `384` | `AIHero__mFlatBaseSpellBlockMod_getter` |
| `mIsTargetableToTeamFlags` | `0x130` | `304` | `AIHero__mIsTargetableToTeamFlags_getter` |
| `ManaCost_Ex4` | `0x184` | `388` | `AIHero__ManaCost_Ex4_getter` |
| `mAbilityHasteMod` | `0x224` | `548` | `AIHero__mAbilityHasteMod_getter` |
| `mFlatMagicDamageMod` | `0x1C` | `28` | `AIHero__mFlatMagicDamageMod_getter` |
| `mIncomingHealingAllied` | `0x38` | `56` | `AIHero__mIncomingHealingAllied_getter` |
| `mFlatArmorPenetration` | `0x148` | `328` | `AIHero__mFlatArmorPenetration_getter` |
| `ManaCost_Ex5` | `0x124` | `292` | `AIHero__ManaCost_Ex5_getter` |
| `mGold` | `0x16C` | `364` | `AIHero__mGold_getter` |
| `mMediumPipBitField` | `0x84` | `132` | `AIHero__mMediumPipBitField_getter` |
| `mHPMaxPenalty` | `0xD4` | `212` | `AIHero__mHPMaxPenalty_getter` |
| `mFlatBubbleRadiusMod` | `0xF0` | `240` | `AIHero__mFlatBubbleRadiusMod_getter` |
| `mFlatMagicPenetration` | `0x17C` | `380` | `AIHero__mFlatMagicPenetration_getter` |
| `ManaCost_Ex8` | `0x23C` | `572` | `AIHero__ManaCost_Ex8_getter` |
| `mAttackRange` | `0x5C` | `92` | `AIGenericCommon__StatusFlags_getter` |
| `mExp` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mIncomingDamage` | `0x1AC` | `428` | `AIHero__mIncomingDamage_getter` |
| `mHP` | `0x90` | `144` | `sub_7FF7F90D9080` |
| `mFlatBaseArmorMod` | `0x9C` | `156` | `AIHero__mFlatBaseArmorMod_getter` |
| `mFlatBaseHPPoolMod` | `0x154` | `340` | `AIHero__mFlatBaseHPPoolMod_getter` |
| `mChampSpecificHealth` | `0x1B0` | `432` | `AIHero__mChampSpecificHealth_getter` |
| `mPAREnabled` | `0x15C` | `348` | `AIHero__mPAREnabled_getter` |
| `SlotEvolveAvailability0` | `0x210` | `528` | `AIHero__SlotEvolveAvailability0_getter` |
| `ManaCost_Ex13` | `0x190` | `400` | `AIHero__ManaCost_Ex13_getter` |
| `mCrit` | `0x1C8` | `456` | `AIHero__mCrit_getter` |
| `mBaseGoldGivenOnDeath` | `0x228` | `552` | `AIHero__mBaseGoldGivenOnDeath_getter` |
| `mBaseAttackDamageSansPercentScale` | `0x114` | `276` | `AIHero__mBaseAttackDamageSansPercentScale_getter` |
| `mBonusSpellBlock` | `0x200` | `512` | `AIHero__mBonusSpellBlock_getter` |
| `mGoldTotal` | `0xA0` | `160` | `AIHero__mGoldTotal_getter` |
| `mIsTargetable` | `0x248` | `584` | `AIHero__mIsTargetable_getter` |
| `StatusFlags` | `0x150` | `336` | `AIHero__StatusFlags_getter` |
| `SlotEvolveAvailability1` | `0x14C` | `332` | `AIHero__SlotEvolveAvailability1_getter` |
| `ManaCost_Ex3` | `0x88` | `136` | `AIHero__ManaCost_Ex3_getter` |
| `mArmor` | `0x118` | `280` | `AIHero__mArmor_getter` |
| `mPercentAbilityHasteMod` | `0x58` | `88` | `AIHero__mPercentAbilityHasteMod_getter` |
| `mHPRegenRate` | `0xFC` | `252` | `AIHero__mHPRegenRate_getter` |
| `mFlatMagicReduction` | `0x1A0` | `416` | `AIHero__mFlatMagicReduction_getter` |
| `mAllShield` | `0x20C` | `524` | `AIHero__mAllShield_getter` |
| `mAutobuildItemId` | `0x1CC` | `460` | `AIHero__mAutobuildItemId_getter` |
| `ReplicatedSecondWordSpellCanCastBitsLower1` | `0x7C` | `124` | `AIHero__ReplicatedSecondWordSpellCanCastBitsLower1_getter` |
| `mSAREnabled` | `0x1E0` | `480` | `AIHero__mSAREnabled_getter` |
| `mBaseAbilityDamage` | `0x108` | `264` | `AIHero__mBaseAbilityDamage_getter` |
| `mLargePipBitField` | `0x40` | `64` | `AIHero__mLargePipBitField_getter` |
| `mCombatType` | `0x204` | `516` | `AIHero__mCombatType_getter` |
| `mFlags` | `0x1D0` | `464` | `AIHero__mFlags_getter` |
| `BerserkInstigator` | `0x198` | `408` | `AIHero__BerserkInstigator_getter` |
| `mNumNeutralMinionsKilled` | `0x54` | `84` | `AIHero__mNumNeutralMinionsKilled_getter` |
| `mStopShieldFade` | `0x208` | `520` | `AIHero__mStopShieldFade_getter` |
| `ManaCost_Ex14` | `0x1EC` | `492` | `AIHero__ManaCost_Ex14_getter` |
| `ManaCost_Ex12` | `0x19C` | `412` | `AIHero__ManaCost_Ex12_getter` |
| `mReplicatedSpellCanCastBitsUpper1` | `0xBC` | `188` | `AIHero__mReplicatedSpellCanCastBitsUpper1_getter` |
| `ManaCost_Ex10` | `0x80` | `128` | `AIHero__ManaCost_Ex10_getter` |
| `ManaCost_Ex0` | `0x94` | `148` | `AIHero__ManaCost_Ex0_getter` |
| `mBaseHPRegenRate` | `0xE8` | `232` | `AIHero__mBaseHPRegenRate_getter` |
| `ManaCost_Ex1` | `0xAC` | `172` | `AIHero__ManaCost_Ex1_getter` |
| `SlotEvolveAvailability3` | `0xB4` | `180` | `AIHero__SlotEvolveAvailability3_getter` |
| `ManaCost_0` | `0x170` | `368` | `AIHero__ManaCost_0_getter` |
| `mReplicatedSpellCanCastBitsLower1` | `0x238` | `568` | `AIHero__mReplicatedSpellCanCastBitsLower1_getter` |
| `mInputLocks` | `0x1A4` | `420` | `AIHero__mInputLocks_getter` |
| `ManaCost_Ex2` | `0x194` | `404` | `AIHero__ManaCost_Ex2_getter` |
| `mEvolvePoints` | `0xDC` | `220` | `AIHero__mEvolvePoints_getter` |
| `ManaCost_2` | `0x168` | `360` | `AIHero__ManaCost_2_getter` |
| `mBaseAttackDamage` | `0x24` | `36` | `AIHero__mBaseAttackDamage_getter` |
| `ManaCost_Ex11` | `0xE4` | `228` | `AIHero__ManaCost_Ex11_getter` |
| `SlotEvolveAvailability2` | `0x120` | `288` | `AIHero__SlotEvolveAvailability2_getter` |
| `mFlatCastRangeMod` | `0x138` | `312` | `AIHero__mFlatCastRangeMod_getter` |
| `mDodge` | `0x140` | `320` | `AIHero__mDodge_getter` |
| `mFlatBaseAttackDamageMod` | `0x68` | `104` | `AIHero__mFlatBaseAttackDamageMod_getter` |
| `ManaCost_Ex7` | `0x1C0` | `448` | `AIHero__ManaCost_Ex7_getter` |
| `ManaCost_Ex15` | `0xE0` | `224` | `AIHero__ManaCost_Ex15_getter` |
| `mSARState` | `0x60` | `96` | `AIHero__mSARState_getter` |
| `mBonusArmor` | `0x174` | `372` | `AIHero__mBonusArmor_getter` |
| `ManaCost_Ex9` | `0xD8` | `216` | `AIHero__ManaCost_Ex9_getter` |
| `mCritDamageMultiplier` | `0x10C` | `268` | `AIHero__mCritDamageMultiplier_getter` |
| `mSkillUpLevelDeltaReplicate` | `0x14` | `20` | `AIHero__mSkillUpLevelDeltaReplicate_getter` |
| `mAttackSpeedMod` | `0x1A8` | `424` | `AIHero__mAttackSpeedMod_getter` |
| `ManaCost_3` | `0x220` | `544` | `AIHero__ManaCost_3_getter` |
| `ManaCost_1` | `0xF8` | `248` | `AIHero__ManaCost_1_getter` |

## AIMinionCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `0x5C` | `92` | `AIGenericCommon__StatusFlags_getter` |
| `mSARState` | `0x88` | `136` | `AIHero__ManaCost_Ex3_getter` |
| `mIsTargetable` | `0x1C` | `28` | `AIHero__mFlatMagicDamageMod_getter` |
| `mFollowTargetNetID` | `0x10` | `16` | `AIMinionCommon__mFollowTargetNetID_getter` |
| `StatusFlags` | `0xF4` | `244` | `AIMinionCommon__StatusFlags_getter` |
| `mPARState` | `0x88` | `136` | `sub_7FF7F91E7080` |
| `mPAREnabled` | `0x90` | `144` | `AIMinionCommon__mPAREnabled_getter` |
| `mSAREnabled` | `0xE0` | `224` | `AIHero__ManaCost_Ex15_getter` |
| `mIsTargetableToTeamFlags` | `0x78` | `120` | `AIMinionCommon__mIsTargetableToTeamFlags_getter` |
| `mStopShieldFade` | `0x74` | `116` | `AIMinionCommon__mStopShieldFade_getter` |

## AITurretCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `0x88` | `136` | `AIHero__ManaCost_Ex3_getter` |
| `mStopShieldFade` | `0x24` | `36` | `sub_7FF7F91E7070` |
| `mIsTargetableToTeamFlags` | `0x2C` | `44` | `AITurretCommon__mIsTargetableToTeamFlags_getter` |
| `StatusFlags` | `0x60` | `96` | `AIHero__mSARState_getter` |
| `mPalisadesCount` | `0x94` | `148` | `AIHero__ManaCost_Ex0_getter` |
| `mMaxPalisadesCount` | `0x50` | `80` | `AITurretCommon__mMaxPalisadesCount_getter` |
| `mIsTargetable` | `0x64` | `100` | `AIGenericCommon__mIsTargetable_getter` |

## Barracks

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x1C` | `28` | `sub_7FF7F914EEB0` |
| `mIsTargetable` | `0x64` | `100` | `AIGenericCommon__mIsTargetable_getter` |
| `StatusFlags` | `0x18` | `24` | `Barracks__StatusFlags_getter` |
| `mIsTargetableToTeamFlags` | `0x30` | `48` | `Barracks__mIsTargetableToTeamFlags_getter` |

## BarracksDampenerCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `StatusFlags` | `0x2C` | `44` | `AITurretCommon__mIsTargetableToTeamFlags_getter` |
| `mIsTargetableToTeamFlags` | `0x10` | `16` | `AIMinionCommon__mFollowTargetNetID_getter` |
| `mIsTargetable` | `0x64` | `100` | `AIGenericCommon__mIsTargetable_getter` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7F91E7AF0` |

## HQCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x2C` | `44` | `sub_7FF7F91E7010` |
| `StatusFlags` | `0x14` | `20` | `AIHero__mSkillUpLevelDeltaReplicate_getter` |
| `mIsTargetable` | `0x64` | `100` | `AIGenericCommon__mIsTargetable_getter` |
| `mIsTargetableToTeamFlags` | `0x38` | `56` | `AIHero__mIncomingHealingAllied_getter` |

