# CPP08 — Syntax, libraries, and tools

## Compiler flags

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

## Essential headers

```cpp
#include <algorithm>   // find, sort, min_element, max_element
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <iostream>
#include <exception>
```

## Iterator loop patterns

```cpp
// Classic
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it;

// C++20 range-for
for (int n : v)
    std::cout << n;

// Algorithms
std::sort(v.begin(), v.end());
auto it = std::find(v.begin(), v.end(), 42);
```

## easyfind.hpp

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int const& value) {
    typename T::iterator result = std::find(container.begin(), container.end(), value);
    if (result == container.end())
        throw std::out_of_range("Value not found");
    return result;
}
```

## Span — vector member

```cpp
class Span {
    unsigned int _maxSize;
    std::vector<int> _numbers;
};
```

## MutantStack — access `c`

```cpp
template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
    using iterator = typename Container::iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};
```

## C++20 utilities

| Feature | Example |
|---------|---------|
| `std::ranges::find` | Alternative to `std::find` (know both) |
| `using` alias | `using iterator = typename T::iterator;` |
| `std::span` | **Not** the exercise class — avoid name confusion in docs |

## Tools

```bash
# Quick complexity test
time ./span  # bonus large input

# Include what you use
clang-tidy main.cpp -- -std=c++20
```

## Checklist

- [ ] `<algorithm>` used where appropriate
- [ ] `Span` throws on invalid span queries
- [ ] `MutantStack` iterators compile and match test output
- [ ] OCF on non-header-only classes
