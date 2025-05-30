/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-25 15:56:25 by khoukouj          #+#    #+#             */
/*   Updated: 2025-05-25 15:56:25 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_error(char *arg)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(arg, 2);
	ft_putstr_fd(RESET, 2);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

int	is_in_set(char c)
{
	return (c == 'N' || c == 'W' || c == 'S'
		|| c == 'E' || c == '0'
		|| c == '1' || c == ' ' || c == '\n');
}

int valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_in_set(line[i]))
			return (0);
		i++;
	}
	return (1);
}
