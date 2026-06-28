# Exam Rank 06

Timed practical exam — typically a single C exercise: **mini_serv**, a multi-client TCP chat server using `select()`.

This is the **last exam** in the common core curriculum.

## Exercise

| Exercise | Directory | Reference solution |
|----------|-----------|-------------------|
| [mini_serv](./mini_serv/) | TCP broadcast chat server | [mini_serv/reference/](./mini_serv/reference/) |

The directory contains:

- `guide.md` — algorithm walkthrough and pitfalls
- `reference/mini_serv.c` — working solution to compare while studying

## Quick test

```bash
cd Rank6/Exam-Rank-06
make test-mini_serv    # compile reference
# Terminal 1:
./build/mini_serv 8080
# Terminal 2 & 3:
nc 127.0.0.1 8080
```

## Shared material

- [study-plan.md](./study-plan.md) — prep order
- [exercises.md](./exercises.md) — requirements and eval traps
- [theory-and-concepts.md](./theory-and-concepts.md) — sockets, `select()`, buffering
- [syntax-libraries-tools.md](./syntax-libraries-tools.md) — allowed APIs

## Exam format

| Detail | Value |
|--------|-------|
| Language | C |
| Typical exercise | `mini_serv` (level 00) |
| Turn-in file | `mini_serv.c` |
| Multiplexer | `select()` |
| Bind address | `127.0.0.1` only |

Practice under timed conditions — you do not choose which exercise you get, but `mini_serv` has been the standard Rank 06 exercise for several years.

## Study workflow

1. Read [mini_serv/guide.md](./mini_serv/guide.md)
2. Implement from scratch (timed, no internet)
3. Diff your code against `reference/`
4. Test manually with multiple `nc` clients

Reference code is for **comparison while studying** — write your own implementation for the exam.
