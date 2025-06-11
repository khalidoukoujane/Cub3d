/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_file_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 13:54:47 by khoukouj          #+#    #+#             */
/*   Updated: 2025-06-10 13:54:47 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	count_splited(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	get_textures_and_colors(t_parsed **data, char **file, int *i)
{
	char	**splited;

	if (!file)
		return (-1);
	while (file[*i] && (is_config_line(file[*i]) || is_only_whitespace(file[*i])))
	{
		
	}
	return (0);
}

int	grep_data(t_parsed **data)
{
	int	i;

	i = 0;
	skip_newlines((*data)->file_content, &i);
	if (get_textures_and_colors(data, (*data)->file_content, &i) == -1)
		return (-1);
	return (0);
}
