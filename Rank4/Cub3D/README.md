# Cub3D — Raycasting engine

Team project: build a **Wolfenstein 3D-style** maze renderer using **raycasting** (not true 3D). Parse `.cub` maps, move the player, render walls with textures.

**Alternative:** Some campuses offer **MiniRT** (ray tracing) instead — confirm your branch on the intranet.

## Project theme

- **Raycasting** — 2D map, cast rays for each screen column
- **MLX** — MiniLibX for window and pixels (Linux/macOS)
- **Parsing** — textures, colors, map validation
- **Controls** — WASD movement, arrow rotation

## Study files

- [study-plan.md](./study-plan.md)
- [theory-and-concepts.md](./theory-and-concepts.md)
- [exercises.md](./exercises.md)
- [syntax-libraries-tools.md](./syntax-libraries-tools.md)

## Global constraints

- **Language:** C (not C++)
- **Graphics:** MiniLibX only — no other graphics libs
- **Forbidden:** `screen`, `system`, `sleep`, `usleep` in render loop (subject); no leaks
- **Map:** Closed by walls; valid chars per subject (`1`, `0`, `N/S/E/W`, spaces)
