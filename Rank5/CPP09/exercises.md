# CPP09 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP09. |
| **Bonus** | None in standard subject — all three exercises mandatory. |

CPP09 is the **final C++ module**. All exercises must pass for module completion.

---

## ex00 — Bitcoin Exchange

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `BitcoinExchange.{h,hpp,cpp}`, `data.csv` |

### What you build

Program reading an input file of `date | value` lines and printing bitcoin value using historical exchange rates from `data.csv`.

### Input / output

```text
# input line
2011-01-03 | 3

# output
2011-01-03 => 3 = 0.9
```

(Exact multiplier depends on rate in database.)

### Expected behaviour

| Validation | Error message |
|------------|---------------|
| Bad line format | `Error: bad input => <line>` |
| Not a positive number | `Error: not a positive number.` |
| Value &gt; 1000 | `Error: too large a number.` |
| Invalid date | Per subject (often bad input) |
| Date not in DB | Use **closest earlier** date’s rate |
| Missing file | `Error: could not open file.` |

### Technical requirements

- Load `data.csv` into **`std::map<std::string, float>`** (date → rate)
- Date format `YYYY-MM-DD` with valid calendar dates (leap years)
- Use `lower_bound` or equivalent for closest earlier date

### Evaluator will check

- Correct multiplication `value * rate`
- Error strings exact
- Leap year / invalid date handling
- Large CSV loads without crash

---

## ex01 — Reverse Polish Notation

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `RPN.{h,hpp,cpp}` |

### What you build

RPN (**postfix**) calculator evaluating numeric expressions from command-line arguments.

### Usage

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# 42

./RPN "1 2 +"
# 3

./RPN "(1 + 1)"
# Error
```

### Expected behaviour

| Rule | Detail |
|------|--------|
| Numbers | Typically single-digit **0–9** only |
| Operators | `+`, `-`, `*`, `/` |
| Algorithm | Stack: push numbers; on operator pop two, compute, push result |
| Division by zero | Error (exit or print `Error`) |
| Invalid expression | Print `Error` |
| Final stack | Exactly one value remaining |

### Technical requirements

- Use **`std::stack`**
- Integer arithmetic (division truncates for ints)

### Evaluator will check

- Subject example outputs
- Division by zero
- Malformed input (too few operands, invalid tokens)

---

## ex02 — PmergeMe

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `PmergeMe.{h,hpp,cpp}` |

### What you build

Sort a sequence of **positive integers** using the **Ford-Johnson** (merge-insertion) algorithm, implemented for both **`std::vector`** and **`std::deque`**, with timing comparison.

### Usage

```bash
./PmergeMe 3 5 9 7 4
```

### Expected output

```text
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : X us
Time to process a range of 5 elements with std::deque  : Y us
```

### Expected behaviour

| Rule | Detail |
|------|--------|
| Input | Positive integers only as argv |
| Invalid input | Clear error handling |
| Algorithm | **Ford-Johnson** — not `std::sort` as the core algorithm |
| Containers | Both `vector` and `deque` sorted independently |
| Timing | Print microseconds (or subject format) for each |
| Large input | Handle ~3000 integers |
| Display | If &gt;5 numbers, show first 5 before/after |

### Evaluator will check

- Sorted output correct
- Both container timings printed
- `shuf -i 1-100000 -n 3000` scale test
- Algorithm is actually merge-insertion (may ask to explain)

---

## Module checklist

- [ ] `data.csv` included for ex00
- [ ] No forbidden functions per subject
- [ ] Ford-Johnson implemented, not only `std::sort`
- [ ] All error messages match subject exactly
