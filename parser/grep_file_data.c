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

static int	get_textures(t_parsed **data, char **file, int *i)
{
	char	**splited;

	while (file[*i])
	{
	}
}

int	grep_data(t_parsed **data)
{
	int	i;
	char	**file;

	i = 0;
	file = (*data)->file_content;
	skip_newlines(file, &i);
	if (get_textures(data, file, &i) == -1)
		return (-1);
	
}
