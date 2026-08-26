<h1 align="center">League — Offset & Pattern Database</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Patch-26.16-blue?style=flat-square" alt="Patch" />
  <img src="https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square" alt="Arch" />
  <img src="https://img.shields.io/badge/Tool-IDA%20Pro%209.4-orange?style=flat-square" alt="Tool" />
  <img src="https://img.shields.io/badge/Status-out_of_date-brightred?style=flat-square" alt="Status" />
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
Example:
<img width="1076" height="706" alt="image" src="https://github.com/user-attachments/assets/04753cf1-3c3a-4f8f-ac3a-067c0dc5d11e" />
## Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.16 (16.16.804.9184) |
| Timestamp | `6A974D38` — Mon Aug 10 16:10:32 2026 |
| Imagebase | `7FF738CA0000` |
| Compiler | Visual C++ · x64 PE |

---

## Contact
Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.
