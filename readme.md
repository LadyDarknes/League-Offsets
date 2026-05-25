<div align="center">

# League of Legends — Offset Reference

![Patch](https://img.shields.io/badge/Patch-26.10-blue?style=flat-square)
![Arch](https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square)
![Tool](https://img.shields.io/badge/Tool-IDA%20Pro%209.3-orange?style=flat-squar)
![Status](https://img.shields.io/badge/Status-Up%20to%20date-brightgreen?style=flat-square)

RVA offsets, AOB patterns, and struct layouts extracted manually from the live binary.  
All reversing is my own work. AI was only used for table formatting.

</div>

---

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.md    ← global RVAs, function entries, all struct field offsets
│   ├── patterns.md   ← AOB byte patterns for every global and function
│   └── w2s.h         ← world-to-screen header (view / proj matrix math)
└── dump/             ← IDA Pro database files (.i64 · .id0 · .id1 · .nam · .til)
```

---

## Files

| File | Contents |
| ---- | -------- |
| [`src/offsets.md`](src/offsets.md) | RVA values for all global pointers and function entries, plus per-struct field offsets — `GameObject`, `HeroManager`, `Camera`, `SpellBook`, `NavGrid`, and more |
| [`src/patterns.md`](src/patterns.md) | AOB signatures for everything in `offsets.md`. Multiple caller-context variants per entry so you can resolve through `E8` calls |
| [`src/w2s.h`](src/w2s.h) | Header-only W2S using the view / projection matrices from the `CameraData` struct |

---

## Build Info

| Field | Value |
| ----- | ----- |
| Patch | 25.10 |
| Timestamp | `6A0507E6` — Wed May 13 23:23:18 2026 |
| SHA-256 | `AD9A3C2B9F1FAAE9BC013C4598F74EA3EB1B16FC90EF7FB2FB496E771803E390` |
| MD5 | `CAE7B6864A09A08974E229CDF43A339A` |
| Imagebase | `0x7FF7C5CD0000` |
| Compiler | Visual C++ · x64 PE |

---

## Contact

Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.
