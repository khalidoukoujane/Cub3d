/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:19:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/15 13:59:22 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	handle_close(t_vars *vars)
{
	vars->status->fail = 314;
	failure_detect(*vars->status);
	return (0);
}

int	handle_mouse_down(int button, int x, int y, void *param)
{
	t_vars	*vars;

	(void)button;
	(void)x;
	(void)y;
	vars = param;
	vars->mouse_down = 1;
	return (0);
}

int	handle_mouse_up(int button, int x, int y, void *param)
{
	t_vars	*vars;

	(void)button;
	(void)x;
	(void)y;
	vars = param;
	vars->mouse_down = 0;
	return (0);
}

int	handle_mouse_move(int x, int y, void *param)
{
	t_vars		*vars;
	static int	first_x = -1;
	double		dx;
	double		speed;

	(void)y;
	speed = 0.01;
	vars = param;
	if (!vars->mouse_down)
		return (first_x = -1, 1);
	first_x = x * (first_x == -1) + first_x * (first_x != -1);
	dx = x - first_x;
	vars->player.angle += speed * radian(dx / WIDTH * 360);
	render(vars);
	return (0);
}
