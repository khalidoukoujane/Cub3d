#include "../cub.h"

void	failure_detect(t_status status)
{
	if (!status.fail)
		return ;
	if (status.sucesses-- != 0)
		mlx_destroy_image(status.vars->mlx, status.vars->img.ptr);
	if (status.sucesses-- != 0)
		mlx_destroy_window(status.vars->mlx, status.vars->win);
	if (status.sucesses-- != 0)
		mlx_destroy_display(status.vars->mlx);
		// free
}

void	init_program(t_vars *vars)
{
	t_status	status;

	status.fail = 0;
	status.sucesses = 0;
	status.vars = vars;
	vars->mlx = ft_mlx_init(&status);
	vars->win = ft_mlx_new_window(&status);
	vars->img.ptr = ft_mlx_new_image(&status);
}
