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


// Since the client caching bug causes the +0x168/+0x169 visibility bytes to remain
// stale (not updating to False when the unit goes in fog of war, because the client
// stops running the IsVisible update loop for culled objects), a more robust check is
// to read the NetVisibilityObjectClient team mask at GameObject + 0x30C.
//
// - GameObject + 0x30C: Team visibility bitmask (updated directly by network packets).
//   - Bit 0: Blue team fog (1 = in fog, 0 = visible).
//   - Bit 1: Red team fog (1 = in fog, 0 = visible).
//
bool IsUnitVisible(void* obj, void* local_player) {
    if (!obj || !local_player) return false;
    
    // Get local player's team ID (100 = Blue, 200 = Red)
    uint8_t local_team = *(uint8_t*)((char*)local_player + 0x259);
    uint32_t team_bit = (local_team == 100) ? 0 : 1;
    
    // Read the NetVisibilityObjectClient visibility mask
    uint32_t vis_mask = *(uint32_t*)((char*)obj + 0x30C);
    
    // A bit of 0 means the team has visibility (visible).
    // A bit of 1 means the team does not have visibility (in fog of war).
    return (vis_mask & (1 << team_bit)) == 0;
}



// Hey Envy! Here is how you solve the issue where Master Yi Q finishes
// but the orbwalker misses the attack cycle or wastes time liek I promised:
//
// Root Cause:
// Yi's AA timer resets instantly when he lands from Q (Alpha Strike)
// If the orbwalker is still waiting for the precast AA cooldown to expire, 
// it just delays the next attack for no reason
//
// Solution:
// 1. Detect if Master Yi is currently casting a spell (like Q) by checking
//    ActiveSpellCast at SpellBook + 0xAD8.
// 2. If ActiveSpellCast is non-null, look up the spell name (e.g. "AlphaStrike")
//    to know he is in the Q animation.
// 3. Once ActiveSpellCast becomes null (meaning he has landed and Q finished),
//    immediately reset your orbwalker's auto-attack timer (set next_attack_time
//    to 0 or current GameTime) so the orbwalker issues an auto-attack command
//    immediately.
//
// C++ Reference Implementation:

struct MsvcString {
    union {
        char buffer[16];
        char* pointer;
    };
    uint64_t length;
    uint64_t capacity;

    const char* c_str() const {
        return capacity > 15 ? pointer : buffer;
    }
};

struct SpellData {
    char padding_0[0x28];
    MsvcString spell_name; // SpellData + 0x28
};

struct SpellCastInfo {
    char padding_0[0x8];
    SpellData* spell_data; // SpellCastInfo + 0x8 (varies)
};

bool IsCastingAlphaStrike(void* local_player) {
    if (!local_player) return false;

    void* spell_book = *(void**)((char*)local_player + 0x3128);
    if (!spell_book) return false;

    // Get ActiveSpellCast (SpellBook + 0xAD8)
    void* active_cast = *(void**)((char*)spell_book + 0xAD8);
    if (!active_cast) return false;
    void* spell_data = *(void**)((char*)active_cast + 0x8); // Adjust offset based on cast structure
    if (!spell_data) return false;

    MsvcString* name_str = (MsvcString*)((char*)spell_data + 0x28);
    if (name_str && name_str->c_str()) {
        // usually "AlphaStrike" or "AlphaStrikeAttack"
        const char* name = name_str->c_str();
        if (name && (name[0] == 'A' && name[1] == 'l')) {
            return true;
        }
    }
    return false;
}

// Example usage inside your Orbwalker tick loop, Not sure how to code in python, but in C++ you would do something like this:
//
// void Orbwalker::Update(void* local_player, float current_game_time) {
//     static bool was_casting_q = false;
//     bool is_casting_q = IsCastingAlphaStrike(local_player);
//
//     // Detect the EXACT frame (yep literally) when Q animation finishes and Master Yi lands:
//     if (was_casting_q && !is_casting_q) {
//         // Reset next auto-attack timer to allow immediate auto-attack
//         this->next_attack_time = 0.0f; 
//     }
//     was_casting_q = is_casting_q;
//
//     // Block regular orbwalker auto-attacks while casting Q
//     if (is_casting_q) return; 
//
//    // Normal orbwalking logic here whatevers you have...
// }

