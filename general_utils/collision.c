/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:45:45 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/25 19:46:45 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	collision(t_vars *vars)
{
	int	x;
	int	y;

	x = (int)vars->player.position.x;
	y = (int)vars->player.position.y;
	return (vars->data->map[x][y] == '1');
}
