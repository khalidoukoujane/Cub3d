/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-30 10:08:57 by khoukouj          #+#    #+#             */
/*   Updated: 2025-05-30 10:08:57 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	count_player(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (is_player(line[i]))
			count++;
		i++;
	}
	return (count);
}

int	check_wall(char **content, int dir, int start, t_lv v)
{
	if (dir == TOP_DIR)
		while (v.j > start && (content[v.j][v.i] == '0'
			|| is_player(content[v.j][v.i])))
			v.j--;
	else if (dir == BTM_DIR)
	{
		while (content[v.j] && content[v.j + 1] && (content[v.j][v.i] == '0'
			|| is_player(content[v.j][v.i])))
			v.j++;
	}
	else if (dir == R_DIR)
	{
		while (content[v.j][v.i] && (content[v.j][v.i] == '0'
			|| is_player(content[v.j][v.i])))
			v.i++;
	}
	else if (dir == L_DIR)
	{
		while (v.i && (content[v.j][v.i] == '0'
			|| is_player(content[v.j][v.i])))
			v.i--;
	}
	if (content[v.j][v.i] != '1')
		return (0);
	return (1);
}

int	is_map_closed(char **content, int start)
{
	t_lv	v;

	v.j = start;
	while (content[v.j])
	{
		v.i = 0;
		while (content[v.j][v.i])
		{
			if (content[v.j][v.i] == '0' || is_player(content[v.j][v.i]))
			{
				if (!check_wall(content, TOP_DIR, start, v)
					|| !check_wall(content, BTM_DIR, start, v)
					|| !check_wall(content, R_DIR, start, v)
					|| !check_wall(content, L_DIR, start, v))
					return (-1);
			}
			v.i++;
		}
		v.j++;
	}
	return (0);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	check_map(char **content, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (content[i])
	{
		if (ft_strchr(content[i], '\t'))
			return (ft_error("Map error: found tab: line"), -1);
		count += count_player(content[i]);
		if (!valid_line(content[i]))
			return (ft_error(MAP_ERR_MSG), -1);
		if (count > 1)
			return (ft_error("Map error: Player error"), -1);
		if (count == 1 && !is_surrounded(content, i))
			return (ft_error("Map error: Player error"), -1);
		i++;
	}
	if (is_map_closed(content, start) == -1)
		return (ft_error("Map error: unclosed map"), -1);
	if (count == 0)
		return (ft_error("Map error: Player error"), -1);
	return (0);
}
