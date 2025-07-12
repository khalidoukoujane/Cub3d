/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 14:48:10 by khoukouj          #+#    #+#             */
/*   Updated: 2025-07-12 14:48:10 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_data(t_parsed **data)
{
	(*data)->no_texture = NULL;
	(*data)->so_texture = NULL;
	(*data)->we_texture = NULL;
	(*data)->ea_texture = NULL;
	(*data)->map = NULL;
	(*data)->file_content = NULL;
}

static void	clear_dptrs(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_data(t_vars *ptr)
{
	free((ptr)->data->no_texture);
	free((ptr)->data->so_texture);
	free((ptr)->data->we_texture);
	free((ptr)->data->ea_texture);
	clear_dptrs((ptr)->data->file_content);
	clear_dptrs((ptr)->data->map);
}
