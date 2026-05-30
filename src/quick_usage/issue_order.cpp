#include <stdint.h>

struct Vec3 { float x, y, z; };


typedef bool(__fastcall* IssueOrderCore_t)(
    void* hud_input_logic,      // HudInputLogic pointer (typically HudInstance + 0x20 or 0x24)
    uint32_t order_type,        // 1 = Attack, 2 = Move, 3 = Stop/Hold or maybe buy item depens on context
    Vec3* order_pos,            // Pointer to target world coordinates
    void* target_obj,           // Pointer to target GameObject (null if moving)
    bool is_triggered_by_user,  // Typically false/true (indicates manual source)
    bool shift_held,            // True if shift modifier is active (attack-move)
    bool queue_order            // True to queue, false to issue immediately
);

void IssueOrderExample(uintptr_t base_addr, void* enemy_champion) {
    IssueOrderCore_t IssueOrder = (IssueOrderCore_t)(base_addr + 0x2DB830); // IssueOrderCore RVA

    void* hud_instance = *(void**)(base_addr + 0x1E682A8); // HudInstance RVA
    if (!hud_instance) return;

    // hud_input_logic is retrieved at HudInstance + 0x24 (or 0x20 depending on compiler offset)
    void* hud_input_logic = *(void**)((char*)hud_instance + 0x24); 
    if (!hud_input_logic) return;

    // A. Issue a Move Order
    Vec3 move_pos = { 1500.0f, 150.0f, 1500.0f };
    IssueOrder(hud_input_logic, 2, &move_pos, nullptr, false, false, true);

    // B. Issue an Attack Order on an Enemy Target
    if (enemy_champion) {
        Vec3 target_pos = *(Vec3*)((char*)enemy_champion + 0x25C); // Position offset
        IssueOrder(hud_input_logic, 1, &target_pos, enemy_champion, false, false, true);
    }
}


// If your visibility check returns true even when a unit has walked into the
// fog of war... it is because the game client caches entities and keeps their
// primary visibility flag active.
//
// To check if a unit is actively visible right now, you must query three
// sequential bytes starting at GameObject + 0x168:
//
// - +0x168 (OFF_VISIBLE_0): Primary visibility flag.
// - +0x169 (OFF_VISIBLE_FOG): Fog-of-War state (0 if visible, 1 if hidden in FOW).
// - +0x16A (OFF_VISIBLE_ALT): Alternate visibility flag.
//
bool IsUnitVisible(void* obj) {
    if (!obj) return false;
    
    bool vis_0 = *(bool*)((char*)obj + 0x168);
    bool vis_fog = *(bool*)((char*)obj + 0x169);
    bool vis_alt = *(bool*)((char*)obj + 0x16A);
    
    // Logic: Must have primary/alternate visibility active, AND must NOT be in the fog of war.
    return (vis_0 || vis_alt) && !vis_fog;
}
