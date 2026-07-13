# CPP04 — C++ Module 04

**Subtype polymorphism**, **abstract classes**, and **interfaces** — Animals, Brains, and Materia.

## Module theme

Master `virtual` functions, pure virtual (`= 0`), `override`, and **deep copy** of polymorphic hierarchies. CPP04 is the direct prerequisite for CPP05 exceptions and CPP05+ abstract forms.

## Exercises

| Exercise | Title | Focus |
|----------|--------|--------|
| ex00 | Polymorphism | `Animal` / `Dog` / `Cat`, wrong types |
| ex01 | I don't want to set the world on fire | `Brain` deep copy in `Dog`/`Cat` |
| ex02 | Abstract class | `ICharacter`, `AMateria`, `MateriaSource` |

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Standard:** C++20
- **Polymorphism:** `virtual` destructor on base classes with virtual methods
- **Deep copy:** `WrongCat` vs `Cat` demonstrates shallow-copy trap
- **STL:** Forbidden until CPP08 (`ex02` uses fixed-size arrays per subject)
