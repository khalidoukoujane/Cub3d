/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/05/20 16:30:39 by ioulkhir         ###   ########.fr       */
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

# define TOP_DIR 0
# define BTM_DIR 1
# define R_DIR 2
# define L_DIR 3


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
int		is_newline(char *line);
#endif