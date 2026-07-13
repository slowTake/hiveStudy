# CPP09 — STL

Final C++ module: practical problems using **STL containers**, file I/O, parsing, and algorithm design (Ford-Johnson / merge-insert sort).

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Bitcoin Exchange | `std::map`, CSV, date validation |
| ex01 | Reverse Polish Notation | `std::stack`, expression evaluation |
| ex02 | PmergeMe | Ford-Johnson sort, `vector` vs `deque`, timing |

## Study files

- [exercises.md](./exercises.md) — **primary reference**: module validation, condensed STL concepts, per-exercise meta tables, concepts, requirements, pitfalls, and evaluator checks (including Bitcoin `lower_bound` and exact error strings)
- [study-plan.md](./study-plan.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **STL:** Full use encouraged (`map`, `stack`, `vector`, `deque`, …)
- **ex02:** Implement Ford-Johnson (merge-insertion) — not `std::sort` as the core algorithm

## Deliverables

| Ex | Files |
|----|-------|
| 00 | `BitcoinExchange.{hpp,cpp}`, `main.cpp`, `data.csv` |
| 01 | `RPN.{hpp,cpp}`, `main.cpp` |
| 02 | `PmergeMe.{hpp,cpp}`, `main.cpp` |
