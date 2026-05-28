// Classification & Type Checking (TypeFlags)

typedef bool(__fastcall* is_type_t)(void* obj, uint32_t flag);
is_type_t is_type = (is_type_t)(base_addr + 0x263150);

// Usage:
bool is_hero = is_type(obj, 0x1000);   // TypeHero = 0x1000
bool is_turret = is_type(obj, 0x2000); // TypeTurret = 0x2000
bool is_minion = is_type(obj, 0x800);  // TypeMinion = 0x800
