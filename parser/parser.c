/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-24 13:35:34 by khoukouj          #+#    #+#             */
/*   Updated: 2025-05-24 13:35:34 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_dot_cub(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (i == 0)
		return (0);
	if (!ft_strcmp(&str[i], ".cub"))
		return (1);
	return (0);
}

int	ft_parser(int ac, char **av, t_parsed **data)
{
	if (ac != 2)
		return (ft_error("Invalid number of arguments"), 0);
	if (!check_dot_cub(av[1]))
		return (ft_error("Invalid or missing file extension"), 0);
	return (1);
}
