# CPP01 — Syntax, libraries, and tools

## Makefile pattern

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

## Headers

| Header | Use |
|--------|-----|
| `<iostream>` | I/O |
| `<string>` | Names |
| `<new>` | `std::bad_alloc` (optional) |

## Valgrind workflow

```bash
make
valgrind --leak-check=full --show-leak-kinds=all ./zombie
```

## Split compilation

Put `newZombie` and `randomChump` in separate `.cpp` files per subject — avoids ODR issues and matches evaluation file list.

## Forbidden

- `malloc`, `free`, `calloc`, `realloc`
- `printf`, `fprintf` (use streams)
