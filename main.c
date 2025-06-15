# include "cub.h"

int	main(int ac, char **av)
{
	t_vars  vars;

	vars.data = malloc(sizeof(t_parsed));
	if (!vars.data)
		return (ft_error("faild to allocate"), 1);
	// if (!ft_parser(ac, av, &vars.data))
	// 	return (1);
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
	vars.data->ea_texture = "wall.xpm";
	vars.data->no_texture = "wall.xpm";
	vars.data->so_texture = "wall.xpm";
	vars.data->we_texture = "wall.xpm";
	// init
	init_program(&vars);
	// render
	render(&vars);
	// hook
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	// cleanup
	return (EXIT_SUCCESS);
}
