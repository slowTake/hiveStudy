# CPP07 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP07. |
| **Bonus** | None in this module. |

CPP07 has **3 mandatory exercises** (ex00–ex02).

---

## ex00 — Start with a few functions

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `whatever.hpp` (or subject name) |

### What you build

Three **function templates**: `swap`, `min`, `max`.

### Expected API

```cpp
template<typename T>
void swap(T& a, T& b);

template<typename T>
T min(T const& a, T const& b);

template<typename T>
T max(T const& a, T const& b);
```

### Expected behaviour

- `swap` exchanges two values of the same type
- `min` / `max` use `operator<` / `operator>`
- Works with at least `int` and `std::string`
- Templates in **header** file

### Evaluator will check

- Correct results in `main` for int and string
- Template compiles only when type supports required operators

---

## ex01 — Iter

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `iter.hpp` |

### What you build

A function template that applies a function to every element of an array.

### Expected API

```cpp
template<typename T>
void iter(T* array, size_t length, void (*f)(T&));
```

(Alternative: template callable parameter — confirm with subject; function pointer version is standard.)

### Expected behaviour

- Iterates `length` elements starting at `array`
- Calls `f` on each element
- `main` demonstrates at least: print function and mutate function (e.g. increment)
- Works on different types (`int`, `std::string`, etc.)

### Evaluator will check

- Array modified after iter with increment
- Print output correct
- No array bounds errors

---

## ex02 — Array

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `Array.hpp` (+ optional `Array.tpp`) |

### What you build

A **class template** wrapping a dynamic array with bounds checking.

### Expected interface

```cpp
template<typename T>
class Array {
public:
    Array();                          // empty
    Array(unsigned int n);            // n default-constructed elements
    Array(const Array& other);        // deep copy
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception;
};
```

### Expected behaviour

| Case | Result |
|------|--------|
| `Array<int> a(5)` | Five value-initialized ints |
| `a[2] = 42` | OK |
| `a[99]` | Throws `OutOfBoundsException` |
| Copy / assign | Independent deep copy |
| `size()` | Returns element count |

### Rules

- OCF required
- No STL `vector` inside — raw `new[]` / `delete[]`
- Exception on out-of-bounds access

### Evaluator will check

- Deep copy (modify copy, original unchanged)
- Exception thrown and catchable
- No leaks (Valgrind)

---

## Module checklist

- [ ] All templates in headers (or included `.tpp`)
- [ ] No STL containers in implementations
- [ ] Three separate `exXX/` directories
