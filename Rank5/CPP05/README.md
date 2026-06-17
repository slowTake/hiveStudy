# CPP05 — Repetition and Exceptions

C++ Module 05 reinforces OOP from earlier modules and introduces **exception handling** through a bureaucratic “forms” simulation.

## Module theme

You build a small hierarchy of classes (`Bureaucrat`, `Form`/`AForm`, concrete forms, `Intern`) where invalid operations fail via **exceptions** instead of error codes. By ex03 you combine **polymorphism**, **abstract classes**, and a simple **factory** pattern.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat`, custom exceptions, grade validation |
| ex01 | Form up, maggots! | `Form`, signing, interaction between classes |
| ex02 | No, you need form 28B, not 28C... | `AForm`, concrete forms, execution |
| ex03 | At least this beats coffee-making | `Intern`, factory / dispatch by name |

## Study files in this directory

- [study-plan.md](./study-plan.md) — recommended order and milestones
- [theory-and-concepts.md](./theory-and-concepts.md) — concepts required per exercise
- [syntax-libraries-tools.md](./syntax-libraries-tools.md) — C++20 syntax, allowed headers, Makefile, debugging

## Global constraints (entire module)

- **Standard:** C++20 (`-std=c++20`)
- **Flags:** `-Wall -Wextra -Werror`
- **STL:** No containers (`vector`, `map`, …) or `<algorithm>` until CPP08 — using them here costs **-42**
- **OCF:** Orthodox Canonical Form required for all classes **except** `Bureaucrat` in ex00 (subject explicitly exempts it)
- **Grade scale:** `1` = highest authority, `150` = lowest (`incrementGrade()` moves toward 1, `decrementGrade()` toward 150)

## Official deliverables (per exercise)

| Ex | Turn-in directory | New files |
|----|-------------------|-----------|
| 00 | `ex00/` | `Bureaucrat.{h,hpp,cpp}`, `main.cpp`, `Makefile` |
| 01 | `ex01/` | + `Form.{h,hpp,cpp}` |
| 02 | `ex02/` | `Form` → `AForm`; + `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` |
| 03 | `ex03/` | + `Intern.{h,hpp,cpp}` |
