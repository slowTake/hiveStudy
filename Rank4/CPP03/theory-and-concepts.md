# CPP03 — Theory and concepts

## Inheritance

```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    void guardGate();
};
```

Derived objects contain a **base subobject**. The base constructor runs before the derived body.

## Name hiding

Derived `attack()` **hides** base `attack()` unless you bring it:

```cpp
using ClapTrap::attack;
```

`DiamondTrap` may need explicit resolution of which `attack` to expose.

## Virtual inheritance (diamond)

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

Without `virtual`, `DiamondTrap` gets **two** `ClapTrap` instances — ambiguous and wrong for subject stats.

## Construction order (diamond)

1. Virtual base (`ClapTrap`)
2. Direct bases left-to-right (`ScavTrap`, `FragTrap`)
3. `DiamondTrap` body

Destruction reverses this order.

## Polymorphism preview

CPP03 often uses non-virtual functions. CPP04 introduces `virtual` and dynamic dispatch — add `virtual ~ClapTrap()` now to avoid leaks later.

## Energy and HP invariants

Centralize decrement logic in private helpers to avoid duplicating guard checks across derived classes.
