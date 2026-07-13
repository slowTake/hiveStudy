# Exam Rank 04 — Exercise reference

Exercises vary by exam version. Below are **representative** subjects — always follow the text on your screen.

---

## Level 00

### aff_first_param

| | |
|---|---|
| **Files** | `aff_first_param.c` |
| **Functions** | `write` only |
| **Behaviour** | Print `argv[1]` + newline; if no args, newline only |

---

## Level 02

### inter

| | |
|---|---|
| **Files** | `inter.c` |
| **Behaviour** | Print characters appearing in **both** `argv[1]` and `argv[2]` (first occurrence order, no duplicates) |

---

## Level 04

### ft_itoa

| | |
|---|---|
| **Files** | `ft_itoa.c` |
| **Prototype** | `char *ft_itoa(int n);` |
| **Functions** | `malloc` |
| **Behaviour** | Return allocated string; handle `INT_MIN` |

### ft_list_foreach

Apply function pointer to each node's data.

---

## Level 05

### brainfuck

| | |
|---|---|
| **Behaviour** | Interpret brainfuck string; 8-bit tape; `.` outputs char |
| **Trap** | Infinite loop on bad input — subject may limit steps |

---

## C++ appearance

Some campuses introduce **early C++** exam questions in later ranks — Rank 04 exam is still **primarily C**. If you receive a C++ exercise, it is usually simple class or `std::string` — confirm with peers who sat recently.

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| Extra library function | Automatic fail |
| File name mismatch | Won't compile |
| Memory leak | May fail Moulinette |
| Norm errors | Varies by campus — exam often relaxed vs projects |

---

## Practice sources

- Peer exam repos (read subjects only, implement yourself)
- [42 C Exam Review](http://nigal.freeshell.org/42/exam-review.php) — subject archive
- Campus `#exam` channel recent level reports
