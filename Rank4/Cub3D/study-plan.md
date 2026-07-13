# Cub3D — Study plan

## Phase 0 — Math & MLX (3–5 days)

| Topic | Action |
|-------|--------|
| Trigonometry | `sin`, `cos`, unit circle |
| Vectors | Direction vector from player angle |
| MLX basics | Window, image buffer, `mlx_pixel_put` |
| Key hooks | `mlx_hook`, `mlx_loop_hook` |

**Checkpoint:** Open window, draw a moving pixel with arrow keys.

---

## Phase 1 — Raycasting theory (2–3 days)

| Topic | Action |
|-------|--------|
| DDA algorithm | Step grid until wall hit |
| Fish-eye fix | Perpendicular wall distance |
| Column height | Map distance → wall strip height |

Read [theory-and-concepts.md](./theory-and-concepts.md); trace one ray on paper.

---

## Phase 2 — Parser (3–5 days)

| Step | Task |
|------|------|
| 1 | Read `.cub` — textures paths, F/C colors |
| 2 | Parse map grid — validate rectangle, closed walls |
| 3 | Find player spawn `N/S/E/W` — set position + angle |
| 4 | Reject invalid maps early with clear error |

---

## Phase 3 — Renderer (5–7 days)

| Step | Task |
|------|------|
| 1 | Cast one ray per screen column |
| 2 | Choose wall color or texture X coordinate |
| 3 | Draw floor/ceiling from F/C RGB |
| 4 | Texture mapping from MLX XPM |

---

## Phase 4 — Movement & collision (2–3 days)

| Step | Task |
|------|------|
| 1 | WASD — update x/y with delta time or fixed step |
| 2 | Collision — block movement into `'1'` cells |
| 3 | Rotate view with left/right arrows |

---

## Phase 5 — Polish & eval (3–5 days)

- Window resize / minimize handling per subject
- `./cub3D map.cub` only argument
- Leaks: `valgrind` clean on exit
- Bonus: sprites, doors, minimap — only if mandatory perfect

---

## Team split suggestion

| Area | Focus |
|------|--------|
| Parser | File I/O, validation |
| Engine | Raycasting, textures |
| MLX/input | Hooks, movement |
| Integration | `main`, error messages, Makefile |
