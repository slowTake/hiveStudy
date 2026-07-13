# Webserve — Syntax, libraries, and tools

## Compiler flags

Subject requires **C++98**:

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME     = webserv
```

Confirm Hive evaluation flag — write portable C++98 until told otherwise.

## Allowed system calls (typical subject list)

```
socket, accept, listen, send, recv, bind, connect,
setsockopt, getsockname, getprotobyname,
htons, htonl, ntohs, ntohl,
select, poll, epoll (epoll_create, epoll_ctl, epoll_wait),
kqueue (kqueue, kevent),
fcntl, close, read, write,
open, stat, access, opendir, readdir, closedir,
fork, pipe, dup, dup2, execve, waitpid,
kill, signal, chdir,
getaddrinfo, freeaddrinfo, gai_strerror
```

**Forbidden:** external HTTP libraries, Boost.

## Non-blocking setup

```cpp
fcntl(fd, F_SETFL, O_NONBLOCK);
```

MacOS: same restriction as IRC — only `F_SETFL` + `O_NONBLOCK` on macOS for some campuses.

## poll() sketch

```cpp
std::vector<struct pollfd> fds;

while (running) {
    poll(fds.data(), fds.size(), timeout);
    for (size_t i = 0; i < fds.size(); ++i) {
        if (fds[i].revents & POLLIN)  { /* read or accept */ }
        if (fds[i].revents & POLLOUT) { /* flush write buffer */ }
    }
}
```

Use fixed array or subject-allowed container — **STL containers may be restricted**; many implementations use `std::vector` only after confirming campus rules for major projects. Subject says C++98 — `vector` is C++98 STL; confirm if Hive applies CPP-style container ban to webserve (usually **not** — webserve allows broader C++ than CPP modules).

## Testing with curl

```bash
./webserv configs/default.conf &
curl -v http://127.0.0.1:8080/
curl -X POST -d "data" http://127.0.0.1:8080/upload
curl -X DELETE http://127.0.0.1:8080/tmp/file.txt
curl -v -H "Host: other.local" http://127.0.0.1:8081/
```

## Compare with NGINX

```bash
nginx -t -c /path/to/nginx.conf
```

Use NGINX only to **validate config semantics** — your server must implement its own parser.

## CGI test script (Python)

```python
#!/usr/bin/env python3
import os
print("Content-Type: text/plain\r")
print("\r")
print("Hello CGI")
print(os.environ.get("REQUEST_METHOD", ""))
```

```bash
chmod +x cgi/test.py
```

## Load testing

```bash
ab -n 1000 -c 10 http://127.0.0.1:8080/
```

Watch for hung connections — sign of blocking I/O or missing POLLOUT handling.

## Debugging

```bash
valgrind --leak-check=full ./webserv config.conf
# Another terminal: curl loops
```

## Sample config fragment

```nginx
server {
    listen 8080;
    server_name localhost;
    root ./www;
    index index.html;
    client_max_body_size 1024;

    error_page 404 /404.html;

    location / {
        allow_methods GET POST;
        autoindex off;
    }

    location /uploads {
        allow_methods POST;
        upload_store ./uploads;
    }

    location ~ \.py$ {
        allow_methods GET POST;
        cgi_extension .py;
    }
}
```

Exact directive names match your PDF — adjust to subject spelling (`cgi_pass` vs `cgi_extension` varies by version).

## File layout suggestion

```
webserv/
├── Makefile
├── main.cpp
├── config/
│   ├── ConfigParser.cpp
│   └── samples/
├── http/
│   ├── Request.cpp
│   └── Response.cpp
├── server/
│   ├── Server.cpp
│   └── Client.cpp
└── cgi/
    └── CgiHandler.cpp
```
