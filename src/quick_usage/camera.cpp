#include <cstdint>

struct Vec3 { float x, y, z; };

void UpdateCamera(uintptr_t base_addr) 
{
    void* hud = *(void**)(base_addr + 0x1E76E08); // HudInstance global
    if (!hud) return;

    void* cam = *(void**)((char*)hud + 0x18); // Camera pointer
    if (!cam) return;

    Vec3 cam_pos = *(Vec3*)((char*)cam + 0x08);
    Vec3 cam_rot = *(Vec3*)((char*)cam + 0x18);
    float fov = *(float*)((char*)cam + 0x3C);
    float near_clip = *(float*)((char*)cam + 0x44);
    float far_clip  = *(float*)((char*)cam + 0x4C);
    float zoom      = *(float*)((char*)cam + 0x324);
    float min_zoom  = *(float*)((char*)cam + 0x310);
    bool attached = *(bool*)((char*)cam + 0x28);
    float move_speed = *(float*)((char*)cam + 0x2C);
    float look_speed = *(float*)((char*)cam + 0x34);

    // Will not work but you can undersant with this example
    Vec3* cam_pos_ptr = (Vec3*)((char*)cam + 0x08);
    cam_pos_ptr->x = 7500.0f;
    cam_pos_ptr->y = 200.0f;
    cam_pos_ptr->z = 7500.0f;

    // Rendering flags
    // Bools are stored as bytes
    bool fog_enabled      = *(bool*)((char*)cam + 0x5A);
    bool outline_select   = *(bool*)((char*)cam + 0x54);
    bool outline_hover    = *(bool*)((char*)cam + 0x56);
    bool floating_text    = *(bool*)((char*)cam + 0x58);
    float navgrid_offset  = *(float*)((char*)cam + 0x5C);
}
