# Inception — Study plan (start to finish)

Assumes [vm-setup.md](./vm-setup.md) is complete: VM running, Docker installed, `/etc/hosts` configured, data dirs created.

---

## Phase 0 — Concepts (2–3 days, parallel with VM setup)

| Topic | Resource |
|-------|----------|
| Containers vs VMs | [theory-and-concepts.md](./theory-and-concepts.md) |
| Dockerfile layers | Official Docker docs — `FROM`, `RUN`, `COPY`, `CMD` |
| Docker Compose | Services, networks, volumes, `depends_on` |
| NGINX reverse proxy + FastCGI | How `.php` goes to php-fpm:9000 |
| MariaDB basics | SQL users, grants, `bind-address` |
| WordPress install | WP-CLI or manual; `wp-config.php` env vars |

**Checkpoint:** Draw the three-container diagram from memory.

---

## Phase 1 — Project skeleton (½ day)

| Step | Task |
|------|------|
| 1 | Create repo root `Makefile` with targets: `all`, `build`, `up`, `down`, `logs`, `clean`, `fclean`, `re` |
| 2 | Create `srcs/docker-compose.yml` (empty services scaffold) |
| 3 | Create `srcs/.env` from subject template — **no secrets in git** |
| 4 | Add `.gitignore`: `.env`, data dirs, secrets |
| 5 | `mkdir -p srcs/requirements/{mariadb,nginx,wordpress}` |

**Checkpoint:** `make` runs `docker compose` from correct directory without errors (even if images empty).

---

## Phase 2 — MariaDB container first (2–4 days)

Build and test **in isolation** before WordPress or NGINX.

| Step | Task |
|------|------|
| 1 | `Dockerfile` from `debian:bookworm` or `alpine:3.x` — install `mariadb-server` |
| 2 | Config: `bind-address = 0.0.0.0`, port `3306` |
| 3 | Entry script: init DB, user, grants from **env vars** (not hardcoded) |
| 4 | Volume: `/var/lib/mysql` → `/home/<login>/data/mariadb` |
| 5 | `EXPOSE 3306` — **do not** publish to host in compose (internal only) |
| 6 | PID 1: `exec mysqld` or wrapper ending in `exec` — no `tail -f` |

**Test:**

```bash
docker compose build mariadb
docker compose up mariadb
docker compose exec mariadb mariadb -u<user> -p<pass> -e "SHOW DATABASES;"
```

**Weak hardware note:** First MariaDB image build = full `apt update` — go make coffee.

---

## Phase 3 — WordPress + PHP-FPM (3–5 days)

| Step | Task |
|------|------|
| 1 | Dockerfile: `php-fpm`, WordPress files, `curl`, `wp-cli` optional |
| 2 | `www.conf`: `listen = 9000` (TCP, not socket — cross-container) |
| 3 | `clear_env = no` so WordPress sees DB env vars |
| 4 | Setup script: download WP, `wp core install`, create **2 users** (no `admin` in name) |
| 5 | Volume: shared web root `/var/www/html` → `/home/<login>/data/wordpress` |
| 6 | `depends_on: mariadb` in compose |
| 7 | DB host = service name `mariadb` |

**Test:**

```bash
docker compose up mariadb wordpress
docker compose exec wordpress php -v
# Check DB connection from wordpress container
```

---

## Phase 4 — NGINX + TLS (3–5 days)

| Step | Task |
|------|------|
| 1 | Dockerfile: install `nginx`, `openssl` |
| 2 | Startup script: generate self-signed cert for `<login>.42.fr` |
| 3 | `ssl_protocols TLSv1.2 TLSv1.3;` only |
| 4 | Listen **443 only** — no port 80 |
| 5 | `root` = WordPress volume path; `try_files` for static |
| 6 | `location ~ \.php$` → `fastcgi_pass wordpress:9000` |
| 7 | Publish **only** nginx: `443:443` in compose |
| 8 | Mount same wordpress volume (read) for static files |

**Test:**

```bash
docker compose up -d
curl -k https://<login>.42.fr
# Browser: accept self-signed warning
```

---

## Phase 5 — Integration & compose polish (2–3 days)

| Step | Task |
|------|------|
| 1 | Single bridge network `inception` (or subject name) |
| 2 | `restart: always` on all services |
| 3 | `container_name` matches image/service naming rules |
| 4 | `env_file: .env` on each service |
| 5 | `make` builds and starts full stack |
| 6 | Idempotent entry scripts (safe on container restart) |

**Checkpoint:** `make re` from clean state produces working site in one command.

---

## Phase 6 — Security & subject compliance (1–2 days)

| Check | Detail |
|-------|--------|
| No passwords in Dockerfiles | Grep Dockerfiles for literals |
| No `latest` tag | Pin `debian:bookworm`, etc. |
| No `network_mode: host` | Grep compose file |
| No `links:` | Grep compose file |
| No forbidden keep-alive CMD | Grep for `sleep infinity`, `tail -f` |
| TLS only v1.2/v1.3 | `nginx -T` or config review |
| Two WP users | Admin name without `admin` substring |
| Volumes on host | `/home/<login>/data/...` |

---

## Phase 7 — Evaluation rehearsal (1–2 days)

Practice exactly as evaluator will:

1. Clone repo on VM (or fresh directory).
2. `make` — wait for full build (time this on campus hardware).
3. Open `https://<login>.42.fr` — login to WordPress admin.
4. Show containers: `docker compose ps`.
5. Show volumes: `docker volume ls` + host paths.
6. `docker compose stop` / restart — data persists.
7. Explain request flow: browser → NGINX → php-fpm → MariaDB.

### Questions to rehearse

- Difference between image and container?
- What is a volume and why do you need two?
- Why is NGINX the only exposed port?
- How do containers resolve `mariadb` hostname?
- What runs as PID 1 in each container?

---

## Phase 8 — Bonus (optional, after mandatory passes)

| Bonus | Complexity |
|-------|------------|
| Redis cache | Medium — extra container + WP plugin/config |
| Adminer | Low — DB UI container on internal network |
| FTP | Medium — file access to wordpress volume |
| Static site | Low — second NGINX server block or container |

---

## Suggested timeline

| Week | Focus |
|------|--------|
| 1 | VM + Docker + Phase 1–2 (MariaDB) |
| 2 | WordPress container |
| 3 | NGINX + TLS + integration |
| 4 | Compliance, `make re` testing, eval prep |

On weak hardware, add **several extra days** for build/wait time — normal, not a sign you are stuck.

---

## Daily workflow on slow machines

```bash
# Morning: pull latest, start DB only
docker compose up -d mariadb

# Work on one Dockerfile
docker compose build wordpress
docker compose up wordpress

# End of day: stop to free RAM
docker compose down

# Before eval: full integration test
make fclean && make && make logs
```

---

## When you are stuck

| Problem | Direction |
|---------|-----------|
| 502 Bad Gateway | NGINX → php-fpm: check `fastcgi_pass`, port 9000, container on same network |
| DB connection error | `DB_HOST=mariadb`, credentials match init script, mariadb healthy |
| White screen | PHP errors: `docker compose logs wordpress` |
| TLS error in browser | Expected with self-signed — use `-k` in curl or accept warning |
| Permission denied on volume | UID mapping — align `www-data` / `mysql` user IDs in Dockerfiles |
| Build runs forever | Check DNS/network on VM; retry `apt` mirrors |

See [syntax-libraries-tools.md](./syntax-libraries-tools.md) for debug commands.
