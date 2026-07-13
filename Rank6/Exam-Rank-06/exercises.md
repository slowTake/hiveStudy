# Exam Rank 06 — Exercise breakdown

## mini_serv

| | |
|---|---|
| **Directory** | [mini_serv/](./mini_serv/) |
| **Files** | `mini_serv.c` |
| **Reference** | [mini_serv/reference/](./mini_serv/reference/) |

Multi-client TCP chat server on `127.0.0.1` — see [mini_serv/guide.md](./mini_serv/guide.md).

---

## Subject requirements (summary)

| Rule | Detail |
|------|--------|
| Argument | `./mini_serv <port>` — wrong argc → `Wrong number of arguments\n` on stderr, exit 1 |
| Bind | `127.0.0.1` only |
| Multiplexer | `select()` |
| Non-blocking | Fds configured by exam harness; call `select` before `recv`/`send` |
| Client IDs | First client = 0, then increment |
| Arrival | Broadcast `server: client %d just arrived\n` to **other** clients |
| Messages | Prefix each **line** with `client %d: ` when broadcasting |
| Departure | Broadcast `server: client %d just left\n` on disconnect |
| Preprocessor | **No `#define`** |
| Leaks | No memory or fd leaks |
| Fatal errors | Before accept loop: `Fatal error\n` on stderr, exit 1 |

### Allowed functions

`write`, `close`, `select`, `socket`, `accept`, `listen`, `send`, `recv`, `bind`, `strstr`, `malloc`, `realloc`, `free`, `calloc`, `bzero`, `atoi`, `sprintf`, `strlen`, `exit`, `strcpy`, `strcat`, `memset`

---

## Common exam rules

| Rule | Detail |
|------|--------|
| Language | C |
| File name | Exact match: `mini_serv.c` |
| Output format | Match subject strings byte-for-byte (including `\n`) |
| Lazy clients | Do **not** disconnect clients that read slowly |
| `EAGAIN` | Do **not** check — use `select` correctly instead |
| Speed | Send messages promptly; avoid unnecessary buffering |

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| `#define` used | Subject violation |
| Bind `0.0.0.0` | Wrong address |
| `poll()` / `epoll()` instead of `select()` | Wrong API |
| Missing `client %d: ` on one line of a multi-line message | Test failure |
| Broadcast includes sender | Wrong output |
| No per-client read buffer | Garbled messages on partial `recv` |
| `recv` returns 0 not handled | Leak or hang |
| `select` on same `fd_set` without copy | Undefined behavior |

---

## Manual test script

```bash
# Terminal 1
./mini_serv 8080

# Terminal 2
nc 127.0.0.1 8080

# Terminal 3
nc 127.0.0.1 8080

# Type in terminal 2 — terminal 3 should see:
# client 0: <your line>

# Ctrl-D in terminal 2 — terminal 3 should see:
# server: client 0 just left
```

---

## Test reference solution

```bash
cd Rank6/Exam-Rank-06
make test-mini_serv
```
