# bigint — Implementation walkthrough

Study guide for the Exam Rank 05 **bigint** exercise.

**Reference solution:** [reference/bigint.hpp](./reference/bigint.hpp) and [reference/bigint.cpp](./reference/bigint.cpp) — compare after your own attempt.

Implement yourself for the exam; use `make test-bigint` from the parent directory to verify the reference.

## Data model

Store the value as `std::string _big` containing decimal digits only, **no leading zeros** except the single character `"0"`.

| Input | Stored as |
|-------|-----------|
| `bigint(0)` | `"0"` |
| `bigint(42)` | `"42"` |
| `bigint(1337)` | `"1337"` |

Helper: after any operation, strip leading zeros (if result empty, set `"0"`).

---

## Required operators (from subject header)

```cpp
bigint operator+(const bigint &other) const;
bigint &operator+=(const bigint &other);
bigint &operator++();           // ++x
bigint operator++(int);         // x++
bigint operator<<(unsigned int amount) const;
bigint &operator<<=(unsigned int amount);
bigint &operator>>=(const bigint &other);
// < > <= >= == !=
std::ostream &operator<<(std::ostream &out, const bigint &other);
```

---

## Addition (`+` and `+=`)

Grade-school algorithm, **right to left**:

```
  999
+   1
-----
 1000
```

1. Pad mentally by position: walk indices `i` from 0 while either string has digits from the right.
2. `digit_a = i < len_a ? a[len-1-i] - '0' : 0`
3. `sum = digit_a + digit_b + carry`
4. Prepend `(sum % 10)` to result string; `carry = sum / 10`
5. After loop, if `carry`, prepend `'1'`

`+=` can delegate: `return *this = *this + other;` or mutate in place with the same loop.

**Edge cases:** `"0" + "0"`, `"9" + "1"`, unequal lengths.

---

## Pre/post increment

- `++x`: add 1 via `+` with `bigint(1)` or inline single-digit carry walk; return `*this`.
- `x++`: save `bigint tmp(*this)`, increment `*this`, return `tmp`.

---

## Digit shift left (`<<` and `<<=`)

This is **not** a bit shift. Append `amount` zeros:

| Expression | Result |
|------------|--------|
| `42 << 3` | `"42000"` |
| `0 << 2` | `"0"` (not `"000"`) |
| `(b << 10) + 42` | shift then add |

```cpp
// << const version
bigint result(*this);
result._big.append(amount, '0');
result.normalize();  // strip leading zeros unless "0"
return result;
```

`<<=` applies the same to `_big` in place.

---

## Digit shift right (`>>=`)

Remove `n` digits from the **right**, where `n` = numeric value of the rhs bigint (from its string as an integer).

| Expression | Result |
|------------|--------|
| `999 >>= bigint(1)` | `"99"` |
| `999 >>= bigint(2)` | `"9"` |
| `42 >>= bigint(5)` | `"0"` (remove more digits than length) |

Algorithm:

1. Parse `n` from `other._big` (if `n >= _big.length()`, result is `"0"`).
2. `_big = _big.substr(0, _big.length() - n)`.
3. Normalize.

Subject main uses: `(d >>= (const bigint)2)` — the rhs is a bigint whose **value** is 2.

---

## Comparisons

Compare as strings after normalizing (no leading zeros):

1. If lengths differ → longer string is larger.
2. Else `strcmp` / lexicographic compare on `_big`.

Derive `<=`, `>=`, `!=` from `<` and `==` or implement directly.

---

## Stream output (`operator<<`)

```cpp
out << bigint._big;  // already no leading zeros
return out;
```

---

## Subject main — expected flow

```cpp
const bigint a(42);
bigint b(21), c, d(1337), e(d);
// a + b → 63
// c += a → c becomes 42
// ++b, b++ → post returns old, pre returns new
// (b << 10) + 42
// d <<= 4 then d >>= bigint(2)
// comparisons between d and a
```

Trace on paper before coding.

---

## Pitfalls

| Bug | Symptom |
|-----|---------|
| Bit shift instead of digit shift | `42 << 3` gives wrong value |
| Leading zeros in output | `"0042"` fails tests |
| `>>=` uses bit count or string length | Wrong truncation |
| Post `++` returns new value | Main prints wrong sequence |
| No normalize after `<<` on zero | `"000"` instead of `"0"` |
| Signed `char` on digit math | Negative digit values on some platforms — use `'0'` subtraction into `int` |

---

## Build & test

```bash
c++ -Wall -Wextra -Werror -std=c++98 bigint.cpp main.cpp -o bigint_test
./bigint_test
```

Use the given `main.cpp` from the exam subject directory.

---

## Self-test cases

| Test | Expected |
|------|----------|
| `bigint(0) + bigint(0)` | `0` |
| `bigint(999) + bigint(1)` | `1000` |
| `bigint(42) << 1` | `420` |
| `bigint(420) >>= bigint(1)` | `42` |
| `bigint(5) < bigint(10)` | `true` |
| `bigint(10) < bigint(5)` | `false` |
