# mini_serv

Exam Rank 06 exercise — multi-client TCP chat server using `select()`.

## Files

| File | Purpose |
|------|---------|
| [guide.md](./guide.md) | Implementation walkthrough and pitfalls |
| [reference/mini_serv.c](./reference/mini_serv.c) | Reference solution |

## How to study

1. Read `guide.md` and implement `mini_serv.c` yourself.
2. Test with multiple `nc 127.0.0.1 <port>` sessions.
3. Compare with `reference/` — pay attention to line buffering and broadcast exclusions.
4. Run under `valgrind` to catch leaks.

## Test the reference

```bash
make test-mini_serv
./build/mini_serv 8080
```

## Exam turn-in

Submit `mini_serv.c` only.
