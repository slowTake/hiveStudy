# CPP06 — Syntax, libraries, and tools

## Compiler flags

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

## Headers by exercise

| Ex | Headers |
|----|---------|
| 00 | `<iostream>`, `<string>`, `<cstdlib>`, `<climits>`, `<cmath>`, `<iomanip>` |
| 01 | `<stdint.h>` or `<cstdint>` (`uintptr_t`), `<iostream>` |
| 02 | `<iostream>`, `<cstdlib>`, `<ctime>`, `<exception>` |

## Cast syntax

```cpp
static_cast<double>(42);
dynamic_cast<Derived*>(basePtr);
reinterpret_cast<uintptr_t>(ptr);
const_cast<char*>(constStr);  // use sparingly
```

## C++20 parsing (ex00)

```cpp
#include <string>

double d = std::stod(arg);           // throws std::invalid_argument
long   l = std::stol(arg, nullptr, 10);
bool   isFloat = arg.find('f') != std::string::npos;
```

Wrap in try/catch or validate before calling.

## Special float detection (ex00)

```cpp
#include <cmath>

if (std::isnan(x)) { /* ... */ }
if (std::isinf(x)) { /* ... */ }
```

## ex02 — dynamic_cast patterns

```cpp
// Pointer — check null
if (auto* a = dynamic_cast<A*>(p)) { /* A */ }

// Reference — catch bad_cast
try {
    dynamic_cast<A&>(p);
} catch (const std::bad_cast&) {
    // not A
}
```

## Forbidden / discouraged

- C-style casts: `(int)x`, `(Data*)raw`
- STL containers in CPP06 (`vector`, `map`, …)
- `typeid` unless subject allows (usually `dynamic_cast` is enough)

## Tools

```bash
cd ex00 && make re && ./convert 42
cd ex02 && valgrind --leak-check=full ./identify
```

## Checklist

- [ ] `-std=c++20` on all exercises
- [ ] Only C++ cast operators in new code
- [ ] `Base` has virtual destructor in ex02
- [ ] ex02 reference `identify` uses no if/else on type checks
- [ ] Scalar output format matches subject exactly
