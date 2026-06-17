#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0x7FF640FB0000;

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
        constexpr uintptr_t BuffManagerClient__OnBuffAdd = 0x93DFD0;
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0x93EB20;
        constexpr uintptr_t CastSpellWrapper = 0x20AC40;
        constexpr uintptr_t ClientMainLoop = 0x5EEC20;
        constexpr uintptr_t ComponentLookupFn = 0x11892B0;
        constexpr uintptr_t ComponentRegistry__Lookup = 0x11892B0;
        constexpr uintptr_t CurrentNodeIdx = 0x3906F;
        constexpr uintptr_t DistanceSq = 0x2205F0;
        constexpr uintptr_t GameObject__IsType = 0x28F150;
        constexpr uintptr_t GetAIManager = 0x27D9D0;
        constexpr uintptr_t GetAttackDelay = 0x5726B0;
        constexpr uintptr_t GetAttackWindup = 0x5725B0;
        constexpr uintptr_t GetBoundingRadius = 0x27EB60;
        constexpr uintptr_t GetCollisionFlags = 0x1243D30;
        constexpr uintptr_t GetFirstObject = 0x54FA50;
        constexpr uintptr_t GetMapID = 0x2852C0;
        constexpr uintptr_t GetNextObject = 0x5509E0;
        constexpr uintptr_t GetPing = 0x6C1780;
        constexpr uintptr_t GetSpellCastInfo = 0x652CC0;
        constexpr uintptr_t GetSpellSlot = 0x96E180;
        constexpr uintptr_t GetSubObjAiMgr = 0x539AE0;
        constexpr uintptr_t IsAlive = 0x2B79D0;
        constexpr uintptr_t IsBuilding = 0x2CCD90;
        constexpr uintptr_t IsHero = 0x2CCBE0;
        constexpr uintptr_t IsTurret = 0x2CCAE0;
        constexpr uintptr_t IsVisible = 0x217F90;
        constexpr uintptr_t IssueOrderCore = 0x290940;
        constexpr uintptr_t MinimapHudInit = 0x940C10;
        constexpr uintptr_t MinimapMoveSelf = 0x57A7F0;
        constexpr uintptr_t NavAgent = 0x591F40;
        constexpr uintptr_t OnCreateObject = 0x55B340;
        constexpr uintptr_t OnDeleteObject = 0x5612F0;
        constexpr uintptr_t OnDoCast = 0x97F310;
        constexpr uintptr_t OnPlayAnimation = 0x29BF90;
        constexpr uintptr_t OnProcessSpell = 0x984D40;
        constexpr uintptr_t OnSpellImpact = 0x97D700;
        constexpr uintptr_t OnStopCast = 0x985480;
        constexpr uintptr_t OnWndProc = 0x5F07A0;
        constexpr uintptr_t PrintChat = 0x112C970;
        constexpr uintptr_t ProjectAndClip = 0x12F6A40;
        constexpr uintptr_t QuestProgress__Calculate = 0x51E710;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0x5237F0;
        constexpr uintptr_t QuestProgressFn = 0x51E710;
        constexpr uintptr_t QuestValueFn = 0x5237F0;
        constexpr uintptr_t RoleBound__Init = 0x10FBE40;
        constexpr uintptr_t RoleBoundInit = 0x10FBE40;
        constexpr uintptr_t SpellSlot__Cast = 0x747F90;
        constexpr uintptr_t SpellSlot__GetCooldown = 0x932C90;
        constexpr uintptr_t SpellSlot__GetLevel = 0x9342CB;
        constexpr uintptr_t TransformVec3 = 0x12F8A80;
        constexpr uintptr_t WaypointCount = 0x399F1;
        constexpr uintptr_t WorldToScreen = 0x12F6B20;
    }

    namespace Standard {
        namespace GameObject {
            constexpr uintptr_t oIndex = 0x8;
            constexpr uintptr_t oNetworkID = 0x10;
            constexpr uintptr_t oTeamID = 0x259;
            constexpr uintptr_t oPosition = 0x25C;
        }
        namespace AIBaseClient {
            constexpr uintptr_t oPetOwner = 0x4D18;
            constexpr uintptr_t oModelInstance = 0x44F0;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t oCharacterDataStackBase = 0x2C88;
            constexpr uintptr_t oCombatStats = 0x49E8;
        }
        namespace CombatStats {
            constexpr uintptr_t mLevel = 0x28;
            constexpr uintptr_t mBaseAD = 0x24;
            constexpr uintptr_t mFlatADMod = 0x1DC;
            constexpr uintptr_t mFlatAPMod = 0x1C;
            constexpr uintptr_t mAttackSpeedMod = 0x1A8;
            constexpr uintptr_t mAttackRange = 0x5C;
            constexpr uintptr_t mCrit = 0x1C8;
            constexpr uintptr_t mArmor = 0x118;
            constexpr uintptr_t mBonusArmor = 0x174;
            constexpr uintptr_t mSpellBlock = 0x180;
            constexpr uintptr_t mBonusSpellBlock = 0x200;
            constexpr uintptr_t mMoveSpeed = 0x24C;
            constexpr uintptr_t mCombatType = 0x204;
        }
        namespace HeroManager {
            constexpr uintptr_t oHeroList = 0x8;
            constexpr uintptr_t oHeroCount = 0x10;
        }
        namespace AIManager {
            constexpr uintptr_t oServerPos = 0x08;
            constexpr uintptr_t oVelocity = 0x18;
            constexpr uintptr_t oTargetPosition = 0x24;
        }
        namespace navInner {
            constexpr uintptr_t oIsMoving = 0x320;
            constexpr uintptr_t oPathStart = 0x328;
            constexpr uintptr_t oPathEnd = 0x338;
            constexpr uintptr_t oIsDashing = 0x348;
            constexpr uintptr_t oDashSpeed = 0x3E0;
            constexpr uintptr_t oNavPath = 0x490;
        }
        namespace CameraData {
            constexpr uintptr_t oCamPos = 0x08;
            constexpr uintptr_t oCamRotation = 0x18;
            constexpr uintptr_t oCamAttached = 0x28;
            constexpr uintptr_t oCamMoveSpeed = 0x2C;
            constexpr uintptr_t oCamLookSpeed = 0x34;
            constexpr uintptr_t oFieldOfView = 0x3C;
            constexpr uintptr_t oNearClip = 0x44;
            constexpr uintptr_t oFarClip = 0x4C;
            constexpr uintptr_t oOutlineSelect = 0x54;
            constexpr uintptr_t oOutlineHover = 0x56;
            constexpr uintptr_t oFloatingText = 0x58;
            constexpr uintptr_t oFogOfWar = 0x5A;
            constexpr uintptr_t oNavGridOffset = 0x5C;
            constexpr uintptr_t oSimulateOffScreenParticles = 0x64;
        }
        namespace SpellBook {
            constexpr uintptr_t oActiveSpellCast = 0xAD8;
            constexpr uintptr_t oSpellSlots = 0xAE0;
        }
        namespace SpellSlot {
            constexpr uintptr_t oLevel = 0x28;
            constexpr uintptr_t oCooldown = 0x30;
            constexpr uintptr_t oCharges = 0x64;
            constexpr uintptr_t oChargeCooldown = 0x68;
        }
        namespace SpellData {
            constexpr uintptr_t oName = 0x28;
        }
        namespace MissileClient {
            constexpr uintptr_t oCasterNetID = 0x48;
            constexpr uintptr_t oTargetNetID = 0x4C;
            constexpr uintptr_t oStartPos = 0x24;
            constexpr uintptr_t oEndPos = 0x30;
            constexpr uintptr_t oSpeed = 0x410;
        }
    }
}
