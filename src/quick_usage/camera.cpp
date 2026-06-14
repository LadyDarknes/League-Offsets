// CameraData — Position, Rotation, FOV, Clip Planes, Rendering Flags
// Accessed via HudInstance -> Camera pointer -> CameraData offsets
// Offsets extracted from HudCameraLogic property registration (sub_7FF7E72A8D50)

#include <cstdint>

struct Vec3 { float x, y, z; };

// -- Read camera world position (camPos) --
void* hud = *(void**)(base_addr + 0x1E76E08);   // HudInstance global
if (hud) {
    void* cam = *(void**)((char*)hud + 0x18);    // Camera pointer
    if (cam) {
        // Camera position in world coordinates (Vec3 at +0x08)
        Vec3 cam_pos = *(Vec3*)((char*)cam + 0x08);

        // Camera rotation in Euler degrees: yaw, pitch, roll (Vec3 at +0x18)
        Vec3 cam_rot = *(Vec3*)((char*)cam + 0x18);

        // Field of view in degrees (default 56.0)
        float fov = *(float*)((char*)cam + 0x3C);

        // Clip planes
        float near_clip = *(float*)((char*)cam + 0x44);
        float far_clip  = *(float*)((char*)cam + 0x4C);

        // Camera zoom (existing offsets from Camera struct)
        float zoom      = *(float*)((char*)cam + 0x324);
        float min_zoom  = *(float*)((char*)cam + 0x310);

        // Camera attached to object (locked camera)
        bool attached = *(bool*)((char*)cam + 0x28);

        // Movement / look speed
        float move_speed = *(float*)((char*)cam + 0x2C);
        float look_speed = *(float*)((char*)cam + 0x34);
    }
}

// -- Write camera position (teleport camera) --
// WARNING: writing to read-only properties may cause desync or crash.
// Prefer using the game's own movement functions when possible.
void* hud2 = *(void**)(base_addr + 0x1E76E08);
if (hud2) {
    void* cam2 = *(void**)((char*)hud2 + 0x18);
    if (cam2) {
        Vec3* cam_pos_ptr = (Vec3*)((char*)cam2 + 0x08);
        cam_pos_ptr->x = 7500.0f;  // center of map X
        cam_pos_ptr->y = 200.0f;   // height
        cam_pos_ptr->z = 7500.0f;  // center of map Z
    }
}

// -- Read rendering flags --
void* hud3 = *(void**)(base_addr + 0x1E76E08);
if (hud3) {
    void* cam3 = *(void**)((char*)hud3 + 0x18);
    if (cam3) {
        bool fog_enabled      = *(bool*)((char*)cam3 + 0x5A);
        bool outline_select   = *(bool*)((char*)cam3 + 0x54);
        bool outline_hover    = *(bool*)((char*)cam3 + 0x56);
        bool floating_text    = *(bool*)((char*)cam3 + 0x58);
        float navgrid_offset  = *(float*)((char*)cam3 + 0x5C);
    }
}
