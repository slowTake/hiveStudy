# AGENTS.md

## Repository purpose

**hiveStudy** is a curated study repository for passing **The Hive's 42 core curriculum**. It collects theory, concepts, study plans, syntax references, and exercise-by-exercise guidance for each project—not implementation solutions.

## Goals

- Provide structured learning paths before starting each project
- Document required theory, patterns, and constraints from the subject
- Highlight useful syntax, standard library features (where allowed), and tooling
- Keep material aligned with 42 evaluation norms (C++98, OCF, forbidden functions, etc.)

## Layout

```
Rank5/
  CPP05/          # Repetition and Exceptions (fully documented)
  CPP06/          # C++ casts (placeholder)
  CPP07/          # Templates (placeholder)
  CPP08/          # Templated containers, iterators, algorithms (placeholder)
  CPP09/          # STL (placeholder)
  Inception/      # Docker / system administration (placeholder)
  Webserv/        # HTTP server (placeholder)
  Exam-Rank-05/   # Rank 5 exam prep (placeholder)
```

Additional ranks (`Rank0`–`Rank4`, `Rank6`, etc.) may be added as the curriculum is covered.

## Conventions for contributors and agents

1. **Study material only** — Do not add graded exercise solutions or code that could be submitted as project work.
2. **One directory per project** — Match official 42 project names (e.g. `CPP05`, not `cpp-module-05`).
3. **Per-project structure** — Prefer:
   - `README.md` — overview and links
   - `study-plan.md` — ordered learning path
   - `theory-and-concepts.md` — concepts grouped by exercise
   - `syntax-libraries-tools.md` — quick reference for allowed APIs and build tooling
4. **C++ modules** — Respect module rules: C++98, `-Wall -Wextra -Werror -std=c++98`, Orthodox Canonical Form where required, and **no STL containers/algorithms before CPP08** unless the subject explicitly allows them.
5. **Source of truth** — When in doubt, defer to the official subject PDF from the 42 intranet and current evaluation sheets.

## Audience

Students at The Hive (42) working through the common core, and AI agents assisting with study planning or concept explanations in this repo.
