# CPP08 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP08. |
| **Bonus** | Optional parts inside an exercise — **not** required to pass. |

CPP08 has **3 mandatory exercises**. ex01 includes an optional **bonus** range insert.

---

## Module concepts

### STL triad

| Component | Role |
|-----------|------|
| **Containers** | Store data (`vector`, `list`, `deque`, `map`, …) |
| **Iterators** | Generalized pointers traversing containers (`begin`/`end`, `*it`, `++it`) |
| **Algorithms** | `find`, `sort`, `min_element`, … in `<algorithm>` operating on iterator ranges |

Algorithms are **non-member** functions that work on any container exposing suitable iterators. CPP08 is the first module where STL containers and `<algorithm>` are **allowed and expected**.

### Iterators and dependent types

- Iterator type is container-specific: `std::vector<int>::iterator` vs `std::list<int>::iterator`.
- In templates, `T::iterator` is a **dependent type** — write `typename T::iterator` (or `using iterator = typename T::iterator;`).
- Forward iterators suffice for `std::find`; both `vector` and `list` qualify.

### Common containers (evaluation-relevant)

| Container | Access | Insert end | Search |
|-----------|--------|------------|--------|
| `vector` | O(1) index | O(1) amortized | O(n) |
| `list` | O(n) | O(1) | O(n) |
| `deque` | O(1) ends | O(1) | O(n) |

Know the trade-off: `vector` — contiguous, fast random access; `list` — no invalidation on insert/erase, no `[]`.

---

## ex00 — Easy find

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `easyfind.hpp` |

### Concepts

- Generic **linear search** returning an iterator to the first match.
- Delegate to **`std::find`** — O(n), works on any container with forward iterators.
- On failure, throw `std::exception` (or a custom `NotFoundException` per subject).
- `typename` before `T::iterator` is mandatory in the template definition.

### Requirements

| Requirement | Detail |
|-------------|--------|
| API | `template<typename T> typename T::iterator easyfind(T& container, int value);` |
| Algorithm | Use **`std::find`** from `<algorithm>` |
| Success | Return iterator to first matching element |
| Failure | Throw exception if value not found |
| `main` | Test with at least `std::vector<int>` and `std::list<int>` |
| Location | Function template in header (`easyfind.hpp`) |

### Pitfalls & evaluator checks

- Missing `typename` before `T::iterator` → compile error in templates.
- Returning `container.end()` instead of throwing when not found (subject expects exception).
- Only testing one container type — evaluator expects both `vector` and `list`.
- Found value must return a **valid** iterator; missing value must **throw**.
- Be ready to explain why `typename` is needed and what `std::find` does.

---

## ex01 — Span

| | |
|---|---|
| **Mandatory** | Yes (core methods) |
| **Bonus** | `addNumbers(iterator, iterator)` — range insert for large datasets |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `Span.{h,hpp,cpp}` |

### Concepts

- Fixed-capacity collection of integers (store in `std::vector<int>`).
- **Shortest span** — minimum difference between any two **distinct** stored values (adjacent values after sorting).
- **Longest span** — `max − min` over all stored values (`max_element` / `min_element`).
- Shortest-span approach: copy, `std::sort`, scan adjacent differences with `std::min`.
- Custom exceptions: fewer than 2 numbers (`SpanException` / `NoSpanException`); full capacity on `addNumber`.
- **Bonus:** template `addNumbers(It begin, It end)` — check `std::distance(begin, end) + size ≤ N` before `insert`.

### Requirements

| Requirement | Detail |
|-------------|--------|
| API | `Span(unsigned int N);` `void addNumber(int n);` `int shortestSpan();` `int longestSpan();` |
| Bonus API | `template<typename It> void addNumbers(It begin, It end);` |
| Capacity | `addNumber` when full → throw exception |
| Span queries | `shortestSpan` / `longestSpan` with &lt; 2 numbers → throw exception |
| Example | Values 6, 3, 17, 9, 11 → shortest = **2** (11−9), longest = **14** (17−3) |
| STL | `std::vector`, `std::sort`, `std::min_element`, `std::max_element`, `std::min` |
| OCF | Required on `Span` |
| Bonus | Insert thousands of values via iterators in one call; must respect max capacity |

### Pitfalls & evaluator checks

- Confusing shortest span with longest — shortest needs sorting or equivalent O(n log n) approach.
- Forgetting exception when only 0 or 1 number stored.
- Bonus: not checking total size before insert → silent overflow or UB.
- Shallow copy / missing OCF — evaluator tests independence after copy-assign.
- Span calculations must be **correct** on edge cases; bonus tested only if presented.
- Be ready to discuss time complexity of `shortestSpan` (sort-based solution).

---

## ex02 — Mutated abomination

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `MutantStack.hpp` |

### Concepts

- `std::stack` is a **container adapter** — LIFO interface, **no iterators** by default.
- `std::stack<T, Container>` wraps protected member **`c`** (default container: `deque`).
- Inherit `std::stack<T>` and expose `c.begin()` / `c.end()` as stack iterators.
- Iterator order: stack **bottom → top** maps to `begin()` → `end()` on underlying `deque`.
- Provide `iterator`, `const_iterator`, `reverse_iterator`, `reverse_const_iterator` typedefs plus `begin`/`end`/`rbegin`/`rend` (const overloads).
- Subject compares iteration order with `std::list` after equivalent push sequence.

### Requirements

| Requirement | Detail |
|-------------|--------|
| Design | `template<typename T> class MutantStack : public std::stack<T>` |
| Iterators | typedefs + `begin()`, `end()`, `rbegin()`, `rend()` — const overloads |
| Implementation | Access protected member **`c`** (underlying deque) for iterator endpoints |
| Stack ops | `push`, `pop`, `top`, `size` unchanged |
| Iteration | Bottom-to-top order via iterators |
| `main` | Output must match equivalent operations on `std::list` (subject test) |
| OCF | Required if implemented beyond header-only pattern |

### Pitfalls & evaluator checks

- Using wrong container typedef (`deque` vs `list`) — default stack uses `deque`; match subject expectations.
- Reversing iteration order (top-first vs bottom-first).
- Breaking stack invariants while adding iterators.
- Iterator loop must print **correct order**; stack behaviour must be **unchanged**.
- Comparison output with `std::list` in subject `main` must match.
- Be ready to explain what `std::stack` is, why it hides iterators, and difference between `vector` and `list`.

---

## Module checklist

- [ ] STL allowed and used appropriately (`<algorithm>`, containers)
- [ ] `typename T::iterator` (or `using`) where needed in templates
- [ ] OCF on `Span` (and `MutantStack` if not header-only)
- [ ] `-std=c++20 -Wall -Wextra -Werror` on all exercises
- [ ] Three separate `ex00/` … `ex02/` directories
- [ ] `make re` clean-builds every exercise
- [ ] Can explain: `vector` vs `list`, `std::stack` as adapter, `typename` rule, `easyfind` exception
