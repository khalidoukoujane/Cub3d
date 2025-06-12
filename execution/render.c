#include "../cub.h"

void	draw_line(t_vars *vars, int x, t_ray ray)
{
	int		start;
	int		end;
	int		length;

	length = HEIGHT / ray.distance;
	start = (HEIGHT - length) / 2;
	end = HEIGHT - start;
	while (start < end)
	{
		// color is f(side)
		mlx_pixel_put(vars->mlx, vars->win, x, start, 0xFFFFFF);
		start++;
	}
}

void	render(t_vars *vars)
{
	t_ray		ray;
	int			x;

	x = 0;
	while (x < HEIGHT)
	{
		ray_init(&ray, vars->player.position, vars->player.angle + (x / HEIGHT * 360));
		ray_cast(vars, &ray);
		draw_line(vars, x, ray);
		x++;
	}
}
