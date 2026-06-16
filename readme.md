<div align="center">

# League of Legends — Offset & Pattern Database

![Patch](https://img.shields.io/badge/Patch-26.12-blue?style=flat-square)
![Arch](https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square)
![Tool](https://img.shields.io/badge/Tool-IDA%20Pro%209.3-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Up%20to%20date-brightgreen?style=flat-square)

star for support ⭐

RVA offsets, AOB patterns, and structure layouts manually reversed from the game client.
AI was only used for table formatting and some code.
</div>

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.md             ← global RVAs, function entries, struct field offsets
│   ├── offsets.hpp            ← generated C++ header file for ready inclusion
│   ├── offsets.json           ← JSON dump of resolved RVAs & member offsets
│   ├── patterns.md            ← AOB byte patterns for every global and function
│   ├── reflection_offsets.md  ← dynamic reflection offsets (AIHero, AIMinionCommon, AITurretCommon…)
│   └── quick_usage/           ← ready-to-use C++ snippets for each system (most of it Vibe Coded!)
```

---
### Quick Usage Snippets (`src/quick_usage/`)
Click on any implementation file to view clean C++ code examples:
*   [**`spellcast.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/spellcast.cpp) — Querying spell maps, tracking active spell casts, and hooking `OnProcessSpell`.
*   [**`camera.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/camera.cpp) — Extracting and setting camera positions, Zoom, FOV, and rendering flags.
*   [**`hooks.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/hooks.cpp) — DetouringWndProc, ClientMainLoop, and registration hooks.
*   [**`ai_manager.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/ai_manager.cpp) — Querying path status, server coordinates, and waypoints.
*   [**`buff_manager.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/buff_manager.cpp) — Enumerating local buffs, reading stack counts, and expiration timers.
*   [**`entity_list.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/entity_list.cpp) — Navigating the ObjectManager entity list and looping champions/minions.
*   [**`hud.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/hud.cpp) — Extracting cursor coordinates and active chat status.
*   [**`is_type.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/is_type.cpp) — Checking entity types dynamically using internal vftable flags.
*   [**`issue_order.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/issue_order.cpp) — Wrapping movement and attack order requests.
*   [**`quest.cpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/quest.cpp) — Reading active quest data and progression values.
*   [**`w2s.h`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/w2s.h) — Resolving projection matrices to translate world space coordinates into screen pixels.

---

## 🛠️ Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.12 |
| Timestamp | `6A2B43A1` — Thu Jun 11 23:24:17 2026 |
| Imagebase | `0x7FF7E6B90000` |
| Compiler | Visual C++ · x64 PE |

---

## 📬 Contact
Discord — **swansizz**
Or open an [issue](../../issues) if a pattern is missing or broken.

