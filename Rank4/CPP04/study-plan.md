# CPP04 — Study plan

## Phase 0 — Virtual functions (1 day)

| Topic | Action |
|-------|--------|
| `virtual` | Dynamic dispatch through base pointer |
| `override` | Explicit override in derived |
| Virtual destructor | `delete` through base pointer |
| Pure virtual | `= 0` makes class abstract |

**Checkpoint:** Explain output of `Animal* a = new Dog(); a->makeSound();`

---

## Phase 1 — ex00 Polymorphism (2 days)

| Class | `makeSound` | Notes |
|-------|-------------|-------|
| `Animal` | Generic or none | Virtual `makeSound()` |
| `Dog`, `Cat` | Specific sounds | Override |
| `WrongAnimal`, `WrongCat` | **Non-virtual** | Shows slicing / wrong dispatch |

---

## Phase 2 — ex01 Deep copy (3 days)

| Step | Task |
|------|------|
| 1 | `Brain` class with `ideas[100]` |
| 2 | `Dog`/`Cat` own `Brain*` |
| 3 | Copy ctor / assign duplicate `Brain` |
| 4 | Test: modify original brain idea — copy unchanged |

---

## Phase 3 — ex02 Materia (4–5 days)

| Step | Task |
|------|------|
| 1 | `ICharacter` interface — pure virtual |
| 2 | `AMateria` abstract with `clone()` |
| 3 | Concrete materia: Ice, Cure |
| 4 | `Character` inventory max 4 |
| 5 | `MateriaSource` learns/clones templates |

---

## Evaluation prep

- `delete` polymorphic objects only through base pointer with virtual dtor
- `WrongCat` demo understood — evaluators ask why sound is wrong
- Materia clone ownership rules — who deletes?
