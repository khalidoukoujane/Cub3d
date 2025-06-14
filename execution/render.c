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

#define FOV 0.66

int	get_wall_color(int side, int y, int wall_height, int tex_x, int tex_width, int tex_height, int *wall_data)
{
	int tex_y = (y * tex_height) / wall_height;

	if (tex_y < 0) tex_y = 0;
	if (tex_y >= tex_height) tex_y = tex_height - 1;

	int color = wall_data[tex_y * tex_width + tex_x];

	if (side == 1)
		color = (color >> 1) & 0x7F7F7F;

	return color;
}

void draw_line(t_vars *vars, int x, t_ray ray, int tex_x, int tex_width, int tex_height, int *wall_data)
{
	int start, end, length, color;

	if (ray.distance < 0.0001)
		ray.distance = 0.0001;

	length = HEIGHT / ray.distance;
	if (length > HEIGHT)
		length = HEIGHT;

	start = (HEIGHT - length) / 2;
	end = start + length;

	if (start < 0) start = 0;
	if (end > HEIGHT) end = HEIGHT;

	while (start < end)
	{
		color = get_wall_color(ray.side, start, length, tex_x, tex_width, tex_height, wall_data);
		mlx_pixel_put(vars->mlx, vars->win, x, start, color);
		start++;
	}
}

void render(t_vars *vars)
{
	t_ray ray;
	int x = 0;


	mlx_clear_window(vars->mlx, vars->win);

	while (x < WIDTH)
	{
		double camera_x = 2 * x / (double)WIDTH - 1;
		double ray_angle = vars->player.angle + atan(camera_x * FOV);

		ray_init(&ray, vars->player.position, ray_angle);
		ray_cast(vars, &ray);

		// Compute texture X coordinate
		double wall_x;
		if (ray.side == 0)
			wall_x = ray.origin.y + ray.distance * ray.direction.y;
		else
			wall_x = ray.origin.x + ray.distance * ray.direction.x;

		wall_x -= floor(wall_x); // keep only the fractional part
		int tex_x = (int)(wall_x * vars->textures[0].width);

		// Flip tex_x if needed to avoid mirrored textures
		if ((ray.side == 0 && ray.direction.x > 0) || (ray.side == 1 && ray.direction.y < 0))
			tex_x = vars->textures[0].width - tex_x - 1;

		draw_line(vars, x, ray, tex_x, vars->textures[0].width, vars->textures[0].height, vars->textures[0].data);
		x++;
	}
}


