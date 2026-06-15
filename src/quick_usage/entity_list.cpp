#include <stdint.h>
#include <vector>

struct Vec3 { float x, y, z; };

struct GameObject {};

typedef bool(__fastcall* is_type_t)(void* obj, uint32_t flag);

struct MapNode 
{
    MapNode* left;
    MapNode* parent;
    MapNode* right;
    char color;
    char is_sentinel;
    char padding[6];
    uint32_t key;
    char padding2[4];
    void* value;
};

struct MsvcString 
{
    union {
        char buffer[16];
        char* pointer;
    };
    uint64_t length;
    uint64_t capacity;

    const char* c_str() const 
    {
        return capacity > 15 ? pointer : buffer;
    }
};

void TraverseMap(MapNode* node, MapNode* sentinel, std::vector<void*>& out_objects) 
{
    if (!node || node == sentinel || node->is_sentinel) return;

    TraverseMap(node->left, sentinel, out_objects);
    
    if (node->value) out_objects.push_back(node->value);
    
    TraverseMap(node->right, sentinel, out_objects);
}

std::vector<void*> GetActiveEntities(uintptr_t base_addr) 
{
    std::vector<void*> objects;
    void* object_manager = *(void**)(base_addr + 0x1E62DA8);
    if (!object_manager) return objects;

    void* map_allocator = *(void**)((char*)object_manager + 0x38);
    if (!map_allocator) return objects;

    MapNode* head_node = *(MapNode**)((char*)object_manager + 0x40);
    if (!head_node) return objects;

    MapNode* root = head_node->parent;
    if (root && root != head_node) 
    {
        TraverseMap(root, head_node, objects);
    }

    return objects;
}

std::vector<void*> GetChampions(uintptr_t base_addr) 
{
    std::vector<void*> heroes;
    void* hero_manager = *(void**)(base_addr + 0x1E62DE8);
    if (hero_manager) 
    {
        void** list = *(void***)((char*)hero_manager + 0x08);
        uint32_t count = *(uint32_t*)((char*)hero_manager + 0x10);
        for (uint32_t i = 0; i < count; i++) 
        {
            if (list[i]) 
            {
                heroes.push_back(list[i]);
            }
        }
    }
    return heroes;
}

std::vector<void*> GetMinions(uintptr_t base_addr) 
{
    std::vector<void*> minions;
    is_type_t is_type = (is_type_t)(base_addr + 0x263150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    for (void* obj : entities) 
    {
        if (obj && is_type(obj, 0x800)) // TypeMinion = 0x800, others are TypeHero = 0x1000, TypeTurret = 0x2000
        { 
            minions.push_back(obj);
        }
    }
    return minions;
}

std::vector<void*> GetJungleMonsters(uintptr_t base_addr) 
{
    // Common Neutral/Jungle Monster Names (accessible at GameObject + 0x68):
    // - Baron Nashor: "SRU_Baron"
    // - Rift Herald: "SRU_Herald"
    // - Red Brambleback (Red Buff): "SRU_Red"
    // - Blue Sentinel (Blue Buff): "SRU_Blue"
    // - Scuttle Crab: "Sru_Crab"
    // - Dragon: "SRU_Dragon" (Elements: SRU_Dragon_Fire, SRU_Dragon_Water, SRU_Dragon_Earth, SRU_Dragon_Air, SRU_Dragon_Elder, SRU_Dragon_Chemtech, SRU_Dragon_Hextech)
    std::vector<void*> monsters;
    is_type_t is_type = (is_type_t)(base_addr + 0x263150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    for (void* obj : entities) 
    {
        if (obj && is_type(obj, 0x800)) // Minion type
        { 
            uint8_t team_id = *(uint8_t*)((char*)obj + 0x259);
            if (team_id != 100 && team_id != 200) // Neutral (not Blue 100 or Red 200)
            { 
                monsters.push_back(obj);
            }
        }
    }
    return monsters;
}

void ProcessEntitiesExample(uintptr_t base_addr) 
{
    is_type_t is_type = (is_type_t)(base_addr + 0x263150);
    std::vector<void*> entities = GetActiveEntities(base_addr);
    void* local_player = *(void**)(base_addr + 0x1EA0528);
    uint8_t local_team = local_player ? *(uint8_t*)((char*)local_player + 0x259) : 100;
    uint32_t team_bit = (local_team == 100) ? 0 : 1;

    for (void* obj : entities) 
    {
        if (!obj) continue;

        bool is_hero = is_type(obj, 0x1000);
        bool is_minion = is_type(obj, 0x800);
        bool is_turret = is_type(obj, 0x2000);

        if (!is_hero && !is_minion && !is_turret) continue;

        float hp = *(float*)((char*)obj + 0x1080);
        float hp_max = *(float*)((char*)obj + 0x10A8);
        if (hp <= 0.0f) continue;

        MsvcString* name_str = (MsvcString*)((char*)obj + 0x68);
        const char* name = name_str->c_str();

        uint8_t team_id = *(uint8_t*)((char*)obj + 0x259);

        Vec3 pos = *(Vec3*)((char*)obj + 0x25C);

        uint32_t vis_mask = *(uint32_t*)((char*)obj + 0x30C);
        bool is_visible = (vis_mask & (1 << team_bit)) == 0;

        float mana = *(float*)((char*)obj + 0x360);
        float mana_max = *(float*)((char*)obj + 0x388);
        bool mana_enabled = *(bool*)((char*)obj + 0x3B0);

        int level = *(int*)((char*)obj + 0x4D58);

        float armor = *(float*)((char*)obj + 0x4F38);
        float mr = *(float*)((char*)obj + 0x4CB8);
        float move_speed = *(float*)((char*)obj + 0x5000);

        float all_shield = *(float*)((char*)obj + 0x1120);
        float phys_shield = *(float*)((char*)obj + 0x1148);
        float mag_shield = *(float*)((char*)obj + 0x1170);

        void* ai_mgr_wrapper = *(void**)((char*)obj + 0x4070);
        if (ai_mgr_wrapper) 
        {
            void* ai_mgr = *(void**)((char*)ai_mgr_wrapper + 0x28);
            void* nav_inner = *(void**)((char*)ai_mgr_wrapper + 0x40);
            if (ai_mgr && nav_inner) 
            {
                bool is_moving = *(bool*)((char*)nav_inner + 0x320);
                bool is_dashing = *(bool*)((char*)nav_inner + 0x348);
                float dash_speed = *(float*)((char*)nav_inner + 0x3E0);
                Vec3 target_pos = *(Vec3*)((char*)ai_mgr + 0x24);
                Vec3 velocity = *(Vec3*)((char*)ai_mgr + 0x18);
                Vec3 server_pos = *(Vec3*)((char*)ai_mgr + 0x08);

                void* nav_path = (char*)nav_inner + 0x490;
                int current_node_idx = *(int*)((char*)nav_path + 0x00);
                int waypoint_count = *(int*)((char*)nav_path + 0x30);
                Vec3* waypoints = *(Vec3**)((char*)nav_path + 0x28);
            }
        }
    }
}
