# CPP08 — Study plan

## Phase 0 — STL foundations (1 day)

| Topic | Action |
|-------|--------|
| `std::vector`, `std::list` | Push, iterate, `begin`/`end` |
| Iterators | `*it`, `++it`, `it != end` |
| `<algorithm>` | `find`, `sort`, `min_element`, `max_element` |
| `typename T::iterator` | Dependent type in templates |

**Checkpoint:** Iterate a `vector<int>` with iterators and range-for.

---

## Phase 1 — ex00: easyfind (½ day)

| Step | Task |
|------|------|
| 1 | Template `easyfind(container, value)` |
| 2 | Return iterator or throw `std::exception` if not found |
| 3 | Test with `vector` and `list` |

---

## Phase 2 — ex01: Span (1–2 days)

| Step | Task |
|------|------|
| 1 | Store up to N ints in `vector` |
| 2 | `addNumber`, `shortestSpan`, `longestSpan` |
| 3 | Exceptions: full span, fewer than 2 numbers |
| 4 | Bonus: `addNumbers` iterator range |

---

## Phase 3 — ex02: MutantStack (1–2 days)

| Step | Task |
|------|------|
| 1 | `template<typename T> class MutantStack : public std::stack<T>` |
| 2 | Expose iterators via protected member `c` (underlying deque) |
| 3 | Match subject test output vs `std::list` behavior |
| 4 | typedef iterator types |

---

## Phase 4 — Evaluation prep

- Explain iterator invalidation basics on `vector`
- Time complexity of `shortestSpan` with sort
- `make re` all exercises
