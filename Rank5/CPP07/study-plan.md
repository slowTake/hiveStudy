# CPP07 — Study plan

## Phase 0 — Template basics (before ex00)

| Topic | Action |
|-------|--------|
| Function templates | Syntax `template<typename T>` |
| Type deduction | Compiler deduces `T` from arguments |
| Template instantiation | Each `(T)` combo generates code |
| Header-only pattern | Why templates live in headers |

**Checkpoint:** Explain why `min(3, 3.14)` fails to compile.

---

## Phase 1 — ex00: swap, min, max (½ day)

| Step | Task |
|------|------|
| 1 | Implement `swap(T& a, T& b)` |
| 2 | Implement `min(T const& a, T const& b)` |
| 3 | Implement `max(T const& a, T const& b)` |
| 4 | Test with `int` and `std::string` in `main` |

---

## Phase 2 — ex01: iter (½–1 day)

| Step | Task |
|------|------|
| 1 | `iter(T* array, size_t len, void (*f)(T&))` or template functor variant |
| 2 | Write helper functions: print, increment |
| 3 | Test on `int[]` and `std::string[]` |

---

## Phase 3 — ex02: Array class template (2 days)

| Step | Task |
|------|------|
| 1 | Default ctor (empty), sized ctor `Array(unsigned int n)` |
| 2 | Deep copy ctor and assignment |
| 3 | `operator[]` with bounds check → `OutOfBoundsException` |
| 4 | `size()` member |
| 5 | `delete[]` in destructor |

**Checkpoint:** `Array<int> a(5); a[10] = 1;` throws; copy is independent.

---

## Phase 4 — Evaluation prep

- Explain template vs macro
- Walk through OCF for `Array<std::string>`
- `make re` all exercises
