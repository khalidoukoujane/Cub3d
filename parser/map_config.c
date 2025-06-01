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
	if (count == 0)
		return (ft_error("Map error: Player error"), -1);
	return (0);
}
