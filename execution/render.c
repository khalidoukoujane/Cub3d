#include "../cub.h"

int	get_wall_color()
{
	return 0;
}

void	get_line_len(int *start, int *end, t_ray ray)
{
	int	line_length;

	if (ray.distance < 0.00001)
		ray.distance = 0.00001;
	line_length = HEIGHT / ray.distance;
	if (line_length > HEIGHT)
		line_length = HEIGHT;
	*start = (HEIGHT - line_length) / 2;
	*end = *start + line_length;
	if (*end > HEIGHT) *end = HEIGHT;
}

void	draw_line(t_vars *vars, int x, t_ray ray)
{
	int	y;
	int	color;
	int	start;
	int	end;

	y = 0;
	get_line_len(&start, &end, ray);
	while (y < start)
		my_mlx_pixel_put(&vars->img, x, y++, 0x0000ee);
	while (y < end)
		my_mlx_pixel_put(&vars->img, x, y++, ray.side * 0x220000 + 0x111111);
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
		draw_line(vars, x, ray);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}
