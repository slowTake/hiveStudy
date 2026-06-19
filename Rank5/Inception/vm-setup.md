# Inception — VM setup guide

Complete guide to preparing the **host machine**, **virtual machine**, and **Docker environment** before writing any project code. Read this first if you are starting from zero.

---

## Overview: three layers

```text
┌─────────────────────────────────────────────────────────┐
│  Host PC (your laptop or 42 workstation)                │
│  /etc/hosts → login.42.fr → 127.0.0.1                   │
│  VirtualBox port forward: host:443 → VM:443             │
│  ┌───────────────────────────────────────────────────┐  │
│  │  Debian VM (2 GB RAM, 20 GB disk)                 │  │
│  │  Docker Engine + Compose                          │  │
│  │  /home/login/data/{wordpress,mysql}               │  │
│  │  ┌─────────┐ ┌───────────┐ ┌─────────┐           │  │
│  │  │ NGINX   │ │ WordPress │ │ MariaDB │           │  │
│  │  └─────────┘ └───────────┘ └─────────┘           │  │
│  └───────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────┘
```

---

## Before you install anything

### Checklist

- [ ] Know your 42 **login** (used in `login.42.fr` and `/home/login/data`)
- [ ] Download **Debian netinst** (64-bit) — penultimate stable if subject requires it
- [ ] Install **VirtualBox** on host (or use campus-provided hypervisor)
- [ ] Confirm **virtualization** enabled in BIOS/UEFI
- [ ] Pick VM disk location with enough space (**20 GB+**; on 42 use `/sgoinfre/<login>/` if home is small)

### Weak hardware at The Hive — plan ahead

Campus workstations often have limited RAM and slow disks. These choices reduce pain:

| Tip | Why |
|-----|-----|
| **CLI-only Debian** (no desktop) | Saves 500 MB–1 GB RAM; faster installs |
| **2 GB RAM, 1 CPU** for VM | Enough for three containers; more RAM helps MariaDB |
| **20 GB dynamic disk** on fast storage (`/sgoinfre`) | Avoid filling small `$HOME` |
| **SSH from host** | Edit with VS Code Remote-SSH instead of VM GUI |
| **Build one image at a time** | `docker compose build mariadb` instead of full stack while iterating |
| **Don't `make re` constantly** | Rebuilds re-run every `apt install` layer — slow on weak disks |
| **Test MariaDB first** | Smallest feedback loop before WordPress + NGINX |
| **Run builds when machine is idle** | First `apt update` inside Dockerfiles is I/O heavy |
| **Increase VirtualBox video memory only if using GUI** | Irrelevant for headless setup |

If builds consistently timeout or freeze, close browsers, stop other VMs, and ensure no other Docker projects are running.

---

## Step 1 — Create the virtual machine (VirtualBox)

### Download Debian

- [Debian netinst ISO](https://www.debian.org/distrib/) — **amd64 netinst**
- Use **penultimate stable** if your subject specifies (e.g. Bookworm if Trixie is current)

### New VM settings

| Setting | Recommended |
|---------|-------------|
| Name | `inception-<login>` |
| Type / Version | Linux / Debian (64-bit) |
| Memory | **2048 MB** (3072 MB if host has 16 GB+) |
| CPUs | **1** (2 if host has 8+ cores) |
| Disk | **20 GB** VDI, dynamically allocated |
| Disk location | `/sgoinfre/<login>/VMs/` on 42 when possible |

### Network (initial)

- Adapter 1: **NAT** (default)
- Port forwarding added later (SSH + HTTPS)

### Install Debian

1. Boot from ISO.
2. **Guided — use entire disk**, single partition (fine for this project).
3. **Software selection:**
   - Uncheck **desktop environment** and **GNOME** (headless setup).
   - Check **SSH server** and **standard system utilities**.
4. Install GRUB to the virtual disk.
5. Reboot, eject ISO.

### First login inside VM

```bash
# Update system (can take several minutes on slow disks)
sudo apt update && sudo apt upgrade -y

# Tools you will need
sudo apt install -y curl git make sudo vim ca-certificates gnupg
```

---

## Step 2 — SSH access (work from host)

Editing inside the VirtualBox console is awkward. Use SSH.

### Confirm SSH in VM

```bash
sudo systemctl enable ssh
sudo systemctl start ssh
grep ^Port /etc/ssh/sshd_config   # default 22
```

### Port forwarding (VirtualBox)

1. Shut down VM.
2. **Settings → Network → Adapter 1 → Advanced → Port Forwarding**
3. Add rules:

| Name | Protocol | Host IP | Host Port | Guest Port |
|------|----------|---------|-----------|------------|
| `ssh` | TCP | 127.0.0.1 | `2222` | `22` |
| `https` | TCP | 127.0.0.1 | `443` | `443` |

4. Start VM.

### Connect from host

```bash
ssh <login>@127.0.0.1 -p 2222
```

### Optional: `~/.ssh/config` on host

```sshconfig
Host inception
    HostName 127.0.0.1
    User <login>
    Port 2222
```

Then: `ssh inception`

### VS Code Remote-SSH

1. Install **Remote - SSH** extension.
2. Connect to `inception` host.
3. Open project folder on VM — edit and terminal run on VM directly.

---

## Step 3 — Sudo and Docker group

```bash
# If your user lacks sudo
su -
usermod -aG sudo <login>
exit
# log out and back in

# Verify
groups
```

---

## Step 4 — Install Docker Engine (official method)

Follow [Install Docker Engine on Debian](https://docs.docker.com/engine/install/debian/) — **apt repository** method.

Summary:

```bash
sudo apt update
sudo apt install -y ca-certificates curl gnupg

sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | \
  sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
sudo chmod a+r /etc/apt/keyrings/docker.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] \
  https://download.docker.com/linux/debian $(. /etc/os-release && echo $VERSION_CODENAME) stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt update
sudo apt install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

### Verify

```bash
sudo docker run hello-world
docker compose version
```

### Run Docker without sudo

```bash
sudo usermod -aG docker $USER
# log out and back in
docker ps
```

**On weak hardware:** `hello-world` pull is small; first real builds will be much slower.

---

## Step 5 — Domain and hosts file

The site must answer at **`https://<login>.42.fr`** (replace `<login>` with your intra login).

### Option A — Browse from host (recommended)

**On host machine** (`/etc/hosts`):

```text
127.0.0.1   <login>.42.fr
```

VirtualBox forwards host `443` → VM `443`. Traffic: browser → host loopback → VM → NGINX container.

### Option B — Browse from inside VM only

If you cannot edit host `/etc/hosts` (locked 42 workstation):

**Inside VM** `/etc/hosts`:

```text
127.0.0.1   <login>.42.fr
```

Install a minimal browser in VM (`firefox-esr`) or test with `curl -k`. Heavier on RAM — avoid on weak PCs unless necessary.

### Verify DNS resolution

```bash
ping -c 1 <login>.42.fr
# should hit 127.0.0.1
```

---

## Step 6 — Data directories on VM

Subject requires persistent data under `/home/<login>/data`:

```bash
mkdir -p /home/$USER/data/wordpress
mkdir -p /home/$USER/data/mariadb
# or /home/$USER/data/mysql — match your compose volume paths
ls -la /home/$USER/data/
```

These paths are **bind-mounted** into containers. Data survives `docker compose down`; wiped only if you delete host folders or run aggressive `fclean`.

---

## Step 7 — Project repository on VM

```bash
cd ~
git clone <your-inception-repo> inception
cd inception
```

Expected layout (you will create during project):

```text
inception/
├── Makefile
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        ├── nginx/
        └── wordpress/
```

---

## Step 8 — Sanity checks before coding

Run on VM:

```bash
# Docker works
docker ps

# Disk space (need several GB free for images)
df -h /home/$USER
df -h /var/lib/docker

# Compose plugin
docker compose version

# Port 443 free on VM (before starting stack)
sudo ss -tlnp | grep :443 || echo "443 is free"
```

---

## Troubleshooting VM performance

| Symptom | Things to try |
|---------|----------------|
| VM extremely slow | Confirm VM disk is not on network FS; move to `/sgoinfre`; reduce RAM to 2 GB if host is swapping |
| VirtualBox sluggish on Windows | Disable Hyper-V / WSL2 hypervisor if docs allow; or use campus Linux machines |
| `apt` / `docker build` hangs | Wait — first run can take 30+ min; check `top` for I/O wait |
| SSH connection refused | VM running? Port forward rule? `sudo systemctl status ssh` |
| `443` already in use on host | Change host forward to `8443:443` temporarily; use `https://login.42.fr:8443` for testing |
| Out of disk | `docker system df`; `docker system prune` (careful — removes unused images) |

---

## Snapshot strategy (recommended)

After Docker installs successfully:

1. Power off VM.
2. VirtualBox → **Snapshots → Take** — name: `clean-docker-ready`.
3. Before evaluation, snapshot `pre-eval`.

If a build breaks the system, restore snapshot instead of reinstalling Debian.

---

## Next step

VM is ready. Continue with [study-plan.md](./study-plan.md) Phase 1 (project skeleton and MariaDB container).
