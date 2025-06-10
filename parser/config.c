/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-29 03:12:33 by khoukouj          #+#    #+#             */
/*   Updated: 2025-05-29 03:12:33 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	do_checks(char **content, int *i, t_local_vars *v)
{
	if (!ft_strncmp(content[*i], "SO ", 3))
		v->so_t++;
	else if (!ft_strncmp(content[*i], "NO ", 3))
		v->no_t++;
	else if(!ft_strncmp(content[*i], "WE ", 3))
		v->we_t++;
	else if (!ft_strncmp (content[*i], "EA ", 3))
		v->ea_t++;
	else if (!ft_strncmp(content[*i], "F ", 2))
		v->f_color++;
	else if (!ft_strncmp(content[*i], "C ", 2))
		v->c_color++;
	(*i)++;
}
void	init_local_vars(t_local_vars *vars)
{
	vars->c_color = 0;
	vars->f_color = 0;
	vars->ea_t = 0;
	vars->no_t = 0;
	vars->so_t = 0;
	vars->we_t = 0;
}

static int check_textures_n_colors(char **content, int *i)
{
	t_local_vars	v;

	init_local_vars(&v);
	while (content[*i] && (is_config_line(content[*i])
		|| is_only_whitespace(content[*i])))
	{
		if (is_config_line(content[*i]))
			do_checks(content, i, &v);
		else if (is_only_whitespace(content[*i]))
			(*i)++;
	}
	if (v.ea_t > 1 || v.so_t > 1 || v.no_t > 1 || v.we_t > 1)
		return (ft_error("duplicated textures"), -1);
	if (v.ea_t + v.no_t + v.so_t + v.we_t != 4)
		return (ft_error("textures error"), -1);
	if (v.c_color + v.f_color != 2)
		return (ft_error("colors error"), -1);
	return (0);
}

static void    skip_newlines(char **content, int *i)
{
    while (content[*i] && is_only_whitespace(content[*i]))
        (*i)++;
}

int check_config(char  **content)
{
    int i;

    i = 0;
    skip_newlines(content, &i);
    if (check_textures_n_colors(content, &i) == -1)
        return (-1);
    skip_newlines(content, &i);
    if (!content[i])
        return (ft_error("Map is missing"), -1);
	if (check_map(content, i) == -1)
		return (-1);
	return (0);
}
