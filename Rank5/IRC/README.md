# IRC — ft_irc

Team project: build an **IRC server** in C++20 compatible with a real IRC client (Irssi, HexChat, WeeChat, etc.). No custom client; no server-to-server links.

## Project theme

Single-process, **non-blocking** event loop using `poll()` (or equivalent). Clients connect over TCP, authenticate, join channels, and exchange messages per IRC protocol (RFC 1459 / RFC 2812).

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **Binary:** `ircserv` — run as `./ircserv <port> <password>`
- **I/O:** Non-blocking sockets + **one** `poll()` (or `select`/`kqueue`/`epoll` per subject)
- **Forbidden:** `fork()` for per-client processes; threads often forbidden unless bonus
- **No client implementation** required

## Mandatory features

- Password authentication (`PASS`)
- Registration (`NICK`, `USER`)
- Channels (`JOIN`, `PART`, `TOPIC`)
- Messaging (`PRIVMSG`, `NOTICE`)
- Operator commands (`KICK`, `INVITE`, `MODE`)
- Channel modes: `i`, `t`, `k`, `o`, `l`

## Typical bonuses

- Bot (`NOTICE`-triggered commands)
- DCC file transfer relay
