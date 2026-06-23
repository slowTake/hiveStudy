# Exam Rank 05 — Study plan

## Phase 0 — Exam mechanics (half day)

| Task | Detail |
|------|--------|
| Run exam shell | `exam` on campus or practice equivalent |
| Understand grading | Level 00 must pass to unlock 01; one exercise per attempt at each level |
| File layout | Only submit files named in the subject; given `main.cpp` must compile unchanged |

---

## Phase 1 — vect2 (1 day)

Easiest of the three. Good warm-up for operator overloading.

| Step | Task |
|------|------|
| 1 | Read [vect2.md](./vect2.md) |
| 2 | Implement from header skeleton only |
| 3 | Run given `main.cpp` — fix pre/post inc/dec return values |
| 4 | Time yourself: aim under 45 minutes |

**Checkpoint:** Given main compiles and prints expected `{x, y}` values.

---

## Phase 2 — bigint (1–2 days)

Medium difficulty. String arithmetic and edge cases.

| Step | Task |
|------|------|
| 1 | Read [bigint.md](./bigint.md) |
| 2 | Implement `+`, `++`, comparison first |
| 3 | Add `<<` / `<<=` digit shift |
| 4 | Add `>>=` (shift amount = value of rhs bigint) |
| 5 | Test: `0`, leading zeros, carry chains (`999 + 1`) |

**Checkpoint:** Given main from subject passes all outputs.

---

## Phase 3 — polyset (2 days)

Hardest level-00 exercise. Inheritance + virtual diamond + wrapping.

| Step | Task |
|------|------|
| 1 | Read [polyset.md](./polyset.md) and given `bag.hpp` hierarchy |
| 2 | Implement `searchable_array_bag::has` (linear scan) |
| 3 | Implement `searchable_tree_bag::has` (BST walk) |
| 4 | Implement `set` wrapper (deduplicating insert) |
| 5 | Add OCF where subject requires it |
| 6 | Run given `main.cpp` with args: `./a.out 1 2 3 2` |

**Checkpoint:** `has()` correct on both bag types; `set` ignores duplicate inserts.

---

## Phase 4 — Timed rehearsal (1 day)

| Drill | Target |
|-------|--------|
| vect2 cold start | ≤ 45 min |
| bigint cold start | ≤ 90 min |
| polyset cold start | ≤ 120 min |
| No internet | Simulate exam conditions |

---

## Phase 5 — Level 01 (optional)

If level 00 is solid, prep **life** (Conway's Game of Life on a terminal grid). Not covered in this directory yet.

---

## Suggested focus order

1. **vect2** — build confidence with operators
2. **bigint** — algorithmic thinking
3. **polyset** — OOP design under time pressure

Do not skip polyset because it feels hard — it appears frequently in exams.
