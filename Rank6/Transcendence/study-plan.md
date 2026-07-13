# Transcendence — Study plan

Assumes you completed Rank 5 (especially **Inception** for Docker, **IRC** for sockets/event loops). Transcendence is longer — plan as a team from day one.

---

## Phase 0 — Team & module planning (3–5 days)

| Task | Detail |
|------|--------|
| Read subject PDF end-to-end | Mandatory baseline + full module list |
| Pick modules totaling ≥ 7 pts | Write a table: module → owner → dependencies |
| Choose tech stack | Backend framework, frontend toolkit, database — align with chosen modules |
| Repo & workflow | Git branching, code review, who owns Docker/CI |
| Draw architecture | SPA ↔ API ↔ DB ↔ game (client or server) |

**Checkpoint:** Team agrees on module list and can explain point math (e.g. 5 major + 4 minor = 7).

---

## Phase 1 — Web foundations (1–2 weeks, parallel)

| Topic | Resource |
|-------|----------|
| HTTP / REST | Methods, status codes, JSON bodies |
| HTML / CSS / JS or TS | DOM, events, `fetch`, modules |
| SPA routing | History API, back/forward without reload |
| Docker Compose | Multi-service stacks (reuse Inception skills) |
| TLS basics | Reverse proxy, cert paths, WSS vs WS |

**Checkpoint:** Tiny static SPA in Docker — one `make` or `docker compose up` brings it up.

---

## Phase 2 — Mandatory baseline skeleton (2–3 weeks)

Build the non-negotiable core before optional modules.

| Step | Task |
|------|------|
| 1 | Root `Makefile` → `docker compose up --build` |
| 2 | SPA shell with client-side routing |
| 3 | Local 2-player Pong (canvas or DOM) |
| 4 | Tournament UI: create tournament, register aliases, bracket/matchmaking |
| 5 | Security baseline: env secrets, hashed passwords if accounts exist |

**Checkpoint:** Two players on one machine can finish a tournament match; stack starts with one command.

---

## Phase 3 — Core modules (3–6 weeks)

Typical “foundation” picks (adjust to your subject):

| Module theme | Common deliverables |
|--------------|---------------------|
| Backend framework | REST API, routing, middleware |
| Database | User/game schema, migrations |
| User management | Register, login, profile, match history |
| Remote players | WebSockets or similar for networked Pong |

**Checkpoint:** Two browsers on two machines can play one match and see results stored.

---

## Phase 4 — Remaining modules & polish (2–4 weeks)

| Step | Task |
|------|------|
| 1 | Implement remaining chosen modules one at a time |
| 2 | 2FA/JWT, OAuth, AI, 3D, chat — per your module list |
| 3 | Responsive layout if “all devices” module selected |
| 4 | Logging, monitoring, GDPR — if DevOps modules selected |

**Checkpoint:** Module checklist matches subject; each feature demoable in eval.

---

## Phase 5 — Hardening & defense prep (1–2 weeks)

| Task | Detail |
|------|--------|
| HTTPS/WSS | nginx or traefik in compose |
| Peer eval script | Walk through every mandatory + module feature |
| Failure modes | DB down, bad input, disconnect mid-game |
| Documentation | README: install, env vars, module list |
| Exam Rank 06 | Prep [Exam-Rank-06](../Exam-Rank-06/) in parallel if not done |

**Checkpoint:** Teammate who didn’t write a module can still explain it; `make` works on a clean clone.

---

## Suggested module bundles (examples only)

Confirm names and points on your PDF.

| Goal | Example mix | Points |
|------|-------------|--------|
| Minimal web stack | Backend framework + DB + frontend toolkit + user mgmt + remote players + browser support | 7.0 |
| Security focus | Above + 2FA/JWT + remote auth | 8.0+ |
| Game-heavy | User mgmt + remote players + AI opponent + stats dashboard + customization | 7.5+ |

Do not copy a bundle blindly — dependencies and campus-specific rules may differ.

---

## Time management tips

- **Docker first** — unblock everyone early with a running compose file.
- **One vertical slice** — auth + one game path before polishing UI.
- **Module freeze** — stop adding modules when you hit 7+ with stable mandatory.
- **Exam Rank 06** — can be done during Transcendence; uses C sockets like IRC but with `select()` and stricter output format.
