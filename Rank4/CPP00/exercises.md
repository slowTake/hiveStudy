# CPP00 — Exercise breakdown

## Module validation

Every exercise in your campus PDF is **mandatory** for 100/100. Each lives in its own `exNN/` directory with `Makefile`, `main.cpp`, and required class files.

---

## ex00 — Megaphone

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp` |

### Expected behaviour

- Uppercase all characters from `argv[1..]` and print with no extra separators
- No arguments → print newline only
- No `std::string` required (but allowed)

### Evaluator checks

- Mixed case input
- Single argument with spaces (shell quoting)
- Empty string argument

---

## ex01 — My Awesome PhoneBook

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | `Makefile`, `main.cpp`, `Contact.{hpp,cpp}`, `PhoneBook.{hpp,cpp}` |

### Expected behaviour

| Command | Action |
|---------|--------|
| `ADD` | Prompt for fields; store up to **8** contacts (oldest replaced when full) |
| `SEARCH` | Display index table; prompt for index; show full contact or error |
| `EXIT` | Quit cleanly |

### Field rules

- First name, last name, nickname — required strings
- Phone number, darkest secret — subject defines validation (often any non-empty)
- Display column width **10** chars; truncate with `.` if longer; right-align index

### Evaluator checks

- 9th ADD overwrites oldest
- Invalid SEARCH index
- No leaks on EXIT

---

## ex02 — The Job Of Your Dreams

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | Provided `Account.cpp`, `Account.hpp`, `tests.cpp` — implement methods |

### Expected behaviour

- Static data members track total accounts, total amount, total deposits
- Each operation logs `[timestamp] index:amount;message`
- `displayAccountsInfos()` prints summary block

### Evaluator checks

- Log format **exact** match to subject samples
- Withdrawal refuses insufficient funds

---

## ex03 — Unnecessary violence

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex03/` |
| **Files** | `Weapon`, `HumanA`, `HumanB` classes + `main.cpp` |

### Expected behaviour

- `HumanA` holds `Weapon&` — must always have weapon
- `HumanB` holds `Weapon*` — may be nullptr → "bare hands"
- `attack()` prints: `<name> attacks with their <type>`

---

## ex04 — Sed is for losers

| | |
|---|---|
| **Mandatory** | Yes (if on PDF) |
| **Turn-in** | `ex04/` |
| **Arguments** | `./sed_is_for_losers <filename> <s1> <s2>` |

### Expected behaviour

- Read file, replace **all** non-overlapping occurrences of `s1` with `s2`
- Write result to `<filename>.replace`
- Errors: wrong arg count, unreadable file

---

## ex05 — Harl 2.0

| | |
|---|---|
| **Mandatory** | Yes (if on PDF) |
| **Turn-in** | `ex05/` |
| **Arguments** | `./harlFilter <level>` |

### Expected behaviour

- Print complaints from given level **up to** `ERROR`
- Unknown level → nothing or error per subject
- Use member function pointers (subject requirement)

---

## ex06 / ex07 — Campus-dependent

Some campuses include Robot-hub and Intern in CPP00. If present, treat as early factory/polymorphism warm-up — see CPP05 `Intern` for the mature pattern.

---

## Common evaluation traps

| Trap | Consequence |
|------|-------------|
| Using `vector` / `map` | -42 in CPP00–CPP07 |
| Wrong PhoneBook column format | Fails display tests |
| Account log format drift | Automatic fail on ex02 |
| `system()`, `exec()` | Forbidden in most modules |
