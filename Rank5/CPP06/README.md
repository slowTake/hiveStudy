# CPP06 — C++ casts

Module 06 teaches the four C++ cast operators and **RTTI** (Runtime Type Information) through scalar conversion, pointer serialization, and type identification.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Conversion of scalar types | `static_cast`, string parsing, special floats |
| ex01 | Serialization | `reinterpret_cast`, `uintptr_t` |
| ex02 | Identify real type | `dynamic_cast`, polymorphism, RTTI |

## Study files

- [exercises.md](./exercises.md) — **per-exercise breakdown**, deliverables, expected behaviour, mandatory vs bonus
- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **Flags:** `-Wall -Wextra -Werror`
- **STL:** Still no containers/algorithms in CPP06 (module rule)
- **Casts:** Use C++ casts only — no C-style `(type)value` in new code

## Deliverables

| Ex | New files |
|----|-----------|
| 00 | `ScalarConverter.{hpp,cpp}`, `main.cpp`, `Makefile` |
| 01 | `Serializer.{hpp,cpp}`, `Data.hpp`, `main.cpp` |
| 02 | `Base.{hpp,cpp}`, `A.hpp`, `B.hpp`, `C.hpp`, `main.cpp` |
