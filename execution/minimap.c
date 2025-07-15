/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:01:04 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/15 09:41:29 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static double	calc_distance(t_vector a, t_vector b)
{
	double	dx;
	double	dy;

	dx = (a.x - b.x) * (a.x - b.x);
	dy = (a.y - b.y) * (a.y - b.y);
	return (dx + dy);
}

static int	out_of_map(char **map, int map_height, t_vector px)
{
	if (px.y < 0 || px.y >= map_height)
		return (1);
	if (px.x < 0 || (int)px.x >= (int)ft_strlen(map[(int)px.y]))
		return (1);
	return (0);
}

int	get_minimap_color(t_vars *vars, int x, int y)
{
	t_vector	reference;
	t_vector	px;
	double		view;
	int			map_len;

	view = 10;
	map_len = 14;
	reference = vars->player.position;
	px = reference;
	px.x += ((double)(x - MINI_WIDTH / 2) / MINI_WIDTH) * 24 * view;
	px.y += ((double)(y - MINI_HEIGHT / 2 )/ MINI_HEIGHT) * 14 * view;
	if (calc_distance(px, reference) < 0.05)
		return (0xFF0000);
	if (out_of_map(vars->data->map, (int)vars->data->map_dimension.y, px))
		return (0x000000);
	if (vars->data->map[(int)px.y][(int)px.x] == '1')
		return (0x1f333a);
	else if (vars->data->map[(int)px.y][(int)px.x] >= '0')
		return (0xb7f0c1);
	return (0x000000);
}
