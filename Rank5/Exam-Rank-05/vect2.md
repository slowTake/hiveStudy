# vect2 — Implementation walkthrough

Study guide for the Exam Rank 05 **vect2** exercise.

## Data model

```cpp
class vect2 {
    int _x;
    int _y;
};
```

Default `(0, 0)`. Both components participate together in every operation.

---

## Required members (from subject header)

| Category | Operators |
|----------|-----------|
| OCF | Copy ctor (given), `operator=` |
| Access | `int operator[](int) const`, `int &operator[](int)` |
| Inc/dec | `++` pre/post, `--` pre/post |
| Arithmetic | `+`, `+=`, `-`, `-=`, `*`, `*=`, unary `-` |
| Compare | `==`, `!=` |
| Friends | `operator*(int, const vect2 &)`, `operator<<` |

Index `0` → `_x`, index `1` → `_y`. No bounds checking.

---

## `operator=`

```cpp
vect2 &vect2::operator=(const vect2 &other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}
```

---

## `operator[]`

Two overloads — required for `v1[1] = 12` on non-const and `v3[1]` on const:

```cpp
int vect2::operator[](int i) const { return i == 0 ? _x : _y; }
int &vect2::operator[](int i) { return i == 0 ? _x : _y; }
```

---

## Increment / decrement

Pre-increment **both** components, return reference:

```cpp
vect2 &vect2::operator++() { ++_x; ++_y; return *this; }
```

Post-increment: save old copy, increment, return old:

```cpp
vect2 vect2::operator++(int) {
    vect2 old(*this);
    ++(*this);
    return old;
}
```

Same pattern for `--`.

### Subject main trace

Starting `v4 = (1, 2)`:

| Expression | Printed | `v4` after |
|------------|---------|------------|
| `v4++` | `{1, 2}` | `{2, 3}` |
| `++v4` | `{3, 4}` | `{3, 4}` |
| `v4--` | `{3, 4}` | `{2, 3}` |
| `--v4` | `{1, 2}` | `{1, 2}` |

---

## Arithmetic

Component-wise:

```cpp
vect2 vect2::operator+(const vect2 &o) const {
    return vect2(_x + o._x, _y + o._y);
}
vect2 vect2::operator-(const vect2 &o) const {
    return vect2(_x - o._x, _y - o._y);
}
vect2 vect2::operator*(int s) const {
    return vect2(_x * s, _y * s);
}
vect2 vect2::operator-() const {
    return vect2(-_x, -_y);
}
```

`+=`, `-=`, `*=` mutate in place and return `*this`.

---

## Free `operator*(int, vect2)`

Required for `3 * v2`:

```cpp
vect2 operator*(int scalar, const vect2 &v) {
    return v * scalar;
}
```

Declare in header after the class; define in `.cpp`.

---

## Comparisons

```cpp
bool vect2::operator==(const vect2 &o) const {
    return _x == o._x && _y == o._y;
}
bool vect2::operator!=(const vect2 &o) const {
    return !(*this == o);
}
```

---

## `operator<<`

Format: `{x, y}` — space after comma per subject:

```cpp
std::ostream &operator<<(std::ostream &out, const vect2 &v) {
    out << "{" << v[0] << ", " << v[1] << "}";
    return out;
}
```

Use `v[0]` / `v[1]` (const overload) not private members directly if you want consistency.

---

## Subject main — key expressions

```cpp
v2 += v3;              // (1,2) + (1,2) → (2,4)
v1 -= v2;              // (0,0) - (2,4) → (-2,-4)
v2 = v3 + v3 * 2;      // (1,2) + (2,4) → (3,6)  — note precedence: * before +
v2 = 3 * v2;           // (9,18)
v2 += v2 += v3;        // associative: inner += first
v1 *= 42;
v1 = v1 - v1 + v1;     // (0,0) + (0,0) → (0,0) after sub
```

---

## Pitfalls

| Bug | Symptom |
|-----|---------|
| Post inc returns reference | Compile error or wrong prints |
| Only increment `_x` | Wrong vector math |
| Missing `const operator[]` | `v3[1]` fails on const object |
| Missing `3 * v2` free function | Compile error on `3 * v2` |
| Wrong `<<` format | Missing space or braces |
| `operator=` no self-check | UB on `v = v` (rare but easy fix) |

---

## Build & test

```bash
c++ -Wall -Wextra -Werror -std=c++98 vect2.cpp main.cpp -o vect2_test
./vect2_test
```

---

## Timed drill target

~30–45 minutes including header from scratch. Fastest level-00 exercise — use it to build exam confidence.
