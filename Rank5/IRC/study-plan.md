# IRC — Study plan

## Phase 0 — Networking foundations (3–5 days)

| Topic | Action |
|-------|--------|
| TCP/IP | Ports, IP addresses, client/server roles |
| Sockets API | `socket`, `bind`, `listen`, `accept`, `send`, `recv` |
| Non-blocking I/O | `fcntl` `O_NONBLOCK`, `EAGAIN`/`EWOULDBLOCK` |
| `poll()` | `struct pollfd`, `POLLIN`/`POLLOUT`, timeout |
| Byte streams | Partial reads, message buffering |

**Checkpoint:** Write a tiny echo server that handles multiple clients with `poll()`.

**Resources:** Beej's Guide to Network Programming.

---

## Phase 1 — Protocol & architecture (2–3 days)

| Topic | Action |
|-------|--------|
| IRC message format | `@prefix CMD params :trailing\r\n` |
| RFC 2812 | Read registration, JOIN, PRIVMSG sections |
| Choose reference client | Install Irssi or HexChat; connect to a public server and observe |
| Class design | `Server`, `Client`, `Channel`, `Parser` |

**Checkpoint:** Diagram classes and who owns sockets/channels.

---

## Phase 2 — Core server skeleton (3–5 days)

| Step | Task |
|------|------|
| 1 | Parse CLI: port + password |
| 2 | Create listening socket, bind, listen, non-blocking |
| 3 | `poll()` loop: accept new clients, read/write ready fds |
| 4 | Per-client read buffer — accumulate until `\r\n` |
| 5 | SIGINT handler — graceful shutdown |

---

## Phase 3 — Registration & auth (2–3 days)

| Step | Task |
|------|------|
| 1 | `PASS` — verify password or disconnect |
| 2 | `NICK` — set nickname, handle collisions |
| 3 | `USER` — set username/realname |
| 4 | Send numeric replies: welcome `001`, etc. |
| 5 | Reject commands until registration complete |

**Checkpoint:** Reference client connects and shows successful registration.

---

## Phase 4 — Channels & messaging (4–6 days)

| Step | Task |
|------|------|
| 1 | `JOIN` — create/join `#channel`, track membership |
| 2 | `PART` — leave channel, destroy if empty |
| 3 | `PRIVMSG` — user and channel targets |
| 4 | `NOTICE` — like PRIVMSG without auto-reply expectation |
| 5 | Broadcast channel messages to all members |
| 6 | `TOPIC` — get/set topic |

---

## Phase 5 — Operator & modes (3–4 days)

| Step | Task |
|------|------|
| 1 | Track channel operators |
| 2 | `MODE` — implement `+i`, `+t`, `+k`, `+o`, `+l` |
| 3 | `KICK` — operator removes user |
| 4 | `INVITE` — invite to `+i` channels |
| 5 | Enforce mode rules (key required, user limit, topic restriction) |

---

## Phase 6 — Polish & evaluation (2–3 days)

| Task | Detail |
|------|--------|
| Numeric replies | Match what reference client expects |
| `PING`/`PONG` | Keep reference client connected |
| Edge cases | Nick in use, not in channel, wrong password |
| Partial data | Subject `nc -C` test — split commands with Ctrl+D |
| Leaks | Valgrind with connect/disconnect storms |
| Multi-client test | 3+ clients, same channel, cross-talk |
| Subject checklist | Walk [exercises.md](./exercises.md) and evaluation sheet line by line |
| Live mod prep | Be ready for a small on-the-spot code change at eval |

---

## Phase 7 — Bonus (optional)

- IRC bot class connecting as a client or internal pseudo-client
- DCC SEND handshake relay between clients

---

## Suggested team split

| Area | Owner focus |
|------|-------------|
| Socket/poll layer | Server I/O, accept, send queue |
| Parser | Tokenize IRC lines, dispatch commands |
| Channel logic | Modes, membership, broadcasts |
| Client state | Registration, nick, buffers |

Sync daily on message formats and numeric reply codes.
