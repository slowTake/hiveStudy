# Webserve — Study plan

## Phase 0 — HTTP & networking (3–5 days)

| Topic | Action |
|-------|--------|
| HTTP/1.1 | Request line, headers, body, status codes |
| RFC 7230 skim | Message syntax, persistent connections |
| TCP review | Same as IRC: bind, listen, accept, non-blocking |
| `poll()` | `POLLIN`/`POLLOUT` on all sockets |
| Compare with IRC | [IRC/study-plan.md](../IRC/study-plan.md) Phase 0 |

**Checkpoint:** Explain difference between headers terminated by `\r\n\r\n` and body length.

---

## Phase 1 — Config parser (3–5 days)

| Step | Task |
|------|------|
| 1 | Tokenize NGINX-like blocks: `server { ... }`, `location { ... }` |
| 2 | Directives: `listen`, `server_name`, `root`, `index`, `error_page` |
| 3 | Route rules: `allow_methods`, `return`, `autoindex`, `upload_store`, CGI extension |
| 4 | Multiple `server` blocks on different ports |

**Checkpoint:** Parse sample config into structs; reject syntax errors with clear messages.

---

## Phase 2 — Server skeleton (3–5 days)

| Step | Task |
|------|------|
| 1 | Create listening sockets per `listen` directive |
| 2 | Single `poll()` loop — accept, register client fds |
| 3 | Per-client read buffer until full request headers |
| 4 | Non-blocking write queue for responses |

**Checkpoint:** Return `200 OK` with plain text body for `GET /`.

---

## Phase 3 — Request parser (4–6 days)

| Step | Task |
|------|------|
| 1 | Parse method, path, version |
| 2 | Header map (case-insensitive keys) |
| 3 | `Content-Length` and **chunked** transfer decoding |
| 4 | Keep-alive vs close (start with close for simplicity) |

---

## Phase 4 — Static file serving (3–5 days)

| Step | Task |
|------|------|
| 1 | Map URL to filesystem path via `root` + URI |
| 2 | `GET` file — correct MIME type |
| 3 | Directory → `index` file or **403/404** |
| 4 | `autoindex on` — generate HTML listing |
| 5 | Custom `error_page` paths |

---

## Phase 5 — Methods & uploads (3–4 days)

| Method | Behaviour |
|--------|-----------|
| `GET` | Serve file or directory |
| `POST` | Upload body to `upload_store` path |
| `DELETE` | Remove file if allowed |

Handle `client_max_body_size` — return **413** when exceeded.

---

## Phase 6 — CGI (5–7 days)

| Step | Task |
|------|------|
| 1 | Match extension (`.php`, `.py`) → CGI handler |
| 2 | `fork` + pipes for stdin/stdout |
| 3 | Set CGI env vars (`REQUEST_METHOD`, `PATH_INFO`, …) |
| 4 | Feed body (unchunked) to CGI stdin |
| 5 | Parse CGI output into HTTP response |
| 6 | `chdir` to script directory before `execve` |

**Checkpoint:** `GET` on `.php` runs script; `POST` form reaches CGI.

---

## Phase 7 — Redirects & polish (2–3 days)

- `return 301/302` with `Location`
- Default error pages (404, 413, 500)
- Stress test: `curl`, browser, siege/ab
- Compare behaviour with real NGINX on same config snippets

---

## Phase 8 — Evaluation prep (2–3 days)

- Walk [exercises.md](./exercises.md) checklist
- `poll()` trap: no read/write outside loop
- No `errno` check after I/O
- Valgrind / leak tests on connect storm
- Config edge cases: duplicate listen, missing root

---

## Suggested architecture

| Component | Responsibility |
|-----------|----------------|
| `ConfigParser` | File → `Server`/`Route` structs |
| `SocketManager` | Listen sockets, accept |
| `Client` / `Connection` | Buffer, state machine |
| `HttpRequest` / `HttpResponse` | Parse/build messages |
| `Router` | Match location, dispatch handler |
| `CgiHandler` | fork/exec/pipe |
