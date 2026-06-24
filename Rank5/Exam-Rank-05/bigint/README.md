# bigint

Exam Rank 05 level-00 exercise — arbitrary-precision unsigned integer.

## Files

| File | Purpose |
|------|---------|
| [guide.md](./guide.md) | Algorithm walkthrough and pitfalls |
| [main.cpp](./main.cpp) | Exam test harness |
| [reference/bigint.hpp](./reference/bigint.hpp) | Reference solution header |
| [reference/bigint.cpp](./reference/bigint.cpp) | Reference solution implementation |

## How to study

1. Read `guide.md` and try implementing `bigint.hpp` / `bigint.cpp` yourself.
2. Compare your version with `reference/` when stuck.
3. Test against `main.cpp`.

## Test the reference

From `Rank5/Exam-Rank-05/`:

```bash
make test-bigint
```

Or manually:

```bash
c++ -Wall -Wextra -Werror -std=c++98 \
  bigint/reference/bigint.cpp bigint/main.cpp \
  -I bigint/reference -o /tmp/bigint-test && /tmp/bigint-test
```

## Exam turn-in

Submit only `bigint.hpp` and `bigint.cpp` — copy logic from reference into your own files, do not submit this folder verbatim.
