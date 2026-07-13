# CPP04 — Exercise breakdown

## ex00 — Polymorphism

| | |
|---|---|
| **Classes** | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat` |
| **Key** | `virtual void makeSound() const` on correct pair; **no** `virtual` on Wrong* |

### Evaluator checks

- Array of `Animal*` with dogs and cats — correct sounds
- `WrongAnimal*` holding `WrongCat` — **Animal** sound (static binding)
- Virtual destructor — no leak on `delete` through base

---

## ex01 — Brain deep copy

| | |
|---|---|
| **Ownership** | `Dog`/`Cat` allocate `Brain` in constructor |
| **Copy** | Deep copy in copy ctor and `operator=` |
| **Assignment** | Self-assignment safe; old brain deleted |

### Trap

Shallow copy → two objects share `Brain*` → double delete.

---

## ex02 — Abstract class (Materia)

| Interface | Role |
|-----------|------|
| `ICharacter` | `equip`, `unequip`, `use` |
| `AMateria` | `getType`, `clone()`, `use(ICharacter&)` |
| `MateriaSource` | `learnMateria`, `createMateria` |

### Rules

- Inventory size **4** slots
- `unequip` drops pointer at floor — **does not delete** (subject)
- `use` prints effect on target
- `clone()` returns deep copy of materia

---

## Traps

| Trap | Consequence |
|------|-------------|
| Missing virtual destructor | Leak / UB on delete |
| Shallow Brain copy | Crash |
| Deleting unequipped materia too early | Double delete |
