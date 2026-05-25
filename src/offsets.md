# League of Legends — RVA Offsets

| Field | Value |
| ----- | ----- |
| SHA-256 | `AD9A3C2B9F1FAAE9BC013C4598F74EA3EB1B16FC90EF7FB2FB496E771803E390` |
| MD5 | `CAE7B6864A09A08974E229CDF43A339A` |
| CRC32 | `3540AE51` |
| Compiler | Visual C++ |
| Format | Portable executable for AMD64 (PE) |
| Imagebase | `7FF7C5CD0000` |
| Timestamp | 6A0507E6 (Wed May 13 23:23:18 2026) |

---

## Global Offsets

| Name | RVA | Address |
| ---- | --- | ------- |
| `LocalPlayer` | `0x1e73448` | `0x7ff7c7b43448` |
| `HeroManager` | `0x1e3a418` | `0x7ff7c7b0a418` |
| `ViewPort` | `0x1e4e870` | `0x7ff7c7b1e870` |
| `GameTime` | `0x1e49ac0` | `0x7ff7c7b19ac0` |
| `EntityList` | `0x1e3a430` | `0x7ff7c7b0a430` |
| `ObjectManager` | `0x1e3a3c0` | `0x7ff7c7b0a3c0` |
| `MissileManager` | `0x1e3a480` | `0x7ff7c7b0a480` |
| `NavGrid` | `0x1e3e3f0` | `0x7ff7c7b0e3f0` |
| `HudInstance` | `0x1e3a560` | `0x7ff7c7b0a560` |
| `r3dRenderer` | `0x1f0b248` | `0x7ff7c7bdb248` |
| `NetInstance` | `0x1e3a3d0` | `0x7ff7c7b0a3d0` |
| `NetClient (GetPing)` | `0x1e3a3b8` | `0x7ff7c7b0a3b8` |
| `UnderMouseObj` | `0x1e3e690` | `0x7ff7c7b0e690` |
| `ChatClient` | `0x1f09da8` | `0x7ff7c7bd9da8` |

---

## Function Entries

| Name | RVA | Address |
| ---- | --- | ------- |
| `IssueOrderCore` | `0x2bf6c0` | `0x7ff7c5f8f6c0` |
| `IssueOrderCore (caller)` | `0x2bf6c0` | `0x7ff7c5f8f6c0` |
| `WorldToScreen (fn entry)` | `0x12c9c20` | `0x7ff7c6f99c20` |
| `WorldToScreen (caller ctx)` | `0x12c9c20` | `0x7ff7c6f99c20` |
| `GetBoundingRadius` | `0x2a3f20` | `0x7ff7c5f73f20` |
| `GetAttackWindup` | `0x55d3e0` | `0x7ff7c622d3e0` |
| `GetAttackDelay (caller ctx)` | `0x55d4e0` | `0x7ff7c622d4e0` |
| `GetCollisionFlags` | `0x12170b0` | `0x7ff7c6ee70b0` |
| `IsTurret` | `0x32e100` | `0x7ff7c5ffe100` |
| `IsTurret (caller ctx)` | `0x30a040` | `0x7ff7c5fda040` |
| `IsAlive` | `0x30a040` | `0x7ff7c5fda040` |
| `SpellBook::GetSpellSlot` | `0x98c480` | `0x7ff7c665c480` |
| `SpellSlot::GetCooldown` | `0x92cc40` | `0x7ff7c65fcc40` |
| `SpellSlot::Cast` | `0x70ac00` | `0x7ff7c63dac00` |
| `BuffManagerClient::OnBuffAdd` | `0x93fb00` | `0x7ff7c660fb00` |
| `BuffManagerClient::OnBuffRemove` | `0x9405c0` | `0x7ff7c66105c0` |
