# IRC — Syntax, libraries, and tools

## Compiler flags

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
LDFLAGS  =

NAME = ircserv
```

## Allowed system calls (typical subject)

```
socket, bind, listen, accept, connect, send, recv, close
setsockopt, getsockname, getprotobyname, gethostbyname
getaddrinfo, freeaddrinfo, htons, htonl, ntohs, ntohl
inet_addr, inet_ntoa, fcntl, poll (or select/epoll/kqueue)
signal, sigaction, errno
```

Check your subject PDF — list is authoritative.

## Socket setup sketch

```cpp
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

int srv = socket(AF_INET, SOCK_STREAM, 0);

int opt = 1;
setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

sockaddr_in addr{};
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = INADDR_ANY;
addr.sin_port = htons(port);

bind(srv, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
listen(srv, SOMAXCONN);

int flags = fcntl(srv, F_GETFL, 0);
fcntl(srv, F_SETFL, flags | O_NONBLOCK);
```

## poll() loop

```cpp
#include <poll.h>

std::vector<pollfd> fds;
fds.push_back({srv, POLLIN, 0});

while (running) {
  if (poll(fds.data(), fds.size(), -1) < 0)
    break;  // handle EINTR

  for (auto& p : fds) {
    if (!(p.revents & POLLIN))
      continue;
    if (p.fd == srv)
      acceptNewClient();
    else
      handleClientRead(p.fd);
  }
}
```

## C++20 containers for server state

STL is allowed in ft_irc (not a CPP module):

```cpp
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <unordered_map>
#include <optional>
#include <memory>

std::map<int, Client> clientsByFd;
std::map<std::string, Channel> channels;
```

## Parsing IRC lines

```cpp
#include <sstream>
#include <string_view>

struct IrcMessage {
  std::optional<std::string> prefix;
  std::string command;
  std::vector<std::string> params;
  std::optional<std::string> trailing;
};

// Split on \r\n, then parse tokens
std::string_view line = "PRIVMSG #chan :Hello";
// command + middle params + optional :trailing
```

## Sending replies

```cpp
void Client::sendNumeric(int code, const std::string& text) {
  std::string msg = ":server.name " + std::to_string(code) + " " + nick + " " + text + "\r\n";
  enqueueSend(msg);
}
```

## Reference clients (pick one for eval)

| Client | Install |
|--------|---------|
| Irssi | `irssi` |
| HexChat | GUI |
| WeeChat | `weechat` |
| nc (debug) | `nc localhost 6667` — manual protocol testing |

### Irssi connect

```text
/connect -pass mypass localhost 6667
```

## Debugging tools

| Tool | Use |
|------|-----|
| `nc localhost 6667` | Raw protocol probe |
| `wireshark` | Capture IRC plaintext |
| `valgrind --leak-check=full ./ircserv 6667 pass` | Leak hunt |
| `strace -e poll,recv,send ./ircserv` | Syscall trace |
| `lsof -i :6667` | Check bound port |

## Test script idea

```bash
#!/bin/bash
./ircserv 6667 testpass &
sleep 1
{ echo "PASS testpass"; echo "NICK bot1"; echo "USER bot1 0 * :Bot"; sleep 1; echo "JOIN #test"; echo "PRIVMSG #test :hi"; } | nc -w 2 localhost 6667
kill %1
```

## Project structure (suggested)

```text
incs/     headers
srcs/     Server.cpp Client.cpp Channel.cpp Parser.cpp main.cpp
Makefile
```

## Checklist

- [ ] `./ircserv <port> <password>` — exactly two args
- [ ] All sockets non-blocking
- [ ] Single `poll()` (or approved equivalent) — no `fork`
- [ ] Messages end with `\r\n`
- [ ] Reference client connects without errors
- [ ] Channel broadcast works for 2+ clients
- [ ] All five mode letters implemented
- [ ] `-std=c++20` clean build
- [ ] No leaks on connect/disconnect cycle

## References

- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [RFC 2812 — IRC client protocol](https://www.rfc-editor.org/rfc/rfc2812)
- [man poll(2)](https://man7.org/linux/man-pages/man2/poll.2.html)
- [man fcntl(2)](https://man7.org/linux/man-pages/man2/fcntl.2.html)
