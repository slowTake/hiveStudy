# Exam Rank 05 — Exercise breakdown (level 00)

Level 00 exercises from the new Exam Rank 05 pool. You receive **one** at random per attempt.

---

## vect2

| | |
|---|---|
| **Files** | `vect2.hpp`, `vect2.cpp` |
| **Topic** | Operator overloading, OCF |
| **Guide** | [vect2.md](./vect2.md) |

2D integer vector with `+`, `-`, `*`, `+=`, `-=`, `*=`, unary `-`, pre/post `++`/`--`, `[]`, `==`/`!=`, `<<`, and free `int * vect2`.

---

## bigint

| | |
|---|---|
| **Files** | `bigint.hpp`, `bigint.cpp` |
| **Topic** | String arithmetic, operators |
| **Guide** | [bigint.md](./bigint.md) |

Arbitrary-precision **unsigned** integer stored as a decimal string. Supports `+`, `+=`, `++` (pre/post), `<<` / `<<=` (digit shift left), `>>=` (digit shift right), comparisons, and `<<` stream output (no leading zeros).

---

## polyset

| | |
|---|---|
| **Files** | `searchable_array_bag.{hpp,cpp}`, `searchable_tree_bag.{hpp,cpp}`, `set.{hpp,cpp}` |
| **Topic** | Multiple inheritance, virtual inheritance, polymorphism |
| **Guide** | [polyset.md](./polyset.md) |

Extend given `array_bag` / `tree_bag` hierarchy with `has()`, then wrap a `searchable_bag` in a `set` that rejects duplicate inserts.

Given files (do not modify): `bag.hpp`, `searchable_bag.hpp`, `array_bag.*`, `tree_bag.*`, `main.cpp`.

---

## Common exam rules

| Rule | Detail |
|------|--------|
| Given main | Must compile and run without modification |
| File names | Exact match to subject — typos fail |
| Orthodox canonical form | Default ctor, copy ctor, copy assign, dtor where applicable |
| `const` | Match subject signatures — `has() const`, `print() const`, etc. |
| No leaks | Especially polyset (trees, arrays) |
| Time | Level 00 typically ~3 hours total for one exercise |

---

## Evaluation traps (all exercises)

| Trap | Applies to |
|------|------------|
| Post-increment returns **old** value | vect2, bigint |
| `const` object calling non-`const` `operator[]` | vect2 |
| Leading zeros in bigint output | bigint |
| `>>=` shift count = **value** of rhs bigint, not bit count | bigint |
| Diamond inheritance without `virtual` | polyset |
| `set::insert` adds duplicates | polyset |
| Forgot free `operator*(int, vect2)` | vect2 |
| `operator=` missing self-assignment guard | all |

---

## Practice repos (external)

Community subjects and mains (verify against your exam version):

- [flmarsou/42nice-exam05](https://github.com/flmarsou/42nice-exam05) — subjects + mains for bigint, vect2, polyset
- [fbkeskin/42-exam-rank-05](https://github.com/fbkeskin/42-exam-rank-05) — passed solutions (use for testing only after your own attempt)

Do not submit copied code — exam similarity checks and defense questions apply.
