# CPP09 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP09. |
| **Bonus** | None in standard subject — all three exercises mandatory. |

CPP09 is the **final C++ module**. All exercises must pass for module completion.

---

## Module concepts (STL containers & algorithms)

CPP09 combines **data structures**, **parsing**, and **algorithms** at practical scale. Container choice and exact error strings matter as much as correctness.

| Container | Use in module | Why |
|-----------|---------------|-----|
| `std::map` | ex00 date → rate DB | Keys sorted; `lower_bound` finds closest earlier date |
| `std::stack` | ex01 RPN | LIFO — most recent operands popped first for binary ops |
| `std::vector` / `std::deque` | ex02 PmergeMe | Same Ford-Johnson on both; compare timing |

**Algorithms:** ex00 uses `map::lower_bound` (not a full search from scratch). ex02 requires **Ford-Johnson merge-insertion sort** — not `std::sort` as the core algorithm. ex01 is stack-driven evaluation, not a library algorithm.

**Evaluation topics (module-wide):** `lower_bound` behavior; RPN trace on whiteboard; why Ford-Johnson is O(n log n) with fewer comparisons; when `vector` beats `deque`.

---

## ex00 — Bitcoin Exchange

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `BitcoinExchange.{h,hpp,cpp}`, `data.csv` |

### Concepts

Program reads an input file of `date | value` lines and prints bitcoin value using historical rates from `data.csv`.

```cpp
std::map<std::string, float> _database;  // "YYYY-MM-DD" -> rate
```

`map` keeps keys sorted — enables `lower_bound` for the **closest earlier date** when the exact date is missing.

**Input line format:** `2011-01-03 | 3` → output `2011-01-03 => 3 = 0.9` (multiplier depends on rate).

**Closest earlier date** (core lookup):

```cpp
auto it = _database.lower_bound(date);
if (it == _database.begin() && (it == _database.end() || it->first != date))
    // no earlier rate
if (it != _database.end() && it->first == date)
    return it->second;
if (it != _database.begin()) { --it; return it->second; }
```

**Date validation:** zero-padded `YYYY-MM-DD`; months 1–12; days per month; leap year for February.

### Requirements

| Area | Detail |
|------|--------|
| Data store | Load `data.csv` into `std::map<std::string, float>` (date → rate) |
| Lookup | `lower_bound` or equivalent for closest earlier date |
| Arithmetic | Print `value * rate` |
| Bad line format | `Error: bad input => <line>` |
| Invalid date | `Error: bad input => ...` or date-specific per subject |
| Negative value | `Error: not a positive number.` |
| Value > 1000 | `Error: too large a number.` |
| Date before DB | Handle per subject (often error) |
| Missing file | `Error: could not open file.` |

### Pitfalls & evaluator checks

- Error strings must match subject **exactly**
- Leap years and invalid calendar dates (e.g. `2011-02-30`)
- Large CSV loads without crash
- `lower_bound` edge cases: exact match, date before first DB entry, gap between dates
- Evaluator may ask you to explain `map::lower_bound` behavior on the whiteboard

---

## ex01 — Reverse Polish Notation

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `RPN.{h,hpp,cpp}` |

### Concepts

RPN (**postfix**): operands first, operator last. Example: `8 9 * 9 - 9 - 9 - 4 - 1 +` → `42`.

**Algorithm:**

```
for each token:
  if number → push
  if operator → pop b, pop a, push a op b
end
result = stack.top()  (only if stack size == 1)
```

Use **`std::stack`** — LIFO matches “most recent operands first” for binary operators.

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"   # 42
./RPN "1 2 +"                         # 3
./RPN "(1 + 1)"                       # Error
```

### Requirements

| Area | Detail |
|------|--------|
| Container | `std::stack` |
| Numbers | Typically single-digit **0–9** only |
| Operators | `+`, `-`, `*`, `/` |
| Division | Integer arithmetic; `/` truncates |
| Division by zero | Error (exit or print `Error`) |
| Invalid expression | Print `Error` (too few operands, invalid tokens) |
| Final state | Exactly one value on stack |

### Pitfalls & evaluator checks

- Subject example outputs must match
- Malformed input: extra operands, unknown tokens, parentheses
- Evaluator may trace a small expression on the whiteboard step by step

---

## ex02 — PmergeMe

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `PmergeMe.{h,hpp,cpp}` |

### Concepts

Sort **positive integers** from argv using **Ford-Johnson** (merge-insertion sort), implemented separately for `vector` and `deque`, with timing comparison.

**Ford-Johnson outline:**

1. Pair elements; sort pairs (larger elements form main chain)
2. Recursively sort main chain
3. Insert smaller elements using Jacobsthal sequence for optimal insert order
4. Handle odd leftover element

This is **not** a call to `std::sort` — you implement the algorithm.

**Timing** (`chrono` is fine in C++20; subject may specify `clock()` — follow evaluation sheet):

```cpp
auto start = std::chrono::steady_clock::now();
// sort
auto end = std::chrono::steady_clock::now();
auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
```

**vector vs deque:**

| | vector | deque |
|---|--------|-------|
| Memory | Contiguous | Chunked blocks |
| Insert middle | O(n) | O(n), different constants |
| Cache | Often faster sequential | More pointer chasing |

```bash
./PmergeMe 3 5 9 7 4
```

```text
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : X us
Time to process a range of 5 elements with std::deque  : Y us
```

### Requirements

| Area | Detail |
|------|--------|
| Input | Positive integers only as argv |
| Algorithm | Ford-Johnson merge-insertion — not `std::sort` as core |
| Containers | Both `vector` and `deque` sorted independently |
| Timing | Print microseconds (or subject format) for each |
| Scale | Handle ~3000 integers (`shuf -i 1-100000 -n 3000`) |
| Display | If >5 numbers, show first 5 before/after |
| Invalid input | Clear error handling |

### Pitfalls & evaluator checks

- Using `std::sort` instead of Ford-Johnson fails evaluation
- Non-positive numbers in input
- Forgetting to print both container timings
- Evaluator may ask why Ford-Johnson is O(n log n) with fewer comparisons
- May ask when to pick `vector` over `deque`

---

## Module checklist

- [ ] `data.csv` included for ex00
- [ ] No forbidden functions per subject
- [ ] Ford-Johnson implemented, not only `std::sort`
- [ ] All error messages match subject exactly
- [ ] ex00 `lower_bound` handles exact match and closest earlier date
- [ ] ex01 stack ends with exactly one value
- [ ] ex02 both `vector` and `deque` timings printed
