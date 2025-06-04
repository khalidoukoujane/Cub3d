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

int	check_wall(char **content, int row, int col, int dir)
{
	if (dir == TOP_DIR)
	{
		while (col && (content[row][col] == '0' || is_player(content[row][col])))
			col--;
	}
	else if (dir == BTM_DIR)
	{
		while (content[row] && content[row + 1] && (content[row][col] == '0'
			|| is_player(content[row][col])))
			col++;
	}
	else if (dir == R_DIR)
	{
		while (content[row][col] && (content[row][col] == '0' || is_player(content[row][col])))
			row++;
	}
	else if (dir == L_DIR)
	{
		while (row && (content[row][col] == '0' || is_player(content[row][col])))
			row--;
	}
	if (content[row][col] != '1')
		return (0);
	return (1);
}

int	is_map_closed(char **content, int start)
{
	int	i;
	int	j;

	i = start;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (content[i][j] == '0' || is_player(content[i][j]))
			{
				if (!check_wall(content, i, j, TOP_DIR)
					|| !check_wall(content, i , j, BTM_DIR)
					|| !check_wall(content, i, j, R_DIR)
					|| !check_wall(content, i, j, L_DIR))
					return (-1);
				}
				j++;
			}
		i++;
	}
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
		return (ft_error("Map error: invalid element in the map"), -1);
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
