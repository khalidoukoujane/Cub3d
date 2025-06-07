#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define MAP_W 8
#define MAP_H 8
#define TILE 64
#define FOV 0.66
#define SPEED 0.05
#define ROTATE 0.05

char *map[MAP_H] = {
    "11111111",
    "10000001",
    "10111001",
    "10001001",
    "10001001",
    "10101101",
    "10000001",
    "11111111"
};

typedef struct {
    void *mlx;
    void *win;
    double posX, posY;
    double dirX, dirY;
    double planeX, planeY;
} t_game;

int is_wall(int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
        return 1;
    return map[y][x] == '1';
}

void draw_vert(t_game *g, int x, int start, int end, int color) {
    for (int y = start; y <= end; y++)
        mlx_pixel_put(g->mlx, g->win, x, y, color);
}

int render(t_game *g) {
    for (int x = 0; x < WIDTH; x++) {
        double camX = 2 * x / (double)WIDTH - 1;
        double rayDirX = g->dirX + g->planeX * camX;
        double rayDirY = g->dirY + g->planeY * camX;

        int mapX = (int)g->posX;
        int mapY = (int)g->posY;

        double sideDistX, sideDistY;
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY, hit = 0, side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (g->posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - g->posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (g->posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - g->posY) * deltaDistY;
        }

        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (is_wall(mapX, mapY)) hit = 1;
        }

        perpWallDist = side == 0 ?
            (mapX - g->posX + (1 - stepX) / 2) / rayDirX :
            (mapY - g->posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(HEIGHT / perpWallDist);
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

        int color = side ? 0xAAAAAA : 0xFFFFFF;
        draw_vert(g, x, drawStart, drawEnd, color);
    }
    return 0;
}

int key_hook(int keycode, t_game *g) {
    if (keycode == 53) // ESC
        exit(0);
    if (keycode == 13) { // W
        if (!is_wall((int)(g->posX + g->dirX * SPEED), (int)g->posY))
            g->posX += g->dirX * SPEED;
        if (!is_wall((int)g->posX, (int)(g->posY + g->dirY * SPEED)))
            g->posY += g->dirY * SPEED;
    }
    if (keycode == 1) { // S
        if (!is_wall((int)(g->posX - g->dirX * SPEED), (int)g->posY))
            g->posX -= g->dirX * SPEED;
        if (!is_wall((int)g->posX, (int)(g->posY - g->dirY * SPEED)))
            g->posY -= g->dirY * SPEED;
    }
    if (keycode == 0) { // A
        double oldDirX = g->dirX;
        g->dirX = g->dirX * cos(ROTATE) - g->dirY * sin(ROTATE);
        g->dirY = oldDirX * sin(ROTATE) + g->dirY * cos(ROTATE);
        double oldPlaneX = g->planeX;
        g->planeX = g->planeX * cos(ROTATE) - g->planeY * sin(ROTATE);
        g->planeY = oldPlaneX * sin(ROTATE) + g->planeY * cos(ROTATE);
    }
    if (keycode == 2) { // D
        double oldDirX = g->dirX;
        g->dirX = g->dirX * cos(-ROTATE) - g->dirY * sin(-ROTATE);
        g->dirY = oldDirX * sin(-ROTATE) + g->dirY * cos(-ROTATE);
        double oldPlaneX = g->planeX;
        g->planeX = g->planeX * cos(-ROTATE) - g->planeY * sin(-ROTATE);
        g->planeY = oldPlaneX * sin(-ROTATE) + g->planeY * cos(-ROTATE);
    }
    mlx_clear_window(g->mlx, g->win);
    render(g);
    return 0;
}

int main() {
    t_game g;

    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "minicub3d");

    g.posX = 3.5;
    g.posY = 3.5;
    g.dirX = -1;
    g.dirY = 0;
    g.planeX = 0;
    g.planeY = FOV;

    render(&g);
    mlx_hook(g.win, 2, 1L<<0, key_hook, &g);
    mlx_loop(g.mlx);
    return 0;
}
