# Transcendence — Syntax, libraries, and tools

Quick reference for common stack choices. Your subject may **require** specific technologies for certain modules (e.g. Django for backend framework) — check the PDF.

---

## Docker & orchestration

| Tool | Use |
|------|-----|
| Docker Compose | Multi-container dev and eval |
| `Makefile` | `all`, `build`, `up`, `down`, `clean`, `re` |
| nginx / Traefik | TLS termination, reverse proxy |
| `.env` | Secrets and config (gitignored) |

```makefile
# Typical pattern
all:
	docker compose -f srcs/docker-compose.yml up --build -d
```

---

## Backend frameworks (examples)

| Framework | Language | Notes |
|-----------|----------|-------|
| Django | Python | Batteries included; ORM, auth, admin |
| Fastify / Express | Node.js | Lightweight; large ecosystem |
| NestJS | TypeScript | Structured modules, decorators |
| Spring Boot | Java | Enterprise patterns |

---

## Frontend (examples)

| Tool | Type |
|------|------|
| React + Vite | SPA library + build tool |
| Vue / Nuxt | SPA / SSR option |
| Bootstrap / Tailwind | CSS toolkit (minor module) |
| TypeScript | Typed JS — common in teams |

### SPA routing

```javascript
// History API — back/forward without reload
history.pushState({ page: 'play' }, '', '/play');
window.addEventListener('popstate', (e) => { /* restore view */ });
```

---

## Database

| DB | Typical module |
|----|----------------|
| PostgreSQL | Most common for production-like setups |
| SQLite | Lightweight; fine for smaller stacks |

Use migrations (Django migrations, Prisma, Flyway, etc.) — not raw manual schema each deploy.

---

## Real-time

| Library | Protocol |
|---------|----------|
| Native WebSocket | Browser API + server ws library |
| Socket.IO | Fallback transports; rooms built-in |

Server (Node example):

```javascript
const wss = new WebSocketServer({ server });
wss.on('connection', (ws) => { /* join room, relay state */ });
```

---

## Authentication snippets (concepts)

### Password hash (concept)

```python
# Django — do not roll your own crypto
from django.contrib.auth.hashers import make_password, check_password
hashed = make_password("user_password")
```

### JWT (concept)

```
Authorization: Bearer <header.payload.signature>
```

Verify signature and expiry on protected routes.

### OAuth flow (concept)

```
1. Redirect user to provider /authorize
2. Provider redirects back with ?code=
3. Exchange code for access token (server-side)
4. Fetch user profile → create or link local account
```

---

## Pong / Canvas (minimal pattern)

```javascript
const canvas = document.getElementById('pong');
const ctx = canvas.getContext('2d');
let ball = { x: 200, y: 200, vx: 4, vy: 3 };

function tick() {
  ball.x += ball.vx;
  ball.y += ball.vy;
  // walls, paddles, collision...
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.fillRect(ball.x, ball.y, 8, 8);
  requestAnimationFrame(tick);
}
requestAnimationFrame(tick);
```

---

## 3D module (Three.js)

```javascript
import * as THREE from 'three';
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, w / h, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();
// mesh + animation loop for 3D Pong
```

---

## Testing & quality

| Tool | Purpose |
|------|---------|
| Firefox DevTools | Network, console, responsive mode |
| `docker compose logs -f` | Debug services |
| Postman / curl | REST API testing |
| Lighthouse | a11y / performance hints |

---

## 42 API (remote auth module)

Typical endpoints (confirm current docs):

| Step | Endpoint |
|------|----------|
| Authorize | `https://api.intra.42.fr/oauth/authorize` |
| Token | `https://api.intra.42.fr/oauth/token` |
| User | `https://api.intra.42.fr/v2/me` |

Register redirect URI with your app URL.

---

## Git hygiene

```gitignore
.env
node_modules/
__pycache__/
*.sqlite
data/
dist/
```

Never commit API keys, DB passwords, or JWT secrets.
