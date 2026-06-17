# CPP09 — Syntax, libraries, and tools

## Compiler flags

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

## Headers by exercise

| Ex | Headers |
|----|---------|
| 00 | `<map>`, `<fstream>`, `<sstream>`, `<iostream>`, `<stdexcept>` |
| 01 | `<stack>`, `<iostream>`, `<sstream>`, `<cstdlib>` |
| 02 | `<vector>`, `<deque>`, `<iostream>`, `<chrono>`, `<algorithm>` (utilities only, not std::sort for core) |

## map operations (ex00)

```cpp
std::map<std::string, float> db;
db["2011-01-03"] = 1.0f;

auto it = db.find("2011-01-03");
if (it != db.end()) { /* found */ }

auto lb = db.lower_bound("2011-01-04");  // first >= key
```

## String parsing (ex00)

```cpp
std::getline(file, line);
size_t pipe = line.find('|');
std::string date = trim(line.substr(0, pipe));
std::string val  = trim(line.substr(pipe + 1));
float amount = std::stof(val);
```

## RPN stack (ex01)

```cpp
std::stack<int> st;
st.push(8);
int b = st.top(); st.pop();
int a = st.top(); st.pop();
st.push(a - b);
```

## C++20 parsing (ex01/ex02)

```cpp
#include <span>
#include <string_view>

for (std::string_view tok : tokens) { /* ... */ }
```

## Timing (ex02)

```cpp
auto t0 = std::chrono::steady_clock::now();
fordJohnson(vec);
auto t1 = std::chrono::steady_clock::now();
std::cout << "Time: "
          << std::chrono::duration<double, std::micro>(t1 - t0).count()
          << " us\n";
```

## Test commands

```bash
# ex00
./btc input.txt

# ex01
./RPN "8 9 * 9 - 9 - 9 - 9 - 4 - 1 +"

# ex02 large input
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
```

## References

- [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- [Ford–Johnson algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [cppreference — map](https://en.cppreference.com/w/cpp/container/map)

## Checklist

- [ ] Bitcoin error strings match subject exactly
- [ ] RPN handles division by zero
- [ ] PmergeMe uses Ford-Johnson, not std::sort as algorithm
- [ ] Both vector and deque timings printed
- [ ] `-std=c++20` clean build
