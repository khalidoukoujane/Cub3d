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

int	get_content_len(char *file)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count += (free(line), 1);
		line = get_next_line(fd);
	}
	return (close(fd), count);
}

char	**get_file_content(char *filename)
{
	int		fd;
	int		l;
	int		i;
	char	**content;

	i = 0;
	l = get_content_len(filename);
	if (l == -1)
		return (ft_error("Open: file doesn't exist"), NULL);
	content = malloc(sizeof(char *) * (l + 1));
	if (!content)
		return (NULL);
	fd = open(filename, O_RDONLY);
	content[i] = get_next_line(fd);
	while (i < l && content[i])
	{
		i++;
		content[i] = get_next_line(fd);
	}
	content[i] = NULL;
	return (close(fd), content);
}

int	ft_parser(int ac, char **av, t_parsed **data)
{
	if (ac != 2)
		return (ft_error("Invalid number of arguments"), 0);
	if (!check_dot_cub(av[1]))
		return (ft_error("Invalid or missing file extension"), 0);
	(*data)->file_content = get_file_content(av[1]);
	if (!(*data)->file_content)
		return (0);
	if (check_config((*data)->file_content) == -1)
		return (0);
	return (1);
}
