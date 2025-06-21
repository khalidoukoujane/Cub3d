#include "../cub.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = param;
	if (keycode == RIGHT)
		vars->player.angle += 0.1;
	else if (keycode == LEFT)
		vars->player.angle -= 0.1;
	else if (keycode == D)
	{
		vars->player.position.x += 0.2 / cos(vars->player.angle);
		vars->player.position.y -= 0.2 / sin(vars->player.angle);
	}
	else if (keycode == A)
	{
		vars->player.position.x -= 0.2 / cos(vars->player.angle);
		vars->player.position.y += 0.2 / sin(vars->player.angle);
	}
	else if (keycode == W)
	{
		vars->player.position.x += 0.2 / cos(vars->player.angle);
		vars->player.position.y += 0.2 / sin(vars->player.angle);
	}
	else if (keycode == S)
	{
		vars->player.position.x -= 0.2 / cos(vars->player.angle);
		vars->player.position.y -= 0.2 / sin(vars->player.angle);
	}
	render(vars);
	return (0);
}
