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
	if (keycode == RIGHT)
		(vars->player.angle += 0.1, speed = 0);
	else if (keycode == LEFT)
		(vars->player.angle -= 0.1, speed = 0);
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
