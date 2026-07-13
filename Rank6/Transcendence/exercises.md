# Transcendence — Exercise breakdown

**Source note:** Official subject **ft_transcendence**, **version 19.0**, in this repo at [`./ft_transcendence.pdf`](./ft_transcendence.pdf). When in doubt, defer to the PDF and your campus evaluation sheet. This document is study material only — not a substitute for the subject and not implementation code.

---

## Turn-in summary

| Item | Requirement |
|------|-------------|
| **Team size** | **4–5** students |
| **Deliverable** | Full web application (frontend + backend + database) + Docker/Podman setup |
| **Launch** | **Single command** starts the entire stack (e.g. `make` → `docker compose up --build`) |
| **Module points** | **≥ 14** total (Major = 2 pts, Minor = 1 pt) |
| **README** | Comprehensive `README.md` at repo root (see [README requirements](#readme-requirements-ch-vi)) |
| **Git** | Repository with meaningful commits from **all** team members |

Aim for **more than 14 points** as a buffer — incomplete modules score **0** at evaluation.

---

## Mandatory baseline (Ch III + VI)

These apply to **every** team, regardless of chosen modules or project idea.

### General requirements (III.2)

| Requirement | Detail |
|-------------|--------|
| **Web application** | Frontend, backend, and database — all required |
| **Git** | Meaningful commit messages; commits from **all** members; visible work distribution |
| **Containerization** | Docker, Podman, or equivalent; **one command** to run the full project |
| **Browser** | Latest stable **Google Chrome** — full compatibility required |
| **Console** | **No warnings or errors** in the browser console during normal use |
| **Privacy Policy & Terms of Service** | Real, relevant content — **not** placeholders; easily accessible (e.g. footer links); verified at evaluation; missing/inadequate pages → **rejection** |
| **Multi-user support** | Multiple users logged in and active simultaneously; concurrent actions handled properly; real-time updates reflected when applicable; no data corruption or race conditions |

### Technical requirements (III.3)

| Requirement | Detail |
|-------------|--------|
| **Frontend** | Clear, **responsive**, and **accessible** across all devices |
| **CSS framework** | Use a framework or styling solution (Tailwind, Bootstrap, Material-UI, Styled Components, etc.) |
| **Secrets** | Store credentials in `.env` (gitignored); provide `.env.example` |
| **Database** | Clear schema with **well-defined relations** |
| **Basic auth** | Email + password sign-up/login; passwords **hashed and salted**; OAuth/2FA are optional **modules** |
| **Validation** | All forms and user inputs validated on **frontend and backend** |
| **HTTPS** | Backend must use **HTTPS everywhere** |

### Framework definition (subject)

For module scoring, a **framework** provides structured architecture, built-in features for common tasks (routing, state management, etc.), and a complete ecosystem. Examples: React, Vue, Angular, Svelte, Next.js (frontend); Express, Fastify, NestJS, Django, Flask, Ruby on Rails (backend). **Not** frameworks: jQuery, Lodash, Axios. React counts as a framework in this subject.

### What you are building (III.1)

The **project idea is yours** — Pong is only one example. Valid directions include multiplayer games, collaborative platforms, social networks, project management apps, or any creative web app meeting the mandatory requirements. You must still earn **14 module points** from Ch IV.

---

## Module scoring

| Type | Points |
|------|--------|
| **Major** | 2 |
| **Minor** | 1 |
| **Minimum to validate** | **14** |

- Choose modules from **any** of the 10 categories; mix freely.
- Pick modules only after your product idea is clear.
- **Non-functional or incomplete modules = 0 points** — only fully working implementations count.
- Custom "Modules of choice" require strong README justification; trivial shortcuts → rejection.

---

## Module catalog (Ch IV)

All modules below are optional for scoring except that you need **14 points total**. Point values: Major = 2, Minor = 1.

### IV.1 — Web

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Use frameworks (frontend + backend)** | Frontend framework (React, Vue, Angular, Svelte, etc.) **and** backend framework (Express, NestJS, Django, Flask, Ruby on Rails, etc.). Full-stack frameworks (Next.js, Nuxt.js, SvelteKit) count as **both** if you use frontend and backend capabilities. |
| 1 | Frontend framework only | React, Vue, Angular, Svelte, etc. |
| 1 | Backend framework only | Express, Fastify, NestJS, Django, etc. |
| **2** | **Real-time features (WebSockets)** | Real-time updates across clients; graceful connection/disconnection handling; efficient message broadcasting. |
| **2** | **User interaction** | Basic chat (send/receive between users); profile system (view user info); friends system (add/remove, friends list). |
| **2** | **Public API** | Secured API key, rate limiting, documentation; **≥ 5 endpoints** including GET, POST, PUT, DELETE `/api/{something}`. |
| 1 | ORM | Use an ORM for the database. |
| 1 | Notification system | Complete notifications for all **create, update, and delete** actions. |
| 1 | Real-time collaborative features | Shared workspaces, live editing, collaborative drawing, etc. |
| 1 | Server-Side Rendering (SSR) | Improved performance and SEO. **Incompatible with ICP blockchain backend.** |
| 1 | Progressive Web App (PWA) | Offline support and installability. |
| 1 | Custom design system | Reusable components with color palette, typography, icons — **minimum 10** reusable components. |
| 1 | Advanced search | Filters, sorting, and pagination. |
| 1 | File upload and management | Multiple file types; client + server validation (type, size, format); secure storage with access control; preview where applicable; upload progress; delete files. |

### IV.2 — Accessibility and Internationalization

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Complete accessibility (WCAG 2.1 AA)** | Screen reader support, keyboard navigation, assistive technologies. |
| 1 | Multiple languages (≥ 3) | i18n system; 3 complete translations; language switcher; all user-facing text translatable. |
| 1 | RTL language support | At least one RTL language (Arabic, Hebrew, etc.); full layout mirroring; RTL-specific UI adjustments; seamless LTR ↔ RTL switching. |
| 1 | Additional browsers | Full compatibility with **≥ 2 additional** browsers (Firefox, Safari, Edge, etc.); test and fix all features; document limitations; consistent UI/UX. |

### IV.3 — User Management

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Standard user management** | Update profile; upload avatar (default if none); add friends + see **online status**; profile page. |
| 1 | Game statistics and match history | **Requires a game.** Wins/losses/ranking/level; match history (1v1, dates, results, opponents); achievements/progression; leaderboard. |
| 1 | Remote authentication (OAuth 2.0) | Google, GitHub, 42, etc. |
| **2** | **Advanced permissions** | User CRUD; roles (admin, user, guest, moderator, etc.); role-based views and actions. |
| **2** | **Organization system** | Create/edit/delete organizations; add/remove users; view orgs; org-scoped actions (minimum CRUD). |
| 1 | 2FA | Complete two-factor authentication for users. |
| 1 | User activity analytics | Insights dashboard for user activity. |

### IV.4 — Artificial Intelligence

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **AI Opponent** | **Requires a game.** Challenging, wins occasionally; human-like (not perfect); uses customization options if implemented; explain implementation at eval. |
| **2** | **RAG system** | Large dataset; Q&A with relevant answers; proper context retrieval and response generation. |
| **2** | **LLM interface** | Text and/or image generation; streaming responses; error handling and rate limiting. |
| **2** | **Recommendation system (ML)** | Personalized recommendations; collaborative or content-based filtering; improves over time. |
| 1 | Content moderation AI | Auto moderation, deletion, warnings, etc. |
| 1 | Voice/speech integration | Accessibility or interaction use cases. |
| 1 | Sentiment analysis | For user-generated content. |
| 1 | Image recognition and tagging | Recognition and tagging system. |

### IV.5 — Cybersecurity

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **WAF/ModSecurity + HashiCorp Vault** | Strict ModSecurity/WAF configuration; secrets in Vault (API keys, credentials, env vars) — encrypted and isolated. |

### IV.6 — Gaming and user experience

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Web-based game** | Real-time multiplayer (Pong, Chess, Tic-Tac-Toe, cards, etc.); live matches; clear rules and win/loss; 2D or 3D. |
| **2** | **Remote players** | Two players on **separate computers**, same game in real time; latency/disconnection handling; reconnection logic. |
| **2** | **Multiplayer (3+ players)** | **Requires a game.** Three or more simultaneous players; fair mechanics; client synchronization. |
| **2** | **Add another game** | **Requires a first game.** Second distinct game; user history and stats; matchmaking; performance maintained. |
| **2** | **Advanced 3D graphics** | Three.js or Babylon.js; immersive environment; advanced rendering; smooth interaction. |
| 1 | Advanced chat | **Requires basic chat (User interaction).** Block users; invite to games from chat; game/tournament notifications in chat; profile access from chat; chat history; typing indicators and read receipts. |
| 1 | Tournament system | **Requires a game.** Bracket/matchup order; track pairings; tournament matchmaking; registration and management. |
| 1 | Game customization | **Requires a game.** Power-ups/abilities; maps/themes; customizable settings; sensible defaults. |
| 1 | Gamification | **≥ 3 of:** achievements, badges, leaderboards, XP/level, daily challenges, rewards; persistent in DB; visual feedback; clear progression. |
| 1 | Spectator mode | **Requires a game.** Watch ongoing games; real-time spectator updates; optional spectator chat. |

### IV.7 — Devops

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **ELK log management** | Elasticsearch (store/index), Logstash (collect/transform), Kibana (dashboards); retention/archiving; secure access. |
| **2** | **Prometheus + Grafana monitoring** | Prometheus metrics; exporters/integrations; custom Grafana dashboards; alerting; secure Grafana access. |
| **2** | **Backend microservices** | Loosely coupled services; REST or message queues; single responsibility per service. |
| 1 | Health check + status page | Automated backups and disaster recovery procedures. |

### IV.8 — Data and Analytics

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Advanced analytics dashboard** | Interactive charts (line, bar, pie, etc.); real-time updates; export (PDF, CSV, etc.); customizable date ranges and filters. |
| 1 | Data export/import | JSON, CSV, XML, etc.; import with validation; bulk operations. |
| 1 | GDPR compliance | Users can request their data; deletion with confirmation; export readable user data; confirmation emails for data operations. |

### IV.9 — Blockchain

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Tournament scores on blockchain** | Avalanche + Solidity smart contracts on test blockchain; record/manage/retrieve tournament scores; integrity and immutability. |
| 1 | ICP backend | Internet Computer Protocol backend on blockchain. **Incompatible with SSR.** |

### IV.10 — Modules of choice

| Pts | Module | Requirements summary |
|-----|--------|----------------------|
| **2** | **Custom major module** | Not listed above; substantial technical complexity; full README justification (why, challenges, value, why Major); shortcuts/trivial features → rejection; relevant to your project. |
| 1 | **Custom minor module** | Smaller scope than Major; still demonstrates skill and meaningful value; README justification required. |

---

## Module dependencies

Plan module combinations so prerequisites are satisfied and incompatible pairs are avoided.

| Dependency / rule | Modules affected |
|-------------------|------------------|
| **At least one game first** | AI Opponent, Tournament, Game customization, Spectator mode, Multiplayer 3+, Add another game, Game statistics |
| **First game before second game** | Add another game |
| **Basic chat first** | Advanced chat (from **User interaction** module) |
| **SSR ↔ ICP** | SSR and ICP blockchain backend **cannot** both be claimed |
| **Functional only** | Every claimed module must be demonstrable end-to-end at evaluation |

**Recommended team roles** (Ch II — document in README): Product Owner, PM/Scrum Master, Technical Lead/Architect, Developers (all members). With 4 members, one person may hold multiple roles.

---

## README requirements (Ch VI)

The `README.md` at the repository root is **evaluated**. Incomplete or poor README negatively impacts your score.

### Mandatory sections (all projects)

1. **First line (italic):** `This project has been created as part of the 42 curriculum by <login1>[, <login2>[, ...]]`.
2. **Description** — project goal, overview, **project name**, key features.
3. **Instructions** — prerequisites (software, tools, versions, `.env` setup); step-by-step run instructions (compilation/installation/execution).
4. **Resources** — classic references (docs, articles, tutorials) **and** how AI was used (which tasks, which parts).

### Additional sections required for ft_transcendence

| Section | Content |
|---------|---------|
| **Team Information** | Per member: assigned role(s) (PO, PM, Tech Lead, Developer, etc.) and responsibilities |
| **Project Management** | Work organization; task distribution; meetings; tools (GitHub Issues, Trello, etc.); communication channels (Discord, Slack, etc.) |
| **Technical Stack** | Frontend/backend frameworks; database and rationale; other significant tech; justification for major choices |
| **Database Schema** | Visual or textual schema; tables/collections and relationships; key fields and types |
| **Features List** | Every implemented feature; who worked on it; brief functionality description |
| **Modules** | All chosen modules (Major/Minor); point calculation; justification (especially custom modules); implementation summary; per-module ownership |
| **Individual Contributions** | Per-member breakdown; specific features/modules/components; challenges and how they were overcome |

Optional but welcome: usage docs, known limitations, license, credits.

---

## Example 14-point combinations

### V.1 — Pong (from subject)

| Category | Modules | Points |
|----------|---------|--------|
| Gaming | Web-based game + Remote players + Tournament + Game customization | 2+2+1+1 = **6** |
| User Management | Standard user management + OAuth | 2+1 = **3** |
| Web | Frameworks (FE+BE) + ORM | 2+1 = **3** |
| AI | AI Opponent | **2** |
| **Total** | | **14** |

### Social network (non-Pong)

| Category | Modules | Points |
|----------|---------|--------|
| Web | User interaction + Real-time (WebSockets) + Notification system | 2+2+1 = **5** |
| Web | Frameworks (FE+BE) + File upload | 2+1 = **3** |
| User Management | Standard user management + Advanced permissions | 2+2 = **4** |
| Accessibility | Multiple languages (3) | **1** |
| Devops | Health check + status page | **1** |
| **Total** | | **14** |

Buffer option: add ORM (+1) or OAuth (+1) for 15.

### Collaborative workspace (non-Pong)

| Category | Modules | Points |
|----------|---------|--------|
| Web | Real-time collaborative + Frameworks (FE+BE) + ORM | 2+2+1 = **5** |
| Web | User interaction + File upload | 2+1 = **3** |
| User Management | Organization system + Standard user management | 2+2 = **4** |
| Data | GDPR compliance | **1** |
| Web | Advanced search | **1** |
| **Total** | | **14** |

---

## Evaluation checklist

### Mandatory baseline

- [ ] Single command starts full stack (Docker/Podman)
- [ ] Frontend + backend + database all present and integrated
- [ ] `.env` gitignored; `.env.example` provided
- [ ] DB schema documented with clear relations
- [ ] Email/password auth with hashed, salted passwords
- [ ] Form validation on frontend **and** backend
- [ ] HTTPS on backend
- [ ] Responsive, accessible UI; CSS framework in use
- [ ] Latest stable **Chrome**: no console warnings or errors on main flows
- [ ] Privacy Policy and Terms of Service: real content, footer (or equivalent) links
- [ ] Multiple simultaneous users: no conflicts, race conditions, or corruption
- [ ] Git: all members have meaningful commits; messages describe changes
- [ ] README complete per [Ch VI](#readme-requirements-ch-vi)

### Per claimed module

- [ ] Feature works end-to-end in the running Docker stack (no manual side steps)
- [ ] Module owner can explain design and implementation
- [ ] Dependencies satisfied (game, basic chat, etc.)
- [ ] Incompatible modules not both claimed (SSR + ICP)
- [ ] Custom modules: README justification matches what evaluators see

### Team and process (Ch II — expect questions)

- [ ] Each member can explain the **whole project** and **their own** contributions
- [ ] Roles (PO, PM, Tech Lead, Developers) documented and team can describe distribution
- [ ] Team can explain how work was divided and coordinated
- [ ] Communication and project-management tools described honestly in README

### Live modification (Ch VII)

Evaluators **may** request a small change to verify understanding — e.g. tweak a function, adjust UI display, extend a data structure. Scope is brief (often a few minutes). Be prepared to:

- [ ] Make a small code change in your usual dev environment
- [ ] Explain what you changed and why
- [ ] Demonstrate the result after the change

Details vary per evaluation sheet; not every eval includes this step.

---

## Evaluation traps

| Trap | Why it fails |
|------|----------------|
| **Privacy Policy / ToS missing or placeholder** | Mandatory rejection |
| **Console errors/warnings in Chrome** | Mandatory rejection |
| **Module not in Docker workflow** | Module scores 0; may drop below 14 |
| **Incomplete or broken module** | 0 points for that module |
| **Claiming game-dependent module without a working game** | Module rejected |
| **Advanced chat without basic chat** | Module rejected |
| **SSR + ICP both claimed** | Incompatible combination |
| **AI opponent never wins / plays perfectly** | AI module failure |
| **Remote play only on localhost** | Remote players module failure |
| **Public API missing verbs, docs, rate limit, or API key** | Public API module failure |
| **OAuth/2FA/WAF/Vault cosmetic only** | Security-related module failure |
| **Custom module trivial or unjustified in README** | Rejection of custom module |
| **Team member cannot explain their code** | Peer evaluation risk |
| **README missing required sections or dishonest contributions** | Negative evaluation impact |
| **Fresh clone + single command does not work** | Deployment / mandatory failure |
| **Multi-user race conditions or data corruption** | Mandatory multi-user failure |
| **Assuming Pong/tournament is mandatory** | v19.0 does **not** require Pong — only your chosen modules + baseline |

---

## What this repo does not include

Per [AGENTS.md](../../AGENTS.md): no submitted project code, no copy-paste implementations. Use the official PDF, framework documentation, and your team repository for building the app.
