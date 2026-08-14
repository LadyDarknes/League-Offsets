#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0X7FF62DAE0000;

    namespace Globals {
        constexpr uintptr_t BlueMinionManager = 0X1EF4210;
        constexpr uintptr_t CastSpellFlag = 0X1E55E20;
        constexpr uintptr_t ChatClient = 0X1F2B490;
        constexpr uintptr_t ConnSlotSentinel = 0X1F33F94;
        constexpr uintptr_t EntityList = 0X1EF0ED0;
        constexpr uintptr_t GameClient = 0X1F0DFF8;
        constexpr uintptr_t GameTime = 0X1F00698;
        constexpr uintptr_t HeroManager = 0X1EF0E48;
        constexpr uintptr_t HudInstance = 0X1EF0EB8;
        constexpr uintptr_t IssueOrderFlag = 0X1E55E88;
        constexpr uintptr_t LocalPlayer = 0X1F304B0;
        constexpr uintptr_t MissileManager = 0X1EF4208;
        constexpr uintptr_t MouseScreenVec2 = 0X1EF4260;
        constexpr uintptr_t NavGrid = 0X1EF41F8;
        constexpr uintptr_t NetClient = 0X1EF0D20;
        constexpr uintptr_t NetInstance = 0X1EF0D38;
        constexpr uintptr_t ObjectManager = 0X1EF0D28;
        constexpr uintptr_t RedMinionManager = 0X1EF4218;
        constexpr uintptr_t SpellCastMap = 0X1F1CF30;
        constexpr uintptr_t SwapChain = 0X1F919D0;
        constexpr uintptr_t TimingTable = 0X1F35830;
        constexpr uintptr_t UnderMouseObj = 0X1EF44B8;
        constexpr uintptr_t ViewPort = 0X1EF4258;
        constexpr uintptr_t ZoomAnomalyLatch = 0X1F6D994;
        constexpr uintptr_t r3dRenderLayer = 0X1FD0A20;
        constexpr uintptr_t r3dRenderer = 0X1FD0A28;
        constexpr uintptr_t g_thread_device = 0X1FD0A48;
        constexpr uintptr_t g_current_x3d_device_override = 0X1FD0A48;
        constexpr uintptr_t g_x3d_d3d11_backend = 0X1FD0A48;
        constexpr uintptr_t g_d3dcompiler47_module = 0X1FD1208;
        constexpr uintptr_t g_D3DReflect = 0X1FD1210;
        constexpr uintptr_t TurretManager = 0X1EF0E50;
        constexpr uintptr_t ViewMatrixInstance = 0X1FBA090;
        constexpr uintptr_t X3DDeviceD3D11_vtable = 0X1B4F9D8;
    }

    namespace Functions {
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0X8CBED0;
        constexpr uintptr_t CanCast = 0X2D62D0;
        constexpr uintptr_t CastSpellPosition = 0X99A0B0;
        constexpr uintptr_t CastSpellSafe = 0XBD9750;
        constexpr uintptr_t CastSpellTarget = 0X99A850;
        constexpr uintptr_t CastSpellWrapper = 0X208010;
        constexpr uintptr_t CharacterDataStack__Push = 0X404760;
        constexpr uintptr_t CharacterDataStack__Update = 0X214D90;
        constexpr uintptr_t CharacterDataStackPush = 0X31D000;
        constexpr uintptr_t CharacterDataStackUpdate = 0X214D90;
        constexpr uintptr_t ComponentLookupFn = 0X11BE150;
        constexpr uintptr_t ComponentRegistry__Lookup = 0X259270;
        constexpr uintptr_t CurrentNodeIdx = 0X4A317;
        constexpr uintptr_t DistanceSq = 0X21E610;
        constexpr uintptr_t GameObject__IsType = 0X293FD0;
        constexpr uintptr_t GetAIManager = 0X270850;
        constexpr uintptr_t GetAttackDelay = 0X2988A0;
        constexpr uintptr_t GetAttackWindup = 0X58CFA0;
        constexpr uintptr_t GetBoundingRadius = 0X2823C0;
        constexpr uintptr_t GetCollisionFlags = 0X1280BF0;
        constexpr uintptr_t GetFirstObject = 0X574210;
        constexpr uintptr_t GetGoldRedirectTarget = 0X20D600;
        constexpr uintptr_t GetMapID = 0X17C6290;
        constexpr uintptr_t GetModelInstance = 0X2A2B60;
        constexpr uintptr_t GetNextObject = 0X574CD0;
        constexpr uintptr_t GetObjectByID = 0X573A10;
        constexpr uintptr_t GetPing = 0X6CF9B0;
        constexpr uintptr_t GetRenderPipeline = 0X499960;
        constexpr uintptr_t GetSpellCastInfo = 0X677890;
        constexpr uintptr_t GetSpellSlot = 0X995630;
        constexpr uintptr_t GetSubObjAiMgr = 0X576C80;
        constexpr uintptr_t IsAlive = 0X2C01A0;
        constexpr uintptr_t IsBuilding = 0XE170D0;
        constexpr uintptr_t IsHero = 0XC752D0;
        constexpr uintptr_t IsTurret = 0X2D63C0;
        constexpr uintptr_t IsVisible = 0X215B80;
        constexpr uintptr_t IssueOrderCore = 0X207C60;
        constexpr uintptr_t MinimapHudInit = 0X8CDEA0;
        constexpr uintptr_t MinimapMoveSelf = 0XBD41E0;
        constexpr uintptr_t NavAgent = 0X58C670;
        constexpr uintptr_t NavMesh__CreatePath = 0X20BDF0;
        constexpr uintptr_t OnCreateObject = 0X2B29E0;
        constexpr uintptr_t OnDeleteObject = 0X572E00;
        constexpr uintptr_t OnDoCast = 0X977E20;
        constexpr uintptr_t OnNewPath = 0X26EEB0;
        constexpr uintptr_t OnProcessSpell = 0X97C940;
        constexpr uintptr_t OnSpellImpact = 0X99A6C0;
        constexpr uintptr_t PrintChat = 0X1161AD0;
        constexpr uintptr_t ProjectAndClip = 0X1335010;
        constexpr uintptr_t QuestProgress__Calculate = 0X5152D0;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0X518B10;
        constexpr uintptr_t RemapBoneIndex = 0X436110;
        constexpr uintptr_t RoleBound__Init = 0XA1580;
        constexpr uintptr_t SpellSlot__Cast = 0X759F00;
        constexpr uintptr_t SpellSlot__GetCooldown = 0X8B5A40;
        constexpr uintptr_t SpellSlot__GetLevel = 0X3B839B;
        constexpr uintptr_t TransformVec3 = 0X1337050;
        constexpr uintptr_t TranslateString = 0X11BD840;
        constexpr uintptr_t UpdateCamera = 0X308350;
        constexpr uintptr_t WaypointCount = 0X26E9A0;
        constexpr uintptr_t WorldToScreen = 0X13350F0;
        constexpr uintptr_t fieldOfView = 0X308350;
        constexpr uintptr_t ClientMainLoop = 0X395FB0;
        constexpr uintptr_t OnWndProc = 0X120B2A0;
        constexpr uintptr_t OnStopCast = 0X97CE40;
        constexpr uintptr_t OnPlayAnimation = 0X2A2B60;
        constexpr uintptr_t BuffManagerClient__OnBuffAdd = 0X8CB370;
        constexpr uintptr_t IssueOrderPacketWrapper = 0X208010;
        constexpr uintptr_t GetThreadDevice = 0X13D0D50;
        constexpr uintptr_t X3DDeviceD3D11_Initialize = 0X13CDB00;
        constexpr uintptr_t X3DDeviceD3D11_Release = 0X13DD340;
        constexpr uintptr_t ConstantBuffer_CreateD3D11DynamicBuffer = 0X322A60;
        constexpr uintptr_t D3D11TextureView_CreateShaderResourceView = 0X23BAC0;
        constexpr uintptr_t DX11Backend_CreateDeviceAndSwapChain = 0X20BDF0;
        constexpr uintptr_t GraphicsPipelineD3D11_InitFromDesc = 0XB96990;
        constexpr uintptr_t X3DDeviceD3D11_SetGraphicsPipeline = 0X13D1110;
        constexpr uintptr_t X3DDeviceD3D11_CreateGraphicsPipeline = 0X13D27B0;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexBuffer = 0X13D0D60;
        constexpr uintptr_t X3DDeviceD3D11_CreateIndexBuffer = 0X13D72F0;
        constexpr uintptr_t X3DDeviceD3D11_CreateDataBuffer = 0X13D0D50;
        constexpr uintptr_t X3DDeviceD3D11_CreateTexture2D = 0X13D3520;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexProgram = 0X13E0EA0;
        constexpr uintptr_t X3DDeviceD3D11_CreatePixelProgram = 0X13E1040;
        constexpr uintptr_t X3DDeviceD3D11_CreateShaderProgram = 0X13E0FA0;
        constexpr uintptr_t X3DDeviceD3D11_ClearFramebuffer = 0X13DE280;
        constexpr uintptr_t X3DDeviceD3D11_BeginFrame = 0X13D3C70;
        constexpr uintptr_t X3DDeviceD3D11_EndFrame = 0X13D70C0;
        constexpr uintptr_t X3DDeviceD3D11_BeginRenderPass = 0X13D6540;
        constexpr uintptr_t X3DDeviceD3D11_EndRenderPass = 0X13D7180;
        constexpr uintptr_t X3DDeviceD3D11_IsRenderPassActive = 0X13D32D0;
        constexpr uintptr_t X3DDeviceD3D11_IsFrameActive = 0X13D6DE0;
        constexpr uintptr_t X3DDeviceD3D11_Draw = 0X13D5CB0;
        constexpr uintptr_t X3DDeviceD3D11_DrawIndexed = 0X13D5EB0;
        constexpr uintptr_t g_thread_device = 0X1FD0A48;
        constexpr uintptr_t g_x3d_d3d11_backend = 0X1FD0A48;
    }

    namespace Standard {
        namespace GameObject {
            constexpr uintptr_t oIndex = 0X20;
            constexpr uintptr_t oNetId = 0X20;
            constexpr uintptr_t oTeamID = 0X239;
            constexpr uintptr_t oName = 0X68;
            constexpr uintptr_t oNetworkID = 0XCC;
            constexpr uintptr_t oSourceNetworkId = 0xD4;
            constexpr uintptr_t oDead = 0x231;
            constexpr uintptr_t oEffectEmitterHandle = 0x238;
            constexpr uintptr_t oPosition = 0X23C;
            constexpr uintptr_t oDirection = 0x0;
            constexpr uintptr_t oVisibility = 0x2C0;
            constexpr uintptr_t oVisible = 0x2E8;
            constexpr uintptr_t oMissileClientHandle = 0x2B8;
            constexpr uintptr_t oTargetableComponent = 0x288;
            constexpr uintptr_t oPlayerStatsComponent = 0X2A8;
            constexpr uintptr_t oIsTargetable = 0XEB0;
            constexpr uintptr_t oTargetableState = 0XED8;
            constexpr uintptr_t oRadius = 0x6D8;
            constexpr uintptr_t oModelScaleComponent = 0X2C68;
            constexpr uintptr_t oAIManager = 0X40B0;
            constexpr uintptr_t oCharacterData = 0X48C8;
            constexpr uintptr_t oSpellBook = 0X3108;
            constexpr uintptr_t oCharacterName = 0X4378;
            constexpr uintptr_t oItemList = 0X4498;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t OFF_POS_X = 0x23C;
            constexpr uintptr_t OFF_POS_Y = 0x240;
            constexpr uintptr_t OFF_POS_Z = 0x244;
            constexpr uintptr_t OFF_VISIBLE_0 = 0X168;
            constexpr uintptr_t OFF_VISIBLE_FOG = 0X1;
            constexpr uintptr_t OFF_VISIBLE_ALT = 0x16A;
            constexpr uintptr_t OFF_HP = 0x1060;
            constexpr uintptr_t OFF_HP_MAX = 0x10B0;
            constexpr uintptr_t OFF_MANA = 0x340;
            constexpr uintptr_t OFF_MANA_MAX = 0x48;
            constexpr uintptr_t OFF_MANA_ENABLED = 0x1;
            constexpr uintptr_t OFF_LEVEL = 0x4D58;
            constexpr uintptr_t OFF_MOVE_SPEED = 0X500C;
            constexpr uintptr_t OFF_ARMOR = 0x4F38;
            constexpr uintptr_t OFF_MAGIC_RES = 0x4CB8;
            constexpr uintptr_t OFF_ALL_SHIELD = 0x1100;
            constexpr uintptr_t OFF_PHYS_SHIELD = 0x9;
            constexpr uintptr_t OFF_MAG_SHIELD = 0x1150;
            constexpr uintptr_t OFF_AS_MULTIPLIER = 0X80;
            constexpr uintptr_t OFF_ATK_RANGE = 0X7;
            constexpr uintptr_t OFF_BOUNDING_RADIUS = 0X578;
            constexpr uintptr_t OFF_SPELLBOOK = 0X3128;
            constexpr uintptr_t OFF_AIMANAGER_PTR = 0X4048;
            constexpr uintptr_t OFF_HEROCLIENT_PTR = 0X144;
            constexpr uintptr_t AbilityHaste = 0XB48;
            constexpr uintptr_t Armor = 0X2E8;
            constexpr uintptr_t AttackRange = 0X1;
            constexpr uintptr_t AttackSpeedMod = 0X1;
            constexpr uintptr_t BaseAttackDamage = 0X1F08;
            constexpr uintptr_t Crit = 0XAC8;
            constexpr uintptr_t CritDamageMultiplier = 0X528;
            constexpr uintptr_t FlatArmorPen = 0X868;
            constexpr uintptr_t FlatMagicPen = 0X1;
            constexpr uintptr_t FlatPhysicalDmgMod = 0X1;
            constexpr uintptr_t HPRegenRate = 0x2138;
            constexpr uintptr_t MP = 0X360;
            constexpr uintptr_t MagicLethality = 0X2368;
            constexpr uintptr_t MaxMP = 0X48;
            constexpr uintptr_t MoveSpeed = 0x2188;
            constexpr uintptr_t PercentArmorPen = 0X1;
            constexpr uintptr_t PercentAttackSpeedMod = 0X1;
            constexpr uintptr_t PercentBonusArmorPen = 0X22C8;
            constexpr uintptr_t PercentBonusMagicPen = 0x23B8;
            constexpr uintptr_t PercentCCReduction = 0X1088;
            constexpr uintptr_t PercentLifeSteal = 0XE88;
            constexpr uintptr_t PercentMagicPen = 0X828;
            constexpr uintptr_t PercentOmnivamp = 0XDC8;
            constexpr uintptr_t PercentSpellVamp = 0X2408;
            constexpr uintptr_t PhysicalLethality = 0X1EC;
            constexpr uintptr_t SpellBlock = 0x20E8;
            constexpr uintptr_t CharacterName = 0x4370;
            constexpr uintptr_t Name = 0x4370;
            constexpr uintptr_t AllShield = 0X1120;
            constexpr uintptr_t HP = 0X1080;
            constexpr uintptr_t IsTargetable = 0XED0;
            constexpr uintptr_t MagicalShield = 0X1170;
            constexpr uintptr_t MaxHP = 0X10D0;
            constexpr uintptr_t PhysicalShield = 0X9;
            constexpr uintptr_t TargetableFlags = 0X78;
            constexpr uintptr_t AbilityPower = 0X708;
            constexpr uintptr_t ActionState = 0X488;
            constexpr uintptr_t ActionState2 = 0X1068;
            constexpr uintptr_t ActionStateBase = 0X1470;
            constexpr uintptr_t BonusAttackDamage = 0X1;
            constexpr uintptr_t ChampionName = 0X1;
            constexpr uintptr_t CharData = 0X4030;
            constexpr uintptr_t CharacterActionState = 0x14C8;
            constexpr uintptr_t CharacterDataStack = 0X1;
            constexpr uintptr_t CharacterIntermediate = 0X810;
            constexpr uintptr_t CharacterState = 0X1;
            constexpr uintptr_t CombatStatsBase = 0X810;
            constexpr uintptr_t DirectionComponent = 0X1;
            constexpr uintptr_t DirectionVFunc = 0XA8;
            constexpr uintptr_t DirectionVector = 0X20;
            constexpr uintptr_t EvolvePoints = 0X908;
            constexpr uintptr_t FlatArmorPenetration = 0X868;
            constexpr uintptr_t FlatMagicPenetration = 0X328;
            constexpr uintptr_t Health = 0X1080;
            constexpr uintptr_t Index = 0X20;
            constexpr uintptr_t Inventory = 0X1;
            constexpr uintptr_t IsBotVFunc = 0X88;
            constexpr uintptr_t IsTargetableToTeamFlags = 0X78;
            constexpr uintptr_t IsVisible = 0X48;
            constexpr uintptr_t IsZombie = 0X3A;
            constexpr uintptr_t Mana = 0X360;
            constexpr uintptr_t MaxHealth = 0X10D0;
            constexpr uintptr_t MaxMana = 0X48;
            constexpr uintptr_t OverrideCollisionHeight = 0X88;
            constexpr uintptr_t OverrideCollisionRadius = 0X1;
            constexpr uintptr_t PARRegenRate = 0X688;
            constexpr uintptr_t PARState = 0X2E8;
            constexpr uintptr_t PathfindingCollisionRadius = 0X1;
            constexpr uintptr_t PathfindingRadiusMod = 0X748;
            constexpr uintptr_t PercentArmorPenetration = 0X3C8;
            constexpr uintptr_t PercentBonusArmorPenetration = 0X22C8;
            constexpr uintptr_t PercentBonusMagicPenetration = 0x23B8;
            constexpr uintptr_t PercentHealingAmountMod = 0X928;
            constexpr uintptr_t PercentLifeStealMod = 0XE88;
            constexpr uintptr_t PercentMagicDamageMod = 0X1;
            constexpr uintptr_t PercentMagicPenetration = 0X828;
            constexpr uintptr_t PercentOmnivampMod = 0XDC8;
            constexpr uintptr_t PercentPhysicalDamageMod = 0X308;
            constexpr uintptr_t PercentPhysicalVamp = 0X9A8;
            constexpr uintptr_t PercentSpellVampMod = 0X2E8;
            constexpr uintptr_t Position = 0X1;
            constexpr uintptr_t SelectionHeight = 0X88;
            constexpr uintptr_t SelectionRadius = 0X90;
            constexpr uintptr_t SkinName = 0x4370;
            constexpr uintptr_t StatusFlags = 0XB28;
            constexpr uintptr_t StatusFlagsInvulnerableMask = 0X1;
            constexpr uintptr_t Team = 0X239;
            constexpr uintptr_t FlatPhysicalDamageMod = 0X408;
        }
        namespace AIBaseClient {
            constexpr uintptr_t oCombatStats = 0X4430;
            constexpr uintptr_t oModelInstance = 0X44E0;
            constexpr uintptr_t oCharacterDataStack = 0X1270;
            constexpr uintptr_t oBuffManager = 0X2E78;
            constexpr uintptr_t oFacing = 0X1C0;
            constexpr uintptr_t oPetOwner = 0X4D28;
            constexpr uintptr_t oHeroInventoryClient = 0X4248;
            constexpr uintptr_t SkinId = 0X1314;
            constexpr uintptr_t CharacterData = 0X40E0;
            constexpr uintptr_t oCharacterDataStackBase = 0X110;
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
            constexpr uintptr_t ArrayBegin = 0X18;
            constexpr uintptr_t ArrayCapacity = 0X28;
            constexpr uintptr_t ArrayEnd = 0X20;
            constexpr uintptr_t BuffManager = 0X2E78;
            constexpr uintptr_t Count = 0X78;
            constexpr uintptr_t Duration = 0X20;
            constexpr uintptr_t EndTime = 0X1C;
            constexpr uintptr_t EntryBuffInstance = 0x0;
            constexpr uintptr_t EntryRefCount = 0X8;
            constexpr uintptr_t EntryStride = 0X10;
            constexpr uintptr_t InstanceVtable = 0x0;
            constexpr uintptr_t InstanceVtableOnClearFn = 0X10;
            constexpr uintptr_t InstanceVtableUpdateStackFn = 0X20;
            constexpr uintptr_t IsCleared = 0X88;
            constexpr uintptr_t LookupMap = 0X38;
            constexpr uintptr_t OwnerNameData = 0X8;
            constexpr uintptr_t OwnerNetworkId = 0X10;
            constexpr uintptr_t PointerArrayBegin = 0X48;
            constexpr uintptr_t PointerArrayCapacity = 0X58;
            constexpr uintptr_t PointerArrayEnd = 0X10;
            constexpr uintptr_t PointerArrayStride = 0X8;
            constexpr uintptr_t Script = 0X10;
            constexpr uintptr_t ScriptBuffType = 0X100;
            constexpr uintptr_t ScriptBuffTypeAlt = 0X101;
            constexpr uintptr_t ScriptName = 0X8;
            constexpr uintptr_t ScriptNameHash = 0X18;
            constexpr uintptr_t SourceNetworkId = 0X14;
            constexpr uintptr_t StackDataPtr = 0x0;
            constexpr uintptr_t StackDataSourceId = 0X4;
            constexpr uintptr_t StackStride = 0X10;
            constexpr uintptr_t StacksArray = 0X30;
            constexpr uintptr_t StacksCount = 0X38;
            constexpr uintptr_t StartTime = 0X18;
            constexpr uintptr_t StateArrayBegin = 0X70;
            constexpr uintptr_t StateArrayCapacity = 0X80;
            constexpr uintptr_t StateArrayEnd = 0X78;
            constexpr uintptr_t StateArrayStride = 0X68;
            constexpr uintptr_t Type = 0XC;
            constexpr uintptr_t Vtable = 0x0;
            constexpr uintptr_t VtableHasBuffOfTypeFn = 0X8;
            constexpr uintptr_t VtableUpdateStackFn = 0X20;
            constexpr uintptr_t Avatar = 0X50B8;
            constexpr uintptr_t BaseGoldGivenOnDeath = 0x55B8;
            constexpr uintptr_t CombatType = 0X6B0;
            constexpr uintptr_t Experience = 0x4D38;
            constexpr uintptr_t Level = 0x4D60;
            constexpr uintptr_t MinimumGold = 0x28B8;
            constexpr uintptr_t SkillUpLevelDelta = 0x4D88;
            constexpr uintptr_t SpellTrainingPoints = 0x4D88;
            constexpr uintptr_t AutobuildItemId = 0x57B0;
        }
        namespace CombatStats {
            constexpr uintptr_t mFlatAPMod = 0X1C;
            constexpr uintptr_t mBaseAD = 0X24;
            constexpr uintptr_t mLevel = 0X28;
            constexpr uintptr_t mAttackRange = 0X5C;
            constexpr uintptr_t mArmor = 0X118;
            constexpr uintptr_t mBonusArmor = 0X174;
            constexpr uintptr_t mSpellBlock = 0X25C;
            constexpr uintptr_t mAttackSpeedMod = 0X1A8;
            constexpr uintptr_t mCrit = 0X25C;
            constexpr uintptr_t mFlatADMod = 0X25C;
            constexpr uintptr_t mBonusSpellBlock = 0X200;
            constexpr uintptr_t mCombatType = 0X204;
            constexpr uintptr_t mMoveSpeed = 0X25C;
            constexpr uintptr_t oBuffManager = 0X2E78;
            constexpr uintptr_t oFacing = 0X1C0;
        }
        namespace MissileClient {
            constexpr uintptr_t CasterNetID = 0X30;
            constexpr uintptr_t TargetNetID = 0X34;
            constexpr uintptr_t StartPos = 0X24;
            constexpr uintptr_t EndPos = 0X30;
            constexpr uintptr_t Speed = 0X25C;
            constexpr uintptr_t CurrentPos = 0X1;
            constexpr uintptr_t oCasterNetID = 0X30;
            constexpr uintptr_t oTargetNetID = 0X34;
            constexpr uintptr_t oStartPos = 0X24;
            constexpr uintptr_t oEndPos = 0X30;
            constexpr uintptr_t oSpeed = 0X25C;
            constexpr uintptr_t CastEndPos = 0X0;
            constexpr uintptr_t CastInfoBase = 0X2C0;
            constexpr uintptr_t CasterIndex = 0X360;
            constexpr uintptr_t MissileName = 0X308;
            constexpr uintptr_t MissileNetId = 0X198;
            constexpr uintptr_t Position = 0X1;
            constexpr uintptr_t SpellDataPtr = 0X2C0;
            constexpr uintptr_t SpellName = 0X2E0;
            constexpr uintptr_t StartTime = 0X478;
            constexpr uintptr_t TargetIndex = 0X35C;
        }
        namespace SpellSlot {
            constexpr uintptr_t oLevel = 0X28;
            constexpr uintptr_t oCooldown = 0X30;
            constexpr uintptr_t oCharges = 0X64;
            constexpr uintptr_t oChargeCooldown = 0X68;
            constexpr uintptr_t oChargeLevel = 0X6C;
            constexpr uintptr_t oChargeStartTime = 0X74;
            constexpr uintptr_t ActiveSpellCast = 0X118;
            constexpr uintptr_t ChargeCooldownDuration = 0X6C;
            constexpr uintptr_t ChargeCooldownExpires = 0X68;
            constexpr uintptr_t Cooldown = 0X80;
            constexpr uintptr_t CooldownDuration = 0X74;
            constexpr uintptr_t CooldownExpires = 0X30;
            constexpr uintptr_t CooldownOverride = 0X88;
            constexpr uintptr_t Level = 0X28;
            constexpr uintptr_t MaxStacks = 0X64;
            constexpr uintptr_t Owner = 0X8;
            constexpr uintptr_t SlotType = 0X2;
            constexpr uintptr_t SpellInfo = 0X128;
            constexpr uintptr_t SpellInstanceVars = 0X108;
            constexpr uintptr_t SpellNameHash = 0X120;
            constexpr uintptr_t Stacks = 0X5C;
            constexpr uintptr_t Vtable = 0x0;
        }
        namespace SpellBook {
            constexpr uintptr_t oActiveSpellCast = 0X1F8;
            constexpr uintptr_t oSpellSlots = 0XAE0;
            constexpr uintptr_t OFF_SB_DELAY_PCT = 0X308;
            constexpr uintptr_t ActiveSpellCast = 0X38;
            constexpr uintptr_t LastSlot = 0X3F;
            constexpr uintptr_t MaxSlots = 0X40;
            constexpr uintptr_t SlotStride = 0X8;
            constexpr uintptr_t SpellBook = 0X3128;
            constexpr uintptr_t SpellSlotArray = 0XAE0;
        }
        namespace AIManager {
            constexpr uintptr_t oServerPos = 0X8;
            constexpr uintptr_t oVelocity = 0X18;
            constexpr uintptr_t oTargetPosition = 0X24;
            constexpr uintptr_t oNavPath = 0X40;
            constexpr uintptr_t AiManager = 0X144;
            constexpr uintptr_t CurrentSegment = 0XF;
            constexpr uintptr_t DashSpeed = 0X360;
            constexpr uintptr_t IsDashing = 0X120;
            constexpr uintptr_t IsMoving = 0X31C;
            constexpr uintptr_t MoveVec3 = 0X480;
            constexpr uintptr_t NavArray = 0X1;
            constexpr uintptr_t ObjectOffset = 0X144;
            constexpr uintptr_t PathState = 0XF;
            constexpr uintptr_t SegmentsCount = 0X48;
            constexpr uintptr_t ServerPos = 0X80;
            constexpr uintptr_t StartPath = 0X40;
            constexpr uintptr_t TargetPos = 0X14;
            constexpr uintptr_t TargetPosition = 0x33C;
            constexpr uintptr_t Velocity = 0X0;
        }
        namespace CameraData {
            constexpr uintptr_t oCamPos = 0X8;
            constexpr uintptr_t oCamRotation = 0X18;
            constexpr uintptr_t oCamAttached = 0X28;
            constexpr uintptr_t oCamMoveSpeed = 0X2C;
            constexpr uintptr_t oFieldOfView = 0X3C;
            constexpr uintptr_t oNearClip = 0X44;
            constexpr uintptr_t oFarClip = 0X4C;
            constexpr uintptr_t oFogOfWar = 0x5A;
        }
        namespace CharacterData {
            constexpr uintptr_t oSkinID = 0X14;
            constexpr uintptr_t OFF_CHARDATA_CAST_TIME = 0X25C;
            constexpr uintptr_t OFF_CHARDATA_DELAY_SCALE = 0X9C8;
        }
        namespace SpellData {
            constexpr uintptr_t oName = 0X28;
            constexpr uintptr_t InfoLevelOrFlag = 0X14;
            constexpr uintptr_t InfoOwnerSlot = 0X60;
            constexpr uintptr_t InfoSpellData = 0X8;
            constexpr uintptr_t ResourceData = 0X60;
            constexpr uintptr_t ResourceName = 0X28;
            constexpr uintptr_t Vtable = 0x0;
            constexpr uintptr_t VtableGetTargetingFn = 0X20;
        }
        namespace SpellDataResource {
            constexpr uintptr_t oMissileSpeed = 0X410;
            constexpr uintptr_t DataResourceBase = 0X60;
            constexpr uintptr_t ResAmmoRecharge = 0X1;
            constexpr uintptr_t ResCastRange = 0X478;
            constexpr uintptr_t ResCastRangeDisplayOverride = 0X1;
            constexpr uintptr_t ResCastType = 0X2;
            constexpr uintptr_t ResCooldownTime = 0X88;
            constexpr uintptr_t ResImgIconName = 0X1;
            constexpr uintptr_t ResLineWidth = 0X568;
            constexpr uintptr_t ResMaxAmmo = 0X3C0;
            constexpr uintptr_t ResMissileSpec = 0X560;
            constexpr uintptr_t ResMissileSpeed = 0X518;
            constexpr uintptr_t ResScriptName = 0X80;
        }
        namespace SkinResource {
            constexpr uintptr_t skin_id = 0x0;
            constexpr uintptr_t skin_name = 0X8;
        }
        namespace ChampionManager {
            constexpr uintptr_t champions = 0X18;
        }
        namespace ChampionResource {
            constexpr uintptr_t skins = 0XC8;
        }
        namespace HeroManager {
            constexpr uintptr_t OFF_HEROMGR_LIST = 0X8;
            constexpr uintptr_t OFF_HEROMGR_COUNT = 0X10;
        }
        namespace NavGrid {
            constexpr uintptr_t OFF_NAV_WIDTH = 0XF0;
            constexpr uintptr_t OFF_NAV_HEIGHT = 0X5E4;
            constexpr uintptr_t OFF_NAV_ORIGIN = 0X1;
            constexpr uintptr_t OFF_NAV_CELLSIZE = 0X348;
            constexpr uintptr_t OFF_NAV_DATA = 0X118;
            constexpr uintptr_t CellArray = 0X120;
            constexpr uintptr_t CellCenterOffset = 0X718;
            constexpr uintptr_t CellCountX = 0X1;
            constexpr uintptr_t CellCountZ = 0XB0;
            constexpr uintptr_t CellDataFlags = 0X6;
            constexpr uintptr_t CellDataPtr = 0x0;
            constexpr uintptr_t CellFlagBrush = 0X1;
            constexpr uintptr_t CellFlagBuilding = 0X40;
            constexpr uintptr_t CellFlagProp = 0X80;
            constexpr uintptr_t CellFlagSpecialRegionMask = 0XC00;
            constexpr uintptr_t CellFlagWall = 0X2;
            constexpr uintptr_t CellFlags = 0X8;
            constexpr uintptr_t CellSize = 0XF0;
            constexpr uintptr_t CellSizeInv = 0X5E4;
            constexpr uintptr_t CellStride = 0X10;
            constexpr uintptr_t Grid = 0X8;
            constexpr uintptr_t WorldMaxX = 0XF8;
            constexpr uintptr_t WorldMaxZ = 0X100;
            constexpr uintptr_t WorldMinX = 0XEC;
            constexpr uintptr_t WorldMinZ = 0X1;
        }
        namespace SpellCastInfo {
            constexpr uintptr_t HASHMAP_OFF_SENTINEL = 0X70;
            constexpr uintptr_t HASHMAP_OFF_BUCKETS = 0X80;
            constexpr uintptr_t HASHMAP_OFF_MASK = 0X98;
            constexpr uintptr_t NODE_OFF_NEXT = 0X8;
            constexpr uintptr_t NODE_OFF_KEY_STR = 0X10;
            constexpr uintptr_t NODE_OFF_KEY_HASH = 0X18;
            constexpr uintptr_t NODE_OFF_VALUE = 0X20;
        }
        namespace TimingPing {
            constexpr uintptr_t OFF_A1_CONN_SLOT = 0X423;
            constexpr uintptr_t OFF_A1_TREE_LINK = 0XC8;
            constexpr uintptr_t OFF_NODE_NEXT_LEFT = 0x000;
            constexpr uintptr_t OFF_NODE_NEXT_RIGHT = 0X10;
            constexpr uintptr_t OFF_NODE_END_FLAG = 0X19;
            constexpr uintptr_t OFF_NODE_KEY = 0X20;
            constexpr uintptr_t OFF_NODE_DATA = 0X28;
            constexpr uintptr_t OFF_DATA_RTT_A = 0X148;
            constexpr uintptr_t OFF_DATA_RTT_B = 0X1;
            constexpr uintptr_t TIMING_STRIDE_QWORDS = 0X21;
        }
        namespace CharacterDataStack {
            constexpr uintptr_t ActiveGear = 0XB0;
            constexpr uintptr_t ActiveModel = 0X18;
            constexpr uintptr_t ActiveSkinId = 0X38;
            constexpr uintptr_t Stack = 0x0;
            constexpr uintptr_t StackCapacity = 0X10;
            constexpr uintptr_t StackEnd = 0X8;
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
        namespace Camera {
            constexpr uintptr_t Position = 0x25C;
            constexpr uintptr_t Rotation = 0x18;
            constexpr uintptr_t fieldOfView = 0x749A00;
            constexpr uintptr_t nearClip = 0x44;
            constexpr uintptr_t farClip = 0x4C;
            constexpr uintptr_t OFF_VIEW_MTX = 0x1E4;
            constexpr uintptr_t OFF_PROJ_MTX = 0x224;
            constexpr uintptr_t camMgr_to_camEnt = 0x2F8;
            constexpr uintptr_t camMgr_to_viewport = 0x300;
            constexpr uintptr_t OFF_CAM_POS = 0x10;
            constexpr uintptr_t OFF_CAM_ROT = 0x40;
            constexpr uintptr_t OFF_CAM_FOV = 0x1DC;
            constexpr uintptr_t OFF_CAM_NEAR_CLIP = 0x1F4;
            constexpr uintptr_t OFF_CAM_FAR_CLIP = 0x1F8;
        }
        namespace TFT {
            constexpr uintptr_t OFF_TFT_ENTITY_SIZE = 0x1D8;
            constexpr uintptr_t OFF_TFT_GOLD = 0x2830;
            constexpr uintptr_t OFF_TFT_EXP = 0x4CE8;
            constexpr uintptr_t OFF_TFT_LEVEL = 0x4D10;
        }
        namespace Misc {
            constexpr uintptr_t EntityList_stride = 472;
            constexpr uintptr_t SPELLSLOT_MAX_IDX = 63;
        }
    }
}