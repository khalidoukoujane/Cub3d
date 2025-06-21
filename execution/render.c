#include "../cub.h"

int	get_wall_color(t_vars *vars, int px_x, int px_y, t_ray *ray)
{
	t_tex	texture;
	int		decoder;
	int		color;
	int		line_length;
	int		x;
	int		y;

	decoder = (ray->direction.x < 0) * 2 + (ray->side == 1);
	texture = vars->textures[decoder];
	line_length = ray->end - ray->start;

	y = (int)(((double)(px_y - ray->start) / line_length) * (texture.height - 1));
	if (ray->side == 1)
		x = (int)(decimal_part(ray->side_dist.y) * texture.width);
	else
		x = (int)(decimal_part(ray->side_dist.x) * texture.width);
	color = texture.data[texture.width * y + x];
	return (color);
}

void	get_line_len(t_ray *ray)
{
	int	line_length;

	if (ray->distance < 0.00001)
		ray->distance = 0.00001;
	line_length = HEIGHT / ray->distance;
	if (line_length > HEIGHT)
		line_length = HEIGHT;
	ray->start = (HEIGHT - line_length) / 2;
	ray->end = ray->start + line_length;
	if (ray->end > HEIGHT) ray->end = HEIGHT;
}

void	draw_line(t_vars *vars, int x, t_ray *ray)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	get_line_len(ray);
	while (y < ray->start)
		my_mlx_pixel_put(&vars->img, x, y++, 0x0000ee);
	while (y < ray->end)
		my_mlx_pixel_put(&vars->img, x, y++, get_wall_color(vars, x, y, ray));
	while (y < HEIGHT)
		my_mlx_pixel_put(&vars->img, x, y++, 0x0000aa);
}

void	render(t_vars *vars)
{
	t_ray	ray;
	double	x;
	double	theta;

	x = 0;
	mlx_clear_window(vars->mlx, vars->win);
	while (x < WIDTH)
	{
		theta = vars->player.angle + (x / WIDTH * FOV);
		ray_init(&ray, vars->player.position, theta);
		ray_cast(vars, &ray);
		draw_line(vars, x, &ray);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}
