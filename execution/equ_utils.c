/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equ_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:19:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/25 14:00:50 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_equ	linear_equ(t_ray ray)
{
	t_equ  equ;

	equ.a = ray.tangente;
	equ.b = ray.origin.y - ray.origin.x * equ.a;
	return (equ);
}

double	solve_equs(t_equ equ, t_ray ray)
{
	double	result;

	if (ray.side == 0)
		result = equ.a * (ray.map.x + (ray.map_unit.x < 0)) + equ.b;
	else
		result = (ray.map.y + (ray.map_unit.y < 0) - equ.b) / equ.a;
	return (result);
}
