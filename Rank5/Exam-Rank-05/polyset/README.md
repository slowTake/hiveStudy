# polyset

Exam Rank 05 level-00 exercise — searchable bags and a set wrapper.

## Files

| Path | Purpose |
|------|---------|
| [guide.md](./guide.md) | Inheritance walkthrough |
| [main.cpp](./main.cpp) | Exam test harness |
| [given/](./given/) | Provided exam files (do not modify in the real exam) |
| [reference/](./reference/) | Your reference solution files |

## What you implement

| File | Task |
|------|------|
| `searchable_array_bag.{hpp,cpp}` | `has()` via linear search |
| `searchable_tree_bag.{hpp,cpp}` | `has()` via BST walk |
| `set.{hpp,cpp}` | Deduplicating wrapper around `searchable_bag` |

## How to study

1. Read `given/` headers to understand the hierarchy.
2. Implement the three file pairs yourself.
3. Compare with `reference/` when stuck — the entire solution is ~60 lines.

## Test the reference

```bash
make test-polyset
./build/polyset-test 1 2 3 2
```

## Exam turn-in

Only your six files — `given/` is provided on exam day.
