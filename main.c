# include "cub.h"

int main(int ac, char **av)
{
    t_vars  vars;

	vars.data = malloc(sizeof(t_parsed));
	if (!vars.data)
		return (ft_error("faild to allocate"), 1);
	if (!ft_parser(ac, av, &vars.data))
		return (1);
	while (1)
	{
		printf("%s\n", get_next_line(0));
	}
	printf("h");
    // parsing
    // init
    // render
    // hook
    // cleanup
    return (EXIT_SUCCESS);
}
