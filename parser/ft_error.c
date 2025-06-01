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

int	is_surrounded(char **content, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(content[i]);
	while (content[i][j])
	{
		if (is_player(content[i][j]))
		{
			if (i == 0 || content[i - 1][j] == ' ')
				return (0);
			if (!content[i + 1] || content[i + 1][j] == ' ')
				return (0);
			if (j == 0 || content[i][j - 1] == ' ')
				return (0);
			if (j == len - 1 || content[i][j + 1] == ' ')
				return (0);
		}
		j++;
	}
	return (1);
}
