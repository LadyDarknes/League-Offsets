<div align="center">

> [!NOTE]
> **Announcement:** Updated for Patch 26.16 (Season 16). Fully reversed & verified with IDA Pro 9.4! ✨

# League — Offset & Pattern Database

![Patch](https://img.shields.io/badge/Patch-26.16-blue?style=flat-square)
![Arch](https://img.shields.io/badge/Arch-x64%20PE-lightgrey?style=flat-square)
![Tool](https://img.shields.io/badge/Tool-IDA%20Pro%209.4-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Up%20to%20date-brightgreen?style=flat-square)

Star For Support ⭐

RVA offsets, AOB patterns, and structure layouts manually reversed from the game client.  
AI used for formatting, not for reversing.

</div>

## Repository Layout

```
League-Offsets/
├── src/
│   ├── offsets.hpp            ← generated C++ header file for ready inclusion
│   ├── offsets.json           ← JSON dump of resolved RVAs & member offsets
│   └── quick_usage/           
│       └── all_offsets.hpp    ← unified single header containing all C++ snippets & types
```


## 🛠️ Build Info

| Field | Value |
| ----- | ----- |
| Patch | 26.16 (`16.16.804.9184`) |
| Timestamp | `6A974D38` — Mon Aug 10 16:10:32 2026 |
| Imagebase | `7FF62DAE0000` |
| Compiler | Visual C++ · x64 PE |

---

## 📬 Contact
Discord — **swansizz**  
Or open an [issue](../../issues) if a pattern is missing or broken.
