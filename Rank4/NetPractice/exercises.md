# NetPractice — Exercise breakdown

## Format

| | |
|---|---|
| **Type** | Web UI puzzle — not a Makefile project |
| **Levels** | 10 (typical) |
| **Save file** | Personal `.np` or similar from intra |
| **Evaluation** | Oral defense + live fix on assigned level |

---

## Per-level skills

| Level range | Skills tested |
|-------------|---------------|
| 1–2 | Same subnet, correct mask, assign host IPs |
| 3–4 | Split networks, avoid broadcast conflicts |
| 5–6 | Two subnets + one router, default gateway |
| 7–8 | Multiple routers, static routes |
| 9–10 | Full topology, minimal route tables |

---

## What you configure

| Element | Meaning |
|---------|---------|
| Host IP | Address on local interface |
| Mask | Defines subnet size |
| Gateway | Next hop for off-subnet traffic |
| Route (network, mask, gateway) | Router forwarding rule |

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| Host and gateway not same subnet | No connectivity |
| Overlapping subnets | Routing loops or black holes |
| Wrong broadcast address | Packets never arrive |
| Cannot explain your config | Fail oral even if UI shows success |

---

## Mandatory vs bonus

All 10 levels are **mandatory** for completion. No code bonus section.
