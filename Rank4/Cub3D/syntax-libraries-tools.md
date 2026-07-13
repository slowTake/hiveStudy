# Cub3D — Syntax, libraries, and tools

## Compiler flags

```makefile
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = cub3D

MLX_DIR = lib/minilibx-linux
MLX     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
```

macOS uses `minilibx-macos` and different link flags.

## MiniLibX setup

Clone/install MiniLibX per campus docs into `lib/minilibx-linux` or system path.

## Key functions

| MLX | Purpose |
|-----|---------|
| `mlx_init` | Start connection |
| `mlx_new_window` | Create window |
| `mlx_new_image` | Framebuffer |
| `mlx_xpm_file_to_image` | Load texture |
| `mlx_hook` | Key events |
| `mlx_loop` | Event loop |

## Math library

Link `-lm` for `cos`, `sin`, `sqrt`.

## Valgrind

```bash
valgrind --leak-check=full ./cub3D maps/valid.cub
```

MLX may report still-reachable blocks — know campus tolerance; fix your own allocations.

## Test maps

Build a set of `.cub` files:

- Minimal 3×3 closed box
- Open map (must fail)
- Duplicate player (must fail)
- Missing texture path (must fail)

## Useful reads

- Lode's Computer Graphics Tutorial — Raycasting chapter
- Subject PDF map examples
