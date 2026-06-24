# Exam Rank 05 — Exercise breakdown (level 00)

Each exercise lives in its own directory with a `guide.md` and `reference/` solution.

---

## vect2

| | |
|---|---|
| **Directory** | [vect2/](./vect2/) |
| **Files** | `vect2.hpp`, `vect2.cpp` |
| **Reference** | [vect2/reference/](./vect2/reference/) |

2D integer vector — see [vect2/guide.md](./vect2/guide.md).

---

## bigint

| | |
|---|---|
| **Directory** | [bigint/](./bigint/) |
| **Files** | `bigint.hpp`, `bigint.cpp` |
| **Reference** | [bigint/reference/](./bigint/reference/) |

Arbitrary-precision unsigned integer — see [bigint/guide.md](./bigint/guide.md).

---

## polyset

| | |
|---|---|
| **Directory** | [polyset/](./polyset/) |
| **Files** | `searchable_array_bag.*`, `searchable_tree_bag.*`, `set.*` |
| **Reference** | [polyset/reference/](./polyset/reference/) |
| **Given** | [polyset/given/](./polyset/given/) |

Searchable bags + set wrapper — see [polyset/guide.md](./polyset/guide.md).

---

## Common exam rules

| Rule | Detail |
|------|--------|
| Given main | Must compile and run without modification |
| File names | Exact match to subject |
| Orthodox canonical form | Default/copy ctor, copy assign, dtor where required |
| `const` | Match subject signatures |
| Time | Level 00 ~3 hours for one exercise |

---

## Evaluation traps

| Trap | Exercise |
|------|----------|
| Post-increment returns old value | vect2, bigint |
| Missing `const operator[]` | vect2 |
| Leading zeros in bigint output | bigint |
| `>>=` uses rhs bigint **value** as digit count | bigint |
| `set::insert` adds duplicates | polyset |
| Missing `operator*(int, vect2)` | vect2 |

---

## Test reference solutions

```bash
cd Rank5/Exam-Rank-05
make all
```
