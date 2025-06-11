/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/06/11 23:01:18 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define RED "\033[31m"
# define RESET "\033[0m"

# include "general_utils/utils.h"
# include "structs.h"
# include <limits.h>
# include <stdio.h> // need to remove later
# include <fcntl.h>
# include <math.h>

# define TOP_DIR 0
# define BTM_DIR 1
# define R_DIR 2
# define L_DIR 3

# define PI 3.14159265

void	ft_error(char *arg);
int		ft_parser(int ac, char **av, t_parsed **data);
char	*get_next_line(int fd);
int     check_config(char  **content);
int		check_map(char **content, int start);
int		is_player(char c);
int		valid_line(char *line);
int		is_surrounded(char **content, int i);
int		is_config_line(char *line);
int		is_color_line(char *line);
int		is_texture_line(char *line);
int		is_whitespace(char c);
int		is_only_whitespace(char *str);
void	skip_newlines(char **content, int *i);
int		grep_data(t_parsed **data);

#endif