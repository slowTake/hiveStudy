# Transcendence — Exercise breakdown

Source: official **ft_transcendence** subject PDF on the intranet. Module names and point values may change between versions — treat this document as a study map, not a substitute for the PDF.

---

## Turn-in summary

| | |
|---|---|
| **Project type** | Team (typically 3–5 students) |
| **Deliverable** | Full web application + Docker setup |
| **Launch** | Single command (e.g. `make` → `docker compose up --build`) |
| **Validation** | Mandatory baseline + **≥ 7 module points** |

---

## Mandatory baseline (all teams)

These apply regardless of which modules you choose.

| Requirement | Detail |
|-------------|--------|
| SPA | Single-page application; browser back/forward must work |
| Docker | Entire site runs in containers; one-command startup |
| Browser | Latest stable **Firefox** minimum |
| Security | No plaintext passwords in DB; protect against SQL injection; use HTTPS/WSS where required |
| Pong | Two players can play locally on the same machine |
| Tournament | Registration + matchmaking for tournament matches |
| Website | Coherent UI — not a bare minimum hack |

---

## Module scoring

| Type | Points |
|------|--------|
| Major | 1.0 |
| Minor | 0.5 |
| Two minors | Equivalent to one major |
| **Minimum** | **7.0** to validate |

Bonus modules only count if mandatory and chosen modules are complete — same rule as other 42 projects.

---

## Module catalog (typical subject)

Verify exact wording on your PDF. Points shown are standard across recent versions.

### Web

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Backend framework | Use an approved framework (Django, Fastify, NestJS, etc. — subject may name one) |
| 0.5 | Frontend toolkit/framework | Bootstrap, Tailwind, or similar |
| 0.5 | Database | PostgreSQL, SQLite, or subject-designated DB |

### User management

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Standard user management | Register, login, profile, avatar, friends/block, stats, match history |
| 1.0 | Remote authentication | OAuth (42 API, Google, etc.) |

### Gameplay & UX

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Remote players | Two players on different computers, same match |
| 1.0 | Multiple players | More than two players in one game |
| 1.0 | Another game | Second game + history + matchmaking |
| 0.5 | Game customization | User-adjustable settings (paddle speed, etc.) |
| 1.0 | Live chat | Real-time chat between users |

### AI

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | AI opponent | Computer player that can win sometimes |
| 0.5 | Stats dashboard | User/game statistics views |

### Cybersecurity

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | 2FA + JWT | Two-factor auth + JSON Web Tokens |
| 1.0 | WAF + Vault | ModSecurity (or similar) + HashiCorp Vault for secrets |
| 0.5 | GDPR options | Anonymization, local data, account deletion |

### DevOps

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Microservices | Split backend into separate services |
| 1.0 | Log management | Centralized logging (ELK, etc.) |
| 0.5 | Monitoring | Health/metrics dashboard |
| 1.0 | Blockchain | Store tournament results on blockchain |

### Graphics

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Advanced 3D | Three.js / WebGL techniques |

### Accessibility

| Pts | Module | Summary |
|-----|--------|---------|
| 0.5 | All devices | Tablets and phones (touch) |
| 0.5 | Browser compatibility | Chrome/Chromium in addition to Firefox |
| 0.5 | Multiple languages | i18n (EN + at least two more) |
| 0.5 | Visually impaired a11y | Screen reader / keyboard support |
| 0.5 | SSR | Server-side rendering integration |

### Server-side game

| Pts | Module | Summary |
|-----|--------|---------|
| 1.0 | Server-side Pong + API | Authoritative game logic on server |

---

## Example valid combinations

| Mix | Modules | Total |
|-----|---------|-------|
| A | Backend + DB + frontend toolkit + user mgmt + remote players + remote auth + browser compat | 7.0 |
| B | Backend + DB + user mgmt + remote players + 2FA/JWT + AI opponent + stats dashboard | 7.5 |
| C | 7 major modules (no minors) | 7.0 |

---

## Evaluation checklist

### Mandatory

- [ ] `make` (or documented single command) starts full stack
- [ ] SPA navigation without full reload; back/forward work
- [ ] Pong playable locally (two players)
- [ ] Tournament: register + play through matches
- [ ] Firefox: no console errors on main flows
- [ ] Passwords hashed; no secrets in git

### Per chosen module

- [ ] Feature demonstrable end-to-end
- [ ] Module owner can explain design
- [ ] Module integrates with Docker setup (no manual steps)

### Security (typical eval sheet)

- [ ] HTTPS for production-like setup
- [ ] WSS if using WebSockets
- [ ] SQL injection resistance demonstrated or explained
- [ ] JWT/2FA modules: correct flow, not cosmetic

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| Module “done” but not in Docker workflow | Module not counted |
| Remote players only on localhost | Module failure |
| AI never wins | AI module failure |
| Tournament aliases not unique | Mandatory/tournament failure |
| `docker compose` needs manual DB seed each time | Deployment failure |
| Team member cannot explain any part | Peer eval risk |

---

## What this repo does not include

Per [AGENTS.md](../../AGENTS.md): no submitted project code, no copy-paste app implementations. Use official docs and your team repo for implementation.
