# include "cub.h"

int	main(int ac, char **av)
{
	t_vars		vars;
	t_parsed	data;
	t_status	status;

	vars.data = &data;
	vars.status = &status;
	if (!ft_parser(ac, av, &vars.data))
		return (free_data(&vars), EXIT_FAILURE);
	// init
	init_program(&vars);
	// render
	render(&vars);
	// hook

	// new shit
    mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
    mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	
	// mlx_hook(vars.win, ON_MOUSEDOWN, 0, handle_mouse_down, &vars);
	// mlx_hook(vars.win, ON_MOUSEUP, 0, handle_mouse_up, &vars);
	// mlx_hook(vars.win, ON_MOUSEMOVE, 0, handle_mouse_move, &vars);
	
	mlx_hook(vars.win, ON_MOUSEDOWN, 1L << 2, handle_mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 1L << 3, handle_mouse_up, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 1L << 6, handle_mouse_move, &vars);

    mlx_loop_hook(vars.mlx, game_loop, &vars);
	mlx_loop(vars.mlx);
	// cleanup
	return (EXIT_SUCCESS);
}
