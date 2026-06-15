// HudInstance (Selection, Mouse Position, Camera Zoom)

struct Vec3 { float x, y, z; };

void* hud = *(void**)(base_addr + 0x1E682A8);
if (hud) 
{
    uint32_t selected_net_id = *(uint32_t*)((char*)hud + 0x28);
    Vec3 mouse_pos = *(Vec3*)((char*)hud + 0x34);
    
    void* cam = *(void**)((char*)hud + 0x18);
    if (cam) // canera zoom shits
    {
        float zoom = *(float*)((char*)cam + 0x324);
        float min_zoom = *(float*)((char*)cam + 0x310);
    }
}
