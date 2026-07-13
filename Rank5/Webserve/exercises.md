# Webserve — Exercise breakdown (ft_webserve)

Source: campus **ft_webserve** PDF. When PDF and this doc differ, **the PDF and evaluation sheet win**.

---

## Turn-in summary

| | |
|---|---|
| **Program name** | `webserv` |
| **Run** | `./webserv [configuration file]` |
| **Files** | `Makefile`, `*.{h,hpp}`, `*.cpp`, `*.tpp`, `*.ipp`, config samples |
| **Makefile** | `$(NAME)`, `all`, `clean`, `fclean`, `re` |
| **Standard** | **C++98** per subject |
| **External libs** | Forbidden (no Boost, no libhttp) |

---

## Mandatory architecture

| Requirement | Detail |
|-------------|--------|
| Non-blocking | All client and listen sockets non-blocking (`fcntl` `O_NONBLOCK`) |
| Single multiplexer | **One** `poll()` (or `select` / `epoll` / `kqueue`) for **all** I/O including listen |
| Read/write rule | **Never** `read`/`write`/`send`/`recv` without multiplexer readiness |
| `poll` checks | Must monitor **read and write** simultaneously |
| Config file | May be read **without** `poll()` (explicit exception) |
| `fork` | **Only** for CGI — nowhere else |
| `errno` | **Forbidden** to check after read/write operations |
| Crash | Server must not crash on bad requests or memory pressure |

### poll() trap (grade = 0)

Same pattern as ft_irc: I/O outside the event loop → automatic fail.

---

## HTTP methods

| Method | Required use |
|--------|--------------|
| `GET` | Serve files, directories, trigger GET CGI |
| `POST` | Uploads, POST body to CGI |
| `DELETE` | Remove resources where configured |

Return correct status codes: `200`, `301`/`302`, `403`, `404`, `405`, `413`, `500`, etc.

---

## Configuration (NGINX-like)

### Server block

| Directive | Purpose |
|-----------|---------|
| `listen` | Port (multiple servers → multiple ports) |
| `server_name` | Virtual host matching (eval may test Host header) |
| `root` | Default filesystem root |
| `index` | Default file for directory requests |
| `client_max_body_size` | Max upload body |
| `error_page` | Custom error HTML paths |

### Location / route rules

Routes are **not** regex-based in the subject. Each location may define:

| Feature | Detail |
|---------|--------|
| `allow_methods` | Limit GET/POST/DELETE |
| `return` | HTTP redirect |
| Root alias | URL prefix maps to filesystem path |
| `autoindex` | Directory listing on/off |
| `index` | Default file for directory |
| CGI extension | e.g. `.php` → CGI handler |
| Upload path | Save POST files to configured directory |

---

## Static website

Must serve a **complete static site** from your config (HTML, CSS, images). Evaluators compare with browser and `curl`.

---

## CGI requirements

| Rule | Detail |
|------|--------|
| Invocation | Full script path as `PATH_INFO`; program as first arg to exec |
| Working directory | `chdir` to script's directory for relative paths |
| Environment | Standard CGI variables (`REQUEST_METHOD`, `QUERY_STRING`, `CONTENT_LENGTH`, …) |
| Chunked requests | Server **unchunks** body before CGI; CGI sees EOF at body end |
| CGI output | If no `Content-Length` from CGI, EOF ends response body |
| Languages | At least one working CGI (PHP-CGI, Python, etc.) |

---

## Default error pages

Serve configured error pages for at least **404** and other common errors — subject lists minimum set.

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| Blocking `accept` or `read` | Hangs → fail |
| `errno` after I/O | Subject violation |
| `fork` outside CGI | Fail |
| Wrong status or missing headers | Browser/curl tests fail |
| No chunked POST support | CGI POST fails |
| Leaks / crash on bad config | Fail |

---

## Bonus (typical — confirm PDF)

- Cookies / sessions
- Multiple CGI types
- Advanced load testing resilience

Bonus only if mandatory is **perfect**.

---

## Comparison with IRC

| | IRC | Webserve |
|---|-----|----------|
| Protocol | Line-based text | HTTP with headers + body |
| Config | CLI args | File parser |
| `fork` | Forbidden | CGI only |
| Message format | `\r\n` commands | `\r\n\r\n` header end |
