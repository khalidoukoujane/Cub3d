#include "../cub.h"


static void	move_player(t_vars *vars, double speed, double new_pos)
{
	vars->player.position.x += speed * cos(new_pos);
	vars->player.position.x -= collision(vars) * speed * cos(new_pos);
	vars->player.position.y += speed * sin(new_pos);
	vars->player.position.y -= collision(vars) * speed * sin(new_pos);
	render(vars);
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
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		vars->status->fail = 314;
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
	return (0);
}

int game_loop(t_vars *vars)
{
    double speed = 0.05;
    double new_pos = 0;

    if (vars->key_left)
    {
        vars->player.angle -= 0.05;
        render(vars);
    }
    if (vars->key_right)
    {
        vars->player.angle += 0.05;
        render(vars);
    }

    if (vars->key_w)
    {
        new_pos = vars->player.angle;
        move_player(vars, speed, new_pos);
    }
    if (vars->key_s)
    {
        new_pos = vars->player.angle + PI;
        move_player(vars, speed, new_pos);
    }
    if (vars->key_d)
    {
        new_pos = vars->player.angle + PI / 2;
        move_player(vars, speed, new_pos);
    }
    if (vars->key_a)
    {
        new_pos = vars->player.angle + PI / 2 + PI;
        move_player(vars, speed, new_pos);
    }
    return (0);
}
