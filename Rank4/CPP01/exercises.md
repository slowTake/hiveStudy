# CPP01 — Exercise breakdown

## ex00 — BraiiiiiiinnnzzzZ

| | |
|---|---|
| **Files** | `Zombie.{hpp,cpp}`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp` |
| **Functions** | `Zombie* newZombie(std::string name);` `void randomChump(std::string name);` |

Heap zombie must be explicitly `delete`d. Stack zombie dies when `randomChump` returns.

---

## ex01 — Moar brainz!

| | |
|---|---|
| **Function** | `Zombie* zombieHorde(int N, std::string name);` |
| **Rule** | Caller `delete[]` the returned array |

---

## ex02 — HI THIS IS BRAIN

| | |
|---|---|
| **Output** | Memory address of string + value via pointer and reference |
| **Trap** | String literal vs `std::string` object addresses differ — follow subject |

---

## ex03–ex05

Same functional requirements as CPP00 ex03–ex05. Evaluators may additionally check for leaks and forbidden C functions.

---

## Evaluation traps

| Trap | Detail |
|------|--------|
| `malloc` in C++ module | Fail |
| `delete` on array | Undefined behaviour |
| Memory leak in horde | Valgrind fail |
