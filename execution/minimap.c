
#include "../cub.h"

double	calc_distance(t_vector a, t_vector b)
{
	double dx;
	double dy;

	dx = (a.x - b.x) * (a.x - b.x);
	dy = (a.y - b.y) * (a.y - b.y);
	return (dx + dy);
}

int	get_minimap_color(t_vars *vars, int x, int y)
{
	t_vector	reference;
	t_vector	px;
	double		view = 5;

	reference = vars->player.position;
	
	px = reference;
	
	px.x += ((double)(x - MINI_WIDTH / 2) / MINI_WIDTH) * 24 * view;
	px.y += ((double)(y - MINI_HEIGHT / 2 )/ MINI_HEIGHT) * 14 * view;

	if (calc_distance(px, reference) < 0.05)
		return (0xFF0000);

	// printf("%f, %f\n", px.y, px.x);
	if (px.y >= 14 || px.y < 0)
		return (0);
	// if (((long)ft_strchr(vars->data->map[(int)px.y], '1') - (long)vars->data->map[(int)px.y]) / 8 <= px.x)
	// 	return (0);

	if (vars->data->map[(int)px.y][(int)px.x] == '1')
		return (0xAAAAAA);
	return (0x00FF00);
}


