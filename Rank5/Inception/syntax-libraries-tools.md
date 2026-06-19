# Inception — Syntax, libraries, and tools

Quick reference for Dockerfiles, Compose, Makefile, and debugging. Project runs on the **VM**, not your host OS (except SSH and browser).

---

## Makefile (root)

```makefile
NAME := inception

SRC := srcs
COMPOSE := docker compose -f $(SRC)/docker-compose.yml

all: build up

build:
	$(COMPOSE) build

up:
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

logs:
	$(COMPOSE) logs -f

clean:
	$(COMPOSE) down --rmi local

fclean: down
	docker system prune -af --volumes
	rm -rf /home/$(USER)/data/wordpress/* /home/$(USER)/data/mariadb/*

re: fclean all

.PHONY: all build up down logs clean fclean re
```

Adjust `fclean` to match your data paths and subject rules (some evaluators forbid aggressive prune).

---

## docker-compose.yml skeleton

```yaml
services:
  mariadb:
    build: ./requirements/mariadb
    image: mariadb
    container_name: mariadb
    env_file: .env
    volumes:
      - /home/${USER}/data/mariadb:/var/lib/mysql
    networks:
      - inception
    restart: always

  wordpress:
    build: ./requirements/wordpress
    image: wordpress
    container_name: wordpress
    env_file: .env
    volumes:
      - /home/${USER}/data/wordpress:/var/www/html
    networks:
      - inception
    depends_on:
      - mariadb
    restart: always

  nginx:
    build: ./requirements/nginx
    image: nginx
    container_name: nginx
    env_file: .env
    ports:
      - "443:443"
    volumes:
      - /home/${USER}/data/wordpress:/var/www/html:ro
    networks:
      - inception
    depends_on:
      - wordpress
    restart: always

networks:
  inception:
    driver: bridge
```

**Notes:**

- Use `${USER}` or hardcode login — be consistent with subject.
- Only `nginx` has `ports:`.
- No `version:` key needed with Compose v2 plugin.

---

## Dockerfile patterns

### Debian base (example)

```dockerfile
FROM debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

COPY conf/ /etc/nginx/
COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]
```

### Alpine base (lighter, smaller images)

```dockerfile
FROM alpine:3.19

RUN apk add --no-cache mariadb mariadb-client

COPY conf/ /etc/my.cnf.d/
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
```

**Weak hardware:** Alpine `apk` is often faster than Debian `apt`, but package names differ — pick one family for all three services.

### Layer caching tip

Put rarely-changing steps first:

```dockerfile
RUN apt-get update && apt-get install -y huge-package-list
COPY tools/entrypoint.sh /entrypoint.sh   # changes often — keep COPY late
```

---

## NGINX — TLS + FastCGI snippet

```nginx
server {
    listen 443 ssl;
    server_name login.42.fr;

    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_certificate     /etc/nginx/ssl/server.crt;
    ssl_certificate_key /etc/nginx/ssl/server.key;

    root /var/www/html;
    index index.php;

    location / {
        try_files $uri $uri/ /index.php?$args;
    }

    location ~ \.php$ {
        include fastcgi_params;
        fastcgi_pass wordpress:9000;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    }
}
```

---

## PHP-FPM pool snippet (`www.conf`)

```ini
[www]
listen = 9000
clear_env = no
pm = dynamic
pm.max_children = 5
```

---

## MariaDB config snippet

```ini
[mysqld]
bind-address = 0.0.0.0
port = 3306
```

---

## OpenSSL self-signed cert (entry script)

```bash
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/nginx/ssl/server.key \
  -out /etc/nginx/ssl/server.crt \
  -subj "/CN=${DOMAIN_NAME}"
```

---

## WP-CLI install (wordpress entry script idea)

```bash
wp core download --allow-root
wp config create --dbname="$MYSQL_DATABASE" \
  --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" \
  --dbhost="$WORDPRESS_DB_HOST" --allow-root
wp core install --url="https://${DOMAIN_NAME}" \
  --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" \
  --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" \
  --skip-email --allow-root
wp user create "$WP_USER" "$WP_USER_EMAIL" --role=author \
  --user_pass="$WP_USER_PASSWORD" --allow-root
```

Guard with flag file so reinstall does not run every restart:

```bash
if [ ! -f /var/www/html/.wp_installed ]; then
  # ... install ...
  touch /var/www/html/.wp_installed
fi
exec php-fpm -F
```

---

## Essential commands

### Compose workflow

```bash
cd ~/inception
make build          # or: docker compose -f srcs/docker-compose.yml build
make up
make logs
make down
```

### Inspect running stack

```bash
docker compose ps
docker compose logs nginx
docker compose logs wordpress --tail 50
docker compose exec mariadb mariadb -u root -p
```

### Debug network

```bash
docker network ls
docker network inspect srcs_inception
docker compose exec nginx ping -c 2 wordpress
docker compose exec wordpress nc -zv mariadb 3306
```

### Debug TLS / HTTP

```bash
curl -vk https://login.42.fr
curl -vk https://127.0.0.1 -H "Host: login.42.fr"
```

### Disk and cleanup (careful)

```bash
docker system df
docker compose down
docker image ls
docker volume ls
# fclean only when you intend to wipe data
```

### Build single service (save time on weak HW)

```bash
docker compose build mariadb
docker compose build wordpress
docker compose build nginx
```

---

## `.env` and secrets

```bash
cp srcs/.env.example srcs/.env
chmod 600 srcs/.env
```

Never commit `.env`. Some campuses allow `secrets/` with Docker secrets — check subject.

---

## `.dockerignore`

```
.git
*.md
.env
```

Reduces build context size — faster uploads to daemon on slow disks.

---

## Hosts file

**Host** (with port forward):

```text
127.0.0.1   login.42.fr
```

**VM** (testing inside VM):

```text
127.0.0.1   login.42.fr
```

---

## VirtualBox port forwards

| Service | Host | Guest |
|---------|------|-------|
| SSH | 2222 | 22 |
| HTTPS | 443 | 443 |

---

## Evaluation-day kit

```bash
# On VM
docker compose ps
docker volume ls
ls -la /home/$USER/data/
curl -kI https://login.42.fr
```

Have subject PDF open; know where each env var is used.

---

## Pre-submission checklist

- [ ] VM is where evaluator runs `make`
- [ ] `srcs/.env` present (or documented how to create from example)
- [ ] `/home/<login>/data/wordpress` and `.../mariadb` exist
- [ ] `https://<login>.42.fr` loads WordPress
- [ ] Two WP users; admin name has no `admin`
- [ ] Only port 443 exposed
- [ ] TLS 1.2/1.3 only
- [ ] No forbidden compose network modes
- [ ] No passwords in Dockerfiles
- [ ] Containers restart after `docker compose restart`
- [ ] `make` / `make re` work from repo root

---

## References

- [vm-setup.md](./vm-setup.md) — full VM + Docker install
- [Docker Engine install (Debian)](https://docs.docker.com/engine/install/debian/)
- [Compose file reference](https://docs.docker.com/compose/compose-file/)
- [Dockerfile reference](https://docs.docker.com/reference/dockerfile/)
