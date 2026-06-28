# mini_serv — Implementation walkthrough

Study guide for Exam Rank 06 **mini_serv**.

**Reference solution:** [reference/mini_serv.c](./reference/mini_serv.c) — compare after your own attempt.

Run `make test-mini_serv` from the parent directory to compile the reference.

---

## Architecture overview

```
                    ┌─────────────┐
                    │ listen fd   │
                    └──────┬──────┘
                           │ accept
     ┌─────────────────────┼─────────────────────┐
     ▼                     ▼                     ▼
┌─────────┐          ┌─────────┐          ┌─────────┐
│ client 0│          │ client 1│          │ client 2│
│ id=0    │          │ id=1    │          │ id=2    │
│ buffer  │          │ buffer  │          │ buffer  │
└─────────┘          └─────────┘          └─────────┘
         select() loop broadcasts chat / arrival / departure
```

One process, one `select()` loop, no `fork`.

---

## Step 1 — Argument and fatal error helpers

```c
if (argc != 2) {
    write(2, "Wrong number of arguments\n", 26);
    exit(1);
}

void fatal(void) {
    write(2, "Fatal error\n", 12);
    exit(1);
}
```

---

## Step 2 — Server socket

```c
int port = atoi(argv[1]);
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
    fatal();

struct sockaddr_in addr;
bzero(&addr, sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(2130706433); /* 127.0.0.1 */
addr.sin_port = htons(port);

if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    fatal();
if (listen(sockfd, 128) < 0)
    fatal();
```

---

## Step 3 — Client table and fd sets

```c
typedef struct s_client {
    int   fd;
    int   id;
    char  buf[100000];
} t_client;

t_client clients[1024];
int next_id = 0;

for (int i = 0; i < 1024; i++)
    clients[i].fd = -1;

fd_set rfds, wfds, all;
FD_ZERO(&all);
FD_SET(sockfd, &all);
int maxfd = sockfd;
```

No `#define` — use literals or `enum` for sizes.

---

## Step 4 — Main loop

```c
while (1) {
    rfds = wfds = all;
    if (select(maxfd + 1, &rfds, &wfds, NULL, NULL) < 0)
        continue;

    if (FD_ISSET(sockfd, &rfds))
        accept_new_client();

    for each slot i where clients[i].fd != -1:
        if FD_ISSET(clients[i].fd, &rfds)
            handle_client_read(i);
}
```

---

## Step 5 — Accept new client

```c
int cfd = accept(sockfd, NULL, NULL);
if (cfd < 0)
    return;

/* find free slot */
for (int i = 0; i < 1024; i++) {
    if (clients[i].fd == -1) {
        clients[i].fd = cfd;
        clients[i].id = next_id++;
        memset(clients[i].buf, 0, sizeof(clients[i].buf));
        FD_SET(cfd, &all);
        if (cfd > maxfd) maxfd = cfd;

        char msg[64];
        sprintf(msg, "server: client %d just arrived\n", clients[i].id);
        broadcast(cfd, msg, &wfds);
        break;
    }
}
```

---

## Step 6 — Broadcast helper

Send to every connected client **except** `except_fd`, only if writable in `wfds`:

```c
void broadcast(int except_fd, char *msg, fd_set *wfds) {
    for (int i = 0; i < 1024; i++) {
        if (clients[i].fd == -1 || clients[i].fd == except_fd)
            continue;
        if (FD_ISSET(clients[i].fd, wfds))
            send(clients[i].fd, msg, strlen(msg), 0);
    }
}
```

---

## Step 7 — Handle incoming data

Read one or more bytes per `recv`; append to per-client buffer; on each `\n`, emit one line:

```c
char tmp[1024];
int n = recv(clients[i].fd, tmp, sizeof(tmp) - 1, 0);
if (n <= 0) {
    /* disconnect */
    sprintf(msg, "server: client %d just left\n", clients[i].id);
    broadcast(clients[i].fd, msg, &wfds);
    FD_CLR(clients[i].fd, &all);
    close(clients[i].fd);
    clients[i].fd = -1;
    return;
}
tmp[n] = '\0';

/* append tmp to clients[i].buf, scan for '\n' */
/* for each complete line: */
sprintf(msg, "client %d: %s", clients[i].id, line);
broadcast(clients[i].fd, msg, &wfds);
```

The line in the buffer should **include** the trailing `\n` when passed to `sprintf` if the subject expects `client 0: hello\n`.

Reference implementation scans character-by-character to handle `"a\nb\n"` in one `recv`.

---

## Step 8 — Partial line buffering

If `recv` returns `"hel"` then `"lo\n"`:

1. First read: append `"hel"` — no `\n` yet, no broadcast
2. Second read: buffer is `"hello\n"` — broadcast one message

Without buffering, messages split across packets will fail hidden tests.

---

## Pitfalls checklist

| Issue | Fix |
|-------|-----|
| Sender sees own chat | Pass sender fd as `except_fd` to `broadcast` |
| Wrong id on arrival | Assign `next_id` before broadcast; post-increment |
| `select` maxfd wrong | Update `maxfd` on every new client |
| Multi-line in one recv | Loop all `\n` in buffer |
| Using `#define` | Use `enum` or const |
| `read`/`write` on sockets | Use `recv`/`send` only |

---

## Exam timing strategy

| Minutes | Task |
|---------|------|
| 0–30 | Skeleton: bind, listen, one client echo |
| 30–90 | `select` + client array |
| 90–150 | Broadcast format + arrival/departure |
| 150–180 | Buffering + leak pass + manual `nc` test |

---

## Compare with reference

After your attempt, diff against [reference/mini_serv.c](./reference/mini_serv.c) for:

- Exact `sprintf` format strings
- Whether `send` checks `FD_ISSET` on write set
- Buffer reset after each complete line

Do not memorize — understand the event loop.
