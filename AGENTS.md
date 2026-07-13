# AGENTS.md

## Repository purpose

**hiveStudy** is a curated study repository for passing **Hive Helsinki's 42 core curriculum**. It collects theory, concepts, study plans, syntax references, and exercise-by-exercise guidance for each project—not implementation solutions.

## Goals

- Provide structured learning paths before starting each project
- Document required theory, patterns, and constraints from the subject
- Highlight useful syntax, standard library features (where allowed), and tooling
- Keep material aligned with The Hive evaluation norms (**C++20**, OCF, forbidden functions, etc.)

## Layout

```
Rank4/
  CPP00/          # C++ basics
  CPP01/          # Memory, pointers, references
  CPP02/          # OCF, fixed-point
  CPP03/          # Inheritance, diamond problem
  CPP04/          # Polymorphism, abstract classes
  NetPractice/    # TCP/IP subnetting puzzles
  Cub3D/          # Raycasting (or MiniRT on some campuses)
  Exam-Rank-04/   # Rank 4 exam prep
Rank5/
  CPP05/          # Repetition and Exceptions
  CPP06/          # C++ casts
  CPP07/          # Templates
  CPP08/          # Templated containers, iterators, algorithms
  CPP09/          # STL
  Inception/      # Docker / system administration (fully documented)
  Webserve/       # ft_webserve — HTTP server
  IRC/            # ft_irc — IRC server
  Exam-Rank-05/   # Rank 5 exam prep (vect2, bigint, polyset)
Rank6/
  Transcendence/  # ft_transcendence — modular web app, Docker, 14-point modules
  Exam-Rank-06/   # Rank 6 exam prep (mini_serv)
```

Additional ranks (`Rank0`–`Rank3`, etc.) may be added as the curriculum is covered.

## Conventions for contributors and agents

1. **Study material only** — Do not add graded exercise solutions or code that could be submitted as project work.
2. **One directory per project** — Match official 42 project names (e.g. `CPP05`, `IRC`).
3. **Per-project structure** — Prefer:
   - `README.md` — overview and links
   - `study-plan.md` — ordered learning path
   - `syntax-libraries-tools.md` — quick reference for allowed APIs and build tooling
   - **Rank5 CPP05–CPP09, IRC, Webserve:** `exercises.md` only — module concepts, per-feature (or per-exercise) concepts, requirements, pitfalls, and evaluator checklist in one file
   - **Other projects:** also `theory-and-concepts.md` (concepts grouped by exercise) and `exercises.md` (deliverables and eval checklist)
4. **C++ standard** — The Hive allows **C++20**: compile with `-std=c++20 -Wall -Wextra -Werror`. Use modern features (`nullptr`, `override`, `noexcept`, smart pointers) where they improve clarity. **STL containers/algorithms remain forbidden in CPP05–CPP07** per module subjects; CPP08+ explicitly introduces STL.
5. **IRC / Webserve** — Subject PDFs require **C++98**, non-blocking I/O with `poll()` (or equivalent). IRC: no `fork()`. Webserve: `fork()` only for CGI. Confirm Hive eval flags on evaluation sheets.
6. **Source of truth** — When in doubt, defer to the official subject PDF from the 42 intranet and current evaluation sheets.

## Audience

Students at Hive Helsinki (42) working through the common core, and AI agents assisting with study planning or concept explanations in this repo.
