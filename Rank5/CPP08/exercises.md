# CPP08 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP08. |
| **Bonus** | Optional parts inside an exercise — **not** required to pass. |

CPP08 has **3 mandatory exercises**. ex01 includes an optional **bonus** range insert.

---

## ex00 — Easy find

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `easyfind.hpp` |

### What you build

A function template that finds an **int** in any STL container with iterators.

### Expected API

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value);
// or throws if not found — per subject
```

### Expected behaviour

- Uses **`std::find`** from `<algorithm>`
- Returns iterator to match **or** throws exception if not found
- `main` tests with at least `std::vector<int>` and `std::list<int>`

### Evaluator will check

- Found value returns valid iterator
- Missing value throws (or handles per subject)
- Works across container types

---

## ex01 — Span

| | |
|---|---|
| **Mandatory** | Yes (core methods) |
| **Bonus** | `addNumbers(iterator, iterator)` — range insert for large datasets |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `Span.{h,hpp,cpp}` |

### What you build

A class that stores up to **N** integers and reports **shortest** and **longest** span.

### Expected interface

```cpp
class Span {
public:
    Span(unsigned int N);
    void addNumber(int n);
    int shortestSpan();   // min distance between any two stored values
    int longestSpan();    // max - min
    // Bonus:
    template<typename It>
    void addNumbers(It begin, It end);
};
```

### Expected behaviour

| Case | Result |
|------|--------|
| `addNumber` when full | Throw exception |
| `shortestSpan` / `longestSpan` with &lt; 2 numbers | Throw exception |
| Example: 6, 3, 17, 9, 11 | shortest = 2 (11−9), longest = 14 (17−3) |
| Uses STL | `std::vector`, `std::sort`, `std::min_element`, etc. |

### Bonus (optional)

- `addNumbers` inserts thousands of values via iterators in one call
- Must respect max capacity

### Evaluator will check

- Span calculations correct
- Exceptions on edge cases
- OCF on `Span`
- Bonus tested only if you present it

---

## ex02 — Mutated abomination

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `MutantStack.hpp` |

### What you build

An iterable **`std::stack`** by exposing the underlying container’s iterators.

### Expected design

```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    // iterator, const_iterator, reverse_iterator typedefs
    // begin(), end(), rbegin(), rend() — const overloads too
};
```

### Expected behaviour

- All normal **stack** operations work (`push`, `pop`, `top`, `size`)
- Can iterate bottom-to-top with iterators
- Subject test output should match equivalent operations on `std::list`

### Key implementation detail

Access protected member **`c`** (underlying deque) to expose iterators.

### Evaluator will check

- Iterator loop prints correct order
- Stack behaviour unchanged
- Comparison with `std::list` output in subject `main`

---

## Module checklist

- [ ] STL allowed and used appropriately
- [ ] `typename T::iterator` where needed
- [ ] OCF on `Span` class
