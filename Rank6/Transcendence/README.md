# Transcendence — ft_transcendence

Team project: build a **real-world web application** of your team's choosing — frontend, backend, and database — deployed with **Docker**. Pong with tournaments is one valid example, but **your team decides the product**. This is the final Common Core project; no C or C++ required.

**Subject PDF (source of truth):** [ft_transcendence.pdf](./ft_transcendence.pdf) — **version 19.0**

## Project theme

A **team-chosen web application** with a mandatory core (auth, database, legal pages, multi-user support) plus **modules worth at least 14 points** (major = 2 pts, minor = 1 pt). Teams of **4–5** students assign roles, pick coherent modules, and ship a containerized stack launchable with **one command**.

## Study files

- [study-plan.md](./study-plan.md) — phased learning path from team setup to defense
- [theory-and-concepts.md](./theory-and-concepts.md) — web stack, Docker, WebSockets, auth, modules
- [exercises.md](./exercises.md) — mandatory baseline, module catalog, eval checklist
- [syntax-libraries-tools.md](./syntax-libraries-tools.md) — stack options and tooling reference

## Mandatory core (every team)

| Area | Requirement |
|------|-------------|
| Architecture | Web application with **frontend**, **backend**, and **database** |
| Deployment | Containerization (Docker, Podman, or equivalent) — entire stack with **one command** |
| Browser | Latest stable **Google Chrome** — no warnings or errors in the browser console |
| Legal | Accessible **Privacy Policy** and **Terms of Service** (real content, footer links — not placeholders) |
| Multi-user | Multiple users logged in and active simultaneously; concurrent actions handled without corruption |
| Auth | Basic user management — sign up and log in securely (hashed, salted passwords at minimum) |
| Secrets | Credentials in a local `.env` (gitignored) + `.env.example` provided |
| Transport | **HTTPS** on the backend |
| Input | All forms validated on **frontend and backend** |
| Database | Clear schema with well-defined relations |
| Git | Meaningful commits from **all** team members showing real work distribution |
| README | Comprehensive root `README.md` per subject (team info, stack, schema, modules, contributions, AI disclosure) |

## Module scoring

| Type | Points |
|------|--------|
| Major module | 2 |
| Minor module | 1 |
| **Minimum to validate** | **14** |

Aim for **more than 14** — incomplete modules score **0** at evaluation. Plan dependencies before coding (e.g. gaming modules require a game first; advanced chat requires basic chat from User interaction).

## Team roles (required)

Roles must be documented in `README.md`. One person may hold multiple roles on a 4-person team.

| Role | Responsibility |
|------|----------------|
| **Product Owner (PO)** | Product vision, backlog, feature priorities, validates completed work, communicates with evaluators |
| **Project Manager (PM)** | Meetings, progress tracking, communication, risk/blocker management |
| **Technical Lead** | Architecture, stack decisions, code quality, critical code reviews |
| **Developers** (all members) | Implement features, code reviews, testing, documentation |

Evaluators will ask how roles were assigned, how work was divided, how you communicated, and what each member contributed. **Every member** must explain the project and their own work.

## Evaluation traps (read before defense)

| Trap | Consequence |
|------|-------------|
| Missing or placeholder Privacy Policy / Terms of Service | **Project rejection** |
| Browser console warnings or errors in Chrome | Fails general requirements |
| Stack not launchable with one Docker command | Fails deployment requirement |
| Chosen modules not fully functional at demo | Module scores **0**; may drop below 14 |
| Claiming modules without meeting dependencies (e.g. tournament without a game) | Module not counted |
| Plain HTTP for backend in eval environment | Fails technical requirements |
| Team cannot explain roles, contributions, or their own code | Peer eval / defense failure |
| Incomplete or dishonest README (modules, contributions, AI usage) | Negatively impacts evaluation |
| Over-relying on AI-generated code you cannot explain | Live modification or defense failure |
| `.env` secrets committed to Git | Security failure |

During evaluation, a **brief live modification** may be requested (small behaviour change, a few lines of code, minor feature tweak) to verify real understanding. Be prepared to edit code on the spot.

See [exercises.md](./exercises.md) for the full module catalog and checklist.
