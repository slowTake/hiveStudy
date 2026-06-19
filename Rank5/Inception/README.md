# Inception

System administration project: build a **containerized WordPress stack** inside a **virtual machine** using custom Docker images and Docker Compose.

## Project theme

Three mandatory services — **NGINX**, **WordPress + PHP-FPM**, **MariaDB** — each in its own container, built from **Alpine or Debian** base images only (no pre-built NGINX/WordPress/MariaDB images). NGINX is the sole public entry on **port 443** with **TLSv1.2/TLSv1.3**.

## Study files

| File | Contents |
|------|----------|
| [vm-setup.md](./vm-setup.md) | VirtualBox VM, SSH, Docker install, hosts/DNS, **weak-hardware tips** |
| [study-plan.md](./study-plan.md) | Start-to-finish phases from zero to evaluation |
| [theory-and-concepts.md](./theory-and-concepts.md) | Docker, networking, volumes, each service |
| [syntax-libraries-tools.md](./syntax-libraries-tools.md) | Dockerfile, Compose, Makefile, commands |

## Mandatory stack

```text
[Browser] --HTTPS:443--> [NGINX] --FastCGI:9000--> [WordPress/php-fpm] --TCP:3306--> [MariaDB]
```

## Global constraints (verify in subject PDF)

| Rule | Detail |
|------|--------|
| VM required | Entire project runs inside a VM |
| `srcs/` | All config under `srcs/` |
| Root `Makefile` | Builds/runs via `docker compose` |
| Base images | **Alpine** or **Debian** (penultimate stable) only |
| No pre-built service images | Build NGINX, WP, MariaDB yourself |
| Network | User-defined bridge — **no** `network_mode: host`, `--link`, or `links:` |
| Secrets | No passwords in Dockerfiles — use `.env` / env vars |
| Volumes | DB volume + WordPress files at `/home/<login>/data` on host |
| Domain | `login.42.fr` → local IP via `/etc/hosts` |
| Restart | Containers restart on crash |
| PID 1 | No infinite loops (`tail -f`, `sleep infinity`, `while true`) as main process |
| WordPress users | Two users; admin username must **not** contain `admin` |

## Typical bonuses

Redis cache, FTP, Adminer, static site — only after mandatory part is solid.

## Time expectations (weak hardware)

On underpowered campus machines, first full `docker compose build` can take **20–60+ minutes**. Plan builds overnight or between sessions; use layer caching and build one service at a time while developing.
