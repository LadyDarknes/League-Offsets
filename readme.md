<h1 align="center">League — Offset & Pattern Database</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Patch-26.18-blue?style=flat-square" alt="Patch" />
  <img src="https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square" alt="Arch" />
  <img src="https://img.shields.io/badge/Tool-IDA%20Pro%209.4-orange?style=flat-square" alt="Tool" />
  <img src="https://img.shields.io/badge/Status-up_to_date-brightgreen?style=flat-square" alt="Status" />
</p>

<p align="center">
  <strong>Star For Support ⭐</strong><br>
  RVA offsets, AOB patterns, and structure layouts manually reversed from the game client.
</p>

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.hpp            ← generated C++ header file for ready inclusion
│   ├── offsets.json           ← JSON dump of resolved RVAs & member offsets
│   └── quick_usage/           
│       └── all_offsets.hpp    ← unified single header containing all C++ snippets & types
```

## Memory & Offset Architecture Tree

```mermaid
flowchart LR
    subgraph Managers ["Managers & Globals"]
        direction TB
        LP["LocalPlayer (0x1FBC8A8)"]
        OM["ObjectManager (0x1F78B18)<br/>+0x38 TreeHead<br/>+0x08 TreeRoot"]
        EM["EntityManagers<br/>Hero: 0x1F78C38<br/>Minion: 0x1F78C78<br/>Turret: 0x1F78C40"]
        MM["MissileManager (0x1F7BF50)<br/>+0x48 ActiveMissileMap"]
        VP["ViewPort & Camera (0x1F7BF00)<br/>+0x1E4 ViewMatrix<br/>+0x224 ProjMatrix"]
        HUD["HudInstance (0x1F78CA8)<br/>+0x60 ChatClient (+0x671)"]
    end

    subgraph Entities ["Core Entities"]
        direction TB
        GO["GameObject (Base)<br/>+0x20 Index<br/>+0xBC NetworkID<br/>+0x231 IsDead<br/>+0x239 Team<br/>+0x23C Position<br/>+0x2E8 Visible<br/>+0x340 Mana / +0x368 Max<br/>+0x1060 Health / +0x1088 Max<br/>+0x10E0 IsTargetable<br/>+0x1CE0 BonusAD / +0x1EE8 BaseAD<br/>+0x1E48 AttackSpeed<br/>+0x2078 Armor / +0x20C8 MR<br/>+0x21B8 AttackRange<br/>+0x41E8 Name"]
        MC["MissileClient<br/>+0xBC NetworkID<br/>+0x239 Team<br/>+0x23C Position<br/>+0x2C0 SpellName<br/>+0x340 CasterNetID<br/>+0x370 StartPos<br/>+0x37C EndPos<br/>+0x388 CastPos<br/>+0x3B0 TargetNetID"]
    end

    subgraph Components ["Internal Components"]
        direction TB
        SB["SpellBook<br/>+0x38 ActiveSpellCast<br/>+0x308 DelayPct<br/>+0xAE0 SpellSlots[]<br/>+0xF10 LastCastTime<br/>+0xF18 LastCastSlot"]
        NAV["Navigation & Pathing<br/>+0x4058 XorKeyTable<br/>+0x4060 Wrapper Array<br/>+0x4083 ActiveSlotIndex<br/>+0x10 PathController<br/>+0x320 CurrentWaypoint<br/>+0x348 WaypointArray<br/>+0x350 WaypointCount<br/>+0x474 ServerPos"]
        BM["BuffManager<br/>+0x18 ArrayStart<br/>+0x20 ArrayEnd"]
        CS["CharacterStats (0x1B78)<br/>+0x28 AbilityHasteMod<br/>+0x168 FlatBonusAD<br/>+0x208 AbilityPower<br/>+0x370 BaseAD<br/>+0x5F0 MoveSpeed"]
    end

    subgraph SubComponents ["Sub-Structures"]
        direction TB
        SCI["SpellCastInfo<br/>+0x08 SpellData<br/>+0x28 SpellName<br/>+0x50 Level<br/>+0xD8 StartPos<br/>+0xE4 EndPos<br/>+0xF0 CastPos<br/>+0x128 CastDelay<br/>+0x15C SlotID<br/>+0x1A4 EndTime"]
        SLOT["SpellSlot<br/>+0x28 Level<br/>+0x30 CooldownExpire<br/>+0x34 CastStartTime<br/>+0x5C Ammo<br/>+0x74 TotalCooldown<br/>+0x8C Charges<br/>+0xF4 SlotID<br/>+0x130 SpellData"]
        BE["BuffEntry<br/>+0x10 Script<br/>+0x1C ExpireTime<br/>+0x38 StartTime<br/>+0x88 IsPermanent<br/>+0x8C Stacks"]
        BS["BuffScript<br/>+0x08 BuffName<br/>+0x18 BuffNameAlt"]
    end

    subgraph DataEngine ["Spell Data Engine"]
        direction TB
        SD["SpellData<br/>+0x28 SpellName<br/>+0x60 SpellInfo"]
        SDR["SpellDataResource<br/>+0x3F8 MissileSpeed<br/>+0x448 LineWidth<br/>+0x6D8 BaseCost<br/>+0x6F0 CooldownTime<br/>+0x760 CastRange<br/>+0x7B4 CastRadius"]
    end

    LP -->|points to| GO
    OM -->|NodeValue +0x28| GO
    EM -->|List[i] +0x08| GO
    MM -->|ActiveMissileMap +0x48| MC

    GO -->|+0x3110| SB
    GO -->|+0x4058 / +0x4060| NAV
    GO -->|+0x2E60| BM
    GO -->|+0x1B78| CS

    SB -->|+0x38| SCI
    SB -->|+0xAE0| SLOT
    SLOT -->|+0x130| SD
    SCI -->|+0x08| SD
    MC -->|+0x2A0| SD
    SD -->|+0x60| SDR

    BM -->|ArrayStart[i]| BE
    BE -->|+0x10| BS
```


## Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.18 (16.18.idk.rest.of.it) |
| Timestamp | `6A9BBDC4` — Sat Sep 05 06:59:16 2026 UTC |
| Imagebase | `7FF7EA4F0000` |
| Compiler | Visual C++ · x64 PE |

---

## Contact
Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.
