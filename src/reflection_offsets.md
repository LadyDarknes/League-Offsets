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
| `StatusFlags` | `0x14` | `20` | `sub_7FF7C60402D0` |
| `mIsTargetable` | `0x1C` | `28` | `sub_7FF7C60426D0` |
| `mIsTargetableToTeamFlags` | `0x30` | `48` | `sub_7FF7C6041E00` |
| `BerserkInstigator` | `0x34` | `52` | `sub_7FF7C6040350` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7C60402C0` |

## AIHero

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `ManaCost_Ex6` | `0x14` | `20` | `sub_7FF7C60402D0` |
| `mLevelRef` | `0x24` | `36` | `sub_7FF7C6042A30` |
| `mPARState` | `0x28` | `40` | `sub_7FF7C5EEA8B0` |
| `mFlatPhysicalDamageMod` | `0x2C` | `44` | `sub_7FF7C6041E50` |
| `mFlatBaseSpellBlockMod` | `0x30` | `48` | `sub_7FF7C6041E00` |
| `mIsTargetableToTeamFlags` | `0x34` | `52` | `sub_7FF7C6040350` |
| `ManaCost_Ex4` | `0x38` | `56` | `sub_7FF7C6040320` |
| `mAbilityHasteMod` | `0x3C` | `60` | `sub_7FF7C6040210` |
| `mFlatMagicDamageMod` | `0x44` | `68` | `sub_7FF7C60402C0` |
| `mIncomingHealingAllied` | `0x48` | `72` | `sub_7FF7C6040300` |
| `mFlatArmorPenetration` | `0x4C` | `76` | `sub_7FF7C6041DC0` |
| `ManaCost_Ex5` | `0x54` | `84` | `sub_7FF7C60402E0` |
| `mGold` | `0x60` | `96` | `sub_7FF7C5EE6240` |
| `mMediumPipBitField` | `0x64` | `100` | `sub_7FF7C60426B0` |
| `mHPMaxPenalty` | `0x68` | `104` | `sub_7FF7C5F7C780` |
| `mFlatBubbleRadiusMod` | `0x70` | `112` | `sub_7FF7C6041510` |
| `mFlatMagicPenetration` | `0x74` | `116` | `sub_7FF7C6040980` |
| `ManaCost_Ex8` | `0x78` | `120` | `sub_7FF7C6041E20` |
| `mAttackRange` | `0x7C` | `124` | `sub_7FF7C6040620` |
| `mExp` | `0x88` | `136` | `CSource::pStateLock` |
| `mIncomingDamage` | `0x8C` | `140` | `sub_7FF7C6042A10` |
| `mHP` | `0x90` | `144` | `sub_7FF7C5F811A0` |
| `mFlatBaseArmorMod` | `0x98` | `152` | `Concurrency::details::ResourceManager::GetThreadProxyFactoryManager` |
| `mFlatBaseHPPoolMod` | `0x9C` | `156` | `sub_7FF7C5F7D4E0` |
| `mChampSpecificHealth` | `0xA4` | `164` | `sub_7FF7C6040E90` |
| `mPAREnabled` | `0xA8` | `168` | `sub_7FF7C6043C80` |
| `SlotEvolveAvailability0` | `0xAC` | `172` | `sub_7FF7C60448C0` |
| `ManaCost_Ex13` | `0xC4` | `196` | `sub_7FF7C6043B10` |
| `mCrit` | `0xCC` | `204` | `sub_7FF7C6041500` |
| `mBaseGoldGivenOnDeath` | `0xD0` | `208` | `sub_7FF7C5EE11E0` |
| `mBaseAttackDamageSansPercentScale` | `0xD4` | `212` | `sub_7FF7C6040910` |
| `mBonusSpellBlock` | `0xD8` | `216` | `Concurrency::details::VirtualProcessor::GetLocation` |
| `mGoldTotal` | `0xF0` | `240` | `CBaseInputPin::SampleProps` |
| `mIsTargetable` | `0xF4` | `244` | `sub_7FF7C6042FB0` |
| `StatusFlags` | `0xF8` | `248` | `sub_7FF7C5F73ED0` |
| `SlotEvolveAvailability1` | `0xFC` | `252` | `CMFCVisualManager::GetRibbonMainImageOffset` |
| `ManaCost_Ex3` | `0x104` | `260` | `sub_7FF7C6043B60` |
| `mArmor` | `0x108` | `264` | `sub_7FF7C60403C0` |
| `mPercentAbilityHasteMod` | `0x110` | `272` | `sub_7FF7C6044760` |
| `mHPRegenRate` | `0x114` | `276` | `sub_7FF7C60426F0` |
| `mFlatMagicReduction` | `0x11C` | `284` | `sub_7FF7C6041E30` |
| `mAllShield` | `0x124` | `292` | `sub_7FF7C6040310` |
| `mAutobuildItemId` | `0x130` | `304` | `sub_7FF7C6040810` |
| `ReplicatedSecondWordSpellCanCastBitsLower1` | `0x134` | `308` | `sub_7FF7C6045060` |
| `mSAREnabled` | `0x13C` | `316` | `sub_7FF7C60450A0` |
| `mBaseAbilityDamage` | `0x148` | `328` | `sub_7FF7C60408E0` |
| `mLargePipBitField` | `0x14C` | `332` | `sub_7FF7C6043220` |
| `mCombatType` | `0x150` | `336` | `sub_7FF7C6041470` |
| `mFlags` | `0x160` | `352` | `CMFCCustomizeButton::GetInvisibleButtons` |
| `BerserkInstigator` | `0x174` | `372` | `sub_7FF7C6040930` |
| `mNumNeutralMinionsKilled` | `0x17C` | `380` | `sub_7FF7C6044390` |
| `mStopShieldFade` | `0x180` | `384` | `sub_7FF7C6045F10` |
| `ManaCost_Ex14` | `0x184` | `388` | `sub_7FF7C6043B20` |
| `ManaCost_Ex12` | `0x188` | `392` | `sub_7FF7C6043B00` |
| `mReplicatedSpellCanCastBitsUpper1` | `0x18C` | `396` | `sub_7FF7C6045080` |
| `ManaCost_Ex10` | `0x190` | `400` | `sub_7FF7C6043AE0` |
| `ManaCost_Ex0` | `0x198` | `408` | `sub_7FF7C6043AD0` |
| `mBaseHPRegenRate` | `0x19C` | `412` | `sub_7FF7C6040920` |
| `ManaCost_Ex1` | `0x1A4` | `420` | `sub_7FF7C6043B40` |
| `SlotEvolveAvailability3` | `0x1A8` | `424` | `CDockSite::GetPaneList` |
| `ManaCost_0` | `0x1B0` | `432` | `sub_7FF7C6043A90` |
| `mReplicatedSpellCanCastBitsLower1` | `0x1B4` | `436` | `sub_7FF7C6045070` |
| `mInputLocks` | `0x1B8` | `440` | `sub_7FF7C6042AC0` |
| `ManaCost_Ex2` | `0x1BC` | `444` | `sub_7FF7C6043B50` |
| `mEvolvePoints` | `0x1CC` | `460` | `sub_7FF7C6041AF0` |
| `ManaCost_2` | `0x1D8` | `472` | `sub_7FF7C6043AB0` |
| `mBaseAttackDamage` | `0x1E4` | `484` | `sub_7FF7C60408F0` |
| `ManaCost_Ex11` | `0x1EC` | `492` | `sub_7FF7C6043AF0` |
| `SlotEvolveAvailability2` | `0x1F0` | `496` | `sub_7FF7C60456E0` |
| `mFlatCastRangeMod` | `0x1F8` | `504` | `sub_7FF7C5F6F9B0` |
| `mDodge` | `0x1FC` | `508` | `sub_7FF7C6041970` |
| `mFlatBaseAttackDamageMod` | `0x200` | `512` | `sub_7FF7C6041DE0` |
| `ManaCost_Ex7` | `0x208` | `520` | `CMFCPropertyGridCtrl::GetHeaderCtrl` |
| `ManaCost_Ex15` | `0x20C` | `524` | `sub_7FF7C6043B30` |
| `mSARState` | `0x214` | `532` | `sub_7FF7C60450B0` |
| `mBonusArmor` | `0x21C` | `540` | `sub_7FF7C6040940` |
| `ManaCost_Ex9` | `0x228` | `552` | `CMDIFrameWndEx::GetDockingManager` |
| `mCritDamageMultiplier` | `0x230` | `560` | `CMFCPopupMenu::GetMenuBar` |
| `mSkillUpLevelDeltaReplicate` | `0x234` | `564` | `sub_7FF7C60455C0` |
| `mAttackSpeedMod` | `0x240` | `576` | `sub_7FF7C60406D0` |
| `ManaCost_3` | `0x244` | `580` | `sub_7FF7C6043AC0` |
| `ManaCost_1` | `0x248` | `584` | `CMFCRibbonButton::GetSubItems` |

## AIMinionCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `mSARState` | `0x24` | `36` | `sub_7FF7C6042A30` |
| `mIsTargetable` | `0x40` | `64` | `sub_7FF7C60426E0` |
| `mFollowTargetNetID` | `0x60` | `96` | `sub_7FF7C5EE6240` |
| `StatusFlags` | `0x64` | `100` | `sub_7FF7C60426B0` |
| `mPARState` | `0x88` | `136` | `CSource::pStateLock` |
| `mPAREnabled` | `0x98` | `152` | `Concurrency::details::ResourceManager::GetThreadProxyFactoryManager` |
| `mSAREnabled` | `0xC8` | `200` | `sub_7FF7C6042A40` |
| `mIsTargetableToTeamFlags` | `0xCC` | `204` | `sub_7FF7C6041500` |
| `mStopShieldFade` | `0x100` | `256` | `CFrameWnd::OnHelpPromptAddr` |

## AITurretCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `ActionState` | `—` | `—` | `UNKNOWN_GETTER` |
| `ActionState2` | `—` | `—` | `UNKNOWN_GETTER` |
| `mStopShieldFade` | `0x24` | `36` | `sub_7FF7C6042A30` |
| `mIsTargetableToTeamFlags` | `0x44` | `68` | `sub_7FF7C60402C0` |
| `StatusFlags` | `0x50` | `80` | `sub_7FF7C6044060` |
| `mPalisadesCount` | `0x74` | `116` | `sub_7FF7C6040980` |
| `mMaxPalisadesCount` | `0x8C` | `140` | `sub_7FF7C6042A10` |
| `mIsTargetable` | `0x98` | `152` | `Concurrency::details::ResourceManager::GetThreadProxyFactoryManager` |

## Barracks

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x1C` | `28` | `sub_7FF7C60426D0` |
| `mIsTargetable` | `0x2C` | `44` | `sub_7FF7C6041E50` |
| `StatusFlags` | `0x30` | `48` | `sub_7FF7C6041E00` |
| `mIsTargetableToTeamFlags` | `0x38` | `56` | `sub_7FF7C6040320` |

## BarracksDampenerCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `StatusFlags` | `0x14` | `20` | `sub_7FF7C60402D0` |
| `mIsTargetableToTeamFlags` | `0x2C` | `44` | `sub_7FF7C6041E50` |
| `mIsTargetable` | `0x40` | `64` | `sub_7FF7C60426E0` |
| `mStopShieldFade` | `0x44` | `68` | `sub_7FF7C60402C0` |

## HQCommon

| Property Name | Field Offset (Hex) | Field Offset (Dec) | Getter Function |
| ------------- | ------------------ | ------------------ | --------------- |
| `mStopShieldFade` | `0x2C` | `44` | `sub_7FF7C6041E50` |
| `StatusFlags` | `0x30` | `48` | `sub_7FF7C6041E00` |
| `mIsTargetable` | `0x38` | `56` | `sub_7FF7C6040320` |
| `mIsTargetableToTeamFlags` | `0x40` | `64` | `sub_7FF7C60426E0` |

