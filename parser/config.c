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

static int check_textures(char **content, int *i)
{
    int no_t;
    int so_t;
    int we_t;
    int ea_t;

    1 && (no_t = 0, so_t = 0, we_t = 0, ea_t = 0);
    while (content[*i])
    {
        if (!ft_strncmp(content[*i], "SO ", 3))
            so_t++;
        else if (!ft_strncmp(content[*i], "NO ", 3))
            no_t++;
        else if (!ft_strncmp(content[*i], "WE ", 3))
            we_t++;
        else if (!ft_strncmp(content[*i], "EA ", 3))
            ea_t++;
        else
            break;
        (*i)++;
    }
    if ((no_t + so_t + we_t + ea_t) != 4)
        return (ft_error("Error: Invalid or incomplete texture definitions"), -1);
    if (*i == 0)
        return (ft_error("Error: Configuration file is empty."), -1);
    return (0);
}

static int check_colors(char **content, int *i)
{
    int f_color;
    int c_color;

    f_color = 0;
    c_color = 0;
    while (content[*i])
    {
        if (!ft_strncmp(content[*i], "F ", 2))
            f_color++;
        else if (!ft_strncmp(content[*i], "C ", 2))
            c_color++;
        else
            break;
        (*i)++;
    }
    if (f_color + c_color != 2)
        return (ft_error("colors error"), -1);
    return (0);
}

static void    skip_newlines(char **content, int *i)
{
    while (content[*i] && !ft_strcmp(content[*i], "\n"))
        (*i)++;
}

int check_config(char  **content)
{
    int i;

    i = 0;
    if (check_textures(content, &i) == -1)
        return (-1);
    skip_newlines(content, &i);
    if (check_colors(content, &i) == -1)
    return (-1);
    skip_newlines(content, &i);
    if (!content[i])
        return (ft_error("Map is messing"), -1);
}
