/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:15:58 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/14 16:25:09 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_wall_color(t_vars *vars, int px_y, t_ray *ray)
{
	t_tex	texture;
	int		decoder;
	double	wall_x;
	double	wall_y;
	t_equ	equ;

	decoder = !ray->side + (get_side_vec(ray, ray->direction) > 0) * 2;
	texture = vars->textures[decoder];
	ray->line_len = ray->end - ray->start;
	wall_y = (int)(((double)(px_y - ray->start) / ray->line_len)
			* (texture.height));
	equ = linear_equ(*ray);
	wall_x = solve_equs(equ, *ray);
	wall_x = (int)(decimal_part(wall_x) * (texture.width));
	return (texture.data[texture.width * (int)wall_y + (int)wall_x]);
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
		my_mlx_pixel_put(&vars->img, x, y++, vars->data->ceiling_color.result);
	while (y < ray->end && y < HEIGHT)
	{
		my_mlx_pixel_put(&vars->img, x, y, get_wall_color(vars, y, ray));
		y++;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(&vars->img, x, y++, vars->data->floor_color.result);
	if (x >= MINI_WIDTH)
		return ;
	y = 0;
	while (y < MINI_HEIGHT)
		my_mlx_pixel_put(&vars->img, x, y++, get_minimap_color(vars, x, y));
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
		ray.distance *= cos(theta - vars->player.angle);
		draw_line(vars, x, &ray);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}
