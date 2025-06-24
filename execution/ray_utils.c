/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:20:49 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/24 09:05:10 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	get_side_vec(t_ray *ray, t_vector vec)
{
	if (ray->side == 0)
		return (vec.x);
	return (vec.y);
}

void	ray_init(t_ray *ray, t_vector origin, double theta)
{
	ray->origin = origin;
	ray->tangente = tan(theta);
	ray->direction = (t_vector){cos(theta), sin(theta)};
	ray->map = (t_vector){(int)origin.x, (int)origin.y};
	ray->map_unit.x = (ray->direction.x < 0) * -2 + 1;
	ray->map_unit.y = (ray->direction.y < 0) * -2 + 1;
	ray->step.x = (ray->direction.x != 0)
		* fabs(1 / zero_protect(ray->direction.x));
	ray->step.y = (ray->direction.y != 0)
		* fabs(1 / zero_protect(ray->direction.y));
	ray->hit = 0;
	ray->side = -1;
	ray->side_dist.x = decimal_part(origin.x) * ray->step.x;
	if (ray->direction.x > 0)
		ray->side_dist.x = (1 - decimal_part(origin.x)) * ray->step.x;
	ray->side_dist.y = decimal_part(origin.y) * ray->step.y;
	if (ray->direction.y > 0)
		ray->side_dist.y = (1 - decimal_part(origin.y)) * ray->step.y;
}

void	ray_cast(t_vars *vars, t_ray *ray)
{
	while (!ray->hit)
	{
		if ((ray->side_dist.x < ray->side_dist.y && ray->direction.x != 0)
			|| ray->direction.y == 0)
		{
			ray->side_dist.x += ray->step.x;
			ray->map.x += ray->map_unit.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->step.y;
			ray->map.y += ray->map_unit.y;
			ray->side = 1;
		}
		ray->hit = vars->data->map[(int)ray->map.x][(int)ray->map.y] == '1';
	}
	ray->distance = get_side_vec(ray, ray->side_dist)
		- get_side_vec(ray, ray->step);
}
