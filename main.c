# include "cub.h"

int	main(int ac, char **av)
{
	t_vars  vars;

	vars.data = malloc(sizeof(t_parsed));
	if (!vars.data)
		return (ft_error("faild to allocate"), 1);
	// if (!ft_parser(ac, av, &vars.data))
	// 	return (1);
	(void)ac;
	(void)av;
	char *map[] = {
		"11111111111111111",
		"10000000000000001",
		"10000000001000001",
		"10000000000000001",
		"10000000000000001",
		"10000000000010001",
		"10000000000010001",
		"10000001000000001",
		"10000010000000001",
		"10000100000010001",
		"10000000000010001",
		"10000000000010001",
		"10000000000010001",
		"11111111111111111",
	};
	vars.data->map = map;
	vars.player.position.x = 7;
	vars.player.position.y = 6;
	vars.player.angle = 2;
	vars.data->ea_texture = "texture/east_texture.xpm";
	vars.data->no_texture = "texture/north_texture.xpm";
	vars.data->so_texture = "texture/south_texture.xpm";
	vars.data->we_texture = "texture/west_texture.xpm";
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
