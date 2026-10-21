#pragma once
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t ImageBase = 0X7FF69A1B0000;

    namespace Globals {
        constexpr uintptr_t LocalPlayer   = 0X1CC6FD8;
        constexpr uintptr_t HeroManager   = 0X1C88FB0;
        constexpr uintptr_t MinionManager = 0X1C8C440;
        constexpr uintptr_t TurretManager = 0X1C91BE0;
        constexpr uintptr_t ObjectManager = 0X1C88FF0; // AllUnits pool
        constexpr uintptr_t GameClient    = 0X1C8C428;
        constexpr uintptr_t GameTime      = 0X1C95618;
        constexpr uintptr_t ViewPort      = 0X1C8C418;
        constexpr uintptr_t HudInstance   = 0X1C89020;
        constexpr uintptr_t NavGrid       = 0X1C8C3B0;
        constexpr uintptr_t MissileManager= 0X1C8C450;
        constexpr uintptr_t ChampionManager=0X1CAA520;
    }

    namespace Functions {
        constexpr uintptr_t GetGoldRedirect = 0X214870;
        constexpr uintptr_t TranslateString = 0XF7F7B0;
        constexpr uintptr_t CDSPush         = 0X238310;
        constexpr uintptr_t CDSUpdate       = 0X21C1E0;
    }

    namespace GameObject {
        constexpr uintptr_t NetworkID       = 0X78;
        constexpr uintptr_t Position        = 0X15C;
        constexpr uintptr_t Team            = 0X158;
        constexpr uintptr_t Visible         = 0X208;
        constexpr uintptr_t Name            = 0X3890;
        constexpr uintptr_t AttackRange     = 0XFDC;
        constexpr uintptr_t BuffManager     = 0X25E8;
        constexpr uintptr_t MinionType      = 0X4B39;
        constexpr uintptr_t CharacterDataStack = 0X3638;
        constexpr uintptr_t Health          = 0X910;
        constexpr uintptr_t MaxHealth       = 0X938;
        constexpr uintptr_t Shield          = 0X9B0;
        constexpr uintptr_t MagicShield     = 0XA00;
        constexpr uintptr_t HealthObf       = 0X930;
        constexpr uintptr_t MaxHealthObf    = 0X958;
        constexpr uintptr_t ShieldObf       = 0X9D0;
        constexpr uintptr_t MagicShieldObf  = 0XA20;
        constexpr uintptr_t oPosition       = Position;
        constexpr uintptr_t oTeamID         = Team;
        constexpr uintptr_t oHealth         = Health;
        constexpr uintptr_t oMaxHealth      = MaxHealth;
        constexpr uintptr_t oName           = Name;
        constexpr uintptr_t oAttackRange    = AttackRange;
        constexpr uintptr_t oVisible        = Visible;
    }

    namespace Manager {
        constexpr uintptr_t List  = 0X8;
        constexpr uintptr_t Count = 0X10;
    }

    // Backward compatibility Standard namespace
    namespace Standard {
        namespace GameObject {
            using namespace Offsets::GameObject;
        }
        namespace Manager {
            using namespace Offsets::Manager;
        }
    }
}
