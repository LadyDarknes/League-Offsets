<h1 align="center">League — Offset & Pattern Database</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Patch-26.17-blue?style=flat-square" alt="Patch" />
  <img src="https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square" alt="Arch" />
  <img src="https://img.shields.io/badge/Tool-IDA%20Pro%209.4-orange?style=flat-square" alt="Tool" />
  <img src="https://img.shields.io/badge/Status-up_to_date-brightgreen?style=flat-square" alt="Status" />
</p>

<p align="center">
  <strong>Star For Support ⭐</strong><br>
  RVA offsets, AOB patterns, and structure layouts manually reversed from the game client.
</p>

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.hpp            ← generated C++ header file for ready inclusion
│   ├── offsets.json           ← JSON dump of resolved RVAs & member offsets
│   └── quick_usage/           
│       └── all_offsets.hpp    ← unified single header containing all C++ snippets & types
```

## Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.17 (16.17.810.4348) |
| Timestamp | `6AABB000` — Mon Aug 24 16:31:59 2026 |
| Imagebase | `7FF7EBAA0000` |
| Compiler | Visual C++ · x64 PE |

---

## Contact
Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.
