/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 09:22:54 by khoukouj          #+#    #+#             */
/*   Updated: 2025-06-12 09:22:54 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_char_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && is_char_sep(str[i], sep))
			i++;
		if (str[i] && !is_char_sep(str[i], sep))
		{
			word++;
			while (str[i] && !is_char_sep(str[i], sep))
				i++;
		}
	}
	return (word);
}

char	*append_words(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_char_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !is_char_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**free_ptr(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_spliter(char *str, char *charset)
{
	int		i;
	char	**split;

	if (!str)
		return (NULL);
	i = 0;
	split = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (NULL == split)
		return (NULL);
	while (*str)
	{
		while (*str && is_char_sep(*str, charset))
			str++;
		if (*str && !is_char_sep(*str, charset))
		{
			split[i] = append_words(str, charset);
			if (split[i] == NULL)
				return (free_ptr(split, i));
			while (*str && !is_char_sep(*str, charset))
				str++;
			i++;
		}
	}
	split[i] = 0;
	return (split);
}
