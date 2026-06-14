#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0x7FF7E6B90000;

    namespace Globals {
        constexpr uintptr_t CastSpellFlag = 0x1DD8F70;
        constexpr uintptr_t ChatClient = 0x1EAE6A0;
        constexpr uintptr_t ConnSlotSentinel = 0x1EB6124;
        constexpr uintptr_t EntityList = 0x1E76E20;
        constexpr uintptr_t GameTime = 0x1E855A0;
        constexpr uintptr_t HeroManager = 0x1E76DA0;
        constexpr uintptr_t HudInstance = 0x1E76E08;
        constexpr uintptr_t IssueOrderFlag = 0x1DD8FD8;
        constexpr uintptr_t LocalPlayer = 0x1EB2020;
        constexpr uintptr_t MissileManager = 0x1E76D10;
        constexpr uintptr_t MouseScreenVec2 = 0x1E79D28;
        constexpr uintptr_t NavGrid = 0x1E79CC0;
        constexpr uintptr_t NetClient = 0x1E76C78;
        constexpr uintptr_t NetInstance = 0x1E76C90;
        constexpr uintptr_t ObjectManager = 0x1E76C80;
        constexpr uintptr_t SpellCastMap = 0x1E9F6C0;
        constexpr uintptr_t TimingTable = 0x1EB6DF0;
        constexpr uintptr_t UnderMouseObj = 0x1E79F78;
        constexpr uintptr_t ViewPort = 0x1E79D20;
        constexpr uintptr_t r3dRenderer = 0x1F4C598;
    }

    namespace Functions {
        constexpr uintptr_t BuffManagerClient__OnBuffAdd = 0x93DFB0;
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0x93EB00;
        constexpr uintptr_t CastSpellWrapper = 0x20AC40;
        constexpr uintptr_t ClientMainLoop = 0x5EEC00;
        constexpr uintptr_t ComponentLookupFn = 0x1189220;
        constexpr uintptr_t ComponentRegistry__Lookup = 0x1189220;
        constexpr uintptr_t CurrentNodeIdx = 0x3906F;
        constexpr uintptr_t DistanceSq = 0x2205F0;
        constexpr uintptr_t GameObject__IsType = 0x28F150;
        constexpr uintptr_t GetAIManager = 0x27D9D0;
        constexpr uintptr_t GetAttackDelay = 0x5726A0;
        constexpr uintptr_t GetAttackWindup = 0x5725A0;
        constexpr uintptr_t GetBoundingRadius = 0x27EB60;
        constexpr uintptr_t GetCollisionFlags = 0x1243CA0;
        constexpr uintptr_t GetFirstObject = 0x54FA40;
        constexpr uintptr_t GetMapID = 0x2852C0;
        constexpr uintptr_t GetNextObject = 0x5509D0;
        constexpr uintptr_t GetPing = 0x6C1760;
        constexpr uintptr_t GetSpellCastInfo = 0x652CA0;
        constexpr uintptr_t GetSpellSlot = 0x96E160;
        constexpr uintptr_t GetSubObjAiMgr = 0x539AD0;
        constexpr uintptr_t IsAlive = 0x2B79D0;
        constexpr uintptr_t IsBuilding = 0x2CCD90;
        constexpr uintptr_t IsHero = 0x2CCBE0;
        constexpr uintptr_t IsTurret = 0x2CCAE0;
        constexpr uintptr_t IsVisible = 0x217F90;
        constexpr uintptr_t IssueOrderCore = 0x290940;
        constexpr uintptr_t MinimapHudInit = 0x940BF0;
        constexpr uintptr_t MinimapMoveSelf = 0x57A7E0;
        constexpr uintptr_t NavAgent = 0x591F10;
        constexpr uintptr_t OnCreateObject = 0x55B330;
        constexpr uintptr_t OnDeleteObject = 0x5612E0;
        constexpr uintptr_t OnDoCast = 0x97F2F0;
        constexpr uintptr_t OnPlayAnimation = 0x29BF90;
        constexpr uintptr_t OnProcessSpell = 0x984D20;
        constexpr uintptr_t OnSpellImpact = 0x97D6E0;
        constexpr uintptr_t OnStopCast = 0x985460;
        constexpr uintptr_t OnWndProc = 0x5F0780;
        constexpr uintptr_t PrintChat = 0x112C8E0;
        constexpr uintptr_t ProjectAndClip = 0x12F69B0;
        constexpr uintptr_t QuestProgress__Calculate = 0x51E700;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0x5237E0;
        constexpr uintptr_t QuestProgressFn = 0x51E700;
        constexpr uintptr_t QuestValueFn = 0x5237E0;
        constexpr uintptr_t RoleBound__Init = 0x10FBDB0;
        constexpr uintptr_t RoleBoundInit = 0x10FBDB0;
        constexpr uintptr_t SpellSlot__Cast = 0x747F70;
        constexpr uintptr_t SpellSlot__GetCooldown = 0x932C70;
        constexpr uintptr_t SpellSlot__GetLevel = 0x9342AB;
        constexpr uintptr_t TransformVec3 = 0x12F89F0;
        constexpr uintptr_t WaypointCount = 0x398B0;
        constexpr uintptr_t WorldToScreen = 0x12F6A90;
    }

    namespace Reflections {
        namespace AIGenericCommon {
            // constexpr uintptr_t ActionState = 0x0; // Failed to resolve
            constexpr uintptr_t ActionState2 = 0x20;
            constexpr uintptr_t StatusFlags = 0x5C;
            constexpr uintptr_t mIsTargetable = 0x64;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x3C;
            constexpr uintptr_t BerserkInstigator = 0x44;
            // constexpr uintptr_t mStopShieldFade = 0x0; // Failed to resolve
        }
        namespace AIHero {
            constexpr uintptr_t ActionState = 0xEC;
            constexpr uintptr_t ActionState2 = 0x164;
            constexpr uintptr_t ManaCost_Ex6 = 0x1B4;
            constexpr uintptr_t mLevelRef = 0x28;
            constexpr uintptr_t mPARState = 0x214;
            constexpr uintptr_t mFlatPhysicalDamageMod = 0x1DC;
            constexpr uintptr_t mFlatBaseSpellBlockMod = 0x180;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x130;
            constexpr uintptr_t ManaCost_Ex4 = 0x184;
            constexpr uintptr_t mAbilityHasteMod = 0x224;
            constexpr uintptr_t mFlatMagicDamageMod = 0x1C;
            constexpr uintptr_t mIncomingHealingAllied = 0x38;
            constexpr uintptr_t mFlatArmorPenetration = 0x148;
            constexpr uintptr_t ManaCost_Ex5 = 0x124;
            constexpr uintptr_t mGold = 0x16C;
            constexpr uintptr_t mMediumPipBitField = 0x84;
            constexpr uintptr_t mHPMaxPenalty = 0xD4;
            constexpr uintptr_t mFlatBubbleRadiusMod = 0xF0;
            constexpr uintptr_t mFlatMagicPenetration = 0x17C;
            constexpr uintptr_t ManaCost_Ex8 = 0x23C;
            constexpr uintptr_t mAttackRange = 0x5C;
            // constexpr uintptr_t mExp = 0x0; // Failed to resolve
            constexpr uintptr_t mIncomingDamage = 0x1AC;
            // constexpr uintptr_t mHP = 0x0; // Failed to resolve
            constexpr uintptr_t mFlatBaseArmorMod = 0x9C;
            constexpr uintptr_t mFlatBaseHPPoolMod = 0x154;
            constexpr uintptr_t mChampSpecificHealth = 0x1B0;
            constexpr uintptr_t mPAREnabled = 0x15C;
            constexpr uintptr_t SlotEvolveAvailability0 = 0x210;
            constexpr uintptr_t ManaCost_Ex13 = 0x190;
            constexpr uintptr_t mCrit = 0x1C8;
            constexpr uintptr_t mBaseGoldGivenOnDeath = 0x228;
            constexpr uintptr_t mBaseAttackDamageSansPercentScale = 0x114;
            constexpr uintptr_t mBonusSpellBlock = 0x200;
            constexpr uintptr_t mGoldTotal = 0xA0;
            constexpr uintptr_t mIsTargetable = 0x248;
            constexpr uintptr_t StatusFlags = 0x150;
            constexpr uintptr_t SlotEvolveAvailability1 = 0x14C;
            constexpr uintptr_t ManaCost_Ex3 = 0x88;
            constexpr uintptr_t mArmor = 0x118;
            constexpr uintptr_t mPercentAbilityHasteMod = 0x58;
            constexpr uintptr_t mHPRegenRate = 0xFC;
            constexpr uintptr_t mFlatMagicReduction = 0x1A0;
            constexpr uintptr_t mAllShield = 0x20C;
            constexpr uintptr_t mAutobuildItemId = 0x1CC;
            constexpr uintptr_t ReplicatedSecondWordSpellCanCastBitsLower1 = 0x7C;
            constexpr uintptr_t mSAREnabled = 0x1E0;
            constexpr uintptr_t mBaseAbilityDamage = 0x108;
            constexpr uintptr_t mLargePipBitField = 0x40;
            constexpr uintptr_t mCombatType = 0x204;
            constexpr uintptr_t mFlags = 0x1D0;
            constexpr uintptr_t BerserkInstigator = 0x198;
            constexpr uintptr_t mNumNeutralMinionsKilled = 0x54;
            constexpr uintptr_t mStopShieldFade = 0x208;
            constexpr uintptr_t ManaCost_Ex14 = 0x1EC;
            constexpr uintptr_t ManaCost_Ex12 = 0x19C;
            constexpr uintptr_t mReplicatedSpellCanCastBitsUpper1 = 0xBC;
            constexpr uintptr_t ManaCost_Ex10 = 0x80;
            constexpr uintptr_t ManaCost_Ex0 = 0x94;
            constexpr uintptr_t mBaseHPRegenRate = 0xE8;
            constexpr uintptr_t ManaCost_Ex1 = 0xAC;
            constexpr uintptr_t SlotEvolveAvailability3 = 0xB4;
            constexpr uintptr_t ManaCost_0 = 0x170;
            constexpr uintptr_t mReplicatedSpellCanCastBitsLower1 = 0x238;
            constexpr uintptr_t mInputLocks = 0x1A4;
            constexpr uintptr_t ManaCost_Ex2 = 0x194;
            constexpr uintptr_t mEvolvePoints = 0xDC;
            constexpr uintptr_t ManaCost_2 = 0x168;
            constexpr uintptr_t mBaseAttackDamage = 0x24;
            constexpr uintptr_t ManaCost_Ex11 = 0xE4;
            constexpr uintptr_t SlotEvolveAvailability2 = 0x120;
            constexpr uintptr_t mFlatCastRangeMod = 0x138;
            constexpr uintptr_t mDodge = 0x140;
            constexpr uintptr_t mFlatBaseAttackDamageMod = 0x68;
            constexpr uintptr_t ManaCost_Ex7 = 0x1C0;
            constexpr uintptr_t ManaCost_Ex15 = 0xE0;
            constexpr uintptr_t mSARState = 0x60;
            constexpr uintptr_t mBonusArmor = 0x174;
            constexpr uintptr_t ManaCost_Ex9 = 0xD8;
            constexpr uintptr_t mCritDamageMultiplier = 0x10C;
            constexpr uintptr_t mSkillUpLevelDeltaReplicate = 0x14;
            constexpr uintptr_t mAttackSpeedMod = 0x1A8;
            constexpr uintptr_t ManaCost_3 = 0x220;
            constexpr uintptr_t ManaCost_1 = 0xF8;
        }
        namespace AIMinionCommon {
            // constexpr uintptr_t ActionState = 0x0; // Failed to resolve
            constexpr uintptr_t ActionState2 = 0x5C;
            constexpr uintptr_t mSARState = 0x88;
            constexpr uintptr_t mIsTargetable = 0x1C;
            constexpr uintptr_t mFollowTargetNetID = 0x10;
            constexpr uintptr_t StatusFlags = 0xF4;
            // constexpr uintptr_t mPARState = 0x0; // Failed to resolve
            constexpr uintptr_t mPAREnabled = 0x90;
            constexpr uintptr_t mSAREnabled = 0xE0;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x78;
            constexpr uintptr_t mStopShieldFade = 0x74;
        }
        namespace AITurretCommon {
            // constexpr uintptr_t ActionState = 0x0; // Failed to resolve
            constexpr uintptr_t ActionState2 = 0x88;
            // constexpr uintptr_t mStopShieldFade = 0x0; // Failed to resolve
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x2C;
            constexpr uintptr_t StatusFlags = 0x60;
            constexpr uintptr_t mPalisadesCount = 0x94;
            constexpr uintptr_t mMaxPalisadesCount = 0x50;
            constexpr uintptr_t mIsTargetable = 0x64;
        }
        namespace Barracks {
            // constexpr uintptr_t mStopShieldFade = 0x0; // Failed to resolve
            constexpr uintptr_t mIsTargetable = 0x64;
            constexpr uintptr_t StatusFlags = 0x18;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x30;
        }
        namespace BarracksDampenerCommon {
            constexpr uintptr_t StatusFlags = 0x2C;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x10;
            constexpr uintptr_t mIsTargetable = 0x64;
            // constexpr uintptr_t mStopShieldFade = 0x0; // Failed to resolve
        }
        namespace Class Instance Adjustment Offset {
        }
        namespace HQCommon {
            // constexpr uintptr_t mStopShieldFade = 0x0; // Failed to resolve
            constexpr uintptr_t StatusFlags = 0x14;
            constexpr uintptr_t mIsTargetable = 0x64;
            constexpr uintptr_t mIsTargetableToTeamFlags = 0x38;
        }
        namespace How Offsets are Resolved {
        }
    }

    namespace Standard {
        namespace AIBaseClient {
            constexpr uintptr_t oPetOwner = 0x4D18;
            constexpr uintptr_t oModelInstance = 0x44F0;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t oCharacterDataStackBase = 0x2C88;
        }
        namespace CharacterDataStack {
            constexpr uintptr_t oSkinName = 0x18;
            constexpr uintptr_t oModelIndex = 0xC4;
        }
        namespace HeroManager {
            constexpr uintptr_t oHeroList = 0x8;
            constexpr uintptr_t oHeroCount = 0x10;
        }
    }
}
