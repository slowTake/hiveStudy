# Exam Rank 04 — Tools and syntax

## Compile one file

```bash
gcc -Wall -Wextra -Werror aff_first_param.c -o aff_first_param
./aff_first_param test
```

## Allowed headers (typical)

Only what exercise permits. Common:

| Header | Provides |
|--------|----------|
| `<unistd.h>` | `write` |
| `<stdlib.h>` | `malloc`, `free` |
| `<stdio.h>` | Sometimes forbidden — check subject |

## Test harness habit

```bash
diff <(./your_prog args) <(expected_command)
```

## Leak check (practice at home)

```bash
gcc -g prog.c -o prog && valgrind --leak-check=full ./prog
```

Exam machine may not have valgrind — practice until leak-free locally.

## Subject file layout

```
exercise_name/
└── exercise_name.c   # exact name from subject
```

## Time management

| Level | Suggested max time |
|-------|-------------------|
| 00 | 15–20 min |
| 01 | 20–25 min |
| 02 | 25–30 min |
| 03 | 30–35 min |
| 04 | 35–40 min |

Adjust if campus pass line is lower.

## C++ note

If Rank 04 exam on your campus is C-only, ignore C++ compile flags. For mixed exams:

```bash
c++ -std=c++20 -Wall -Wextra -Werror main.cpp -o prog
```
