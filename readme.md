<div align="center">

# League of (removed) — Offset Reference

![Patch](https://img.shields.io/badge/Patch-26.11-blue?style=flat-square)
![Arch](https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square)
![Tool](https://img.shields.io/badge/Tool-IDA%20Pro%209.3-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Up%20to%20date-brightgreen?style=flat-square)

star for support ⭐

RVA offsets, AOB patterns, and struct layouts extracted manually from the league.  
All reversing is my own work. AI was only used for table formatting and some code.

</div>

---

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.md             ← global RVAs, function entries, struct field offsets
│   ├── patterns.md            ← AOB byte patterns for every global and function
│   ├── reflection_offsets.md  ← dynamic reflection offsets (AIHero, AIMinionCommon, AITurretCommon…)
│   └── quick_usage/           ← ready-to-use C++ snippets for each system (most of it Vibe Coded!)
│       ├── w2s.h              ← world-to-screen header (view / proj matrix math)
│       ├── ai_manager.cpp     ← navigation / movement (AIManager)
│       ├── buff_manager.cpp   ← buff iteration and lookup
│       ├── hud.cpp            ← HudInstance and camera access
│       ├── is_type.cpp        ← type classification helpers
│       └── quest.cpp          ← quest progress and RoleBound system
└── dump/                      ← IDA Pro database files (.i64 · .id0 · .id1 · .nam · .til)
```

---

## Files

| File | Contents |
| ---- | -------- |
| [`src/offsets.md`](src/offsets.md) | RVA values for all global pointers and function entries, plus per-struct field offsets — `GameObject`, `HeroManager`, `Camera`, `SpellBook`, `NavGrid`, and more |
| [`src/patterns.md`](src/patterns.md) | AOB signatures for everything in `offsets.md`. Multiple caller-context variants per entry so you can resolve through `E8` calls |
| [`src/reflection_offsets.md`](src/reflection_offsets.md) | Dynamic reflection offsets for `AIHero`, `AIMinionCommon`, `AITurretCommon`, `Barracks`, `HQ`, and more — extracted from getter functions |
| [`src/quick_usage/`](src/quick_usage/) | Ready-to-paste C++ snippets covering W2S, navigation, buffs, HUD, type checks, and quest system |

---

## Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.11 |
| Timestamp | `6A0F8BDE` — Thu May 21 22:49:02 2026 |
| SHA-256 | `6F460B721D6B5997839AEB57A11432B8EEA4128992E8821F64F08C7A9CD5F392` |
| MD5 | `7AF934464747DDB6490C800FA37D5402` |
| Imagebase | `0x7FF7F8E80000` |
| Compiler | Visual C++ · x64 PE |

---

## Contact

Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.

Thank you for sharing guys, but please star this repo 🥰
<img width="1179" height="1374" alt="image" src="https://github.com/user-attachments/assets/14696c5a-06f6-4295-b774-bcf300463763" />

