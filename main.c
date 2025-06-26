# include "cub.h"

int	main(int ac, char **av)
{
	t_vars		vars;
	t_parsed	data;
	t_status	status;

	vars.data = &data;
	vars.status = &status;
	if (!ft_parser(ac, av, &vars.data))
		return (1);
	// init
	init_program(&vars);
	// render
	render(&vars);
	// hook
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, handle_mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 0, handle_mouse_up, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, handle_mouse_move, &vars);
	mlx_loop(vars.mlx);
	// cleanup
	return (EXIT_SUCCESS);
}
