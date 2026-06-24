# Exam Rank 05 — Theory and concepts

Shared C++ concepts across **vect2**, **bigint**, and **polyset**.

---

## Operator overloading essentials

### Return types matter

| Operator | Typical return | Why |
|----------|----------------|-----|
| `+` (binary) | New value (`bigint`, `vect2`) | Does not mutate lhs |
| `+=` | Reference to `*this` | Chaining: `a += b += c` |
| `++` pre | Reference to `*this` | |
| `++` post | Copy of **old** value | `x++` uses old in expression |
| `<<` stream | `std::ostream &` | Chaining: `cout << a << b` |
| `[]` const | `int` (by value) | Read-only access |
| `[]` non-const | `int &` | Assignment: `v[1] = 12` |

### Member vs free function

| Form | Example |
|------|---------|
| Member | `v2 * 2` → `vect2::operator*(int)` |
| Free (non-member) | `2 * v2` → `operator*(int, const vect2 &)` |

Implement both when the subject main uses both orders.

---

## Orthodox canonical form (OCF)

Four special member functions:

1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

**Rule of thumb:** if you manage dynamic memory (polyset trees/arrays), define or disable all four. Wrapper classes holding references (`set`) may omit copy operations if not used.

Always guard self-assignment in `operator=`:

```cpp
if (this != &other) { /* copy */ }
return *this;
```

---

## Virtual inheritance (polyset)

When two parent classes share a common base (`bag`), use `virtual` inheritance on the base to get one shared subobject:

```cpp
class searchable_bag : virtual public bag { ... };
class array_bag : virtual public bag { ... };
class searchable_array_bag : public searchable_bag, public array_bag { ... };
```

Without `virtual`, ambiguous `bag` base — compile errors on calls to `insert`.

---

## Polymorphism via pointers

```cpp
searchable_bag *p = new searchable_tree_bag;
p->insert(42);   // tree_bag::insert via vtable
p->has(42);      // searchable_tree_bag::has via vtable
```

Base pointer must call derived `has()` — ensure `has` is `virtual` in `searchable_bag` (given).

---

## String digit arithmetic (bigint)

Why strings?

- Values exceed `unsigned long long`
- Exam focuses on algorithm, not big-int libraries

| Operation | Analog |
|-----------|--------|
| `<< n` | Multiply by 10^n (append zeros) |
| `>>= n` | Integer divide by 10^n (drop digits) |
| `+` | Grade-school carry |
| Compare | Longer decimal string → larger (after normalizing) |

---

## Component-wise vectors (vect2)

2D vectors add/subtract/multiply **per component** — not dot product, not matrix math.

```
(1, 2) + (3, 4) = (4, 6)
(2, 3) * 2      = (4, 6)
-(1, 2)         = (-1, -2)
```

Increment adds 1 to **both** x and y — unusual but what the subject specifies.

---

## Exam strategy

| Phase | Action |
|-------|--------|
| Read subject | 5 min — list files and operators |
| Header first | Match signatures exactly |
| Compile early | Fix errors incrementally |
| Given main | Do not edit — adapt your code |
| Last 15 min | Leak check, re-read subject file names |

---

## C++20 at The Hive

Compile with `-std=c++20 -Wall -Wextra -Werror`. Useful features in these exercises:

| Feature | Where |
|---------|-------|
| `std::to_string` | bigint constructor |
| `nullptr` | polyset pointer checks |
| `override` | polyset virtual methods (optional clarity) |

---

| Avoid | Reason |
|-------|--------|
| External bigint libraries | Not allowed |
| Changing given `main.cpp` | Auto-fail |
| `std::bitset` for bigint shift | Subject means decimal digit shift |
| Skipping `const` overloads | Const objects in main |

---

## Further reading

- [CPP05 theory — operators](../CPP05/theory-and-concepts.md)
- [RFC / Beej's](https://beej.us/guide/bgnet/) — not needed for these exercises
- Community subjects: [42nice-exam05](https://github.com/flmarsou/42nice-exam05)
