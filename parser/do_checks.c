/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-01 12:50:13 by khoukouj          #+#    #+#             */
/*   Updated: 2025-07-01 12:50:13 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	do_colors_checks(t_parsed **data)
{
	if ((*data)->ceiling_color.r < 0 || (*data)->ceiling_color.r > 255)
		return (-1);
	else if ((*data)->ceiling_color.g < 0 || (*data)->ceiling_color.g > 255)
		return (-1);
	else if ((*data)->ceiling_color.b < 0 || (*data)->ceiling_color.b > 255)
		return (-1);
	else if ((*data)->floor_color.g < 0 || (*data)->floor_color.g > 255)
		return (-1);
	else if ((*data)->floor_color.b < 0 || (*data)->floor_color.b > 255)
		return (-1);
	else if ((*data)->floor_color.r < 0 || (*data)->floor_color.r > 255)
		return (-1);
	return (0);
}

void	ft_close_fds(int *fds)
{
	int	i;

	i = 0;
	while (i < 4)
		close(fds[i++]);
}

void	get_angle(t_parsed **data, int i, int j)
{
	if ((*data)->map[i][j] == 'N')
		(*data)->angle = N_ORIENTED;
	else if ((*data)->map[i][j] == 'S')
		(*data)->angle = S_ORIENTED;
	else if ((*data)->map[i][j] == 'W')
		(*data)->angle = W_ORIENTED;
	else if ((*data)->map[i][j] == 'E')
		(*data)->angle = E_ORIENTED;
}

int	get_player_pos(t_parsed **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->map[i])
	{
		j = 0;
		while ((*data)->map[i][j])
		{
			if (is_player((*data)->map[i][j]))
			{
				(*data)->player_pos.x = j + 0.5;
				(*data)->player_pos.y = i + 0.5;
				get_angle(data, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
	#### return -1 on failure with an error msg
*/
int	do_conf_checks(t_parsed **data)
{
	if (do_textures_checks(data) == -1)
		return (ft_error("textures not found"), -1);
	if (do_colors_checks(data) == -1)
		return (ft_error("colors overflow error [0, 255]"), -1);
	get_player_pos(data);
	return (0);
}
