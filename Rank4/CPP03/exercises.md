# CPP03 — Exercise breakdown

## ex00 — ClapTrap

| Method | Behaviour |
|--------|-----------|
| `attack` | Target takes damage; costs 1 energy |
| `takeDamage` | Reduce HP |
| `beRepaired` | Increase HP; costs 1 energy |
| Guards | No action at 0 HP or 0 energy |

Output messages must match subject strings exactly (evaluators diff output).

---

## ex01 — ScavTrap

| Stat | Typical override |
|------|------------------|
| HP | 100 |
| Energy | 50 |
| Damage | 20 |
| Special | `guardGate()` |

---

## ex02 — FragTrap

| Stat | Typical override |
|------|------------------|
| HP | 100 |
| Energy | 100 |
| Damage | 30 |
| Special | `highFivesGuys()` |

---

## ex03 — DiamondTrap

Inherits `ScavTrap` and `FragTrap` with **virtual** `ClapTrap`.

| Trait | Source |
|-------|--------|
| Name | `FragTrap` name + `"_diamond"` |
| HP | `ScavTrap` |
| Energy | `ScavTrap` |
| Damage | `FragTrap` |
| Abilities | Both `attack` (Frag damage) and `guardGate` |

---

## Traps

| Trap | Detail |
|------|--------|
| Non-virtual diamond | Double `ClapTrap` base — wrong stats |
| Wrong construction order | Fails destructor trace tests |
| Using STL containers for traps | -42 |
