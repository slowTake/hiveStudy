# Exam Rank 06 — Theory and concepts

Shared C networking concepts for **mini_serv**.

---

## TCP server lifecycle

```
socket() → bind(127.0.0.1, port) → listen() → accept() → recv()/send() → close()
```

| Call | Purpose |
|------|---------|
| `socket(AF_INET, SOCK_STREAM, 0)` | IPv4 TCP |
| `bind` | Attach to port on local address |
| `listen` | Queue incoming connections |
| `accept` | New connected client fd |
| `recv` / `send` | Byte stream I/O |

### Bind to localhost only

```c
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(2130706433); /* 127.0.0.1 */
addr.sin_port = htons(port);
```

`2130706433` is `INADDR_LOOPBACK` in network byte order — common exam pattern when `arpa/inet.h` helpers are restricted.

---

## `select()` multiplexing

Monitor many fds in one thread — required for this exam.

```c
fd_set read_fds, master_fds;
FD_ZERO(&master_fds);
FD_SET(listen_fd, &master_fds);
int max_fd = listen_fd;

while (1) {
    read_fds = master_fds;  /* copy — select modifies the set */
    if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0)
        continue; /* or handle error per subject */
    /* check FD_ISSET for listen_fd and each client */
}
```

| Macro | Role |
|-------|------|
| `FD_ZERO` | Clear set |
| `FD_SET` | Add fd |
| `FD_CLR` | Remove fd |
| `FD_ISSET` | Test if fd ready after `select` |

Track `max_fd` — first argument to `select` is `max_fd + 1`.

### Read and write sets

`mini_serv` broadcasts to clients that are writable. Copy both read and write master sets each loop; pass write set as second argument to `select` when you need to know which clients can accept `send`.

---

## Non-blocking I/O (exam context)

The exam harness sets client fds so `recv`/`send` block **only if** you skip `select`. You must:

1. Call `select`
2. Only `recv`/`send` on fds in the returned set

Do **not** spin on `EAGAIN` — the subject says not to check it.

---

## Per-client state

Each connection needs:

| Field | Purpose |
|-------|---------|
| `fd` | Socket (-1 if slot free) |
| `id` | Integer id for messages |
| `buffer` | Accumulate bytes until `\n` |

Use a fixed array of client structs indexed by slot, or index by fd if bounded (fd as array index works when fds are small consecutive integers — common exam pattern).

---

## Message framing

TCP is a **byte stream** — one `recv` may contain half a line or multiple lines.

Algorithm:

```
append recv bytes to client.buffer
for each complete line (ending in \n):
    format "client %d: %s" and broadcast to other clients
    clear consumed part of buffer
```

A single `recv` may deliver `"hello\nworld\n"` — emit two broadcast messages.

---

## Broadcast pattern

```c
void broadcast(int except_fd, const char *msg, fd_set *write_fds) {
    for each client c:
        if c.fd != -1 && c.fd != except_fd && FD_ISSET(c.fd, write_fds))
            send(c.fd, msg, strlen(msg), 0);
}
```

- Arrival/departure: `except_fd` = new or departing client (they should not get their own “arrived” line in some interpretations — subject: “all **other** clients”).
- Chat: `except_fd` = sender (sender should not receive their own message back).

---

## Disconnect handling

| `recv` return | Meaning |
|---------------|---------|
| `> 0` | Data read |
| `0` | Peer closed connection |
| `< 0` | Error |

On `<= 0`: broadcast left message, `FD_CLR`, `close(fd)`, mark slot free.

---

## Error messages

| Condition | stderr | Exit |
|-----------|--------|------|
| `argc != 2` | `Wrong number of arguments\n` | 1 |
| syscall fail before loop / malloc fail | `Fatal error\n` | 1 |

Use `write(2, ...)` for stderr in exam-safe style.

---

## Comparison to IRC (ft_irc)

| | IRC | mini_serv |
|---|-----|-----------|
| Language | C++98 | C |
| Multiplexer | `poll()` | `select()` |
| Protocol | IRC RFC | Custom line format |
| Complexity | Channels, modes, auth | Broadcast chat |
| Address | Any | `127.0.0.1` only |

Skills transfer: event loop, client table, read buffering, broadcast.

---

## Memory discipline

- Free client buffers on disconnect if heap-allocated
- Close every fd before exit
- `valgrind --leak-check=full ./mini_serv 8080` during practice

---

## No `#define`

Use `enum` or `const int` for buffer sizes:

```c
enum { MAX_CLIENTS = 1024, BUF_SIZE = 100000 };
```

Preprocessor macros are forbidden by the subject.
