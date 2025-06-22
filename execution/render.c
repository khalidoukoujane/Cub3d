#include "../cub.h"

// int	get_wall_color(t_vars *vars, int px_y, t_ray *ray)
// {
// 	t_tex	texture;
// 	int		decoder;
// 	int		color;
// 	int		x, y;
// 	double	wall_x;
// 	int		line_length;

// 	decoder = ray->side + (get_side_vec(ray, ray->direction) > 0) * 2;
// 	texture = vars->textures[decoder];

// 	line_length = ray->end - ray->start + 1;
// 	y = (int)(((double)(px_y - ray->start) / line_length) * (texture.height - 1));

// 	wall_x = get_side_vec(ray, ray->origin) + ray->distance * get_side_vec(ray, ray->direction);
// 	wall_x -= floor(wall_x);

// 	x = (int)(wall_x * texture.width);

// 	color = texture.data[texture.width * y + x];
// 	return (color);
// }


#define EAST_TEXTURE 0
#define SOUTH_TEXTURE 1
#define WEST_TEXTURE 2
#define NORTH_TEXTURE 3


int	get_wall_color(t_vars *vars, int px_y, t_ray *ray)
{
	t_tex	texture;
	int		decoder;
	int		color;
	int		x, y;
	double	wall_x;
	int		line_length;

	decoder = ray->side + (get_side_vec(ray, ray->direction) > 0) * 2; // need adjustment
	texture = vars->textures[decoder];
	line_length = ray->end - ray->start + 1;
	y = (int)(((double)(px_y - ray->start) / line_length) * (texture.height - 1));
	ray->side = !ray->side;
	wall_x = get_side_vec(ray, ray->origin) + ray->distance * get_side_vec(ray, ray->direction);
	wall_x = decimal_part(wall_x);
	ray->side = !ray->side;
	x = (int)(wall_x * (texture.width - 1));
	color = texture.data[texture.width * y + x];
	return (color);
}


void	get_line_len(t_ray *ray)
{
	int	line_length;

	if (ray->distance < 0.00001)
		ray->distance = 0.00001;
	line_length = HEIGHT / ray->distance;
	ray->start = (HEIGHT - line_length) / 2;
	ray->end = ray->start + line_length;
}

void	draw_line(t_vars *vars, int x, t_ray *ray)
{
	int	y;
	int	start;
	int	end;

	(void)start;
	(void)end;
	y = 0;
	get_line_len(ray);
	while (y < ray->start && ray->start >= 0)
		my_mlx_pixel_put(&vars->img, x, y++, 0x8dcaff);
	while (y < ray->end && y < HEIGHT)
	{
		my_mlx_pixel_put(&vars->img, x, y, get_wall_color(vars, y, ray));
		y++;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(&vars->img, x, y++, 0x2d608d);
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
		theta = vars->player.angle + (x / WIDTH * FOV) - FOV / 2;
		ray_init(&ray, vars->player.position, theta);
		ray_cast(vars, &ray);
		draw_line(vars, x, &ray);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}
