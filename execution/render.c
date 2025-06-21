#include "../cub.h"

// int	get_wall_color(t_vars *vars, int px_x, int px_y, t_ray *ray)
// {
// 	t_tex	texture;
// 	int		decoder;
// 	int		color;
// 	int		line_length;
// 	int		x;
// 	int		y;

// 	decoder = (ray->direction.x < 0) * 2 + (ray->side == 1);
// 	texture = vars->textures[decoder];
// 	line_length = ray->end - ray->start;

// 	y = (int)(((double)(px_y - ray->start) / line_length) * (texture.height - 1));
// 	if (ray->side == 1)
// 		x = (int)(decimal_part(ray->side_dist.y) * texture.width);
// 	else
// 		x = (int)(decimal_part(ray->side_dist.x) * texture.width);
// 	color = texture.data[texture.width * y + x];
// 	return (color);
// }

int	get_wall_color(t_vars *vars, int px_y, t_ray *ray)
{
	t_tex	texture;
	int		decoder;
	int		color;
	int		x, y;
	double	wall_x;
	int		line_length;

	// Select correct texture based on ray direction and side
	decoder = (ray->direction.y < 0) * 2 + (ray->side == 1);
	texture = vars->textures[decoder];

	// Prevent division by zero in line length
	line_length = ray->end - ray->start;
	if (line_length == 0)
		line_length = 1;

	// Y coordinate on texture
	y = (int)(((double)(px_y - ray->start) / line_length) * (texture.height - 1));

	// Compute exact wall hit point (wall_x) for texture X coordinate
	if (ray->side == 0)
		wall_x = ray->origin.y + ray->distance * ray->direction.y;
	else
		wall_x = ray->origin.x + ray->distance * ray->direction.x;
	wall_x -= floor(wall_x); // Keep only the fractional part

	x = (int)(wall_x * texture.width);

	// Flip texture X coordinate depending on side and direction
	if ((ray->side == 0 && ray->direction.x > 0) ||
		(ray->side == 1 && ray->direction.y < 0))
		x = texture.width - x - 1;

	// Clamp texture coordinates
	if (x < 0) x = 0;
	if (x >= texture.width) x = texture.width - 1;
	if (y < 0) y = 0;
	if (y >= texture.height) y = texture.height - 1;

	// Get pixel color from texture
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
		my_mlx_pixel_put(&vars->img, x, y++, get_wall_color(vars, y, ray));
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
