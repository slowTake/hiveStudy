# CPP09 — Theory and concepts

## Module-wide

CPP09 combines **data structures**, **parsing**, and **algorithms** at practical scale. Focus on correct validation messages and container choice.

---

## ex00 — Bitcoin Exchange

### Data model

```cpp
std::map<std::string, float> _database;  // "YYYY-MM-DD" -> rate
```

`map` keeps keys sorted — enables `lower_bound` for “closest earlier date.”

### Input line format

```text
2011-01-03 | 3
```

### Validation rules

| Check | Error |
|-------|-------|
| Bad format | `Error: bad input => ...` |
| Invalid date | `Error: bad input => ...` or date-specific per subject |
| Negative value | `Error: not a positive number.` |
| Value > 1000 | `Error: too large a number.` |
| Date before DB | handle per subject (often error) |

### Closest earlier date

```cpp
auto it = _database.lower_bound(date);
if (it == _database.begin() && (it == _database.end() || it->first != date))
    // no earlier rate
if (it != _database.end() && it->first == date)
    return it->second;
if (it != _database.begin()) { --it; return it->second; }
```

### Date validation

- Months 1–12, days per month, leap year for February
- Zero-padded `YYYY-MM-DD` format

---

## ex01 — Reverse Polish Notation

### RPN recap

Postfix notation: operands first, operator last.

```text
8 9 * 9 - 9 - 9 - 4 - 1 +   →   42
```

### Algorithm

```
for each token:
  if number → push
  if operator → pop b, pop a, push a op b
end
result = stack.top()  (only if stack size == 1)
```

### Subject constraints

- Typically single-digit integers only
- Operators: `+ - * /`
- Integer division for `/`
- Division by zero → error

### Why stack

LIFO matches “most recent operands first” for binary operators.

---

## ex02 — PmergeMe (Ford-Johnson)

### Objective

Sort a sequence of positive integers using **merge-insertion sort** (Ford-Johnson algorithm), implemented separately for `vector` and `deque`, with timing comparison.

### Ford-Johnson outline

1. **Pair elements** and sort pairs (larger elements form main chain)
2. **Recursively sort** main chain (larger elements)
3. **Insert** smaller elements using Jacobsthal sequence for optimal insert order
4. Handle odd leftover element

This is **not** a call to `std::sort` — you implement the algorithm.

### Timing

```cpp
#include <chrono>

auto start = std::chrono::steady_clock::now();
// sort
auto end = std::chrono::steady_clock::now();
auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
```

Subject may specify `clock()` — use what evaluation sheet expects; chrono is cleaner in C++20.

### Output format

```text
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of N elements with std::vector : X us
Time to process a range of N elements with std::deque  : Y us
```

### vector vs deque

| | vector | deque |
|---|--------|-------|
| Memory | Contiguous | Chunked blocks |
| Insert middle | O(n) | O(n) but different constants |
| Cache | Often faster sequential | More pointer chasing |

Expect different timings for same algorithm.

### Pitfalls

- Using `std::sort` instead of Ford-Johnson
- Non-positive numbers in input
- Displaying entire sequence when N > 5

---

## Evaluation topics

1. `map::lower_bound` behavior
2. RPN trace on whiteboard
3. Why Ford-Johnson is O(n log n) with fewer comparisons
4. When to pick `vector` over `deque`
