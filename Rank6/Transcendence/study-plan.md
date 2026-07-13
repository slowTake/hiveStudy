# Transcendence — Study plan

Assumes you completed Rank 5 (especially **Inception** for Docker, **IRC** for sockets/event loops). Transcendence is a long group project — plan as a team from day one. All requirements below follow [ft_transcendence.pdf](./ft_transcendence.pdf) **v19.0**.

---

## Phase 0 — Team, roles & module planning (3–5 days)

| Task | Detail |
|------|--------|
| Read PDF v19.0 end-to-end | Mandatory core + full module catalog + README requirements |
| Assign team roles | PO, PM, Tech Lead, Developers — document in README (4-person teams: some members hold multiple roles) |
| Choose project idea | Team picks the web application (Pong, social network, LMS, marketplace, etc.) — must support 14+ module points coherently |
| Plan modules ≥ 14 pts | Table: module → major/minor → points → owner → dependencies → demo plan |
| Map dependencies | Gaming modules need a game first; Game statistics needs a game; advanced chat needs basic chat; SSR incompatible with ICP blockchain |
| Choose tech stack | Frontend + backend frameworks, database, real-time layer — align with chosen modules |
| Repo & workflow | Git branching, code review policy, who owns Docker/compose |
| Draw architecture | Client ↔ API ↔ DB ↔ optional services (WebSockets, ELK, etc.) |

**Checkpoint:** Team agrees on product vision, role assignments, and module table totaling **≥ 14 pts** (consider **15–16+** as buffer). Everyone can explain the point math (e.g. 5 major + 4 minor = 14).

---

## Phase 1 — Web foundations + Docker + README skeleton (1–2 weeks)

| Topic | Resource |
|-------|----------|
| HTTP / REST | Methods, status codes, JSON bodies, validation |
| HTML / CSS / JS or TS | DOM, events, `fetch`, component structure |
| Responsive UI | CSS framework or styling solution of your choice |
| Docker Compose | Multi-service stacks (reuse Inception skills) |
| TLS / HTTPS | Reverse proxy, certificates, WSS vs WS |
| README skeleton | First line, Description, Instructions, Resources placeholders; Team Information section started |

**Checkpoint:** Tiny web app in Docker — one `make` or `docker compose up` brings up frontend + backend + DB. README skeleton committed with team logins and roles.

---

## Phase 2 — Mandatory baseline (2–3 weeks)

Build the non-negotiable core **before** optional modules. This phase is **not Pong-first** — focus on the foundation every team needs regardless of product.

| Step | Task |
|------|------|
| 1 | Root `Makefile` or script → `docker compose up --build` |
| 2 | Frontend shell — clear, responsive, accessible layout |
| 3 | Backend with **HTTPS**; `.env` + `.env.example` for secrets |
| 4 | Database with clear schema and defined relations |
| 5 | User auth — sign up, login, hashed + salted passwords; frontend **and** backend validation |
| 6 | Privacy Policy + Terms of Service pages (real content, footer links) |
| 7 | Multi-user support — concurrent sessions, no race conditions on shared data |
| 8 | Chrome compatibility — fix all console warnings and errors |

**Checkpoint:** Two browsers can register, log in, and use the app simultaneously; legal pages accessible; stack starts with one command; Chrome console is clean.

---

## Phase 3 — Core modules (3–6 weeks)

Implement the **highest-dependency** modules your product needs. Content varies by team — examples:

| Module theme | Typical deliverables |
|--------------|---------------------|
| Web frameworks | Frontend + backend framework in use |
| Real-time features | WebSockets — connection handling, broadcasting |
| User interaction | Basic chat, profiles, friends system |
| Gaming (if chosen) | First playable game, remote players |
| User management | Profile updates, avatar, online status |
| Public API | Secured key, rate limiting, docs, ≥ 5 REST endpoints |

**Checkpoint:** One complete vertical slice demoable end-to-end (e.g. two remote users chatting, or two remote players in a live match, depending on your product).

---

## Phase 4 — Remaining modules to 14+ (2–4 weeks)

| Step | Task |
|------|------|
| 1 | Implement remaining chosen modules one at a time — verify each is fully functional before claiming points |
| 2 | Respect dependency order (tournaments after game, advanced chat after basic chat, etc.) |
| 3 | Add polish modules: i18n, accessibility, analytics, DevOps, AI, blockchain — per your plan |
| 4 | Buffer modules | If time allows, add 1–2 extra minor modules as insurance |

**Checkpoint:** Module checklist matches subject; each claimed module is demoable; point total **≥ 14** with stable mandatory core.

---

## Phase 5 — README, defense prep & live modification readiness (1–2 weeks)

| Task | Detail |
|------|--------|
| Complete README | All required sections: team roles, project management, stack justification, DB schema, features list, modules with point math, individual contributions, AI disclosure in Resources |
| HTTPS hardening | Reverse proxy (nginx, traefik, etc.) in compose if not already done |
| Peer eval script | Walk through every mandatory requirement + each claimed module |
| Failure modes | DB down, bad input, disconnect mid-session, auth edge cases |
| Live modification prep | Each member can locate and edit their area quickly — small function change, display tweak, or data structure adjustment |
| AI accountability | Document which tasks used AI; ensure every member understands all AI-assisted code |
| Exam Rank 06 | Prep [Exam-Rank-06](../Exam-Rank-06/) in parallel if not done |

**Checkpoint:** Teammate who didn't write a module can still explain it; `make` / `docker compose up` works on a clean clone; README is complete and honest.

---

## Suggested module bundles (examples from PDF v19.0)

Confirm exact names and requirements on your PDF. Major = 2 pts, Minor = 1 pt.

| Goal | Example mix | Points |
|------|-------------|--------|
| Multiplayer Pong | Web-based game (2) + Remote players (2) + Tournament (1) + AI Opponent (2) + Frontend framework (1) + Backend framework (1) + Real-time (2) + User interaction (2) + ORM (1) | 14 |
| Social network | User interaction (2) + Real-time (2) + Notification (1) + Advanced chat (1) + File upload (1) + Frontend framework (1) + Backend framework (1) + ORM (1) + Standard user mgmt (2) + Public API (2) | 14 |
| Collaborative workspace | Real-time collaborative (1) + User interaction (2) + Organization system (2) + File upload (1) + Frontend framework (1) + Backend framework (1) + Real-time (2) + Advanced permissions (2) + ORM (1) + Notification (1) | 14 |
| Online Chess | Web-based game (2) + Remote players (2) + AI Opponent (2) + Spectator mode (1) + Game statistics (1) + Frontend framework (1) + Backend framework (1) + Real-time (2) + User interaction (2) | 14 |
| Forum platform | User interaction (2) + Advanced permissions (2) + Gamification (1) + Content moderation AI (1) + Advanced search (1) + Frontend framework (1) + Backend framework (1) + ORM (1) + Standard user mgmt (2) + Public API (2) | 14 |
| Task management | Organization system (2) + User interaction (2) + Real-time collaborative (1) + Notification (1) + Analytics dashboard (2) + Frontend framework (1) + Backend framework (1) + ORM (1) + Advanced permissions (2) + Public API (1) | 14 |

Do not copy a bundle blindly — pick modules that fit **your** product and respect dependency chains.

---

## Time management tips

- **Docker first** — unblock everyone early with a running compose file.
- **Mandatory before modules** — auth, DB, legal pages, and multi-user support before feature sprawl.
- **One vertical slice** — one complete user flow before polishing UI.
- **Module freeze** — stop adding modules when you hit 14+ with everything stable and demoable.
- **README as you go** — updating contributions and module notes weekly avoids a last-minute scramble.
- **Exam Rank 06** — can be done during Transcendence; uses C sockets with `select()` and strict output format.
