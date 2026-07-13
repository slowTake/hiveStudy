# CPP01 — Study plan

## Phase 0 — Memory model (1 day)

| Topic | Action |
|-------|--------|
| Stack vs heap | Local `Zombie` vs `new Zombie` |
| `new` / `delete` | Single objects |
| `new[]` / `delete[]` | Arrays of objects |
| Leaks | Run Valgrind after every exercise |

**Checkpoint:** Explain when destructor runs for stack vs heap zombie.

---

## Phase 1 — ex00 Zombies (1 day)

| Step | Task |
|------|------|
| 1 | `randomChump()` — stack zombie, dies at scope end |
| 2 | `newZombie(name)` — heap zombie, caller deletes |
| 3 | `Zombie::announce()` prints name |

---

## Phase 2 — ex01 Horde (1 day)

| Step | Task |
|------|------|
| 1 | `zombieHorde(n, name)` allocates `n` zombies |
| 2 | Return pointer to array; `main` uses `delete[]` |
| 3 | Each zombie announces with same name |

---

## Phase 3 — ex02 Brain (½ day)

| Step | Task |
|------|------|
| 1 | `string` variable on stack |
| 2 | `stringPTR` — pointer to string |
| 3 | `stringREF` — reference to string |
| 4 | Print address and value via each |

---

## Phase 4 — ex03–ex05 (2–3 days)

Revisit CPP00 ex03–ex05 with stricter memory discipline. Apply OCF where classes own pointers.

---

## Evaluation prep

- Valgrind clean on all exercises
- No C allocation functions
- Correct `delete` vs `delete[]`
