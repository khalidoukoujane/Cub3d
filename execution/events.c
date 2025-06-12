#include "../cub.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = param;
	printf("%d\n", keycode == RIGHT);
	if (keycode == RIGHT)
		vars->player.angle += 0.1;
	else if (keycode == LEFT)
		vars->player.angle -= 0.1;
	else if (keycode == D)
		vars->player.position.y += 0.5;
	else if (keycode == A)
		vars->player.position.y -= 0.5;
	else if (keycode == W)
		vars->player.position.x += 0.5;
	else if (keycode == S)
		vars->player.position.x -= 0.5;
	render(vars);
	return (0);
}
