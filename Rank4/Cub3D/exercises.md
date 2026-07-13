# Cub3D — Exercise breakdown

## Turn-in summary

| | |
|---|---|
| **Program** | `cub3D` |
| **Run** | `./cub3D <map.cub>` |
| **Language** | C |
| **Makefile** | `NAME`, `all`, `clean`, `fclean`, `re` |

---

## Mandatory features

### Parsing

| Requirement | Detail |
|-------------|--------|
| Map chars | `0` empty, `1` wall, `N/S/E/W` player (one only) |
| Colors | `F R,G,B` and `C R,G,B` (0–255) |
| Textures | `NO`, `SO`, `WE`, `EA` paths to XPM files |
| Validation | Closed map, single player, valid paths |

### Rendering

| Requirement | Detail |
|-------------|--------|
| Raycasting | 3D view from 2D map |
| Textures | Different wall sides (N/S/E/W) |
| Floor/ceiling | From parsed colors |
| Movement | Forward/back/strafe + rotate |

### Controls (typical subject)

| Key | Action |
|-----|--------|
| W/A/S/D | Move |
| ← / → | Rotate |
| ESC | Quit cleanly |

---

## Bonus (examples — confirm PDF)

- Sprites
- Animated textures
- Mouse look
- Minimap overlay

Bonus graded only if mandatory is **perfect**.

---

## Evaluation traps

| Trap | Consequence |
|------|-------------|
| Leaks on exit | Fail |
| Crash on bad map | Fail |
| `system("leaks")` dependency | Forbidden |
| Map not closed | Parser must reject |
| Using non-MLX graphics | Fail |

---

## MiniRT alternative

If your campus assigns **MiniRT** instead of Cub3D, this directory still helps with vector math and MLX — see MiniRT subject for sphere/plane/cylinder intersection instead of raycasting.
