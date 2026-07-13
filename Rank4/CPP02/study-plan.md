# CPP02 — Study plan

## Phase 0 — OCF fundamentals (1–2 days)

| Topic | Action |
|-------|--------|
| Rule of Three | If you define one of dtor/copy ctor/copy assign, define all |
| Deep vs shallow copy | Pointer members need duplicated resources |
| Self-assignment | `if (this != &other)` guard |
| Initializer lists | Required for `const` and reference members |

**Checkpoint:** Draw memory diagrams for shallow vs deep copy on destruction.

---

## Phase 1 — ex00 My First Class (1 day)

Implement a trivial class with all four OCF functions even if some are `= default` only where safe.

---

## Phase 2 — ex01 Casts (1 day)

| Cast | Use case |
|------|----------|
| `static_cast` | Safe numeric / hierarchy upcasts |
| `dynamic_cast` | Runtime polymorphism checks |
| `const_cast` | Add/remove const (rare, documented) |
| `reinterpret_cast` | Low-level bit reinterpretation |

Replace C-style `(type)value` with explicit C++ casts in provided code.

---

## Phase 3 — ex02 Fixed (3–4 days)

| Step | Task |
|------|------|
| 1 | Store value as integer with **8 fractional bits** (subject standard) |
| 2 | Constructors from int and float |
| 3 | Operators: `+`, `-`, `*`, `/`, comparisons, `<<` |
| 4 | `toInt()`, `toFloat()` |

**Checkpoint:** `42.42` represented without storing `float` internally.

---

## Phase 4 — ex03 OCF exercise (2 days)

Apply full OCF to class owning dynamic resource (often a string buffer or array).

---

## Evaluation prep

- Copy assignment returns `Fixed&`
- No `-fsanitize` reliance — fix real bugs
- Test copy: `Fixed b = a; Fixed c; c = a;`
