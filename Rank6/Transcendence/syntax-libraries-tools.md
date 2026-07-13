# Transcendence — Syntax, libraries, and tools

Quick reference for **ft_transcendence v19.0**. Your chosen modules may **require** specific technologies (e.g. Django for backend framework, Avalanche for blockchain) — always confirm against [`ft_transcendence.pdf`](./ft_transcendence.pdf).

**Scoring (v19):** Major = **2 pts**, Minor = **1 pt**, minimum to validate = **14 pts**.

---

## Docker & orchestration

| Tool | Use |
|------|-----|
| Docker Compose | Multi-container dev and eval |
| `Makefile` | `all`, `build`, `up`, `down`, `clean`, `re` |
| nginx / Traefik | TLS termination, reverse proxy |
| `.env` | Secrets and config (gitignored) |
| `.env.example` | Committed template — no real secrets |

```makefile
# Typical pattern — entire stack with one command
all:
	docker compose -f srcs/docker-compose.yml up --build -d
```

### `.env.example` pattern

Commit a template; copy to `.env` locally and in eval:

```bash
# .env.example — copy to .env and fill in real values
POSTGRES_USER=app
POSTGRES_PASSWORD=change_me
POSTGRES_DB=transcendence
DATABASE_URL=postgresql://${POSTGRES_USER}:${POSTGRES_PASSWORD}@db:5432/${POSTGRES_DB}

JWT_SECRET=generate_a_long_random_string
OAUTH_42_CLIENT_ID=
OAUTH_42_CLIENT_SECRET=
OAUTH_42_REDIRECT_URI=https://localhost/auth/callback

# Optional module keys
VAULT_ADDR=http://vault:8200
VAULT_TOKEN=
PROMETHEUS_URL=http://prometheus:9090
```

```gitignore
.env
node_modules/
__pycache__/
*.sqlite
data/
dist/
```

Never commit API keys, DB passwords, or JWT secrets.

---

## Approved frameworks (subject definition)

The PDF defines a **framework** as a tool with structured architecture, built-in routing/state conventions, and an ecosystem — not a utility library (jQuery, Lodash, Axios alone do not count).

### Frontend

| Framework | Notes |
|-----------|-------|
| React | Counts as framework per subject (ecosystem + patterns) |
| Vue | SPA; pair with Vite or Nuxt |
| Angular | Full opinionated SPA |
| Svelte | Compile-time reactivity |
| Next.js | Full-stack if you use **both** frontend and backend capabilities |
| Nuxt.js | Vue full-stack (frontend + server) |
| SvelteKit | Svelte full-stack |

### Backend

| Framework | Language |
|-----------|----------|
| Express | Node.js |
| Fastify | Node.js — lightweight, schema validation |
| NestJS | TypeScript — modules, decorators |
| Django | Python — batteries included |
| Flask | Python — minimal, explicit |
| Ruby on Rails | Ruby — convention over configuration |

**Module mapping:** Major “Use a framework for both frontend and backend” needs both sides. Full-stack frameworks (Next.js, Nuxt, SvelteKit) count as **both** when you use their frontend and backend features. Minor frontend-only or backend-only modules split the requirement.

### Styling (mandatory baseline, not a module)

Tailwind CSS, Bootstrap, Material-UI, Styled Components, or any CSS framework/solution of your choice.

---

## Database

| DB | Typical use |
|----|-------------|
| PostgreSQL | Production-like relational data |
| SQLite | Lightweight; fine for smaller stacks |

- Clear schema with well-defined relations (mandatory).
- Migrations — Django migrations, Prisma, Alembic, Flyway, etc.
- **ORM** is a minor module — raw SQL everywhere is fine for baseline only.

---

## Real-time (WebSockets module)

| Library | Protocol |
|---------|----------|
| Native WebSocket | Browser API + server `ws` / framework equivalent |
| Socket.IO | Fallback transports; rooms built-in |

Server (Node example):

```javascript
import { WebSocketServer } from 'ws';

const wss = new WebSocketServer({ server });
wss.on('connection', (ws) => {
  ws.on('message', (data) => { /* route, broadcast, persist */ });
  ws.on('close', () => { /* cleanup room membership */ });
});
```

Handle connect/disconnect gracefully; broadcast efficiently for chat, live updates, and multiplayer sync.

---

## Authentication snippets (concepts)

Baseline requires email/password with **hashed, salted** passwords. OAuth, 2FA, JWT are module choices.

### Password hash (concept)

```python
# Django — do not roll your own crypto
from django.contrib.auth.hashers import make_password, check_password
hashed = make_password("user_password")
check_password("user_password", hashed)
```

### JWT (concept — 2FA/JWT or API modules)

```
Authorization: Bearer <header.payload.signature>
```

Verify signature and expiry on protected routes; store secrets in `.env` / Vault.

### OAuth 2.0 flow (concept — remote auth module)

```
1. Redirect user to provider /authorize
2. Provider redirects back with ?code=
3. Exchange code for access token (server-side only)
4. Fetch user profile → create or link local account
```

### 42 API (remote auth)

| Step | Endpoint |
|------|----------|
| Authorize | `https://api.intra.42.fr/oauth/authorize` |
| Token | `https://api.intra.42.fr/oauth/token` |
| User | `https://api.intra.42.fr/v2/me` |

Register redirect URI with your app URL.

---

## 2D game loop (generic — Canvas or similar)

Mandatory baseline does **not** require Pong; gaming modules need at least one complete web game. Pattern applies to Pong, breakout, snake, etc.

```javascript
const canvas = document.getElementById('game');
const ctx = canvas.getContext('2d');

const state = {
  entities: [],
  input: { up: false, down: false },
  lastTime: 0,
};

function update(dt) {
  // rules, collisions, score, win/loss
  for (const e of state.entities) e.tick(dt, state);
}

function render() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  for (const e of state.entities) e.draw(ctx);
}

function loop(timestamp) {
  const dt = (timestamp - state.lastTime) / 1000;
  state.lastTime = timestamp;
  update(dt);
  render();
  requestAnimationFrame(loop);
}

window.addEventListener('keydown', (e) => { /* map keys to state.input */ });
requestAnimationFrame(loop);
```

For remote/multiplayer modules: run authoritative or synchronized logic server-side; reconcile latency and disconnects on the client.

---

## 3D graphics module (Three.js / Babylon.js)

```javascript
import * as THREE from 'three';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, width / height, 0.1, 1000);
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(width, height);

const mesh = new THREE.Mesh(
  new THREE.BoxGeometry(),
  new THREE.MeshStandardMaterial({ color: 0x4488ff })
);
scene.add(mesh);

function animate() {
  requestAnimationFrame(animate);
  mesh.rotation.y += 0.01;
  renderer.render(scene, camera);
}
animate();
```

**Babylon.js** alternative: `BABYLON.Engine`, `BABYLON.Scene`, `ArcRotateCamera`, `MeshBuilder`. Target smooth interaction and stable frame rate.

---

## DevOps modules

### ELK (log management — major)

| Component | Role |
|-----------|------|
| Elasticsearch | Store and index logs |
| Logstash | Collect, parse, transform |
| Kibana | Dashboards and search |

Ship structured logs from each container; define retention/archiving; restrict Kibana/ES access.

### Prometheus + Grafana (monitoring — major)

| Tool | Role |
|------|------|
| Prometheus | Scrape metrics (`/metrics` exporters) |
| Grafana | Dashboards, alerting rules |

Instrument services (HTTP latency, error rates, queue depth); secure Grafana admin.

### Microservices (major)

Loosely coupled services, single responsibility, REST or message queues between them. Compose file should start every service with the one-command rule.

---

## Blockchain module (Avalanche + Solidity)

- Deploy smart contracts on an **Avalanche test network**.
- Record tournament (or game) scores on-chain with integrity/immutability.
- Typical stack: Hardhat or Foundry, Solidity contracts, Web3/ethers client from backend.
- **Note:** ICP backend minor module is **incompatible with SSR**.

---

## Internationalization (i18n — minor module)

| Approach | Tools |
|----------|-------|
| React | `react-i18next`, `next-intl` (Next.js) |
| Vue | `vue-i18n` |
| Angular | `@angular/localize` |
| Backend strings | JSON/YAML locale files per language |

Requirements: **≥ 3 complete languages**, language switcher, all user-facing text translatable. Optional RTL minor: layout mirroring, not only `dir="rtl"`.

---

## Accessibility (WCAG 2.1 AA — major)

| Tool | Purpose |
|------|---------|
| **Chrome DevTools** | Primary debugger — Lighthouse, Accessibility tree, Performance |
| axe DevTools extension | Automated a11y rule checks |
| Lighthouse (Chrome) | a11y / performance / SEO audits |
| Screen reader | NVDA (Windows), VoiceOver (macOS) — manual verification |

Checklist: semantic HTML, labels, focus order, keyboard navigation, color contrast, ARIA only when needed, no console errors/warnings in Chrome.

### Additional browsers (minor module)

Subject requires **latest stable Chrome** for baseline. The **additional browsers** module needs **≥ 2 more** (Firefox, Safari, Edge, etc.) with documented testing and consistent UX. Use Firefox DevTools when fixing Firefox-specific issues.

---

## SPA routing

```javascript
// History API — back/forward without full reload
history.pushState({ view: 'dashboard' }, '', '/dashboard');
window.addEventListener('popstate', (e) => {
  renderView(e.state?.view ?? routeFromPath(location.pathname));
});
```

---

## Testing & debugging

| Tool | Purpose |
|------|---------|
| Chrome DevTools | Network, console, responsive, Lighthouse (primary) |
| `docker compose logs -f <service>` | Container debugging |
| Postman / curl / httpie | REST and public API module |
| Playwright / Cypress | Cross-browser regression (optional) |

---

## README.md required sections (v19.0)

Your project README at the **repository root** is evaluated. Include at least:

| Section | Content |
|---------|---------|
| First line | *This project has been created as part of the 42 curriculum by \<login1\>[, \<login2\>…]* |
| Description | Project name, goal, overview, key features |
| Instructions | Prerequisites, `.env` setup, single-command run steps |
| Resources | Docs, tutorials, articles + **how AI was used** (tasks and parts) |
| Team Information | Each member: role(s) (PO, PM, Tech Lead, Developer) and responsibilities |
| Project Management | Task distribution, meetings, tools (Issues, Trello), comms (Discord, Slack) |
| Technical Stack | Frontend, backend, database, libraries; justify major choices |
| Database Schema | Tables/collections, relationships, key fields |
| Features List | Every feature, owner(s), short description |
| Modules | All chosen majors/minors, point math (2/1), justification, implementation notes, owners |
| Individual Contributions | Per-person work, challenges overcome |

Optional but useful: usage examples, known limitations, license, credits.

---

## Quick module → tooling map

| Module area | Typical tooling |
|-------------|-----------------|
| Web frameworks | React, Vue, Angular, Svelte, Next/Nuxt/SvelteKit, Django, Flask, Express, Fastify, NestJS, Rails |
| Real-time | WebSocket, Socket.IO, SSE |
| Public API | OpenAPI/Swagger, rate limiting middleware |
| ORM | Prisma, Django ORM, TypeORM, SQLAlchemy |
| WAF + Vault | ModSecurity, HashiCorp Vault |
| 3D | Three.js, Babylon.js |
| Logs | ELK stack |
| Metrics | Prometheus, Grafana |
| Blockchain | Avalanche, Solidity, Hardhat/Foundry |
| i18n | react-i18next, vue-i18n, locale JSON |
| a11y | axe, Lighthouse, semantic HTML, keyboard QA |

---

## Git hygiene

- Meaningful commits from **all** team members.
- `.env` gitignored; `.env.example` committed.
- No secrets in history — rotate if leaked.
