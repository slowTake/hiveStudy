# Webserve — ft_webserve

Solo project: build an **HTTP/1.1 server** in C++ from scratch. Parse NGINX-style config, serve static files, handle uploads, redirects, and **CGI** — all with **non-blocking I/O** and a **single** `poll()` (or equivalent) loop.

**Subject PDF:** Confirm version on your intranet — source of truth for requirements.

## Project theme

Production-like HTTP server architecture without frameworks:

- Config-driven **virtual hosts** and **routes**
- Methods: **GET**, **POST**, **DELETE**
- **CGI** via `fork` + `pipe` + `execve` (only place `fork` is allowed)
- One event loop for listen socket + all clients

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard (subject):** C++98 — must compile with `-std=c++98`; confirm Hive eval flag
- **Binary:** `webserv` — `./webserv [configuration file]`
- **I/O:** Non-blocking sockets; **one** `poll()`/`select()`/`epoll()`/`kqueue()` for all fds
- **Forbidden:** Checking `errno` after read/write; `fork` except CGI; external HTTP libs
- **Config:** Read config file **without** going through poll (explicit subject exception)

## Relation to IRC

Both are network servers with a single multiplexer loop. Webserve adds HTTP parsing, config grammar, and CGI. Studying IRC first helps socket/poll patterns; Webserve adds application-layer complexity.
