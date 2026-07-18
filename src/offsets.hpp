#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0X7FF736E70000;

    namespace Globals {
        constexpr uintptr_t BlueMinionManager = 0X1ED9FB0;
        constexpr uintptr_t CastSpellFlag = 0X1E3BD60;
        constexpr uintptr_t ChatClient = 0X1F10F28;
        constexpr uintptr_t ConnSlotSentinel = 0X1F192D4;
        constexpr uintptr_t EntityList = 0X1ED6E40;
        constexpr uintptr_t GameClient = 0X1EF37E8;
        constexpr uintptr_t GameTime = 0X1EE5D30;
        constexpr uintptr_t HeroManager = 0X1ED6DB8;
        constexpr uintptr_t HudInstance = 0X1ED6E28;
        constexpr uintptr_t IssueOrderFlag = 0X1E3BDC8;
        constexpr uintptr_t LocalPlayer = 0X1F15390;
        constexpr uintptr_t MissileManager = 0X1ED9FC0;
        constexpr uintptr_t MouseScreenVec2 = 0X1ED9F70;
        constexpr uintptr_t NavGrid = 0X1ED9F08;
        constexpr uintptr_t NetClient = 0X1ED6C90;
        constexpr uintptr_t NetInstance = 0X1ED6CA8;
        constexpr uintptr_t ObjectManager = 0X1ED6C98;
        constexpr uintptr_t RedMinionManager = 0X1ED9FB8;
        constexpr uintptr_t SpellCastMap = 0X1F010D0;
        constexpr uintptr_t SwapChain = 0X1F765C0;
        constexpr uintptr_t TimingTable = 0X1F1A810;
        constexpr uintptr_t UnderMouseObj = 0X1EDA1B8;
        constexpr uintptr_t ViewPort = 0X1ED9F68;
        constexpr uintptr_t ZoomAnomalyLatch = 0X1F528D4;
        constexpr uintptr_t r3dRenderLayer = 0X1FB42E0;
        constexpr uintptr_t r3dRenderer = 0X1FB65D8;
        constexpr uintptr_t g_thread_device = 0X1FB42F0;
        constexpr uintptr_t g_current_x3d_device_override = 0X1F765C0;
        constexpr uintptr_t g_x3d_d3d11_backend = 0X1FB4310;
        constexpr uintptr_t g_d3dcompiler47_module = 0x1F7B1F0;
        constexpr uintptr_t g_D3DReflect = 0x1F7B1F8;
        constexpr uintptr_t TurretManager = 0X1EDE7A0;
        constexpr uintptr_t ViewMatrixInstance = 0X1F9E520;
        constexpr uintptr_t X3DDeviceD3D11_vtable = 0x1B00890;
    }

    namespace Functions {
        constexpr uintptr_t BuffManagerClient__OnBuffRemove = 0X92FE10;
        constexpr uintptr_t CanCast = 0X2C5950;
        constexpr uintptr_t CastSpellPosition = 0X988810;
        constexpr uintptr_t CastSpellSafe = 0XBE3300;
        constexpr uintptr_t CastSpellTarget = 0X987F30;
        constexpr uintptr_t CastSpellWrapper = 0X2036E0;
        constexpr uintptr_t CharacterDataStack__Push = 0X3F4900;
        constexpr uintptr_t CharacterDataStack__Update = 0X3F57A0;
        constexpr uintptr_t CharacterDataStackPush = 0X309F40;
        constexpr uintptr_t CharacterDataStackUpdate = 0X210460;
        constexpr uintptr_t ComponentLookupFn = 0X11BAEE0;
        constexpr uintptr_t ComponentRegistry__Lookup = 0x11AA460;
        constexpr uintptr_t CurrentNodeIdx = 0X3906F;
        constexpr uintptr_t DistanceSq = 0X219DE0;
        constexpr uintptr_t GameObject__IsType = 0X288420;
        constexpr uintptr_t GetAIManager = 0x276E70;
        constexpr uintptr_t GetAttackDelay = 0X28C0B0;
        constexpr uintptr_t GetAttackWindup = 0X576A80;
        constexpr uintptr_t GetBoundingRadius = 0X278170;
        constexpr uintptr_t GetCollisionFlags = 0X127BAB0;
        constexpr uintptr_t GetFirstObject = 0X556900;
        constexpr uintptr_t GetGoldRedirectTarget = 0X208CD0;
        constexpr uintptr_t GetMapID = 0X17B15A0;
        constexpr uintptr_t GetModelInstance = 0X2951A0;
        constexpr uintptr_t GetNextObject = 0X557750;
        constexpr uintptr_t GetObjectByID = 0X555D10;
        constexpr uintptr_t GetPing = 0X6D1680;
        constexpr uintptr_t GetRenderPipeline = 0X4BA5E0;
        constexpr uintptr_t GetSpellCastInfo = 0X67A640;
        constexpr uintptr_t GetSpellSlot = 0X977B50;
        constexpr uintptr_t GetSubObjAiMgr = 0X55C850;
        constexpr uintptr_t IsAlive = 0X2B0CE0;
        constexpr uintptr_t IsBuilding = 0XE15A80;
        constexpr uintptr_t IsHero = 0XC7E3C0;
        constexpr uintptr_t IsTurret = 0X2C5A40;
        constexpr uintptr_t IsVisible = 0X211330;
        constexpr uintptr_t IssueOrderCore = 0X289BF0;
        constexpr uintptr_t MinimapHudInit = 0X931E50;
        constexpr uintptr_t MinimapMoveSelf = 0X59FAB0;
        constexpr uintptr_t NavAgent = 0X5944D0;
        constexpr uintptr_t NavMesh__CreatePath = 0X2074C0;
        constexpr uintptr_t OnCreateObject = 0X2A4C00;
        constexpr uintptr_t OnDeleteObject = 0X553D00;
        constexpr uintptr_t OnDoCast = 0X989150;
        constexpr uintptr_t OnNewPath = 0x2E5960;
        constexpr uintptr_t OnProcessSpell = 0X98EF00;
        constexpr uintptr_t OnSpellImpact = 0X987520;
        constexpr uintptr_t PrintChat = 0X115F3D0;
        constexpr uintptr_t ProjectAndClip = 0X1327FF0;
        constexpr uintptr_t QuestProgress__Calculate = 0X525E40;
        constexpr uintptr_t QuestProgress__GetQuestValue = 0X52A000;
        constexpr uintptr_t RemapBoneIndex = 0X2CBA00;
        constexpr uintptr_t RoleBound__Init = 0XA1580;
        constexpr uintptr_t SpellSlot__Cast = 0X75A980;
        constexpr uintptr_t SpellSlot__GetCooldown = 0X921B10;
        constexpr uintptr_t SpellSlot__GetLevel = 0X3ADA5B;
        constexpr uintptr_t TransformVec3 = 0X132A030;
        constexpr uintptr_t TranslateString = 0X11BA5C0;
        constexpr uintptr_t UpdateCamera = 0X2F85F0;
        constexpr uintptr_t WaypointCount = 0X398B0;
        constexpr uintptr_t WorldToScreen = 0X13280D0;
        constexpr uintptr_t fieldOfView = 0X72AC60;
        constexpr uintptr_t ClientMainLoop = 0X5F5F00;
        constexpr uintptr_t OnWndProc = 0X9808A0;
        constexpr uintptr_t OnStopCast = None;
        constexpr uintptr_t OnPlayAnimation = None;
        constexpr uintptr_t BuffManagerClient__OnBuffAdd = 0X92F290;
        constexpr uintptr_t IssueOrderPacketWrapper = None;
        constexpr uintptr_t GetThreadDevice = 0X13CA650;
        constexpr uintptr_t X3DDeviceD3D11_Initialize = 0X13BA0E0;
        constexpr uintptr_t X3DDeviceD3D11_Release = 0X20D8D0;
        constexpr uintptr_t ConstantBuffer_CreateD3D11DynamicBuffer = 0X381790;
        constexpr uintptr_t D3D11TextureView_CreateShaderResourceView = 0X30A4F0;
        constexpr uintptr_t DX11Backend_CreateDeviceAndSwapChain = 0X2074C0;
        constexpr uintptr_t GraphicsPipelineD3D11_InitFromDesc = 0XBA1120;
        constexpr uintptr_t X3DDeviceD3D11_SetGraphicsPipeline = 0X13C00D0;
        constexpr uintptr_t X3DDeviceD3D11_CreateGraphicsPipeline = 0X13C2430;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexBuffer = 0X4ABB20;
        constexpr uintptr_t X3DDeviceD3D11_CreateIndexBuffer = 0X1EA4B0;
        constexpr uintptr_t X3DDeviceD3D11_CreateDataBuffer = 0X13C2280;
        constexpr uintptr_t X3DDeviceD3D11_CreateTexture2D = 0X843FD0;
        constexpr uintptr_t X3DDeviceD3D11_CreateVertexProgram = 0X13C3090;
        constexpr uintptr_t X3DDeviceD3D11_CreatePixelProgram = 0X13C2EE0;
        constexpr uintptr_t X3DDeviceD3D11_CreateShaderProgram = 0X451930;
        constexpr uintptr_t X3DDeviceD3D11_ClearFramebuffer = 0XB5D7F0;
        constexpr uintptr_t X3DDeviceD3D11_BeginFrame = 0X13BE7A0;
        constexpr uintptr_t X3DDeviceD3D11_EndFrame = 0X4FE090;
        constexpr uintptr_t X3DDeviceD3D11_BeginRenderPass = 0X13BE860;
        constexpr uintptr_t X3DDeviceD3D11_EndRenderPass = 0X13C5E10;
        constexpr uintptr_t X3DDeviceD3D11_IsRenderPassActive = 0X284740;
        constexpr uintptr_t X3DDeviceD3D11_IsFrameActive = 0X284740;
        constexpr uintptr_t X3DDeviceD3D11_Draw = 0X13CC5B0;
        constexpr uintptr_t X3DDeviceD3D11_DrawIndexed = 0X13CC5B0;
        constexpr uintptr_t g_thread_device = 0x13BA550;
        constexpr uintptr_t g_x3d_d3d11_backend = 0x13B8690;
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
            constexpr uintptr_t oAIManager = 0X4050;
            constexpr uintptr_t oCharacterData = 0X48C8;
            constexpr uintptr_t oSpellBook = 0X3108;
            constexpr uintptr_t oCharacterName = 0X40E8;
            constexpr uintptr_t oItemList = 0X44A0;
            constexpr uintptr_t oCharacterDataStack = 0x1270;
            constexpr uintptr_t OFF_POS_X = 0x23C;
            constexpr uintptr_t OFF_POS_Y = 0x240;
            constexpr uintptr_t OFF_POS_Z = 0x244;
            constexpr uintptr_t OFF_VISIBLE_0 = 0X168;
            constexpr uintptr_t OFF_VISIBLE_FOG = 0X1;
            constexpr uintptr_t OFF_VISIBLE_ALT = 0x16A;
            constexpr uintptr_t OFF_HP = 0x1060;
            constexpr uintptr_t OFF_HP_MAX = 0X1088;
            constexpr uintptr_t OFF_MANA = 0x340;
            constexpr uintptr_t OFF_MANA_MAX = 0x48;
            constexpr uintptr_t OFF_MANA_ENABLED = 0x1;
            constexpr uintptr_t OFF_LEVEL = 0X4D70;
            constexpr uintptr_t OFF_MOVE_SPEED = 0X2168;
            constexpr uintptr_t OFF_ARMOR = 0X2078;
            constexpr uintptr_t OFF_MAGIC_RES = 0X20C8;
            constexpr uintptr_t OFF_ALL_SHIELD = 0x1100;
            constexpr uintptr_t OFF_PHYS_SHIELD = 0X1128;
            constexpr uintptr_t OFF_MAG_SHIELD = 0x1150;
            constexpr uintptr_t OFF_AS_MULTIPLIER = 0X1E48;
            constexpr uintptr_t OFF_ATK_RANGE = 0X21B8;
            constexpr uintptr_t OFF_BOUNDING_RADIUS = 0X1;
            constexpr uintptr_t OFF_SPELLBOOK = 0X3108;
            constexpr uintptr_t OFF_AIMANAGER_PTR = 0X4050;
            constexpr uintptr_t OFF_HEROCLIENT_PTR = 0X144;
            constexpr uintptr_t AbilityHaste = 0X1BA0;
            constexpr uintptr_t Armor = 0X2078;
            constexpr uintptr_t AttackRange = 0X21B8;
            constexpr uintptr_t AttackSpeedMod = 0X1E48;
            constexpr uintptr_t BaseAttackDamage = 0X1EE8;
            constexpr uintptr_t Crit = 0X2028;
            constexpr uintptr_t CritDamageMultiplier = 0X1FB0;
            constexpr uintptr_t FlatArmorPen = 0X2230;
            constexpr uintptr_t FlatMagicPen = 0X2320;
            constexpr uintptr_t FlatPhysicalDmgMod = 0X1CE0;
            constexpr uintptr_t HPRegenRate = 0X2118;
            constexpr uintptr_t MP = 0X360;
            constexpr uintptr_t MagicLethality = 0X2348;
            constexpr uintptr_t MaxMP = 0X48;
            constexpr uintptr_t MoveSpeed = 0X2168;
            constexpr uintptr_t PercentArmorPen = 0X2280;
            constexpr uintptr_t PercentAttackSpeedMod = 0X1E70;
            constexpr uintptr_t PercentBonusArmorPen = 0X22A8;
            constexpr uintptr_t PercentBonusMagicPen = 0X2398;
            constexpr uintptr_t PercentCCReduction = 0X2488;
            constexpr uintptr_t PercentLifeSteal = 0X23C0;
            constexpr uintptr_t PercentMagicPen = 0X2370;
            constexpr uintptr_t PercentOmnivamp = 0X2410;
            constexpr uintptr_t PercentSpellVamp = 0X23E8;
            constexpr uintptr_t PhysicalLethality = 0X2258;
            constexpr uintptr_t SpellBlock = 0X20C8;
            constexpr uintptr_t CharacterName = 0X40E8;
            constexpr uintptr_t Name = 0X40E8;
            constexpr uintptr_t AllShield = 0X1100;
            constexpr uintptr_t HP = 0X1060;
            constexpr uintptr_t IsTargetable = 0XED0;
            constexpr uintptr_t MagicalShield = 0X1150;
            constexpr uintptr_t MaxHP = 0X1088;
            constexpr uintptr_t PhysicalShield = 0X1128;
            constexpr uintptr_t TargetableFlags = 0X0;
            constexpr uintptr_t AbilityPower = 0X708;
            constexpr uintptr_t ActionState = 0X488;
            constexpr uintptr_t ActionState2 = 0X1068;
            constexpr uintptr_t ActionStateBase = 0X1470;
            constexpr uintptr_t BonusAttackDamage = 0X1;
            constexpr uintptr_t ChampionName = 0X1;
            constexpr uintptr_t CharData = 0X4038;
            constexpr uintptr_t CharacterActionState = 0x14C8;
            constexpr uintptr_t CharacterDataStack = 0X1;
            constexpr uintptr_t CharacterIntermediate = 0X810;
            constexpr uintptr_t CharacterState = 0X1;
            constexpr uintptr_t CombatStatsBase = 0X810;
            constexpr uintptr_t DirectionComponent = 0X1;
            constexpr uintptr_t DirectionVFunc = 0XA8;
            constexpr uintptr_t DirectionVector = 0X20;
            constexpr uintptr_t EvolvePoints = 0X908;
            constexpr uintptr_t FlatArmorPenetration = 0X2230;
            constexpr uintptr_t FlatMagicPenetration = 0X2320;
            constexpr uintptr_t Health = 0X1060;
            constexpr uintptr_t Index = 0X20;
            constexpr uintptr_t Inventory = 0X1;
            constexpr uintptr_t IsBotVFunc = 0X88;
            constexpr uintptr_t IsTargetableToTeamFlags = 0X0;
            constexpr uintptr_t IsVisible = 0X48;
            constexpr uintptr_t IsZombie = 0X3A;
            constexpr uintptr_t Mana = 0X360;
            constexpr uintptr_t MaxHealth = 0X1088;
            constexpr uintptr_t MaxMana = 0X48;
            constexpr uintptr_t OverrideCollisionHeight = 0X88;
            constexpr uintptr_t OverrideCollisionRadius = 0X1;
            constexpr uintptr_t PARRegenRate = 0X2528;
            constexpr uintptr_t PARState = 0X2E8;
            constexpr uintptr_t PathfindingCollisionRadius = 0X1;
            constexpr uintptr_t PathfindingRadiusMod = 0X2460;
            constexpr uintptr_t PercentArmorPenetration = 0X2280;
            constexpr uintptr_t PercentBonusArmorPenetration = 0X22A8;
            constexpr uintptr_t PercentBonusMagicPenetration = 0X2398;
            constexpr uintptr_t PercentHealingAmountMod = 0X1EC0;
            constexpr uintptr_t PercentLifeStealMod = 0X23C0;
            constexpr uintptr_t PercentMagicDamageMod = 0X1DA8;
            constexpr uintptr_t PercentMagicPenetration = 0X2370;
            constexpr uintptr_t PercentOmnivampMod = 0X2410;
            constexpr uintptr_t PercentPhysicalDamageMod = 0X1D08;
            constexpr uintptr_t PercentPhysicalVamp = 0X2438;
            constexpr uintptr_t PercentSpellVampMod = 0X23E8;
            constexpr uintptr_t Position = 0X1;
            constexpr uintptr_t SelectionHeight = 0X88;
            constexpr uintptr_t SelectionRadius = 0X8C;
            constexpr uintptr_t SkinName = 0x4370;
            constexpr uintptr_t StatusFlags = 0XB28;
            constexpr uintptr_t StatusFlagsInvulnerableMask = 0X1;
            constexpr uintptr_t Team = 0X239;
            constexpr uintptr_t FlatPhysicalDamageMod = 0X1CE0;
        }
        namespace AIBaseClient {
            constexpr uintptr_t oCombatStats = 0X1B78;
            constexpr uintptr_t oModelInstance = 0X44E8;
            constexpr uintptr_t oCharacterDataStack = 0X1270;
            constexpr uintptr_t oBuffManager = 0X2E58;
            constexpr uintptr_t oFacing = 0X1C0;
            constexpr uintptr_t oPetOwner = 0X4D28;
            constexpr uintptr_t oHeroInventoryClient = 0X4250;
            constexpr uintptr_t SkinId = 0X1314;
            constexpr uintptr_t CharacterData = 0X40E8;
            constexpr uintptr_t oCharacterDataStackBase = 0X110;
            constexpr uintptr_t BaseGoldOnDeath = 0x55B8;
            constexpr uintptr_t Exp = 0X4D48;
            constexpr uintptr_t Gold = 0x2868;
            constexpr uintptr_t GoldTotal = 0x2890;
            constexpr uintptr_t LevelRef = 0X4D70;
            constexpr uintptr_t LevelUpPoints = 0x4D88;
            constexpr uintptr_t NeutralMinionsKilled = 0x55E0;
            constexpr uintptr_t RuneManager = 0x50E8;
            constexpr uintptr_t ShutdownValue = 0x5590;
            constexpr uintptr_t VisionScore = 0x5568;
            constexpr uintptr_t ArrayBegin = 0X2F00;
            constexpr uintptr_t ArrayCapacity = 0X28;
            constexpr uintptr_t ArrayEnd = 0X2F08;
            constexpr uintptr_t BuffManager = 0X2E58;
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
            constexpr uintptr_t Experience = 0X4D48;
            constexpr uintptr_t Level = 0X4D70;
            constexpr uintptr_t MinimumGold = 0x28B8;
            constexpr uintptr_t SkillUpLevelDelta = 0x4D88;
            constexpr uintptr_t SpellTrainingPoints = 0x4D88;
            constexpr uintptr_t AutobuildItemId = 0x57B0;
        }
        namespace CombatStats {
            constexpr uintptr_t mFlatAPMod = 0X1C;
            constexpr uintptr_t mBaseAD = 0X370;
            constexpr uintptr_t mLevel = 0X28;
            constexpr uintptr_t mAttackRange = 0X640;
            constexpr uintptr_t mArmor = 0X500;
            constexpr uintptr_t mBonusArmor = 0X528;
            constexpr uintptr_t mSpellBlock = 0X550;
            constexpr uintptr_t mAttackSpeedMod = 0X2D0;
            constexpr uintptr_t mCrit = 0X4B0;
            constexpr uintptr_t mFlatADMod = 0X25C;
            constexpr uintptr_t mBonusSpellBlock = 0X578;
            constexpr uintptr_t mCombatType = 0X204;
            constexpr uintptr_t mMoveSpeed = 0X5F0;
            constexpr uintptr_t oBuffManager = 0X2E58;
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
            constexpr uintptr_t CastEndPos = 0X30;
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
            constexpr uintptr_t SlotType = 0X31;
            constexpr uintptr_t SpellInfo = 0X128;
            constexpr uintptr_t SpellInstanceVars = 0X108;
            constexpr uintptr_t SpellNameHash = 0X120;
            constexpr uintptr_t Stacks = 0X5C;
            constexpr uintptr_t Vtable = 0x0;
        }
        namespace SpellBook {
            constexpr uintptr_t oActiveSpellCast = 0X1F8;
            constexpr uintptr_t oSpellSlots = 0XC0;
            constexpr uintptr_t OFF_SB_DELAY_PCT = 0X308;
            constexpr uintptr_t ActiveSpellCast = 0X38;
            constexpr uintptr_t LastSlot = 0X3F;
            constexpr uintptr_t MaxSlots = 0X40;
            constexpr uintptr_t SlotStride = 0X28;
            constexpr uintptr_t SpellBook = 0X3108;
            constexpr uintptr_t SpellSlotArray = 0XC0;
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
            constexpr uintptr_t StartPath = 0X0;
            constexpr uintptr_t TargetPos = 0X14;
            constexpr uintptr_t TargetPosition = 0x33C;
            constexpr uintptr_t Velocity = 0X18;
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
            constexpr uintptr_t ResCastType = 0X31;
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
            constexpr uintptr_t ActiveGear = 0X1;
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
            constexpr uintptr_t OFF_VIEW_MTX = 0x1A4;
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