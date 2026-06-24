# Exam Rank 05

Timed practical exam covering C++ OOP topics from Rank 5. Level 00 exercises: **vect2**, **polyset**, **bigint**.

**Standard:** C++20 (`-std=c++20`) at The Hive.

## Exercises

| Exercise | Directory | Reference solution |
|----------|-----------|-------------------|
| [vect2](./vect2/) | 2D vector operators | [vect2/reference/](./vect2/reference/) |
| [bigint](./bigint/) | String bignum | [bigint/reference/](./bigint/reference/) |
| [polyset](./polyset/) | Inheritance + set | [polyset/reference/](./polyset/reference/) |

Each directory contains:

- `guide.md` — algorithm walkthrough
- `main.cpp` — exam test harness
- `reference/` — working solution to compare while studying

## Quick test

```bash
cd Rank5/Exam-Rank-05
make all          # compile and run all three references
make test-bigint  # one exercise only
```

## Shared material

- [study-plan.md](./study-plan.md) — prep order
- [exercises.md](./exercises.md) — requirements and eval traps
- [theory-and-concepts.md](./theory-and-concepts.md) — OOP / operator concepts

## Exam format

| Level | Exercises |
|-------|-----------|
| 00 | `vect2`, `polyset`, `bigint` (one random) |
| 01 | `life`, `bsq`, … |

Practice all three level-00 exercises — you do not choose which one you get.

## Study workflow

1. Read the exercise `guide.md`
2. Implement from scratch (timed)
3. Diff your code against `reference/`
4. Run `main.cpp` via `make test-<name>`

Reference code is for **comparison while studying** — write your own implementation for the exam.
