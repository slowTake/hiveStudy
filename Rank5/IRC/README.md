# IRC — ft_irc

Team project: build an **IRC server** compatible with a real IRC client (Irssi, HexChat, WeeChat, etc.). No custom client; no server-to-server links.

**Subject PDF:** [ft_irc.pdf](./ft_irc.pdf) (v9.1) — source of truth for requirements.

## Project theme

Single-process, **non-blocking** event loop using `poll()` (or equivalent). Clients connect over TCP, authenticate, join channels, and exchange messages per IRC protocol (RFC 1459 / RFC 2812).

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md) — subject requirements, eval traps, checklist
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard (subject):** C++98 — must compile with `-std=c++98` per PDF; confirm Hive eval flag with evaluation sheet
- **Binary:** `ircserv` — run as `./ircserv <port> <password>`
- **I/O:** Non-blocking sockets + **one** `poll()` (or `select`/`kqueue`/`epoll`) for **all** fds
- **Forbidden:** `fork()`; external libraries and Boost; server-to-server; your own IRC client
- **Crash = 0:** Server must not crash or quit unexpectedly

## Mandatory features (subject v9.1)

- Password authentication (`PASS`)
- Registration (`NICK`, `USER`)
- Channels (`JOIN`; `PART` strongly recommended for reference clients)
- Messaging (`PRIVMSG` — channel broadcast to **other** members + private messages)
- Operator commands (`KICK`, `INVITE`, `TOPIC`, `MODE`)
- Channel modes: `i`, `t`, `k`, `o`, `l`
- Operators vs regular users

## Practical extras (not named in PDF, often required in practice)

- `PING` / `PONG` — reference clients disconnect without these
- `QUIT` — clean teardown

## Typical bonuses

- Bot
- File transfer (DCC)

Bonus is graded only if mandatory is **perfect**.

## Evaluation traps (read before defense)

| Trap | Consequence |
|------|-------------|
| `read`/`write` without `poll()` | Grade **0** |
| More than one multiplexer loop pattern | Violates “only 1 poll()” rule |
| Blocking I/O | Server hangs under load |
| Crash on bad input / OOM | Grade **0** |
| Reference client protocol errors | Fails “connect without error” |
| Incomplete mandatory + bonus | Bonus not evaluated |

See [exercises.md](./exercises.md) for the full checklist and MacOS `fcntl` rule.
