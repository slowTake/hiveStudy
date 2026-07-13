# CPP07 — Templates

Module 07 introduces **generic programming** with function templates and class templates.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Start with a few functions | `swap`, `min`, `max` templates |
| ex01 | Iter | `iter` — apply function to array |
| ex02 | Array | Class template with bounds checking |

## Study files

- [exercises.md](./exercises.md) — **per-exercise breakdown** with module concepts (templates, headers, type requirements), requirements tables, pitfalls, and evaluator checks; deliverables and mandatory vs bonus
- [study-plan.md](./study-plan.md) — recommended order and milestones
- [syntax-libraries-tools.md](./syntax-libraries-tools.md) — C++20 syntax, allowed headers, Makefile, debugging

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
