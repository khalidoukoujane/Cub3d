/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-01 12:51:38 by khoukouj          #+#    #+#             */
/*   Updated: 2025-07-01 12:51:38 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	do_textures_checks(t_parsed **data)
{
	int	fds[4];

	fds[0] = open((*data)->no_texture, O_RDONLY);
	fds[1] = open((*data)->so_texture, O_RDONLY);
	fds[2] = open((*data)->we_texture, O_RDONLY);
	fds[3] = open((*data)->ea_texture, O_RDONLY);
	if (fds[0] < 0 || fds[1] < 0 || fds[2] < 0 || fds[3] < 0)
		return (ft_close_fds(fds), -1);
	return (ft_close_fds(fds), 0);
}

int	copy_map(t_parsed **data, char **content, int i)
{
	int	len;
	int	start;

	len = 0;
	start = i;
	while (valid_line(content[start]) && !is_only_whitespace(content[start]))
		len += (start++, 1);
	(*data)->map = malloc(sizeof(char *) * (len + 1));
	if (!((*data)->map))
		return (-1);
	start = i;
	len = 0;
	while (valid_line(content[start]) && !is_only_whitespace(content[start]))
	{
		(*data)->map[len] = ft_strdup(content[start]);
		len += (start++, 1);
	}
	(*data)->map[len] = NULL;
	return (0);
}

void	fill_colors(char **data, t_color *color)
{
	color->r = ft_atoi(data[0]);
	color->g = ft_atoi(data[1]);
	color->b = ft_atoi(data[2]);
	color->result = color->r << 16;
	color->result |= color->g << 8;
	color->result |= color->b;
}
