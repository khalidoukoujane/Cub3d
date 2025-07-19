/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:55:56 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/19 12:06:15 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	move_player(t_vars *vars, double speed, double new_pos)
{
	vars->player.position.x += speed * cos(new_pos);
	vars->player.position.x -= collision(vars) * speed * cos(new_pos);
	vars->player.position.y += speed * sin(new_pos);
	vars->player.position.y -= collision(vars) * speed * sin(new_pos);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == W)
		vars->key_w = 1;
	else if (keycode == S)
		vars->key_s = 1;
	else if (keycode == A)
		vars->key_a = 1;
	else if (keycode == D)
		vars->key_d = 1;
	else if (keycode == RIGHT)
		vars->key_right = 1;
	else if (keycode == LEFT)
		vars->key_left = 1;
	else if (keycode == UP)
		vars->key_up = 1;
	else if (keycode == DOWN)
		vars->key_down = 1;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		vars->status->fail = NO_ERR;
	failure_detect(*vars->status);
	if (keycode == W)
		vars->key_w = 0;
	else if (keycode == S)
		vars->key_s = 0;
	else if (keycode == A)
		vars->key_a = 0;
	else if (keycode == D)
		vars->key_d = 0;
	else if (keycode == RIGHT)
		vars->key_right = 0;
	else if (keycode == LEFT)
		vars->key_left = 0;
	else if (keycode == UP)
		vars->key_up = 0;
	else if (keycode == DOWN)
		vars->key_down = 0;
	return (0);
}

int	game_loop(t_vars *vars)
{
	double	speed;

	speed = 0.1;
	if (vars->key_left)
		vars->player.angle -= 0.06;
	if (vars->key_right)
		vars->player.angle += 0.06;
	if (vars->key_up)
		vars->view++;
	if (vars->key_down)
		vars->view -= vars->view >= 2;
	if (vars->key_w)
		move_player(vars, speed, vars->player.angle);
	if (vars->key_s)
		move_player(vars, speed, vars->player.angle + PI);
	if (vars->key_d)
		move_player(vars, speed, vars->player.angle + PI / 2);
	if (vars->key_a)
		move_player(vars, speed, vars->player.angle + PI / 2 + PI);
	render(vars);
	animation(vars);
	return (0);
}
