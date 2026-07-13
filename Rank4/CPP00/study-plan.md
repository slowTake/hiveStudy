# CPP00 — Study plan

## Phase 0 — C++ environment (½ day)

| Topic | Action |
|-------|--------|
| Compile & link | `c++ -std=c++20 -Wall -Wextra -Werror` |
| Headers | `.hpp` vs `.h`, include guards (`#pragma once` or `#ifndef`) |
| `iostream` | `std::cout`, `std::cerr`, `std::endl` vs `\n` |
| Namespaces | `std::`, `using` sparingly |

**Checkpoint:** Compile a hello-world with the Hive flags and zero warnings.

---

## Phase 1 — ex00 Megaphone (½ day)

| Step | Task |
|------|------|
| 1 | Parse `argv[1..]` |
| 2 | Uppercase each character before output |
| 3 | Handle no-args case (newline only) |

**Checkpoint:** `./megaphone "shhhhh... I think the students are asleep..."` matches subject output.

---

## Phase 2 — ex01 PhoneBook (2–3 days)

| Step | Task |
|------|------|
| 1 | Design `Contact` with private fields + getters |
| 2 | Design `PhoneBook` with fixed array (max 8 contacts) |
| 3 | Implement `ADD`, `SEARCH`, `EXIT` commands |
| 4 | Format search table with truncated/wide columns |

**Checkpoint:** Add 8 contacts, reject 9th, search by index, EXIT cleans up.

---

## Phase 3 — ex02 Account (1–2 days)

| Step | Task |
|------|------|
| 1 | Read subject for `Account` API (static members) |
| 2 | Implement `makeDeposit`, `makeWithdrawal`, `displayStatus` |
| 3 | Log timestamps and totals to `[timestamp] ...` format |

**Checkpoint:** Output matches provided log samples line-for-line.

---

## Phase 4 — ex03 Violence (1–2 days)

| Step | Task |
|------|------|
| 1 | `Weapon` with `getType` / `setType` |
| 2 | `HumanA` — weapon by **reference** (always armed) |
| 3 | `HumanB` — weapon by **pointer** (may be unarmed) |
| 4 | `attack()` prints type or empty hands |

**Checkpoint:** Explain why `HumanA` uses reference and `HumanB` uses pointer.

---

## Phase 5 — ex04 Sed (1 day)

| Step | Task |
|------|------|
| 1 | Read input file line by line or whole-file |
| 2 | Replace all occurrences of `s1` with `s2` |
| 3 | Write `<filename>.replace` |

**Checkpoint:** No partial replacements; empty `s1` is invalid per subject.

---

## Phase 6 — ex05 Harl (1 day)

| Step | Task |
|------|------|
| 1 | Implement `Harl::complain(level)` |
| 2 | Use member function pointer table or switch |
| 3 | Filter macros: `DEBUG`, `INFO`, `WARNING`, `ERROR` |

**Checkpoint:** `./harlFilter WARNING` prints WARNING and ERROR only.

---

## Phase 7 — Remaining exercises (optional per campus)

- **ex06/ex07:** Robot factory patterns — preview of CPP05 `Intern`; defer deep dive until CPP05 if not on your PDF.

---

## Evaluation prep (1 day)

- Re-read [exercises.md](./exercises.md) per exercise
- Run each binary through peer-style edge cases
- Verify Makefile targets: `all`, `clean`, `fclean`, `re`
