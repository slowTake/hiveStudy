# Transcendence — ft_transcendence

Team project: build a **web application** where users play **Pong**, run tournaments, and authenticate securely. This is the first major web project in the common core — no C or C++ required.

**Subject PDF:** official `ft_transcendence` PDF on the 42 intranet — source of truth for requirements and module list.

## Project theme

A **single-page application (SPA)** deployed with **Docker**, featuring a playable Pong game, tournament registration/matchmaking, and a modular extension system. Teams pick modules worth at least **7 points** (major = 1 pt, minor = 0.5 pt; two minors = one major).

## Study files

- [study-plan.md](./study-plan.md) — phased learning path from web basics to defense
- [theory-and-concepts.md](./theory-and-concepts.md) — SPA, Docker, WebSockets, auth, modules
- [exercises.md](./exercises.md) — mandatory baseline, module catalog, eval traps
- [syntax-libraries-tools.md](./syntax-libraries-tools.md) — stack options and tooling reference

## Global constraints (typical subject)

| Area | Requirement |
|------|-------------|
| Architecture | Single-page application — browser back/forward must work |
| Deployment | `docker compose` (or equivalent) — launch entire stack with **one command** |
| Browser | Latest stable **Firefox** at minimum; additional browsers often a module |
| Security | HTTPS/WSS in production; hash passwords; protect against SQL injection |
| Game | Local 2-player Pong + tournament system (registration, matchmaking) |
| Team | Usually 3–5 students; divide modules early |

## Module scoring

| Type | Points |
|------|--------|
| Major module | 1.0 |
| Minor module | 0.5 |
| **Minimum to validate** | **7.0** |

Plan modules before coding. Dependencies exist (e.g. database module often required before user management).

## Evaluation traps (read before defense)

| Trap | Consequence |
|------|-------------|
| Not a true SPA (full page reloads on navigation) | Fails mandatory baseline |
| Stack not launchable with one Docker command | Fails deployment requirement |
| Chosen modules not fully implemented | Module points lost; may drop below 7 |
| Plain HTTP for sensitive data in eval environment | Security checklist failure |
| Tournament flow broken or untestable | Mandatory feature failure |
| Team cannot explain their own code | Peer eval / defense failure |

See [exercises.md](./exercises.md) for the full module catalog and checklist.
