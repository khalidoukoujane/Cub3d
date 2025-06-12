# include "cub.h"

int	main(int ac, char **av)
{
	t_vars  vars;

	vars.data = malloc(sizeof(t_parsed));
	if (!vars.data)
		return (ft_error("faild to allocate"), 1);
	if (!ft_parser(ac, av, &vars.data))
		return (1);
	// init
	init_program(&vars);
	// render
	render(&vars);
	// hook
	mlx_loop(vars.mlx);
	// cleanup
	return (EXIT_SUCCESS);
}
