# CPP01 — Theory and concepts

## Heap allocation

```cpp
Zombie* z = new Zombie("Bob");
// ...
delete z;
```

`new` calls constructor; `delete` calls destructor.

## Array allocation

```cpp
Zombie* horde = new Zombie[n];  // default-constructs n objects
delete[] horde;                   // MUST be delete[]
```

## Pointers vs references (ex02)

| | Pointer `T*` | Reference `T&` |
|---|--------------|----------------|
| Address | Can be reassigned | Alias; cannot reseat |
| Null | Allowed | Not null |
| Syntax | `*ptr`, `ptr->` | direct use |

## `const` correctness preview

- `const std::string&` parameter — read-only, no copy
- `const` member function — promises not to modify observable state

## Ownership rule

Whoever calls `new` (or receives heap ownership) calls `delete`. Document ownership in comments when passing raw pointers between functions.

## Why no `malloc` in C++ modules

Subjects forbid C heap APIs to force C++ constructors/destructors and RAII thinking.
