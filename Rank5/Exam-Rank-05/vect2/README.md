# vect2

Exam Rank 05 level-00 exercise — 2D integer vector with operator overloading.

## Files

| File | Purpose |
|------|---------|
| [guide.md](./guide.md) | Operator walkthrough and pitfalls |
| [main.cpp](./main.cpp) | Exam test harness |
| [reference/vect2.hpp](./reference/vect2.hpp) | Reference solution header |
| [reference/vect2.cpp](./reference/vect2.cpp) | Reference solution implementation |

## How to study

1. Read `guide.md` and implement `vect2.hpp` / `vect2.cpp` yourself.
2. Compare with `reference/` — pay attention to post-increment return values and `const operator[]`.
3. Run `main.cpp` until all expected comments match output.

## Test the reference

```bash
make test-vect2
```

## Exam turn-in

Submit `vect2.hpp` and `vect2.cpp` only.
