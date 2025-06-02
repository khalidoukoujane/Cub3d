/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-02 12:12:22 by khoukouj          #+#    #+#             */
/*   Updated: 2025-06-02 12:12:22 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_texture_line(char *line)
{
	return (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3));
}

int	is_color_line(char *line)
{
	return (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2));
}

int	is_config_line(char *line)
{
	return (is_texture_line(line) || is_color_line(line));
}

int	is_newline(char *line)
{
	return (!ft_strcmp(line, "\n"));
}
