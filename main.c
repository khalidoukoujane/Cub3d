#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIN_W 640
#define WIN_H 480
#define MAP_W 8
#define MAP_H 8
#define TILE 64
#define FOV (M_PI / 3)  // 60 degrees

int map[MAP_H][MAP_W] = {
    {1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,1,0,0,1,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *data;
    int bpp;
    int size_line;
    int endian;
    int width;
    int height;
} t_img;

typedef struct {
    double x, y;
    double angle;
} t_player;


typedef struct {
    void *mlx;
    void *win;
    t_img img;
    t_player player;
} t_vars;


void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return;
    char *dst = img->data + (y * img->size_line + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

int close_win(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int key_hook(int keycode, t_vars *vars)
{
    double move_step = 5;
    double new_x, new_y;

    if (keycode == 53) // ESC key on macOS
        exit(0);
    else if (keycode == 123) // Left arrow - rotate left
        vars->player.angle -= 0.1;
    else if (keycode == 124) // Right arrow - rotate right
        vars->player.angle += 0.1;
    else if (keycode == 126) // Up arrow - move forward
    {
        new_x = vars->player.x + cos(vars->player.angle) * move_step;
        new_y = vars->player.y + sin(vars->player.angle) * move_step;
        if (map[(int)(new_y / TILE)][(int)(new_x / TILE)] == 0)
        {
            vars->player.x = new_x;
            vars->player.y = new_y;
        }
    }
    else if (keycode == 125) // Down arrow - move backward
    {
        new_x = vars->player.x - cos(vars->player.angle) * move_step;
        new_y = vars->player.y - sin(vars->player.angle) * move_step;
        if (map[(int)(new_y / TILE)][(int)(new_x / TILE)] == 0)
        {
            vars->player.x = new_x;
            vars->player.y = new_y;
        }
    }
    return (0);
}

void draw_column(t_vars *vars, int x, int start, int end, int color)
{
    for (int y = start; y < end; y++)
        my_mlx_pixel_put(&vars->img, x, y, color);
}

void render(t_vars *vars)
{
    int x;
    double ray_angle;
    double ray_x, ray_y;
    double dist_to_wall;
    int hit_wall;
    int line_height;
    int draw_start, draw_end;
    int color;

    // Clear image (simple)
    for (int i = 0; i < WIN_W * WIN_H; i++)
        ((int*)vars->img.data)[i] = 0x444444; // dark gray background

    // Draw floor and ceiling (just color bands)
    for (int y = 0; y < WIN_H / 2; y++) {
        for (int x = 0; x < WIN_W; x++)
            my_mlx_pixel_put(&vars->img, x, y, 0x87CEEB); // sky blue ceiling
    }
    for (int y = WIN_H / 2; y < WIN_H; y++) {
        for (int x = 0; x < WIN_W; x++)
            my_mlx_pixel_put(&vars->img, x, y, 0x654321); // brown floor
    }

    for (x = 0; x < WIN_W; x++)
    {
        ray_angle = vars->player.angle - (FOV / 2) + ((double)x / WIN_W) * FOV;
        ray_x = cos(ray_angle);
        ray_y = sin(ray_angle);

        dist_to_wall = 0;
        hit_wall = 0;

        while (!hit_wall && dist_to_wall < 1000)
        {
            dist_to_wall += 1;
            int test_x = (int)((vars->player.x + ray_x * dist_to_wall) / TILE);
            int test_y = (int)((vars->player.y + ray_y * dist_to_wall) / TILE);

            if (test_x < 0 || test_x >= MAP_W || test_y < 0 || test_y >= MAP_H)
            {
                hit_wall = 1;
                dist_to_wall = 1000;
            }
            else if (map[test_y][test_x] == 1)
                hit_wall = 1;
        }

        // Fish-eye correction
        double corrected_dist = dist_to_wall * cos(ray_angle - vars->player.angle);
        line_height = (int)(WIN_H * TILE / corrected_dist);

        draw_start = WIN_H / 2 - line_height / 2;
        if (draw_start < 0) draw_start = 0;

        draw_end = WIN_H / 2 + line_height / 2;
        if (draw_end >= WIN_H) draw_end = WIN_H - 1;

        // Simple shading by distance
        int shade = (int)(255 - (corrected_dist * 255 / 500));
        if (shade < 0) shade = 0;
        color = (shade << 16) | (shade << 8) | shade; // grayscale

        draw_column(vars, x, draw_start, draw_end, color);
    }

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Mini Cub3D mlx");
    vars.img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
    vars.img.data = mlx_get_data_addr(vars.img.img, &vars.img.bpp, &vars.img.size_line, &vars.img.endian);
    vars.img.width = WIN_W;
    vars.img.height = WIN_H;

    vars.player.x = 300;
    vars.player.y = 300;
    vars.player.angle = 0;

    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);   // Key press
    mlx_hook(vars.win, 17, 0, close_win, NULL);      // Close window
    mlx_loop_hook(vars.mlx, (int(*)())render, &vars);

    mlx_loop(vars.mlx);

    return 0;
}
