# Exam Rank 06 — Study plan

## Phase 0 — Exam mechanics (half day)

| Task | Detail |
|------|--------|
| Run exam shell | `exam` on campus or practice equivalent |
| Understand grading | Usually one exercise; must pass to validate Rank 06 |
| File layout | Submit only `mini_serv.c` |

---

## Phase 1 — Socket refresher (1–2 days)

Reuse Rank 5 IRC networking knowledge with C instead of C++.

| Step | Task |
|------|------|
| 1 | Re-read Beej's Guide — TCP server setup |
| 2 | Write echo server: `socket` → `bind` → `listen` → `accept` → `recv`/`send` |
| 3 | Bind to `127.0.0.1` explicitly (`htonl(2130706433)`) |
| 4 | Test with `nc 127.0.0.1 <port>` |

**Checkpoint:** Single-client echo works.

---

## Phase 2 — `select()` multiplexing (1–2 days)

| Step | Task |
|------|------|
| 1 | Read [theory-and-concepts.md](./theory-and-concepts.md) — `fd_set`, `FD_SET`, `FD_ISSET` |
| 2 | Track `maxfd` across listen socket + clients |
| 3 | Copy `fd_set` before each `select()` — kernel modifies the set |
| 4 | Handle `accept` when listen fd is ready |

**Checkpoint:** Server accepts multiple `nc` clients without blocking.

---

## Phase 3 — mini_serv requirements (2–3 days)

| Step | Task |
|------|------|
| 1 | Read [mini_serv/guide.md](./mini_serv/guide.md) |
| 2 | Client IDs: 0, 1, 2, … on connect |
| 3 | Broadcast: `server: client %d just arrived\n` / `just left\n` |
| 4 | Per-line prefix: `client %d: ` on every complete line |
| 5 | Message buffer per client until `\n` |
| 6 | Compare with [mini_serv/reference/](./mini_serv/reference/) |

**Checkpoint:** Three `nc` sessions show correct arrival, chat, and departure messages.

---

## Phase 4 — Timed rehearsal (1 day)

| Drill | Target |
|-------|--------|
| Cold start from empty file | ≤ 3 hours |
| No internet | Simulate exam conditions |
| Leak check | `valgrind` or close all fds on disconnect |
| Edge cases | Multi-line packet, partial line, simultaneous connect |

---

## Suggested focus order

1. **TCP server skeleton** — bind, listen, one client
2. **`select()` loop** — multiple clients
3. **Broadcast + formatting** — subject output is strict
4. **Buffering** — partial reads are the main failure mode

If IRC is fresh, Rank 06 feels familiar — but the exam uses **`select()`**, not `poll()`, and forbids `#define`.
