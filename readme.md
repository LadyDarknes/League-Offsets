<div align="center">

# League of Legends — Offset & Pattern Database

![Patch](https://img.shields.io/badge/Patch-26.13-blue?style=flat-square)
![Arch](https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square)
![Tool](https://img.shields.io/badge/Tool-IDA%20Pro%209.3-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Up%20to%20date-brightgreen?style=flat-square)

Star For Support ⭐

RVA offsets, AOB patterns, and structure layouts manually reversed from the game client.
Ai used for formating, not for reversing.


Special thanks to everyone who supported this project: "Raphael, Wasik, hernos, IA20201"
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
│   └── quick_usage/           
│       └── all_offsets.hpp    ← unified single header containing all C++ snippets & types
```

---
### Quick Usage Snippets (`src/quick_usage/`)
Click on the unified header file to view clean C++ code examples:
*   [**`all_offsets.hpp`**](file:///c:/Users/Administrator/Desktop/League-Offsets/src/quick_usage/all_offsets.hpp) — Unified header containing W2S projection, ObjectManager navigation tree, spellcast mapping queries, active spell tracking, issue order wrappers, type flags checking, buff lists, and Hook setups.

---

## 🛠️ Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.13 |
| Timestamp | `6A3B418B` — Wed Jun 24 02:31:39 2026 |
| Imagebase | `0x7FF701D60000` |
| Compiler | Visual C++ · x64 PE |

---

## 📬 Contact
Discord — **swansizz**
Or open an [issue](../../issues) if a pattern is missing or broken.
