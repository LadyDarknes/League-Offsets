#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0x7FF701D60000;

    namespace Globals {
        constexpr uintptr_t BlueMinionManager = 0x1EA0240;
        constexpr uintptr_t CastSpellFlag = 0x1DFEF70;
        constexpr uintptr_t ChatClient = 0x1ED6E88;
        constexpr uintptr_t ConnSlotSentinel = 0x1EDED88;
        constexpr uintptr_t EntityList = 0x1E9D160;
        constexpr uintptr_t GameClient = 0x1EB97F8;
        constexpr uintptr_t GameTime = 0x1EABFF0;
        constexpr uintptr_t HeroManager = 0x1E9D0D8;
        constexpr uintptr_t HudInstance = 0x1E9D148;
        constexpr uintptr_t IssueOrderFlag = 0x1DFEFD8;
        constexpr uintptr_t LocalPlayer = 0x1EDB378;
        constexpr uintptr_t MissileManager = 0x1E9D048;
        constexpr uintptr_t MouseScreenVec2 = 0x1EA0200;
        constexpr uintptr_t NavGrid = 0x1EA0198;
        constexpr uintptr_t NetClient = 0x1E9CFB0;
        constexpr uintptr_t NetInstance = 0x1E9CFC8;
        constexpr uintptr_t ObjectManager = 0x1E9CFB8;
        constexpr uintptr_t RedMinionManager = 0x1EA0248;
        constexpr uintptr_t SpellCastMap = 0x1EC70D0;
        constexpr uintptr_t SwapChain = 0x1F7B178;
        constexpr uintptr_t TimingTable = 0x1EE0740;
        constexpr uintptr_t UnderMouseObj = 0x1EA0448;
        constexpr uintptr_t ViewPort = 0x1EA01F8;
        constexpr uintptr_t r3dRenderLayer = 0x1F7AA08;
        constexpr uintptr_t r3dRenderer = 0x1F7CD08;
    }

    namespace Functions {
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0x920320;
        constexpr uintptr_t CanCast = 0x2C50A0;
        constexpr uintptr_t CastSpellPosition = 0x97A980;
        constexpr uintptr_t CastSpellTarget = 0x97A0B0;
        constexpr uintptr_t CastSpellWrapper = 0x2045D0;
        constexpr uintptr_t CharacterDataStack__Push = 0x3F22D0;
        constexpr uintptr_t CharacterDataStack__Update = 0x3F3170;
        constexpr uintptr_t ComponentLookupFn = 0x11AA460;
        constexpr uintptr_t ComponentRegistry__Lookup = 0x11AA460;
        constexpr uintptr_t CurrentNodeIdx = 0x3906F;
        constexpr uintptr_t DistanceSq = 0x21A6D0;
        constexpr uintptr_t GameObject__IsType = 0x2881F0;
        constexpr uintptr_t GetAIManager = 0x276E70;
        constexpr uintptr_t GetAttackDelay = 0x573590;
        constexpr uintptr_t GetAttackWindup = 0x573490;
        constexpr uintptr_t GetBoundingRadius = 0x278010;
        constexpr uintptr_t GetCollisionFlags = 0x126A150;
        constexpr uintptr_t GetFirstObject = 0x552DC0;
        constexpr uintptr_t GetMapID = 0x27E660;
        constexpr uintptr_t GetModelInstance = 0x295080;
        constexpr uintptr_t GetNextObject = 0x553C30;
        constexpr uintptr_t GetPing = 0x6CC720;
        constexpr uintptr_t GetSpellCastInfo = 0x659420;
        constexpr uintptr_t GetSpellSlot = 0x969340;
        constexpr uintptr_t GetSubObjAiMgr = 0x53DB50;
        constexpr uintptr_t IsAlive = 0x2B0C10;
        constexpr uintptr_t IsBuilding = 0x2C5440;
        constexpr uintptr_t IsHero = 0x2C5290;
        constexpr uintptr_t IsTurret = 0x2C5190;
        constexpr uintptr_t IsVisible = 0x211CA0;
        constexpr uintptr_t IssueOrderCore = 0x2899D0;
        constexpr uintptr_t MinimapHudInit = 0x9221E0;
        constexpr uintptr_t MinimapMoveSelf = 0x599950;
        constexpr uintptr_t NavAgent = 0x58EEC0;
        constexpr uintptr_t NavMesh__CreatePath = 0x2309B0;
        constexpr uintptr_t OnCreateObject = 0x55D860;
        constexpr uintptr_t OnDeleteObject = 0x562DE0;
        constexpr uintptr_t OnDoCast = 0x97B2D0;
        constexpr uintptr_t OnProcessSpell = 0x981C50;
        constexpr uintptr_t OnSpellImpact = 0x979640;
        constexpr uintptr_t PrintChat = 0x114EC00;
        constexpr uintptr_t ProjectAndClip = 0x13160C0;
        constexpr uintptr_t QuestProgress__Calculate = 0x522410;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0x526560;
        constexpr uintptr_t QuestProgressFn = 0x522410;
        constexpr uintptr_t QuestValueFn = 0x526560;
        constexpr uintptr_t RemapBoneIndex = 0x2CAFF0;
        constexpr uintptr_t RoleBound__Init = 0x111E610;
        constexpr uintptr_t RoleBoundInit = 0x111E610;
        constexpr uintptr_t SpellSlot__Cast = 0x755450;
        constexpr uintptr_t SpellSlot__GetCooldown = 0x912EF0;
        constexpr uintptr_t SpellSlot__GetLevel = 0x3A8B8B;
        constexpr uintptr_t TransformVec3 = 0x1318100;
        constexpr uintptr_t UpdateCamera = 0x2F89D0;
        constexpr uintptr_t WaypointCount = 0x398B0;
        constexpr uintptr_t WorldToScreen = 0x13161A0;
        constexpr uintptr_t fieldOfView = 0x749A00;
    }

    namespace Reflections {
    }

    namespace Standard {
        namespace SpellData {
            constexpr uintptr_t oName = 0x28;
        }
        namespace CharacterData {
            constexpr uintptr_t oSkinID = 0x14;
        }
        namespace SpellBook {
            constexpr uintptr_t oSpellSlots = 0xAE0;
            constexpr uintptr_t oActiveSpellCast = 0xAD8;
        }
        namespace AIManager {
            constexpr uintptr_t oServerPos = 0x8;
            constexpr uintptr_t oVelocity = 0x18;
            constexpr uintptr_t oTargetPosition = 0x24;
            constexpr uintptr_t oNavPath = 0x40;
        }
        namespace AIBaseClient {
            constexpr uintptr_t oModelInstance = 0x44D0;
            constexpr uintptr_t oCharacterDataStack = 0x1288;
            constexpr uintptr_t oBuffManager = 0x28F0;
            constexpr uintptr_t oFacing = 0x1C0;
            constexpr uintptr_t oCombatStats = 0x4428;
            constexpr uintptr_t oPetOwner = 0x4D18;
        }
        namespace GameObject {
            constexpr uintptr_t oIndex = 0x8;
            constexpr uintptr_t oNetworkID = 0xBC;
            constexpr uintptr_t oTeamID = 0x259;
            constexpr uintptr_t oPosition = 0x25C;
            constexpr uintptr_t oPlayerStatsComponent = 0x2A8;
            constexpr uintptr_t oIsDeleted = 0x110;
            constexpr uintptr_t oSpellBook = 0x3128;
            constexpr uintptr_t oAIManager = 0x4070;
        }
        namespace CombatStats {
            constexpr uintptr_t mLevel = 0x28;
            constexpr uintptr_t mBaseAD = 0x24;
            constexpr uintptr_t mFlatAPMod = 0x1C;
            constexpr uintptr_t mAttackSpeedMod = 0x1A8;
            constexpr uintptr_t mAttackRange = 0x5C;
            constexpr uintptr_t mArmor = 0x118;
            constexpr uintptr_t mBonusArmor = 0x174;
            constexpr uintptr_t mCombatType = 0x204;
        }
        namespace SpellSlot {
            constexpr uintptr_t oLevel = 0x28;
            constexpr uintptr_t oCooldown = 0x30;
            constexpr uintptr_t oCharges = 0x64;
            constexpr uintptr_t oChargeCooldown = 0x68;
            constexpr uintptr_t oChargeLevel = 0x6C;
            constexpr uintptr_t oChargeStartTime = 0x74;
        }
        namespace CameraData {
            constexpr uintptr_t oCamPos = 0x8;
            constexpr uintptr_t oCamRotation = 0x18;
            constexpr uintptr_t oCamMoveSpeed = 0x2C;
            constexpr uintptr_t oFieldOfView = 0x3C;
            constexpr uintptr_t oNearClip = 0x44;
            constexpr uintptr_t oFarClip = 0x4C;
        }
        namespace MissileClient {
            constexpr uintptr_t oCasterNetID = 0x30;
            constexpr uintptr_t oTargetNetID = 0x34;
            constexpr uintptr_t oStartPos = 0x24;
            constexpr uintptr_t oEndPos = 0x30;
        }
    }
}
