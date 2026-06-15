struct Vec3 { float x, y, z; };

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
        Vec3 path_start = *(Vec3*)((char*)nav_inner + 0x328);
        Vec3 path_end = *(Vec3*)((char*)nav_inner + 0x338);
        
        void* nav_path = (char*)nav_inner + 0x490;
        int current_node_idx = *(int*)((char*)nav_path + 0x00);
        int waypoint_count = *(int*)((char*)nav_path + 0x30);
        Vec3* waypoints = *(Vec3**)((char*)nav_path + 0x28);
    }
}
