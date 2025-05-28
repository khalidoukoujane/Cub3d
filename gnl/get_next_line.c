/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:54:09 by khoukouj          #+#    #+#             */
/*   Updated: 2024/11/21 13:28:40 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *str, int fd)
{
	char	*buff;
	char	*tmp;
	int		b_read;

	b_read = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), NULL);
	while (b_read != 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buff), free(str), NULL);
		buff[b_read] = '\0';
		tmp = ft_strjoin(str, buff);
		if (!tmp)
			return (free(buff), free(str), NULL);
		free(str);
		str = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

static char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_buff(char *str)
{
	int		i;
	char	*new_buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	new_buff = ft_substr(str, i, ft_strlen(str) - i);
	if (!new_buff)
		return (free(str), NULL);
	free(str);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*s_str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0
		|| BUFFER_SIZE >= INT_MAX || read(fd, NULL, 0) == -1)
		return (free(s_str), s_str = NULL);
	if (!ft_strchr(s_str, '\n'))
		s_str = read_line(s_str, fd);
	if (!s_str || *s_str == 0)
		return (free(s_str), s_str = NULL);
	line = extract_line(s_str);
	if (!line)
		return (free(s_str), s_str = NULL);
	s_str = update_buff(s_str);
	return (line);
}
