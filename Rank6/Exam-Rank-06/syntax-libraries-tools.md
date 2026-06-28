# Exam Rank 06 — Syntax, libraries, and tools

Allowed APIs and headers for **mini_serv**. Only use functions listed in the subject.

---

## Headers (typical)

```c
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>      /* sprintf only — avoid printf in final */
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
```

Do not use `fcntl`, `printf`, `read`, `write` on sockets (use `send`/`recv`), or functions outside the allowed list.

---

## Allowed functions

| Function | Use |
|----------|-----|
| `socket`, `bind`, `listen`, `accept` | Server setup |
| `send`, `recv` | Client I/O |
| `select` | Multiplexing |
| `close` | Release fd |
| `malloc`, `calloc`, `realloc`, `free` | Client buffers |
| `sprintf` | Format subject strings |
| `strlen`, `strcpy`, `strcat`, `strstr`, `memset`, `bzero` | String/buffer ops |
| `atoi` | Parse port |
| `write` | stderr messages |
| `exit` | Terminate |

---

## `select` quick reference

```c
fd_set rfds, wfds, all;
FD_ZERO(&all);
FD_SET(sockfd, &all);
int maxfd = sockfd;

rfds = wfds = all;
int n = select(maxfd + 1, &rfds, &wfds, NULL, NULL);
```

---

## Compile

```bash
cc -Wall -Wextra -Werror mini_serv.c -o mini_serv
```

Exam may use different flags — avoid warnings.

---

## Test tools

| Tool | Command |
|------|---------|
| netcat | `nc 127.0.0.1 <port>` |
| multiple clients | Several terminals with `nc` |
| valgrind | `valgrind --leak-check=full ./mini_serv 8080` |
| fd watch | `lsof -p <pid>` during stress test |

---

## Localhost address

```c
/* 127.0.0.1 without inet_addr */
addr.sin_addr.s_addr = htonl(2130706433);
```

---

## stderr helpers

```c
void fatal(void) {
    write(2, "Fatal error\n", 12);
    exit(1);
}

/* argc check */
if (argc != 2) {
    write(2, "Wrong number of arguments\n", 26);
    exit(1);
}
```

---

## Practice repo test

```bash
cd Rank6/Exam-Rank-06
make test-mini_serv
./build/mini_serv 4242
```
