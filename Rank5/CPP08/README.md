# CPP08 — Templated containers, iterators, algorithms

Module 08 opens the **STL**: containers, iterators, and `<algorithm>`. You learn to use standard components and extend them (MutantStack).

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Easy find | `std::find`, iterators, function template |
| ex01 | Span | `std::vector`, algorithms, exceptions |
| ex02 | Mutated abomination | `std::stack`, iterators via underlying container |

## Study files

- [exercises.md](./exercises.md) — **module validation**, condensed STL concepts (triad, iterators, algorithms), per-exercise meta tables, concepts, requirements, pitfalls, and evaluator checks, plus module checklist
- [study-plan.md](./study-plan.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **STL:** Allowed and expected from this module onward
- **OCF:** Required on `Span` and `MutantStack` where implemented as classes

## Deliverables

| Ex | Files |
|----|-------|
| 00 | `easyfind.hpp`, `main.cpp` |
| 01 | `Span.{hpp,cpp}`, `main.cpp` |
| 02 | `MutantStack.hpp`, `main.cpp` |
