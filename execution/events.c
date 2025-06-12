#include "../cub.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = param;
	printf("%d\n", keycode == RIGHT);
	if (keycode == RIGHT)
		vars->player.angle += 10;
	render(vars);
	return (0);
}
