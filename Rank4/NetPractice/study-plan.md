# NetPractice — Study plan

## Phase 0 — Number systems (½ day)

| Topic | Action |
|-------|--------|
| Binary | Convert 0–255 quickly |
| Powers of two | /2 and *2 for subnet math |
| AND operation | IP & mask = network address |

**Checkpoint:** Given `10.0.0.17 /255.255.255.0`, compute network address.

---

## Phase 1 — Core concepts (1–2 days)

| Topic | Action |
|-------|--------|
| IP address | Host identifier on a network |
| Subnet mask | Separates network bits from host bits |
| CIDR | `/24` = `255.255.255.0` |
| Gateway | Router interface on local subnet |
| Route | Where to send traffic for remote networks |

Read [theory-and-concepts.md](./theory-and-concepts.md) fully before level 3.

---

## Phase 2 — Levels 1–4 (1–2 days)

Start with the intra file. Early levels: assign IPs and masks so hosts share a LAN.

**Checkpoint:** All hosts ping each other (simulated green links).

---

## Phase 3 — Levels 5–7 (1–2 days)

Introduce **routers** and multiple subnets. Configure:

- Interface IPs on each router port
- Host default gateways pointing to router LAN IP
- Routes on routers for remote subnets

---

## Phase 4 — Levels 8–10 (2–3 days)

Complex topologies — multiple routers, asymmetric paths, summarization hints.

**Checkpoint:** Explain your routing table entries aloud (eval rehearsal).

---

## Phase 5 — Evaluation prep (½ day)

- Pick 3 random levels and re-solve without notes
- Practice explaining **why** each IP/mask/route value works
- Peer eval: you may need to fix a broken config live
