# CPP01 — C++ Module 01

Memory management, pointers, references, and file streams — the bridge from C strings to C++ ownership.

## Module theme

Learn **`new` / `delete`**, pointer arithmetic, `const`, and safe allocation patterns before OCF-heavy classes in CPP02.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | BraiiiiiiinnnzzzZ | `Zombie` on stack vs heap |
| ex01 | Moar brainz! | `ZombieHorde` — array of heap objects |
| ex02 | HI THIS IS BRAIN | Pointers vs references, string literals |
| ex03 | Unnecessary violence | `Weapon`, `HumanA`, `HumanB` (reprise) |
| ex04 | Sed is for losers | File replace (reprise) |
| ex05 | Harl 2.0 | Member function pointers (reprise) |

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 (`-std=c++20`)
- **Memory:** Match every `new` with `delete`; array `new[]` with `delete[]`
- **STL:** Forbidden until CPP08
- **Forbidden:** `printf`, `malloc`, `calloc`, `realloc`, `free` in C++ modules
