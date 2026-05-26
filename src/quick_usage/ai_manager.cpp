// AIManager Component (Navigation)

struct Vec3 { float x, y, z; };

void* wrapper = *(void**)((char*)obj + 0x4230);
if (wrapper) {
    void* ai_mgr = *(void**)((char*)wrapper + 32);
    if (ai_mgr) {
        bool is_moving = *(bool*)((char*)ai_mgr + 0x31C);
        bool is_dashing = *(bool*)((char*)ai_mgr + 0x384);
        float dash_speed = *(float*)((char*)ai_mgr + 0x360);
        Vec3 target_pos = *(Vec3*)((char*)ai_mgr + 0x34);
        Vec3 server_pos = *(Vec3*)((char*)ai_mgr + 0x474);
    }
}
