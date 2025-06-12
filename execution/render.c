#include "../cub.h"

// void	draw_line(t_vars *vars, int x, t_ray ray)
// {
// 	int		start;
// 	int		end;
// 	int		length;

// 	length = HEIGHT / ray.distance;
// 	if (length > HEIGHT) length = HEIGHT;
// 	start = (HEIGHT - length) / 2;
// 	end = HEIGHT - start;
// 	while (start < end)
// 	{
// 		// color is f(side)
// 		mlx_pixel_put(vars->mlx, vars->win, x, start, 0xFFFFFF);
// 		start++;
// 	}
// }

// void	render(t_vars *vars)
// {
// 	t_ray		ray;
// 	int			x;

// 	x = 0;
// 	while (x < HEIGHT)
// 	{
// 		ray_init(&ray, vars->player.position, vars->player.angle + (x / HEIGHT * 360));
// 		ray_cast(vars, &ray);
// 		draw_line(vars, x, ray);
// 		x++;
// 	}
// }



#include "../cub.h"
#include <math.h>

#define FOV 0.66 // Field of view (in radians, e.g. ~66°)

// Simple shading function based on wall side
int get_wall_color(int side)
{
    return (side == 1) ? 0xAAAAAA : 0xFFFFFF;
}

void draw_line(t_vars *vars, int x, t_ray ray)
{
    int start, end, length;
    int color = get_wall_color(ray.side);

    length = HEIGHT / ray.distance;
    if (length > HEIGHT)
        length = HEIGHT;

    start = (HEIGHT - length) / 2;
    end = start + length;

    while (start < end)
    {
        mlx_pixel_put(vars->mlx, vars->win, x, start, color);
        start++;
    }
}

void render(t_vars *vars)
{
    t_ray ray;
    int x;

    x = 0;
	mlx_clear_window(vars->mlx, vars->win);
    while (x < WIDTH)
    {
        double camera_x = 2 * x / (double)WIDTH - 1; // value from -1 to 1
        double ray_angle = vars->player.angle + atan(camera_x * FOV); // perspective correction
        ray_init(&ray, vars->player.position, ray_angle);
        ray_cast(vars, &ray);
        draw_line(vars, x, ray);
        x++;
    }
}

