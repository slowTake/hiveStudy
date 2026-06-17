# CPP07 — Templates

Module 07 introduces **generic programming** with function templates and class templates.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Start with a few functions | `swap`, `min`, `max` templates |
| ex01 | Iter | `iter` — apply function to array |
| ex02 | Array | Class template with bounds checking |

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **Templates in headers:** Definitions usually live in `.hpp` / `.tpp` (not separate `.cpp` for template bodies)
- **STL:** Still forbidden as exercise shortcuts in CPP07 (implement your own `Array`)

## Deliverables

| Ex | Files |
|----|-------|
| 00 | `whatever.hpp`, `main.cpp` |
| 01 | `iter.hpp`, `main.cpp` |
| 02 | `Array.hpp` (+ optional `.tpp`), `main.cpp` |
