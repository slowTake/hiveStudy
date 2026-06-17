# CPP06 — Study plan

## Phase 0 — Cast fundamentals (before ex00)

| Topic | Action |
|-------|--------|
| Implicit vs explicit conversion | Read when C++ converts silently vs when you must cast |
| `static_cast` | Numeric conversions, void* round-trips, up-casts |
| `const_cast` | Remove/add const (know UB risks) |
| `reinterpret_cast` | Bit-pattern reinterpretation |
| `dynamic_cast` | Safe down-cast when base is polymorphic |

**Checkpoint:** Name one safe use and one dangerous use for each cast.

---

## Phase 1 — ex00: ScalarConverter (1–2 days)

| Step | Task |
|------|------|
| 1 | Parse single CLI argument as char, int, float, or double literal |
| 2 | Detect pseudo-literals: `nan`, `nanf`, `inf`, `inff`, `+inf`, `-inf`, etc. |
| 3 | Print four lines: `char:`, `int:`, `float:`, `double:` |
| 4 | Handle non-displayable char, overflow (`impossible`), formatting (`.0f`, `.0`) |

**Checkpoint:** `./convert 42` and `./convert nan` match subject output format.

---

## Phase 2 — ex01: Serializer (½–1 day)

| Step | Task |
|------|------|
| 1 | Define `Data` struct with mixed members |
| 2 | Implement `uintptr_t serialize(Data* ptr)` with `reinterpret_cast` |
| 3 | Implement `Data* deserialize(uintptr_t raw)` |
| 4 | Prove round-trip in `main`: same address, data intact |

**Checkpoint:** Explain why this is only meaningful within the same process.

---

## Phase 3 — ex02: Identify real type (1 day)

| Step | Task |
|------|------|
| 1 | Create polymorphic `Base` with virtual destructor |
| 2 | Empty derived classes `A`, `B`, `C` |
| 3 | `Base* generate()` — random `new A/B/C` |
| 4 | `identify(Base*)` — use `dynamic_cast` pointer form (null on failure) |
| 5 | `identify(Base&)` — use `dynamic_cast` reference form (**no if/else** — try/catch) |

**Checkpoint:** Reference version prints A, B, or C using only `dynamic_cast` + exceptions.

---

## Phase 4 — Evaluation prep

- Rehearse when each cast is appropriate
- Confirm no C-style casts in submission
- `make re` all exercises with `-std=c++20`
