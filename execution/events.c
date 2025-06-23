/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:19:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/23 10:10:16 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	collision(t_vars *vars)
{
	int	x;
	int	y;

	x = (int)vars->player.position.x;
	y = (int)vars->player.position.y;
	return (vars->data->map[x][y] == '1');
}

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;
	double	speed;
	double	new_pos;

	speed = 0.2;
	new_pos = 0;
	vars = param;
	if (keycode == ESC || 1==1)
		vars->status->fail = 314;
	failure_detect(*vars->status);
	if (keycode == RIGHT)
		1 && (vars->player.angle += 0.1, speed = 0);
	else if (keycode == LEFT)
		1 && (vars->player.angle -= 0.1, speed = 0);
	else if (keycode == D)
		new_pos = vars->player.angle + PI / 2;
	else if (keycode == A)
		new_pos = vars->player.angle + PI / 2 + PI;
	else if (keycode == W)
		new_pos = vars->player.angle;
	else if (keycode == S)
		new_pos = vars->player.angle + PI;
	vars->player.position.x += speed * cos(new_pos);
	vars->player.position.x -= collision(vars) * speed * cos(new_pos);
	vars->player.position.y += speed * sin(new_pos);
	vars->player.position.y -= collision(vars) * speed * sin(new_pos);
	render(vars);
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
