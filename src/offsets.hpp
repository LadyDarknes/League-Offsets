#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0x7FF7B90C0000;

    namespace Globals {
        constexpr uintptr_t BlueMinionManager = 0x1EA0240;
        constexpr uintptr_t CastSpellFlag = 0x1DFEF70;
        constexpr uintptr_t ChatClient = 0x1ED6E88;
        constexpr uintptr_t ConnSlotSentinel = 0x1EDED88;
        constexpr uintptr_t EntityList = 0x1E9D160;
        constexpr uintptr_t GameClient = 0x1EB97F8;
        constexpr uintptr_t GameTime = 0x1EE5D30;
        constexpr uintptr_t HeroManager = 0x1ED6DB8;
        constexpr uintptr_t HudInstance = 0x1ED6E28;
        constexpr uintptr_t IssueOrderFlag = 0x1DFEFD8;
        constexpr uintptr_t LocalPlayer = 0x1F15390;
        constexpr uintptr_t MissileManager = 0x1ED9FC0;
        constexpr uintptr_t MouseScreenVec2 = 0x1EA0200;
        constexpr uintptr_t NavGrid = 0x1EA0198;
        constexpr uintptr_t NetClient = 0x1E9CFB0;
        constexpr uintptr_t NetInstance = 0x1E9CFC8;
        constexpr uintptr_t ObjectManager = 0x1ED6C98;
        constexpr uintptr_t RedMinionManager = 0x1EA0248;
        constexpr uintptr_t SpellCastMap = 0x1EC70D0;
        constexpr uintptr_t SwapChain = 0x1F7B178;
        constexpr uintptr_t TimingTable = 0x1EE0740;
        constexpr uintptr_t UnderMouseObj = 0x1EA0448;
        constexpr uintptr_t ViewPort = 0x1EA01F8;
        constexpr uintptr_t ZoomAnomalyLatch = 0x1F187E4;
        constexpr uintptr_t r3dRenderLayer = 0x1F7AA08;
        constexpr uintptr_t r3dRenderer = 0x1F7CD08;
        constexpr uintptr_t g_thread_device = 0x1F7AA18;
        constexpr uintptr_t g_current_x3d_device_override = 0x1F7B178;
        constexpr uintptr_t g_x3d_d3d11_backend = 0x1F7AA38;
        constexpr uintptr_t g_d3dcompiler47_module = 0x1F7B1F0;
        constexpr uintptr_t g_D3DReflect = 0x1F7B1F8;
        constexpr uintptr_t X3DDeviceD3D11_vtable = 0x1B00890;
    }

    namespace Functions {
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0x920320;
        constexpr uintptr_t CanCast = 0x2C50A0;
        constexpr uintptr_t CastSpellPosition = 0x97A980;
        constexpr uintptr_t CastSpellSafe = 0xC130F0;
        constexpr uintptr_t CastSpellTarget = 0x97A0B0;
        constexpr uintptr_t CastSpellWrapper = 0x2045D0;
        constexpr uintptr_t CharacterDataStack__Push = 0x3F22D0;
        constexpr uintptr_t CharacterDataStack__Update = 0x3F3170;
        constexpr uintptr_t CharacterDataStackPush = 0x22B750;
        constexpr uintptr_t CharacterDataStackUpdate = 0x210F70;
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
        constexpr uintptr_t GetGoldRedirectTarget = 0x209B20;
        constexpr uintptr_t GetMapID = 0x27E660;
        constexpr uintptr_t GetModelInstance = 0x295080;
        constexpr uintptr_t GetNextObject = 0x553C30;
        constexpr uintptr_t GetObjectByID = 0x5521B0;
        constexpr uintptr_t GetPing = 0x6CC720;
        constexpr uintptr_t GetRenderPipeline = 0x4B6960;
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
        constexpr uintptr_t OnDeleteObject = 0x2869C0;
        constexpr uintptr_t OnDoCast = 0x97B2D0;
        constexpr uintptr_t OnNewPath = 0x2E5960;
        constexpr uintptr_t OnProcessSpell = 0x981C50;
        constexpr uintptr_t OnSpellImpact = 0x979640;
        constexpr uintptr_t PrintChat = 0x114EC00;
        constexpr uintptr_t ProjectAndClip = 0x13160C0;
        constexpr uintptr_t QuestProgress__Calculate = 0x522410;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0x526560;
        constexpr uintptr_t RemapBoneIndex = 0x2CAFF0;
        constexpr uintptr_t RoleBound__Init = 0x111E610;
        constexpr uintptr_t SpellSlot__Cast = 0x755450;
        constexpr uintptr_t SpellSlot__GetCooldown = 0x912EF0;
        constexpr uintptr_t SpellSlot__GetLevel = 0x3A8B8B;
        constexpr uintptr_t TransformVec3 = 0x1318100;
        constexpr uintptr_t TranslateString = 0x11A9BA0;
        constexpr uintptr_t UpdateCamera = 0x2F89D0;
        constexpr uintptr_t WaypointCount = 0x398B0;
        constexpr uintptr_t WorldToScreen = 0x13161A0;
        constexpr uintptr_t fieldOfView = 0x749A00;
        constexpr uintptr_t GetThreadDevice = 0x13BA550;
        constexpr uintptr_t X3DDeviceD3D11_Initialize = 0x13A7BF0;
        constexpr uintptr_t X3DDeviceD3D11_Release = 0x20E420;
        constexpr uintptr_t ConstantBuffer_CreateD3D11DynamicBuffer = 0x3748C0;
        constexpr uintptr_t D3D11TextureView_CreateShaderResourceView = 0x30A9D0;
        constexpr uintptr_t DX11Backend_CreateDeviceAndSwapChain = 0x2309B0;
        constexpr uintptr_t GraphicsPipelineD3D11_InitFromDesc = 0xBBB470;
        constexpr uintptr_t X3DDeviceD3D11_SetGraphicsPipeline = 0x13ADFF0;
        constexpr uintptr_t X3DDeviceD3D11_CreateGraphicsPipeline = 0x13B05C0;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexBuffer = 0x4A7E80;
        constexpr uintptr_t X3DDeviceD3D11_CreateIndexBuffer = 0x1ED9E0;
        constexpr uintptr_t X3DDeviceD3D11_CreateDataBuffer = 0x13B02D0;
        constexpr uintptr_t X3DDeviceD3D11_CreateTexture2D = 0x838ED0;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexProgram = 0x13B19E0;
        constexpr uintptr_t X3DDeviceD3D11_CreatePixelProgram = 0x13B1810;
        constexpr uintptr_t X3DDeviceD3D11_CreateShaderProgram = 0x44F9F0;
        constexpr uintptr_t X3DDeviceD3D11_ClearFramebuffer = 0xB4A820;
        constexpr uintptr_t X3DDeviceD3D11_BeginFrame = 0x13AC670;
        constexpr uintptr_t X3DDeviceD3D11_EndFrame = 0xCAB3D0;
        constexpr uintptr_t X3DDeviceD3D11_BeginRenderPass = 0x13AC750;
        constexpr uintptr_t X3DDeviceD3D11_EndRenderPass = 0x13B5A60;
        constexpr uintptr_t X3DDeviceD3D11_IsRenderPassActive = 0x284510;
        constexpr uintptr_t X3DDeviceD3D11_IsFrameActive = 0x284510;
        constexpr uintptr_t X3DDeviceD3D11_Draw = 0x13BC7A0;
        constexpr uintptr_t X3DDeviceD3D11_DrawIndexed = 0x13BC7A0;
        constexpr uintptr_t g_thread_device = 0x13BA550;
        constexpr uintptr_t g_x3d_d3d11_backend = 0x13B8690;
    }

    namespace Reflections {
    }

    namespace Standard {
        namespace SpellSlot {
            constexpr uintptr_t oLevel = 0x28;
            constexpr uintptr_t oCooldown = 0x30;
            constexpr uintptr_t oCharges = 0x64;
            constexpr uintptr_t oChargeCooldown = 0x68;
            constexpr uintptr_t oChargeLevel = 0x6C;
            constexpr uintptr_t oChargeStartTime = 0x74;
            constexpr uintptr_t ActiveSpellCast = 0x118;
            constexpr uintptr_t ChargeCooldownDuration = 0x6C;
            constexpr uintptr_t ChargeCooldownExpires = 0x68;
            constexpr uintptr_t Cooldown = 0x80;
            constexpr uintptr_t CooldownDuration = 0x74;
            constexpr uintptr_t CooldownExpires = 0x30;
            constexpr uintptr_t CooldownOverride = 0x88;
            constexpr uintptr_t Level = 0x28;
            constexpr uintptr_t MaxStacks = 0x64;
            constexpr uintptr_t Owner = 0x8;
            constexpr uintptr_t SlotType = 0x31;
            constexpr uintptr_t SpellInfo = 0x128;
            constexpr uintptr_t SpellInstanceVars = 0x108;
            constexpr uintptr_t SpellNameHash = 0x120;
            constexpr uintptr_t Stacks = 0x5C;
            constexpr uintptr_t Vtable = 0x0;
        }
        namespace AIManager {
            constexpr uintptr_t oServerPos = 0x8;
            constexpr uintptr_t oVelocity = 0x18;
            constexpr uintptr_t oTargetPosition = 0x24;
            constexpr uintptr_t oNavPath = 0x40;
            constexpr uintptr_t AiManager = 0x4230;
            constexpr uintptr_t CurrentSegment = 0x320;
            constexpr uintptr_t DashSpeed = 0x360;
            constexpr uintptr_t IsDashing = 0xF0;
            constexpr uintptr_t IsMoving = 0x31C;
            constexpr uintptr_t MoveVec3 = 0x480;
            constexpr uintptr_t NavArray = 0x348;
            constexpr uintptr_t ObjectOffset = 0x4230;
            constexpr uintptr_t PathState = 0x320;
            constexpr uintptr_t SegmentsCount = 0x350;
            constexpr uintptr_t ServerPos = 0x80;
            constexpr uintptr_t StartPath = 0x330;
            constexpr uintptr_t TargetPos = 0x14;
            constexpr uintptr_t TargetPosition = 0x33C;
            constexpr uintptr_t Velocity = 0x318;
        }
        namespace CharacterData {
            constexpr uintptr_t oSkinID = 0x14;
            constexpr uintptr_t OFF_CHARDATA_CAST_TIME = 0x25C;
            constexpr uintptr_t OFF_CHARDATA_DELAY_SCALE = 0x9C8;
        }
        namespace MissileClient {
            constexpr uintptr_t CasterNetID = 0x30;
            constexpr uintptr_t TargetNetID = 0x34;
            constexpr uintptr_t StartPos = 0x390;
            constexpr uintptr_t EndPos = 0x39C;
            constexpr uintptr_t Speed = 0x410;
            constexpr uintptr_t CurrentPos = 0x25C;
            constexpr uintptr_t oCasterNetID = 0x30;
            constexpr uintptr_t oTargetNetID = 0x34;
            constexpr uintptr_t oStartPos = 0x24;
            constexpr uintptr_t oEndPos = 0x30;
            constexpr uintptr_t oSpeed = 0x0;
            constexpr uintptr_t CastEndPos = 0x3A8;
            constexpr uintptr_t CastInfoBase = 0x2C0;
            constexpr uintptr_t CasterIndex = 0x360;
            constexpr uintptr_t MissileName = 0x308;
            constexpr uintptr_t MissileNetId = 0x36C;
            constexpr uintptr_t Position = 0x25C;
            constexpr uintptr_t SpellDataPtr = 0x2C0;
            constexpr uintptr_t SpellName = 0x2E0;
            constexpr uintptr_t StartTime = 0x478;
            constexpr uintptr_t TargetIndex = 0x35C;
        }
        namespace CombatStats {
            constexpr uintptr_t mFlatAPMod = 0x1C;
            constexpr uintptr_t mBaseAD = 0x24;
            constexpr uintptr_t mLevel = 0x28;
            constexpr uintptr_t mAttackRange = 0x5C;
            constexpr uintptr_t mArmor = 0x118;
            constexpr uintptr_t mBonusArmor = 0x174;
            constexpr uintptr_t mSpellBlock = 0x180;
            constexpr uintptr_t mAttackSpeedMod = 0x1A8;
            constexpr uintptr_t mCrit = 0x1C8;
            constexpr uintptr_t mFlatADMod = 0x1DC;
            constexpr uintptr_t mBonusSpellBlock = 0x200;
            constexpr uintptr_t mCombatType = 0x204;
            constexpr uintptr_t mMoveSpeed = 0x24C;
            constexpr uintptr_t oBuffManager = 0x2E78;
            constexpr uintptr_t oFacing = 0x1C0;
        }
        namespace AIBaseClient {
            constexpr uintptr_t oCombatStats = 0x4428;
            constexpr uintptr_t oModelInstance = 0x44D8;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t oBuffManager = 0x2E78;
            constexpr uintptr_t oFacing = 0x1C0;
            constexpr uintptr_t oPetOwner = 0x4D18;
            constexpr uintptr_t oHeroInventoryClient = 0x4230;
            constexpr uintptr_t SkinId = 0x1334;
            constexpr uintptr_t CharacterData = 0x4108;
            constexpr uintptr_t oCharacterDataStackBase = 0x2C88;
            constexpr uintptr_t BaseGoldOnDeath = 0x55B8;
            constexpr uintptr_t Exp = 0x4D38;
            constexpr uintptr_t Gold = 0x2868;
            constexpr uintptr_t GoldTotal = 0x2890;
            constexpr uintptr_t LevelRef = 0x4D60;
            constexpr uintptr_t LevelUpPoints = 0x4D88;
            constexpr uintptr_t NeutralMinionsKilled = 0x55E0;
            constexpr uintptr_t RuneManager = 0x50E8;
            constexpr uintptr_t ShutdownValue = 0x5590;
            constexpr uintptr_t VisionScore = 0x5568;
            constexpr uintptr_t ArrayBegin = 0x18;
            constexpr uintptr_t ArrayCapacity = 0x28;
            constexpr uintptr_t ArrayEnd = 0x20;
            constexpr uintptr_t BuffManager = 0x2E78;
            constexpr uintptr_t Count = 0x78;
            constexpr uintptr_t Duration = 0x20;
            constexpr uintptr_t EndTime = 0x1C;
            constexpr uintptr_t EntryBuffInstance = 0x0;
            constexpr uintptr_t EntryRefCount = 0x8;
            constexpr uintptr_t EntryStride = 0x10;
            constexpr uintptr_t InstanceVtable = 0x0;
            constexpr uintptr_t InstanceVtableOnClearFn = 0x10;
            constexpr uintptr_t InstanceVtableUpdateStackFn = 0x20;
            constexpr uintptr_t IsCleared = 0x88;
            constexpr uintptr_t LookupMap = 0x38;
            constexpr uintptr_t OwnerNameData = 0x8;
            constexpr uintptr_t OwnerNetworkId = 0x10;
            constexpr uintptr_t PointerArrayBegin = 0x48;
            constexpr uintptr_t PointerArrayCapacity = 0x58;
            constexpr uintptr_t PointerArrayEnd = 0x50;
            constexpr uintptr_t PointerArrayStride = 0x8;
            constexpr uintptr_t Script = 0x10;
            constexpr uintptr_t ScriptBuffType = 0x100;
            constexpr uintptr_t ScriptBuffTypeAlt = 0x101;
            constexpr uintptr_t ScriptName = 0x8;
            constexpr uintptr_t ScriptNameHash = 0x18;
            constexpr uintptr_t SourceNetworkId = 0x14;
            constexpr uintptr_t StackDataPtr = 0x0;
            constexpr uintptr_t StackDataSourceId = 0x4;
            constexpr uintptr_t StackStride = 0x10;
            constexpr uintptr_t StacksArray = 0x30;
            constexpr uintptr_t StacksCount = 0x38;
            constexpr uintptr_t StartTime = 0x18;
            constexpr uintptr_t StateArrayBegin = 0x70;
            constexpr uintptr_t StateArrayCapacity = 0x80;
            constexpr uintptr_t StateArrayEnd = 0x78;
            constexpr uintptr_t StateArrayStride = 0x68;
            constexpr uintptr_t Type = 0xC;
            constexpr uintptr_t Vtable = 0x0;
            constexpr uintptr_t VtableHasBuffOfTypeFn = 0x8;
            constexpr uintptr_t VtableUpdateStackFn = 0x20;
            constexpr uintptr_t Avatar = 0x50A8;
            constexpr uintptr_t BaseGoldGivenOnDeath = 0x55B8;
            constexpr uintptr_t CombatType = 0x2CD0;
            constexpr uintptr_t Experience = 0x4D38;
            constexpr uintptr_t Level = 0x4D60;
            constexpr uintptr_t MinimumGold = 0x28B8;
            constexpr uintptr_t SkillUpLevelDelta = 0x4D88;
            constexpr uintptr_t SpellTrainingPoints = 0x4D88;
            constexpr uintptr_t AutobuildItemId = 0x57B0;
        }
        namespace GameObject {
            constexpr uintptr_t oIndex = 0x20;
            constexpr uintptr_t oNetId = 0x20;
            constexpr uintptr_t oTeamID = 0x259;
            constexpr uintptr_t oName = 0x68;
            constexpr uintptr_t oNetworkID = 0xCC;
            constexpr uintptr_t oSourceNetworkId = 0xF4;
            constexpr uintptr_t oDead = 0x250;
            constexpr uintptr_t oEffectEmitterHandle = 0x258;
            constexpr uintptr_t oPosition = 0x25C;
            constexpr uintptr_t oDirection = 0x0;
            constexpr uintptr_t oVisibility = 0x2E0;
            constexpr uintptr_t oVisible = 0x308;
            constexpr uintptr_t oMissileClientHandle = 0x2D8;
            constexpr uintptr_t oTargetableComponent = 0x2A8;
            constexpr uintptr_t oPlayerStatsComponent = 0x2A8;
            constexpr uintptr_t oIsTargetable = 0xED0;
            constexpr uintptr_t oTargetableState = 0xEF8;
            constexpr uintptr_t oRadius = 0x6F8;
            constexpr uintptr_t oModelScaleComponent = 0x2C88;
            constexpr uintptr_t oAIManager = 0x4070;
            constexpr uintptr_t oCharacterData = 0x4078;
            constexpr uintptr_t oSpellBook = 0x3128;
            constexpr uintptr_t oCharacterName = 0x4370;
            constexpr uintptr_t oItemList = 0x4490;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t OFF_POS_X = 0x25C;
            constexpr uintptr_t OFF_POS_Y = 0x260;
            constexpr uintptr_t OFF_POS_Z = 0x264;
            constexpr uintptr_t OFF_VISIBLE_0 = 0x168;
            constexpr uintptr_t OFF_VISIBLE_FOG = 0x169;
            constexpr uintptr_t OFF_VISIBLE_ALT = 0x16A;
            constexpr uintptr_t OFF_HP = 0x1080;
            constexpr uintptr_t OFF_HP_MAX = 0x10D0;
            constexpr uintptr_t OFF_MANA = 0x360;
            constexpr uintptr_t OFF_MANA_MAX = 0x388;
            constexpr uintptr_t OFF_MANA_ENABLED = 0x3B0;
            constexpr uintptr_t OFF_LEVEL = 0x4D58;
            constexpr uintptr_t OFF_MOVE_SPEED = 0x5000;
            constexpr uintptr_t OFF_ARMOR = 0x4F38;
            constexpr uintptr_t OFF_MAGIC_RES = 0x4CB8;
            constexpr uintptr_t OFF_ALL_SHIELD = 0x1120;
            constexpr uintptr_t OFF_PHYS_SHIELD = 0x1148;
            constexpr uintptr_t OFF_MAG_SHIELD = 0x1170;
            constexpr uintptr_t OFF_AS_MULTIPLIER = 0x80;
            constexpr uintptr_t OFF_ATK_RANGE = 0x7;
            constexpr uintptr_t OFF_BOUNDING_RADIUS = 0x6F8;
            constexpr uintptr_t OFF_SPELLBOOK = 0x3128;
            constexpr uintptr_t OFF_AIMANAGER_PTR = 0x4070;
            constexpr uintptr_t OFF_HEROCLIENT_PTR = 0x4230;
            constexpr uintptr_t AbilityHaste = 0x20B0;
            constexpr uintptr_t Armor = 0x1C50;
            constexpr uintptr_t AttackRange = 0x1569;
            constexpr uintptr_t AttackSpeedMod = 0x156B;
            constexpr uintptr_t BaseAttackDamage = 0x1F08;
            constexpr uintptr_t Crit = 0x2030;
            constexpr uintptr_t CritDamageMultiplier = 0x1A90;
            constexpr uintptr_t FlatArmorPen = 0x1DD0;
            constexpr uintptr_t FlatMagicPen = 0x1;
            constexpr uintptr_t FlatPhysicalDmgMod = 0x1;
            constexpr uintptr_t HPRegenRate = 0x2138;
            constexpr uintptr_t MP = 0x360;
            constexpr uintptr_t MagicLethality = 0x2368;
            constexpr uintptr_t MaxMP = 0x388;
            constexpr uintptr_t MoveSpeed = 0x2188;
            constexpr uintptr_t PercentArmorPen = 0x1;
            constexpr uintptr_t PercentAttackSpeedMod = 0x156B;
            constexpr uintptr_t PercentBonusArmorPen = 0x22C8;
            constexpr uintptr_t PercentBonusMagicPen = 0x23B8;
            constexpr uintptr_t PercentCCReduction = 0x25F0;
            constexpr uintptr_t PercentLifeSteal = 0x23F0;
            constexpr uintptr_t PercentMagicPen = 0x1D90;
            constexpr uintptr_t PercentOmnivamp = 0x2330;
            constexpr uintptr_t PercentSpellVamp = 0x2408;
            constexpr uintptr_t PhysicalLethality = 0x2278;
            constexpr uintptr_t SpellBlock = 0x20E8;
            constexpr uintptr_t CharacterName = 0x4370;
            constexpr uintptr_t Name = 0x4370;
            constexpr uintptr_t AllShield = 0x1120;
            constexpr uintptr_t HP = 0x1080;
            constexpr uintptr_t IsTargetable = 0xED0;
            constexpr uintptr_t MagicalShield = 0x1170;
            constexpr uintptr_t MaxHP = 0x10D0;
            constexpr uintptr_t PhysicalShield = 0x1148;
            constexpr uintptr_t TargetableFlags = 0xEF8;
            constexpr uintptr_t AbilityPower = 0x1C70;
            constexpr uintptr_t ActionState = 0x19F0;
            constexpr uintptr_t ActionState2 = 0x25D0;
            constexpr uintptr_t ActionStateBase = 0x1470;
            constexpr uintptr_t BonusAttackDamage = 0x1569;
            constexpr uintptr_t ChampionName = 0x6B8;
            constexpr uintptr_t CharData = 0x4058;
            constexpr uintptr_t CharacterActionState = 0x14C8;
            constexpr uintptr_t CharacterDataStack = 0x4108;
            constexpr uintptr_t CharacterIntermediate = 0x1568;
            constexpr uintptr_t CharacterState = 0x14A0;
            constexpr uintptr_t CombatStatsBase = 0x1568;
            constexpr uintptr_t DirectionComponent = 0x1270;
            constexpr uintptr_t DirectionVFunc = 0xA8;
            constexpr uintptr_t DirectionVector = 0x20;
            constexpr uintptr_t EvolvePoints = 0x1E70;
            constexpr uintptr_t FlatArmorPenetration = 0x1DD0;
            constexpr uintptr_t FlatMagicPenetration = 0x1890;
            constexpr uintptr_t Health = 0x1080;
            constexpr uintptr_t Index = 0x20;
            constexpr uintptr_t Inventory = 0x4DC8;
            constexpr uintptr_t IsBotVFunc = 0x88;
            constexpr uintptr_t IsTargetableToTeamFlags = 0xEF8;
            constexpr uintptr_t IsVisible = 0x310;
            constexpr uintptr_t IsZombie = 0x3A;
            constexpr uintptr_t Mana = 0x360;
            constexpr uintptr_t MaxHealth = 0x10D0;
            constexpr uintptr_t MaxMana = 0x388;
            constexpr uintptr_t OverrideCollisionHeight = 0x88;
            constexpr uintptr_t OverrideCollisionRadius = 0x758;
            constexpr uintptr_t PARRegenRate = 0x1BF0;
            constexpr uintptr_t PARState = 0x2050;
            constexpr uintptr_t PathfindingCollisionRadius = 0x758;
            constexpr uintptr_t PathfindingRadiusMod = 0x1CB0;
            constexpr uintptr_t PercentArmorPenetration = 0x1930;
            constexpr uintptr_t PercentBonusArmorPenetration = 0x22C8;
            constexpr uintptr_t PercentBonusMagicPenetration = 0x23B8;
            constexpr uintptr_t PercentHealingAmountMod = 0x1E90;
            constexpr uintptr_t PercentLifeStealMod = 0x23F0;
            constexpr uintptr_t PercentMagicDamageMod = 0x1;
            constexpr uintptr_t PercentMagicPenetration = 0x1D90;
            constexpr uintptr_t PercentOmnivampMod = 0x2330;
            constexpr uintptr_t PercentPhysicalDamageMod = 0x1870;
            constexpr uintptr_t PercentPhysicalVamp = 0x1F10;
            constexpr uintptr_t PercentSpellVampMod = 0x2350;
            constexpr uintptr_t Position = 0x25C;
            constexpr uintptr_t SelectionHeight = 0x88;
            constexpr uintptr_t SelectionRadius = 0x8C;
            constexpr uintptr_t SkinName = 0x4370;
            constexpr uintptr_t StatusFlags = 0x2090;
            constexpr uintptr_t StatusFlagsInvulnerableMask = 0x1;
            constexpr uintptr_t Team = 0x259;
            constexpr uintptr_t FlatPhysicalDamageMod = 0x1970;
        }
        namespace SpellDataResource {
            constexpr uintptr_t oMissileSpeed = 0x408;
            constexpr uintptr_t DataResourceBase = 0x60;
            constexpr uintptr_t ResAmmoRecharge = 0x408;
            constexpr uintptr_t ResCastRange = 0x478;
            constexpr uintptr_t ResCastRangeDisplayOverride = 0x548;
            constexpr uintptr_t ResCastType = 0x31;
            constexpr uintptr_t ResCooldownTime = 0x88;
            constexpr uintptr_t ResImgIconName = 0x2A0;
            constexpr uintptr_t ResLineWidth = 0x568;
            constexpr uintptr_t ResMaxAmmo = 0x3C0;
            constexpr uintptr_t ResMissileSpec = 0x508;
            constexpr uintptr_t ResMissileSpeed = 0x518;
            constexpr uintptr_t ResScriptName = 0x80;
        }
        namespace SpellBook {
            constexpr uintptr_t oActiveSpellCast = 0xAD8;
            constexpr uintptr_t oSpellSlots = 0xAE0;
            constexpr uintptr_t OFF_SB_DELAY_PCT = 0x308;
            constexpr uintptr_t ActiveSpellCast = 0x38;
            constexpr uintptr_t LastSlot = 0x3F;
            constexpr uintptr_t MaxSlots = 0x40;
            constexpr uintptr_t SlotStride = 0x8;
            constexpr uintptr_t SpellBook = 0x3128;
            constexpr uintptr_t SpellSlotArray = 0xAE0;
        }
        namespace SkinResource {
            constexpr uintptr_t skin_id = 0x0;
            constexpr uintptr_t skin_name = 0x8;
        }
        namespace ChampionManager {
            constexpr uintptr_t champions = 0x18;
        }
        namespace SpellData {
            constexpr uintptr_t oName = 0x28;
            constexpr uintptr_t InfoLevelOrFlag = 0x14;
            constexpr uintptr_t InfoOwnerSlot = 0x60;
            constexpr uintptr_t InfoSpellData = 0x8;
            constexpr uintptr_t ResourceData = 0x60;
            constexpr uintptr_t ResourceName = 0x28;
            constexpr uintptr_t Vtable = 0x0;
            constexpr uintptr_t VtableGetTargetingFn = 0x20;
        }
        namespace ChampionResource {
            constexpr uintptr_t skins = 0xC8;
        }
        namespace CameraData {
            constexpr uintptr_t oCamPos = 0x8;
            constexpr uintptr_t oCamRotation = 0x18;
            constexpr uintptr_t oCamAttached = 0x28;
            constexpr uintptr_t oCamMoveSpeed = 0x2C;
            constexpr uintptr_t oFieldOfView = 0x3C;
            constexpr uintptr_t oNearClip = 0x44;
            constexpr uintptr_t oFarClip = 0x4C;
            constexpr uintptr_t oFogOfWar = 0x5A;
        }
        namespace NavGrid {
            constexpr uintptr_t OFF_NAV_WIDTH = 0x710;
            constexpr uintptr_t OFF_NAV_HEIGHT = 0x604;
            constexpr uintptr_t OFF_NAV_ORIGIN = 0xF4;
            constexpr uintptr_t OFF_NAV_CELLSIZE = 0x71C;
            constexpr uintptr_t OFF_NAV_DATA = 0x118;
            constexpr uintptr_t CellArray = 0x120;
            constexpr uintptr_t CellCenterOffset = 0x718;
            constexpr uintptr_t CellCountX = 0x708;
            constexpr uintptr_t CellCountZ = 0x70C;
            constexpr uintptr_t CellDataFlags = 0x6;
            constexpr uintptr_t CellDataPtr = 0x0;
            constexpr uintptr_t CellFlagBrush = 0x1;
            constexpr uintptr_t CellFlagBuilding = 0x40;
            constexpr uintptr_t CellFlagProp = 0x80;
            constexpr uintptr_t CellFlagSpecialRegionMask = 0xC00;
            constexpr uintptr_t CellFlagWall = 0x2;
            constexpr uintptr_t CellFlags = 0x8;
            constexpr uintptr_t CellSize = 0x710;
            constexpr uintptr_t CellSizeInv = 0x604;
            constexpr uintptr_t CellStride = 0x10;
            constexpr uintptr_t Grid = 0x8;
            constexpr uintptr_t WorldMaxX = 0xF8;
            constexpr uintptr_t WorldMaxZ = 0x100;
            constexpr uintptr_t WorldMinX = 0xEC;
            constexpr uintptr_t WorldMinZ = 0xF4;
        }
        namespace CharacterDataStack {
            constexpr uintptr_t ActiveGear = 0x9C;
            constexpr uintptr_t ActiveModel = 0x18;
            constexpr uintptr_t ActiveSkinId = 0x38;
            constexpr uintptr_t Stack = 0x0;
            constexpr uintptr_t StackCapacity = 0x10;
            constexpr uintptr_t StackEnd = 0x8;
        }
        namespace SpellCastInfo {
            constexpr uintptr_t HASHMAP_OFF_SENTINEL = 0x70;
            constexpr uintptr_t HASHMAP_OFF_BUCKETS = 0x80;
            constexpr uintptr_t HASHMAP_OFF_MASK = 0x98;
            constexpr uintptr_t NODE_OFF_NEXT = 0x8;
            constexpr uintptr_t NODE_OFF_KEY_STR = 0x10;
            constexpr uintptr_t NODE_OFF_KEY_HASH = 0x18;
            constexpr uintptr_t NODE_OFF_VALUE = 0x20;
        }
        namespace TimingPing {
            constexpr uintptr_t OFF_A1_CONN_SLOT = 0x423;
            constexpr uintptr_t OFF_A1_TREE_LINK = 0xC8;
            constexpr uintptr_t OFF_NODE_NEXT_LEFT = 0x000;
            constexpr uintptr_t OFF_NODE_NEXT_RIGHT = 0x10;
            constexpr uintptr_t OFF_NODE_END_FLAG = 0x19;
            constexpr uintptr_t OFF_NODE_KEY = 0x20;
            constexpr uintptr_t OFF_NODE_DATA = 0x28;
            constexpr uintptr_t OFF_DATA_RTT_A = 0x148;
            constexpr uintptr_t OFF_DATA_RTT_B = 0x158;
            constexpr uintptr_t TIMING_STRIDE_QWORDS = 0x21;
        }
        namespace HeroManager {
            constexpr uintptr_t OFF_HEROMGR_LIST = 0x8;
            constexpr uintptr_t OFF_HEROMGR_COUNT = 0x10;
        }
        namespace X3DDeviceD3D11 {
            constexpr uintptr_t vtable = 0x0;
            constexpr uintptr_t device = 0x1E0;
            constexpr uintptr_t feature_level = 0x1E8;
            constexpr uintptr_t adapter = 0x210;
            constexpr uintptr_t swapchain = 0x218;
            constexpr uintptr_t swapchain_desc = 0x240;
            constexpr uintptr_t width = 0x2A8;
            constexpr uintptr_t height = 0x2AC;
            constexpr uintptr_t context = 0x2B0;
            constexpr uintptr_t active_pipeline = 0x728;
        }
        namespace X3DDeviceD3D11Vtable {
            constexpr uintptr_t Release = 0x0;
            constexpr uintptr_t SetGraphicsPipeline = 0x58;
            constexpr uintptr_t CreateGraphicsPipeline = 0x60;
            constexpr uintptr_t CreateVertexBuffer = 0x88;
            constexpr uintptr_t CreateIndexBuffer = 0x98;
            constexpr uintptr_t CreateDataBuffer = 0xB8;
            constexpr uintptr_t CreateTexture2D = 0xC8;
            constexpr uintptr_t CreateVertexProgram = 0x100;
            constexpr uintptr_t CreatePixelProgram = 0x118;
            constexpr uintptr_t CreateShaderProgram = 0x128;
            constexpr uintptr_t ClearFramebuffer = 0x160;
            constexpr uintptr_t BeginFrame = 0x180;
            constexpr uintptr_t EndFrame = 0x188;
            constexpr uintptr_t BeginRenderPass = 0x190;
            constexpr uintptr_t EndRenderPass = 0x198;
            constexpr uintptr_t IsRenderPassActive = 0x1A0;
            constexpr uintptr_t IsFrameActive = 0x1A8;
            constexpr uintptr_t Draw = 0x1C0;
            constexpr uintptr_t DrawIndexed = 0x1C8;
        }
    }
}
