# CPP03 — Syntax, libraries, and tools

## Initializer lists for stats

```cpp
ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}
```

Prefer setting in ctor body or base if subject allows const members via initializer list.

## Virtual inheritance syntax

```cpp
class ScavTrap : virtual public ClapTrap
```

Note spacing: `virtual public` both required.

## Debug construction order

Temporarily log in each ctor/dtor:

```cpp
std::cout << "ScavTrap constructor" << std::endl;
```

Remove or gate behind macro before eval.

## Valgrind

Inheritance bugs often show as double-free — always run after ex03.
