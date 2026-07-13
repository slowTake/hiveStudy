# CPP02 — C++ Module 02

**Orthodox Canonical Form (OCF)** and **fixed-point arithmetic** — the module where class design becomes rigorous.

## Module theme

Implement the **Rule of Three/Four**: default constructor, copy constructor, copy assignment, destructor. Apply fixed-point math without floating point in ex02.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | My First Class | Minimal class + OCF |
| ex01 | adiós séñar | C++98-style casts (`static_cast`, etc.) |
| ex02 | Fixed | Fixed-point numbers (`Fixed` class) |
| ex03 | Orthodox Canonical Form | Full OCF on a resource-owning class |

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20
- **OCF:** Required where subject specifies — shallow copy of owned resources is a classic fail
- **ex02:** No floating-point types for internal storage (`float`, `double` forbidden for value representation)
- **STL:** Forbidden until CPP08
