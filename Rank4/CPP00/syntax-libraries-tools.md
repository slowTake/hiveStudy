# CPP00 — Syntax, libraries, and tools

## Compiler and Makefile

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
NAME     = megaphone   # per exercise

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

## Allowed headers (typical CPP00)

| Header | Use |
|--------|-----|
| `<iostream>` | Standard output/input |
| `<string>` | `std::string` |
| `<fstream>` | File I/O (ex04) |
| `<iomanip>` | `std::setw`, formatting (ex01) |
| `<cctype>` | `std::toupper` (ex00) |
| `<cstdlib>` | `std::exit` (ex01 EXIT) |
| `<ctime>` | Timestamps (ex02) |

## Forbidden until CPP08

```cpp
// DO NOT USE in CPP00
#include <vector>
#include <map>
#include <algorithm>
```

## Include guards

```cpp
#ifndef CONTACT_HPP
# define CONTACT_HPP
// ...
#endif
```

Or `#pragma once` if your campus allows it.

## Debugging

```bash
c++ -g -std=c++20 -Wall -Wextra -Werror main.cpp -o test
valgrind --leak-check=full ./phonebook
```

## File layout per exercise

```
ex01/
├── Makefile
├── main.cpp
├── Contact.hpp
├── Contact.cpp
├── PhoneBook.hpp
└── PhoneBook.cpp
```

One class pair per `.hpp`/`.cpp` is the Hive norm.
