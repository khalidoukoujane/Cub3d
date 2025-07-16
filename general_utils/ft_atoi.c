/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:44:15 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/16 10:18:49 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_limits(unsigned long result, int sign)
{
	if ((result * sign > (unsigned long)INT_MAX)
		|| (result * sign < (unsigned long)INT_MIN))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			break ;
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (check_limits(result, sign) == -1)
		return (-1);
	return (result * sign);
}
