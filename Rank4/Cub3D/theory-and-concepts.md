# Cub3D — Theory and concepts

## Raycasting vs ray tracing

**Raycasting** (Cub3D): one ray per screen column; shoot into 2D grid until wall. Fast, Wolfenstein-style.

**Ray tracing** (MiniRT): rays per pixel with full 3D intersection math.

## Player state

```c
typedef struct s_player {
    double  pos_x, pos_y;
    double  dir_x, dir_y;    /* view direction */
    double  plane_x, plane_y; /* camera plane for FOV */
}   t_player;
```

FOV controlled by camera plane length relative to direction.

## DDA grid traversal

Instead of stepping infinitesimally, step cell-by-cell:

1. Compute `deltaDist` for x and y grid lines
2. Step in direction of shorter side distance
3. Stop when map cell is `'1'`

## Wall distance & fish-eye

Use **perpendicular** distance to wall, not Euclidean to hit point — prevents curved wall effect.

```
wall_height = screen_height / perpendicular_distance
```

## Texture mapping

Determine which side (N/S/E/W) was hit → pick texture.  
Compute fractional wall hit position for X coordinate in texture.

## Map representation

2D char array or int grid. Pad with spaces or void outside bounds — parser should trim and validate rectangle.

## MLX image buffer

```c
img.addr = mlx_get_data_addr(img.img, &bpp, &line_len, &endian);
```

Write pixels via `addr[y * line_len + x * (bpp/8)]` for speed — avoid `mlx_pixel_put` in final render loop.

## Error handling

Return non-zero from `main` on parse failure; free all MLX and map allocations on any exit path.
