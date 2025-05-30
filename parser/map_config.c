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

int	check_map(char **content, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (content[i])
	{
		if (ft_strchr(content[i], "\t"))
			return (ft_error("Map error: found tab"), -1);
		count += count_player(content[i]);
		
	}
}
