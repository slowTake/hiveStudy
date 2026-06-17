# CPP08 — Theory and concepts

## Module-wide: STL triad

| Component | Role |
|-----------|------|
| **Containers** | Store data (`vector`, `list`, `deque`, `map`, …) |
| **Iterators** | Generalized pointers traversing containers |
| **Algorithms** | `find`, `sort`, … operating on iterator ranges |

Algorithms are **non-member** functions in `<algorithm>` that work on any container exposing suitable iterators.

---

## ex00 — easyfind

### Objective

Generic linear search returning an iterator to the first match.

### Implementation sketch

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();  // or custom NotFoundException
    return it;
}
```

### Concepts

- **`typename T::iterator`:** dependent type — `typename` keyword required in templates
- **`std::find`:** O(n) linear search
- Works on any container with forward iterators

---

## ex01 — Span

### Objective

Fixed-capacity collection of integers; report shortest and longest **span** (distance between any two values).

### Definitions

| Method | Meaning |
|--------|---------|
| `shortestSpan()` | Minimum difference between any two distinct stored values |
| `longestSpan()` | `max - min` over all stored values |

### Algorithms

**Longest span:**

```cpp
auto minIt = std::min_element(_vec.begin(), _vec.end());
auto maxIt = std::max_element(_vec.begin(), _vec.end());
return *maxIt - *minIt;
```

**Shortest span:** sort copy, scan adjacent differences:

```cpp
std::vector<int> sorted = _vec;
std::sort(sorted.begin(), sorted.end());
int best = sorted[1] - sorted[0];
for (size_t i = 2; i < sorted.size(); ++i)
    best = std::min(best, sorted[i] - sorted[i - 1]);
```

### Exceptions

- `SpanException` / `NoSpanException` — fewer than 2 numbers
- Full span — cannot `addNumber` when at capacity

### Bonus: range insert

```cpp
template<typename It>
void addNumbers(It begin, It end) {
    if (std::distance(begin, end) + _vec.size() > _max)
        throw SpanFullException();
    _vec.insert(_vec.end(), begin, end);
}
```

---

## ex02 — MutantStack

### Objective

`std::stack` is a **container adapter** — LIFO, no iterators by default. Expose underlying container iterators.

### Key insight

`std::stack<T, Container>` wraps `Container c` (protected). Default container is `deque`.

```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
    // const + reverse variants per subject
};
```

### Iterator order

Stack bottom → top maps to `begin()` → `end()` on underlying `deque`.

### Comparison test

Subject compares iteration order with `std::list` after equivalent push sequence — understand push order vs iteration order.

---

## Container cheat sheet

| Container | Access | Insert end | Search |
|-----------|--------|------------|--------|
| `vector` | O(1) index | O(1) amortized | O(n) |
| `list` | O(n) | O(1) | O(n) |
| `deque` | O(1) ends | O(1) | O(n) |

---

## Evaluation topics

1. Difference between `vector` and `list`
2. What `std::stack` is and why it hides iterators
3. Why `typename` is needed before `T::iterator`
4. Exception when `easyfind` fails
