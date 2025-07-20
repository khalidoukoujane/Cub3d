/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:51:38 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/20 12:42:49 by khoukouj         ###   ########.fr       */
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
	while (valid_line(content[start]) || is_only_whitespace(content[start]))
		len += (start++, 1);
	(*data)->map = malloc(sizeof(char *) * (len + 1));
	if (!((*data)->map))
		return (-1);
	start = i;
	len = 0;
	while (valid_line(content[start]) || is_only_whitespace(content[start]))
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

char	**handle_clr_part(char *line)
{
	char	**data;
	char	**clrs;
	char	**res;
	int		it;

	it = 0;
	data = ft_spliter(line, " \t\n");
	if (!data || !data[0] || !data[1])
		return (NULL);
	clrs = ft_spliter(data[1], ",");
	if (!clrs || count_splited(clrs) != 3)
		return (free_splited(data), free_splited(clrs), NULL);
	res = malloc(sizeof(char *) * (count_splited(clrs) + 2));
	if (!res)
		return (free_splited(clrs), free_splited(data), NULL);
	res[0] = ft_strdup(data[0]);
	if (!res[0])
		return (free(res), free_splited(clrs), free_splited(data), NULL);
	while (it < count_splited(clrs))
	{
		res[it + 1] = ft_strdup(clrs[it]);
		it++;
	}
	res[count_splited(clrs) + 1] = NULL;
	return (free_splited(data), free_splited(clrs), res);
}
