# CPP00 — C++ Module 00

First C++ module: namespaces, classes, member functions, `iostream`, and basic OOP habits without inheritance.

## Module theme

Move from C-style programs to **C++ classes** with encapsulation, `std::string`, and streams. Exercises progress from a simple filter (`Megaphone`) to a phone book (`Contact`) to a bank account simulator (`Account`).

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Megaphone | `argc`/`argv`, `toupper`, streams |
| ex01 | My Awesome PhoneBook | Class design, contact storage, interactive CLI |
| ex02 | The Job Of Your Dreams | Static members, account lifecycle logging |
| ex03 | Unnecessary violence | `Weapon` / `HumanA` / `HumanB` — references vs pointers |
| ex04 | Sed is for losers | File I/O, string replace |
| ex05 | Harl 2.0 | Member function pointers, log levels |
| ex06 | Robot-hub | `Robot` hierarchy (campus-dependent) |
| ex07 | Intern | Factory dispatch (campus-dependent) |

Confirm exact exercise list on your intranet PDF — some campuses stop at ex05.

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20 at The Hive (`-std=c++20 -Wall -Wextra -Werror`)
- **STL:** No containers (`vector`, `map`, …) or `<algorithm>` until CPP08
- **I/O:** Prefer C++ streams (`iostream`, `fstream`) over C stdio where the subject allows
- **OCF:** Not required in early exercises; introduced gradually from CPP02
