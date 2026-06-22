# IRC — Exercise breakdown (ft_irc v9.1)

Source: [ft_irc.pdf](./ft_irc.pdf) (subject v9.1). When the PDF and campus norms differ, **the PDF and evaluation sheet win**.

---

## Turn-in summary

| | |
|---|---|
| **Program name** | `ircserv` |
| **Run** | `./ircserv <port> <password>` |
| **Files** | `Makefile`, `*.{h,hpp}`, `*.cpp`, `*.tpp`, `*.ipp`, optional config file |
| **Makefile rules** | `$(NAME)`, `all`, `clean`, `fclean`, `re` — no unnecessary relinking |
| **Standard (subject)** | **C++98** — must still compile with `-std=c++98` |
| **Libft** | Not applicable |
| **External libs / Boost** | Forbidden |

### Hive note on C++ standard

The subject PDF requires **C++98**. The Hive campus norm for other C++ modules is **C++20**. For ft_irc, confirm with your evaluation sheet which flag evaluators use. Safe approach: write code that compiles cleanly with **both** `-std=c++98` and `-std=c++20` until you know otherwise.

---

## Mandatory requirements (from subject)

### Architecture

| Requirement | Detail |
|-------------|--------|
| Multiple clients | Handle many simultaneous connections without hanging |
| No `fork()` | Single process only |
| Non-blocking I/O | **All** file descriptors non-blocking |
| One multiplexer | **Exactly one** `poll()` (or `select` / `kqueue` / `epoll`) for **all** fds — listen, read, write |
| TCP/IP | IPv4 or IPv6 |
| Reference client | Pick one real client (Irssi, HexChat, WeeChat, …); it must connect **without errors** during eval |
| No IRC client | Do not implement your own client |
| No server-to-server | Do not implement IRC network linking (RFC 2813) |

### poll() trap (grade = 0)

The subject allows non-blocking `read`/`recv` and `write`/`send` in principle, but:

> If you attempt to read/recv or write/send on any file descriptor **without** using `poll()` (or equivalent), your grade will be **0**.

Every I/O operation on client/listen sockets must go through your single event loop.

### Crash trap (grade = 0)

> Your program should not crash in any circumstances (even when it runs out of memory), and should not quit unexpectedly.

Evaluators treat crashes as a non-functional project.

---

## Features you must implement

The subject lists **capabilities**, not every IRC command by name. Map them like this:

| Capability (subject) | Typical commands |
|----------------------|------------------|
| Authenticate | `PASS` |
| Set nickname | `NICK` |
| Set username | `USER` |
| Join a channel | `JOIN` |
| Send/receive private messages | `PRIVMSG` (user and `#channel` targets) |
| Channel broadcast | Forward channel `PRIVMSG` to **every other** member in that channel |
| Operators vs regular users | Track channel operators; enforce privileges |
| Operator commands | `KICK`, `INVITE`, `TOPIC`, `MODE` |

### Channel modes (MODE) — all five required

| Mode | Meaning |
|------|---------|
| `i` | Invite-only channel |
| `t` | Only operators may change `TOPIC` |
| `k` | Channel key (password to join) |
| `o` | Grant/remove operator privilege to a user |
| `l` | User limit on channel |

### Not named in the subject PDF

These are **not** listed as mandatory features, but reference clients often send them during normal use:

| Command | Why it matters |
|---------|----------------|
| `PING` / `PONG` | Clients disconnect if the server does not answer pings |
| `QUIT` | Clean disconnect and resource cleanup |
| `PART` | Leaving a channel — common in every client UI |
| `NOTICE` | Some clients use it; often low priority |
| `NAMES`, `LIST`, `WHO` | Channel user lists in GUI clients |

If your chosen reference client errors on any of these during a normal session, implement a minimal handler or numeric reply.

---

## MacOS-only rule

On macOS, `write()` behaves differently. You may use `fcntl()` **only** as:

```cpp
fcntl(fd, F_SETFL, O_NONBLOCK);
```

Any other `fcntl` flag is forbidden on macOS.

---

## Subject test example (partial data)

The subject requires aggregating fragmented TCP data before parsing a command:

```bash
nc -C 127.0.0.1 6667
```

Send `command` in parts with Ctrl+D: `com`, then `man`, then `d` + newline. The server must rebuild the full line before dispatching.

Also test: low bandwidth, multiple clients, wrong password, nick collision.

---

## Allowed external functions (authoritative list)

```
socket, close, setsockopt, getsockname, getprotobyname, gethostbyname,
getaddrinfo, freeaddrinfo, bind, connect, listen, accept,
htons, htonl, ntohs, ntohl, inet_addr, inet_ntoa, inet_ntop,
send, recv, signal, sigaction,
sigemptyset, sigfillset, sigaddset, sigdelset, sigismember,
lseek, fstat, fcntl, poll (or equivalent)
```

Anything not on this list (or not in the C++ standard library) needs explicit subject approval.

---

## Bonus part

| Bonus | Subject mention |
|-------|-----------------|
| File transfer | DCC or similar |
| Bot | Automated responder |

**Bonus is only graded if mandatory is PERFECT** — all mandatory requirements work without malfunction. Incomplete mandatory = bonus not evaluated.

---

## Peer evaluation — what to expect

| Check | Detail |
|-------|--------|
| Reference client | Evaluator uses **your** chosen client against **your** server |
| Live demo | Auth, join, chat, operator actions, modes |
| Whiteboard | Be ready to explain the `poll()` loop and non-blocking design |
| Live modification | Evaluators **may** ask for a small code change on the spot (few minutes) to verify understanding — e.g. tweak a function, display, or data structure |
| Tests | You may use any test programs during defense; they are not submitted |
| Repo only | Only work inside the Git repo is evaluated |

Walk the evaluation guidelines line by line before defense.

---

## Evaluator checklist (rehearsal)

- [ ] `./ircserv <port> <password>` — exactly two arguments after binary name
- [ ] Builds with `-Wall -Wextra -Werror` and subject standard flag
- [ ] Makefile: `NAME`, `all`, `clean`, `fclean`, `re`; no spurious relinking
- [ ] Single process, no `fork()`
- [ ] All sockets non-blocking
- [ ] One `poll()` (or approved equivalent) drives **all** I/O
- [ ] Partial reads/writes handled; per-client read buffer until `\r\n`
- [ ] Send queue + `POLLOUT` when `send` returns `EAGAIN`
- [ ] `PASS` / wrong password rejected
- [ ] `NICK` + `USER` + welcome numerics — client shows registered state
- [ ] `JOIN` channel; `PRIVMSG` to channel reaches other members
- [ ] `PRIVMSG` to nickname (DM) works
- [ ] Operator: `KICK`, `INVITE`, `TOPIC`, `MODE` with `i`, `t`, `k`, `o`, `l`
- [ ] Mode rules enforced (`+i` needs invite, `+k` needs key, `+t` restricts topic, `+l` limits members)
- [ ] Reference client session has no protocol errors
- [ ] No leaks on connect/disconnect cycles (valgrind)
- [ ] Server survives edge cases without crash
