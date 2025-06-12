# include "cub.h"

int	main(int ac, char **av)
{
	t_vars  vars;

	if (!ft_parser(ac, av, &vars.data))
		return (1);
	// init
	init_program(&vars);
	// render
	// hook
	// cleanup
	return (EXIT_SUCCESS);
}
