# CPP04 — Syntax, libraries, and tools

## override and final (C++11+)

```cpp
void makeSound() const override;
```

Use `override` — catches signature mistakes at compile time.

## Virtual destructor declaration

```cpp
class Animal {
public:
    virtual ~Animal();
};
```

Define in `.cpp` even if empty body.

## Fixed inventory without vector

```cpp
AMateria* _inventory[4];
```

Initialize to `NULL`/`nullptr`; scan slots on equip.

## const correctness

`makeSound() const` — evaluators expect const methods on queries.

## Testing deep copy

```cpp
Dog d1;
Dog d2 = d1;
d1.getBrain()->setIdea(0, "test");
// d2 idea 0 must NOT be "test"
```

## Headers

`<iostream>`, `<string>`, `<cstring>` if needed — no `<vector>` until CPP08.
