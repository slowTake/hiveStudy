# CPP03 — Study plan

## Phase 0 — Inheritance basics (1 day)

| Topic | Action |
|-------|--------|
| Base / derived | `class ScavTrap : public ClapTrap` |
| Constructor order | Base subobject constructed first |
| Access specifiers | `public` inheritance preserves access |
| `virtual` destructor | Preview — essential before CPP04 |

---

## Phase 1 — ex00 ClapTrap (2 days)

| Attribute | Typical subject values |
|-----------|------------------------|
| Hit points | 10 |
| Energy | 10 |
| Attack damage | 0 |

Implement `attack`, `takeDamage`, `beRepaired` with energy/HP guards.

---

## Phase 2 — ex01 ScavTrap (1–2 days)

Inherit from `ClapTrap`, override stats in constructor initializer list, add `guardGate()`.

---

## Phase 3 — ex02 FragTrap (1–2 days)

High HP, `highFivesGuys()` special ability.

---

## Phase 4 — ex03 DiamondTrap (2–3 days)

| Problem | Solution |
|---------|----------|
| Two `ClapTrap` subobjects from dual inheritance | `virtual public ClapTrap` on parents |
| Name collision | `DiamondTrap` name = `FragTrap::name + "_diamond"` |

**Checkpoint:** Only **one** `ClapTrap` subobject in `DiamondTrap`; attack uses `FragTrap` damage, HP from `ScavTrap`.

---

## Evaluation prep

- Construction/destruction log order matches expected diamond layout
- Energy depletion blocks actions
- No attribute drift from subject PDF
