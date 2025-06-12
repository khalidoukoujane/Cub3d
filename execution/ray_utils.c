#include "../cub.h"

void	ray_init(t_ray *ray, t_vector origin, double theta)
{
	ray->origin = origin;
	ray->direction.x = cos(theta);
	ray->direction.y = sin(theta);
	ray->map.x = (int)ray->origin.x;
	ray->map.y = (int)ray->origin.y;
	ray->map_unit.x = ray->direction.x < 0 ? -1 : 1;
	ray->map_unit.y = ray->direction.y < 0 ? -1 : 1;
	ray->step.x = fabs(1 / ray->direction.x);
	ray->step.y = fabs(1 / ray->direction.y);
	ray->hit = 0;
	ray->side = 1;

	// zero if the player is on a point
	if (ray->direction.x < 0)
		ray->side_dist.x = (ray->origin.x - ray->map.x) * ray->step.x;
	else
		ray->side_dist.x = (ray->map.x + 1.0 - ray->origin.x) * ray->step.x;

	if (ray->direction.y < 0)
		ray->side_dist.y = (ray->origin.y - ray->map.y) * ray->step.y;
	else
		ray->side_dist.y = (ray->map.y + 1.0 - ray->origin.y) * ray->step.y;


}

void	ray_trace(t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
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

		if (get_map(ray->map.x, ray->map.y) == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->distance = (ray->map.x - ray->origin.x + (1 - ray->map_unit.x) / 2) / ray->direction.x;
	else
		ray->distance = (ray->map.y - ray->origin.y + (1 - ray->map_unit.y) / 2) / ray->direction.y;
}
