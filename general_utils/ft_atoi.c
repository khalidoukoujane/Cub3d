/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:44:15 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/22 09:23:29 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_limits(unsigned long result, int sign)
{
	if (sign == 1 && result > (unsigned long)INT_MAX)
		return (-1);
	if (sign == -1 && result > (unsigned long)INT_MAX + 1)
		return (-1);
	return (0);
}

static int	check_ulong(unsigned long result, char s)
{
	if (result > ULONG_MAX / 10
		|| (result == ULONG_MAX / 10
			&& (unsigned long)(s - '0') > ULONG_MAX % 10))
		return (-1);
	return (0);
}

static void	init(unsigned long *r, int *i, int *s)
{
	*r = 0;
	*s = 1;
	*i = 0;
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				i;
	int				sign;

	init(&result, &i, &sign);
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if (check_ulong(result, str[i]) == -1)
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	if (check_limits(result, sign) == -1)
		return (-1);
	return (result * sign);
}
