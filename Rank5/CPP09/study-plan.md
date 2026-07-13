# CPP09 — Study plan

## Phase 0 — Parsing & maps (before ex00)

| Topic | Action |
|-------|--------|
| `std::map` | Ordered key-value, `find`, `lower_bound` |
| File I/O | `std::ifstream`, line-by-line |
| String split | `find`, `substr` on `YYYY-MM-DD` and CSV |
| Date validation | Leap years, month lengths |

---

## Phase 1 — ex00: Bitcoin Exchange (2–3 days)

| Step | Task |
|------|------|
| 1 | Load `data.csv` into `map<string, float>` (date → rate) |
| 2 | Parse input file: `date \| value` |
| 3 | Validate date, value in (0, 1000] |
| 4 | Lookup rate: exact date or closest **earlier** date |
| 5 | Print result or precise error messages |

---

## Phase 2 — ex01: RPN (1–2 days)

| Step | Task |
|------|------|
| 1 | Tokenize CLI arguments or single string |
| 2 | Stack: numbers push, operators pop twice and compute |
| 3 | Support `+ - * /` on single-digit ints (per subject) |
| 4 | Print result or `Error` |

---

## Phase 3 — ex02: PmergeMe (3–5 days)

| Step | Task |
|------|------|
| 1 | Parse positive integers from argv |
| 2 | Implement Ford-Johnson merge-insert sort |
| 3 | Run on `std::vector` and `std::deque` |
| 4 | Measure and print microsecond timings |
| 5 | Display before/after (first 5 if large) |

**Checkpoint:** Sort 3000+ numbers; deque vs vector times printed.

---

## Phase 4 — Evaluation prep

- Explain `lower_bound` for bitcoin closest date
- Walk through RPN stack on paper
- Describe Ford-Johnson at high level (pairing, Jacobsthal insertion)
- `make re` + test edge cases
