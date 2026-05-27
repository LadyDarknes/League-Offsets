struct Vec3 { float x, y, z; };

void* ai_mgr_wrapper = *(void**)((char*)obj + 0x4070);
if (ai_mgr_wrapper) {
    void* ai_mgr = *(void**)((char*)ai_mgr_wrapper + 0x28);
    if (ai_mgr) {
        bool is_moving = *(bool*)((char*)ai_mgr + 0x31C);
        bool is_dashing = *(bool*)((char*)ai_mgr + 0x384);
        float dash_speed = *(float*)((char*)ai_mgr + 0x360);
        Vec3 target_pos = *(Vec3*)((char*)ai_mgr + 0x34);
        Vec3 server_pos = *(Vec3*)((char*)ai_mgr + 0x474);
        
        void* nav_inner = *(void**)((char*)ai_mgr + 0x40);
        if (nav_inner) {
            void* nav_path = (char*)nav_inner + 0x45C;
            int current_node_idx = *(int*)((char*)nav_path + 0x00);
            int waypoint_count = *(int*)((char*)nav_path + 0x30);
            Vec3* waypoints = *(Vec3**)((char*)nav_path + 0x28);
        }
    }
}
