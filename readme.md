# League of Legends — Reverse Engineering Reference

> Offsets, AOB patterns, and struct layouts extracted from the League of Legends x64 binary.
> All reversing work is manual. AI was used only for formatting.

---

## Project Structure

```
league-of-legends/
├── src/
│   ├── offsets.md          # RVA & global offsets, function entries, struct field offsets
│   ├── patterns.md         # AOB byte patterns for globals, functions, and structs
│   └── w2s.h               # World-to-screen (W2S) implementation
└── dump/                   # IDA Pro database files (binary dump, .i64, .id0/.id1/.nam/.til)
```

---

## Contents

| File | Description |
| ---- | ----------- |
| [`src/offsets.md`](src/offsets.md) | RVA values for all globals and function entry points, plus per-struct field offsets (GameObject, HeroManager, Camera, SpellBook, NavGrid, etc.) |
| [`src/patterns.md`](src/patterns.md) | AOB signatures for every global pointer and function — includes multiple caller-context patterns for resolving via `E8` call |
| [`src/w2s.h`](src/w2s.h) | Header-only W2S using the view/projection matrices from the CameraData struct |

---

## Build Info

| Field      | Value |
| ---------- | ----- |
| Version    | Patch 25.10 |
| Timestamp  | `6A0507E6` — Wed May 13 23:23:18 2026 |
| SHA-256    | `AD9A3C2B...1803E390` |
| MD5        | `CAE7B686...3A339A` |
| Imagebase  | `0x7FF7C5CD0000` |
| Compiler   | Visual C++ (x64 PE) |

---

## Contact

Discord: **swansizz** — or open an [issue](../../issues) if a pattern is missing or broken.
