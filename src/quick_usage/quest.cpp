// Narrative / Quest Component Lookups

typedef void*(__fastcall* lookup_t)(void* registry, void* key);
lookup_t lookup_comp = (lookup_t)(base_addr + 0x115D9C0);

void* quest_comp = lookup_comp((char*)obj + 0xE0, role_quest_key); // Key: 0x1E66700
uint32_t current_val = get_quest_val(entry->quest_def, entry->quest_type, entry->quest_tier); // Fn: 0x529C70
uint32_t remaining = entry->target - current_val;
