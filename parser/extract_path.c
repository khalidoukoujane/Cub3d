/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:01:09 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/20 11:01:26 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_grep_path(char *line)
{
	char	*path_start;
	char	*path;
	int		len;
	int		i;

	path_start = line;
	while (*path_start && !(*path_start == ' ' || *path_start == '\t'))
		path_start++;
	while (*path_start && (*path_start == ' ' || *path_start == '\t'))
		path_start++;
	len = ft_strlen(path_start);
	if (len > 0 && path_start[len - 1] == '\n')
		len--;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	i = 0;
	while (i < len)
	{
		path[i] = path_start[i];
		i++;
	}
	return (path[len] = '\0', path);
}
