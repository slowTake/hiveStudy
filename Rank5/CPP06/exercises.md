# CPP06 — Exercise breakdown

## How module validation works

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP06. |
| **Bonus** | Not present in CPP06 — all listed exercises are mandatory. |

CPP06 has **3 mandatory exercises** (ex00–ex02). Each is evaluated independently.

---

## ex00 — Conversion of scalar types

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `ScalarConverter.{h,hpp,cpp}` (name may vary: `convert` binary) |
| **Binary name** | Often `convert` |

### What you build

A program that takes **one literal** as argument and prints its value as **char**, **int**, **float**, and **double**.

### Expected behaviour

```bash
./convert 42
# char: '*'
# int: 42
# float: 42.0f
# double: 42.0
```

| Input type | Handling |
|------------|----------|
| Char | Single displayable character |
| Integer | Decimal integer syntax |
| Float | Includes `f` suffix; show `.0f` for whole floats |
| Double | Floating point without `f` |
| `nan` / `inf` | Display `impossible` for char/int; `nanf`/`nan`, `inff`/`inf` for floats |
| Out of range char | `impossible` |
| Non-displayable char | `Non displayable` |

### Rules

- Use **`static_cast`** for conversions between scalar types.
- Detect pseudo-literals: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`, etc.
- No C-style casts.

### Evaluator will check

- Multiple input types (int, float, char, double, nan, inf)
- Output format exactly as subject
- Edge cases: 0, 256, negative numbers

---

## ex01 — Serialization

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `Serializer.{h,hpp,cpp}`, `Data.hpp` |

### What you build

Serialize a pointer to an integer address and deserialize it back.

### Expected API

```cpp
uintptr_t serialize(Data* ptr);
Data*     deserialize(uintptr_t raw);
```

### Expected behaviour

- `serialize` uses **`reinterpret_cast`** to `uintptr_t`
- `deserialize` converts back to `Data*`
- `main` proves original and deserialized pointers are equal and data intact
- `Data` struct has at least one member (e.g. `int`, `std::string`)

### Evaluator will check

- Round-trip preserves address and data
- Understanding of when reinterpret_cast is valid (same process, same run)

---

## ex02 — Identify real type

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | `Makefile`, `main.cpp`, `Base.{h,hpp,cpp}`, `A.hpp`, `B.hpp`, `C.hpp` |

### What you build

Runtime type identification using **`dynamic_cast`** on a polymorphic hierarchy.

### Expected API

```cpp
Base* generate(void);           // random new A, B, or C
void  identify(Base* p);        // print A, B, or C
void  identify(Base& p);        // same, without if/else chain
```

### Expected behaviour

| Function | Technique |
|----------|-----------|
| `generate()` | Randomly returns `new A()`, `new B()`, or `new C()` |
| `identify(Base*)` | `dynamic_cast` pointer — null means not that type |
| `identify(Base&)` | `dynamic_cast` reference — **`std::bad_cast`** caught; **no if/else** allowed for type check |

### Rules

- `Base` must be **polymorphic** (virtual destructor minimum).
- `A`, `B`, `C` are empty derived classes.

### Evaluator will check

- Correct identification over many runs
- Reference version uses try/catch, not if/else on types
- No memory leaks (`delete` in main)

---

## Module checklist

- [ ] Three exercises, each compiles independently
- [ ] C++ casts only (no `(type)` C-style)
- [ ] No STL containers
- [ ] `-std=c++20 -Wall -Wextra -Werror`
