#include "../cub.h"

void	ray_init(t_ray *ray, t_vector origin, double theta)
{
	ray->origin = origin;
	ray->direction.x = cos(theta);
	ray->direction.y = sin(theta);
	ray->map.x = (int)ray->origin.x;
	ray->map.y = (int)ray->origin.y;
	ray->step.x = ray->direction.x < 0 ? -1 : 1;
	ray->step.y = ray->direction.y < 0 ? -1 : 1;
	ray->delta_dist.x = fabs(1 / ray->direction.x);
	ray->delta_dist.y = fabs(1 / ray->direction.y);
	ray->hit = 0;


	if (ray->direction.x < 0)
		ray->side_dist.x = (ray->origin.x - ray->map.x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map.x + 1.0 - ray->origin.x) * ray->delta_dist.x;

	if (ray->direction.y < 0)
		ray->side_dist.y = (ray->origin.y - ray->map.y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map.y + 1.0 - ray->origin.y) * ray->delta_dist.y;


}

void	ray_trace(t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}

		if (get_map(ray->map.x, ray->map.y) == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->distance = (ray->map.x - ray->origin.x + (1 - ray->step.x) / 2) / ray->direction.x;
	else
		ray->distance = (ray->map.y - ray->origin.y + (1 - ray->step.y) / 2) / ray->direction.y;
}
