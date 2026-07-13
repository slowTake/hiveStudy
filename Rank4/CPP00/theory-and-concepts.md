# CPP00 — Theory and concepts

## Module-wide: C++ vs C habits

| C habit | C++ replacement |
|---------|-----------------|
| `char *` strings | `std::string` |
| `printf` | `std::cout` / streams |
| `malloc` / `free` | `new` / `delete` (CPP01+) |
| `.c` files | `.cpp` with `c++` compiler |

## Classes and encapsulation

A **class** bundles data and functions. **Encapsulation** hides implementation:

```cpp
class Contact {
private:
    std::string _firstName;
public:
    void setFirstName(const std::string& s);
    const std::string& getFirstName() const;
};
```

- **Attributes** are usually `private`
- **Getters** often `const` member functions
- Pass strings by `const std::string&` to avoid copies

## ex00 — Streams and argv

`std::toupper` from `<cctype>` works on `unsigned char` cast values. Concatenate `argv` slices in a loop or build one `std::string`.

## ex01 — Fixed-size storage

PhoneBook uses a **static array** of 8 `Contact` objects — no dynamic container. Circular overwrite when full is the classic design:

```
index:  0 1 2 3 4 5 6 7 → next ADD goes to 0 again
```

`std::setw`, `std::right`, `std::trunc` (C++20) help format columns.

## ex02 — Static class members

**Static** members belong to the class, not each object:

```cpp
class Account {
    static int _nbAccounts;
    static void _displayTimestamp();
};
```

Define static data members **once** in `.cpp`:

```cpp
int Account::_nbAccounts = 0;
```

## ex03 — References vs pointers

| Feature | Reference `T&` | Pointer `T*` |
|---------|----------------|--------------|
| Null | Must bind to object | Can be `nullptr` |
| Rebind | No | Yes |
| Syntax | `weapon.getType()` | `weapon->getType()` |

`HumanA` always has a weapon → reference. `HumanB` may be disarmed → pointer.

## ex04 — String find/replace

```cpp
size_t pos = 0;
while ((pos = str.find(s1, pos)) != std::string::npos) {
    str.replace(pos, s1.length(), s2);
    pos += s2.length();
}
```

Non-overlapping rule: advance `pos` past inserted text.

## ex05 — Member function pointers

```cpp
void (Harl::*fn)() = &Harl::debug;
(this->*fn)();
```

Map level strings to member pointers in an array or struct table — avoids long `if/else` chains and satisfies the subject.

## OCF preview

CPP00 rarely requires full Orthodox Canonical Form. From CPP02 onward you will need default/copy/assignment/destructor for classes that own resources.
