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

static int	fill_data(t_parsed **info, char **data, char *line)
{
	if (!data || !*data)
		return (-1);
	if (!ft_strcmp(data[0], "NO"))
		(*info)->no_texture = ft_strdup(data[1]);
	else if (!ft_strcmp(data[0], "SO"))
		(*info)->so_texture = ft_strdup(data[1]);
	else if (!ft_strcmp(data[0], "WE"))
		(*info)->we_texture = ft_strdup(data[1]);
	else if (!ft_strcmp(data[0], "EA"))
		(*info)->ea_texture = ft_strdup(data[1]);
	else if (!ft_strcmp(data[0], "F"))
		fill_colors(data + 1, &(*info)->floor_color);
	else if (!ft_strcmp(data[0], "C"))
		fill_colors(data + 1, &(*info)->ceiling_color);
	return (0);
}

int	put_data(t_parsed **info, char *line, int* i)
{
	char	**data;

	if (is_texture_line(line))
		data = ft_spliter(line, " \t\n");
	else
		data = ft_spliter(line, " \t,\n");
	if (!data || !*data)
		return (-1);
	if (is_texture_line(line) && count_splited(data) != 2)
		return (ft_error("invalid textures"), -1);
	else if (is_color_line(line) && count_splited(data) != 4)
		return (ft_error("invalid colors"), -1);
	if (fill_data(info, data, line) == -1)
		return (-1);
	free_splited(data);
	(*i)++;
	return (0);
}

static int	get_textures_and_colors(t_parsed **data, char **file, int *i)
{
	while (file[*i] && (is_config_line(file[*i]) || is_only_whitespace(file[*i])))
	{
		if (is_config_line(file[*i]))
		{
			if (put_data(data, file[*i], i) == -1)
				return (-1);
		}
		else if (is_only_whitespace(file[*i]))
			(*i)++;
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
