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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include "general_utils/utils.h"
# include "structs.h"
# include <limits.h>
#include <stdio.h> // need to remove later 

void	ft_error(char *arg);
int		ft_parser(int ac, char **av, t_parsed **data);
char	*get_next_line(int fd);

#endif