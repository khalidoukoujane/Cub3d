# include "cub.h"

int	main(int ac, char **av)
{
	t_vars  vars;

	vars.data = malloc(sizeof(t_parsed));
	if (!vars.data)
		return (ft_error("faild to allocate"), 1);
	if (!ft_parser(ac, av, &vars.data))
		return (1);
	// char *map[] = {
	// 	"10000000000000001",
	// 	"10000000001000001",
	// 	"10000000000000001",
	// 	"10000000000000001",
	// 	"10000000000010001",
	// };
	// vars.data->map = map;
	// vars.player.position.x = 1;
	// vars.player.position.y = 2;
	// init
	init_program(&vars);
	// render
	render(&vars);
	// hook
	mlx_loop(vars.mlx);
	// cleanup
	return (EXIT_SUCCESS);
}
