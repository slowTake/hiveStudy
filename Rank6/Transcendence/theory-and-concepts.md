# Transcendence — Theory and concepts

Concepts grouped by mandatory baseline and common module themes. Module names vary by subject version — verify on your PDF.

---

## Single-page application (SPA)

A SPA loads one HTML shell; navigation swaps **views** without full server round-trips.

| Concept | Detail |
|---------|--------|
| Client-side routing | `/play`, `/tournament`, `/profile` map to components |
| History API | `pushState` / `popState` so browser back/forward work |
| API calls | `fetch` or axios to JSON REST backend |
| State | In-memory, context, or store (Redux, Pinia, etc.) |

**Eval trap:** Changing “pages” by reloading `index.html` is not a SPA.

---

## Docker deployment

Reuse Inception patterns at larger scale.

| Piece | Role |
|-------|------|
| `docker-compose.yml` | Services: frontend build, API, DB, reverse proxy |
| Volumes | Persist DB data across restarts |
| Networks | Internal service DNS (`api`, `db`) |
| Root `Makefile` | `all` → build + up in one command |

Secrets go in `.env` — never commit credentials.

---

## Pong implementation options

| Approach | Pros | Cons |
|----------|------|------|
| Canvas 2D | Simple, fast | Manual collision math |
| DOM + CSS | Easy layout | Harder smooth animation |
| Three.js (3D module) | Meets graphics module | Steeper learning curve |
| Server-side game + API | Authoritative state, anti-cheat | More backend work |

For **remote players**, game state must sync over the network (usually WebSockets).

---

## Real-time communication

| Use case | Typical tech |
|----------|--------------|
| Remote Pong | WebSocket or Socket.IO |
| Live chat module | WebSocket rooms |
| Notifications | SSE or WebSocket |

| Term | Meaning |
|------|---------|
| WSS | WebSocket over TLS — required when site is HTTPS |
| Room/channel | Group clients for broadcast (like IRC channels) |

IRC experience maps well: event loop, broadcast to peers, handle disconnect.

---

## Authentication & security

### Password storage

Never store plaintext passwords. Use **bcrypt**, **argon2**, or framework defaults (Django `make_password`, etc.).

### JWT (common module)

| Piece | Role |
|-------|------|
| Access token | Short-lived, sent in `Authorization: Bearer` |
| Refresh token | Optional; longer-lived |
| Payload | User id, roles — **signed**, not encrypted |

Validate signature on every protected route.

### 2FA (common module)

Typical flow: password OK → send one-time code (email/TOTP) → issue session/JWT.

### Remote auth / OAuth

Redirect to provider (42 API, Google) → callback with code → exchange for token → create/link local user.

### SQL injection

Use parameterized queries / ORM — never concatenate user input into SQL.

---

## Tournament system (mandatory)

Minimum conceptual flow:

```
Create tournament → Players register aliases → Bracket / queue
    → Match 1 vs 1 → Record winner → Next round → Champion
```

| Component | Responsibility |
|-----------|----------------|
| Registration | Unique aliases per tournament |
| Matchmaking | Pair waiting players or advance bracket |
| Results | Persist scores for history/stats modules |

---

## Module categories (reference)

Subject versions list ~16 major and ~11 minor modules. Categories often include:

| Category | Example modules |
|----------|-----------------|
| Web | Backend framework, frontend toolkit, database |
| User management | Accounts, profiles, friends, remote auth |
| Gameplay | Remote players, multiplayer (>2), another game, live chat |
| AI | AI opponent |
| Cybersecurity | 2FA + JWT, WAF/Vault, GDPR |
| DevOps | Microservices, log stack, monitoring, blockchain results |
| Graphics | Advanced 3D (Three.js/WebGL) |
| Accessibility | Responsive, extra browsers, i18n, a11y |
| Server-side | Server-authoritative Pong API |

**Dependencies:** Backend framework + database often prerequisite for user management and stats.

---

## Team workflow

| Practice | Why |
|----------|-----|
| Module owner | One DRI per module for eval questions |
| API contract early | Frontend/backend parallel work |
| Feature flags | Merge incomplete modules without breaking mandatory |
| Shared Docker | Same compose for all dev machines |

---

## Relation to prior projects

| Prior project | Transcendence parallel |
|---------------|------------------------|
| Inception | Docker, compose, volumes, reverse proxy |
| IRC | TCP, broadcast, client lifecycle, non-blocking I/O |
| CPP modules | OOP design — less central here |
| Exam Rank 06 | C sockets + `select()` — do before or during Transcendence |
