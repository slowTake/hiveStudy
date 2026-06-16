# CPP05 — Study plan

Work through this plan **before** coding each exercise. CPP05 assumes solid understanding of CPP00–CPP04 (classes, OCF, inheritance, polymorphism, abstract classes).

---

## Phase 0 — Prerequisites refresh (½–1 day)

**Goal:** Be fluent in patterns reused in every exercise.

| Topic | Action |
|-------|--------|
| Orthodox Canonical Form | Review default ctor, copy ctor, copy assignment, destructor; when the compiler-generated versions are unsafe |
| Encapsulation | Private attributes, `const` members, getters only where needed |
| Operator overloading | `operator<<` for `ostream` (used for bureaucrat/form output) |
| const correctness | `const` methods, `const` references as parameters |
| Inheritance & polymorphism | Base pointer/reference to derived object, virtual destructor, pure virtual functions (needed from ex02) |

**Checkpoint:** Explain why a base class destructor should be `virtual` when deleting through a base pointer.

---

## Phase 1 — Exception fundamentals (before ex00)

**Goal:** Understand C++ exception mechanics in C++98.

| Topic | Action |
|-------|--------|
| `try` / `catch` / `throw` | Read examples; practice catching by reference (`catch (std::exception& e)`) |
| `std::exception` | Base class; override `what()` |
| Custom exceptions | Nested classes inheriting `std::exception` |
| Exception safety basics | What happens if an exception is thrown mid-construction |
| When to throw | Use exceptions for exceptional control flow, not normal logic |

**Checkpoint:** Write a tiny program that throws your own exception from a constructor and catches it in `main`.

---

## Phase 2 — Exercise 00: Bureaucrat (1–2 days)

**Read:** [theory-and-concepts.md § ex00](./theory-and-concepts.md#ex00--bureaucrat-and-grade-exceptions)

| Step | Task |
|------|------|
| 1 | Design `Bureaucrat` with `const std::string _name` and `unsigned int _grade` |
| 2 | Validate grade in constructor: throw if `< 1` or `> 150` |
| 3 | Implement `incrementGrade()` / `decrementGrade()` with boundary checks |
| 4 | Add nested `GradeTooHighException` and `GradeTooLowException` with `what()` |
| 5 | Overload `operator<<` to print `<name>, bureaucrat grade <grade>.` |
| 6 | Write `main` with try/catch blocks for constructor and mutator failures |

**Checkpoint:** All invalid grades throw; output format matches the subject; no OCF required for `Bureaucrat` in ex00 only.

---

## Phase 3 — Exercise 01: Form and signing (1–2 days)

**Read:** [theory-and-concepts.md § ex01](./theory-and-concepts.md#ex01--form-and-signing)

| Step | Task |
|------|------|
| 1 | Implement `Form` with `const` name, sign grade, execute grade; mutable `_signed` |
| 2 | Validate grade constants in `Form` constructor (same 1–150 rules) |
| 3 | Implement `beSigned(Bureaucrat const&)` — compare bureaucrat grade to `_gradeToSign` |
| 4 | Add `Bureaucrat::signForm(Form&)` — try/catch, print success or failure message |
| 5 | Apply OCF to `Form` (and extend `Bureaucrat` with OCF if you add it) |

**Checkpoint:** Low-grade bureaucrat cannot sign high-requirement forms; signed forms stay signed; exceptions propagate correctly.

---

## Phase 4 — Exercise 02: AForm and concrete forms (2–3 days)

**Read:** [theory-and-concepts.md § ex02](./theory-and-concepts.md#ex02--aform-polymorphic-execution)

| Step | Task |
|------|------|
| 1 | Rename/refactor `Form` → abstract `AForm` with pure virtual `execute(Bureaucrat const&) const` or protected hook pattern per your design |
| 2 | Centralize checks: signed? executor grade sufficient? then call concrete action |
| 3 | Implement `ShrubberyCreationForm` — file output with ASCII trees |
| 4 | Implement `RobotomyRequestForm` — random 50% success (`std::rand` + seeding) |
| 5 | Implement `PresidentialPardonForm` — pardon message to stdout |
| 6 | Add `Bureaucrat::executeForm(AForm const&)` with try/catch and status messages |
| 7 | Add `FormNotSignedException` and any grade exceptions as required |

**Concrete form grade requirements (subject):**

| Form | Grade to sign | Grade to execute |
|------|---------------|------------------|
| ShrubberyCreationForm | 145 | 137 |
| RobotomyRequestForm | 72 | 45 |
| PresidentialPardonForm | 25 | 5 |

**Checkpoint:** Unsigned form cannot execute; wrong grade throws; each form behaves differently; virtual destructor on `AForm`.

---

## Phase 5 — Exercise 03: Intern factory (1 day)

**Read:** [theory-and-concepts.md § ex03](./theory-and-concepts.md#ex03--intern-factory)

| Step | Task |
|------|------|
| 1 | Implement `Intern` with `makeForm(std::string name, std::string target)` returning `AForm*` |
| 2 | Dispatch on exact form names: `"shrubbery creation"`, `"robotomy request"`, `"presidential pardon"` |
| 3 | Prefer function-pointer table or map-like static array over long if/else chains |
| 4 | Handle unknown form name (print error; subject allows exception or `NULL` — pick one and document) |
| 5 | Test full flow: intern creates → bureaucrat signs → bureaucrat executes |

**Checkpoint:** Adding a new form type should require minimal changes to `Intern` (ideally one table entry + new class).

---

## Phase 6 — Evaluation prep

| Task | Detail |
|------|--------|
| Re-read subject PDF | Verify output strings, class names, and file naming |
| Peer-style quiz | Explain grade direction, why `catch (std::exception& e)`, difference `beSigned` vs `signForm` |
| Memory | Who owns `AForm*` from `makeForm`? Practice `delete` in `main` |
| Clean build | `make re` in each exercise; fix all `-Werror` warnings |
| Forbidden STL | Confirm no `<vector>`, `<map>`, etc. |

---

## Suggested timeline (study + implementation)

| Phase | Focus |
|-------|--------|
| Days 1–2 | Phases 0–1 + ex00 |
| Days 3–4 | ex01 |
| Days 5–7 | ex02 (largest exercise) |
| Day 8 | ex03 |
| Day 9 | Phase 6 evaluation prep |

Adjust pace based on prior CPP module experience.
