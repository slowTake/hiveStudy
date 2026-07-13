# CPP07 — Syntax, libraries, and tools

## Compiler flags

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

## Function template syntax

```cpp
template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// C++20 abbreviated (optional style)
template<typename T>
T min(T const& a, T const& b) requires std::totally_ordered<T>;  // only if you use concepts
```

For 42-style solutions, `template<typename T>` without concepts is standard.

## Class template in header

```cpp
// Array.hpp
template<typename T>
class Array {
    T* _array;
    unsigned int _size;
    // ...
};

// include at bottom if split:
// #include "Array.tpp"
```

## iter — function pointer parameter

```cpp
template<typename T>
void iter(T* array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}
```

## C++20 conveniences

| Feature | Use |
|---------|-----|
| `nullptr` | Empty array pointer |
| `noexcept override` | `OutOfBoundsException::what()` |
| `std::size` | On C arrays in tests: `iter(arr, std::size(arr), fn)` |
| Range-for in `main` | Display results only |

## Headers

| Ex | Headers |
|----|---------|
| 00–01 | `<iostream>`, `<string>` |
| 02 | `<iostream>`, `<exception>`, `<cstddef>` |

## Makefile note

ex00–01 may be header-only + `main.cpp`. ex02 compiles only `main.cpp` if all templates are in headers.

## Tools

```bash
# Explicit instantiation test (debug)
template class Array<int>;  // in a .cpp only for debugging

# Compile error inspection
c++ -std=c++20 -c main.cpp 2>&1 | less
```

## Checklist

- [ ] Template definitions visible from `main.cpp`
- [ ] Deep copy verified with independent modification
- [ ] `operator[]` throws on out-of-bounds
- [ ] No STL containers inside `Array` implementation
