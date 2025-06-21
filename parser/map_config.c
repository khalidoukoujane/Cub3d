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

int	check_wall(char **content, int i, int j, int dir, int start)
{
	if (dir == TOP_DIR)
	{
		while (j > start && (content[j][i] == '0' || is_player(content[j][i])))
			j--;
	}
	else if (dir == BTM_DIR)
	{
		while (content[j] && content[j + 1] && (content[j][i] == '0'
			|| is_player(content[j][i])))
			j++;
	}
	else if (dir == R_DIR)
	{
		while (content[j][i] && (content[j][i] == '0' || is_player(content[j][i])))
			i++;
	}
	else if (dir == L_DIR)
	{
		while (i && (content[j][i] == '0' || is_player(content[j][i])))
			i--;
	}
	if (content[j][i] != '1')
		return (0);
	return (1);
}

int	is_map_closed(char **content, int start)
{
	int	i;
	int	j;

	j = start;
	while (content[j])
	{
		i = 0;
		while (content[j][i])
		{
			if (content[j][i] == '0' || is_player(content[j][i]))
			{
				if (!check_wall(content, i, j, TOP_DIR, start)
					|| !check_wall(content, i , j, BTM_DIR, start)
					|| !check_wall(content, i, j, R_DIR, start)
					|| !check_wall(content, i, j, L_DIR, start))
					return (-1);
				}
				i++;
		}
		j++;
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
			return (ft_error("Map error: invalid element in or after the map"), -1);
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
