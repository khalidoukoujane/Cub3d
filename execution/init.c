#include "../cub.h"

	// vars->mlx = ft_mlx_init(&status);
	// ft_mlx_xpm_file_to_image(&status, vars->data->ea_texture, &vars->textures[0]);
	// ft_mlx_xpm_file_to_image(&status, vars->data->no_texture, &vars->textures[1]);
	// ft_mlx_xpm_file_to_image(&status, vars->data->so_texture, &vars->textures[2]);
	// ft_mlx_xpm_file_to_image(&status, vars->data->we_texture, &vars->textures[3]);
	// vars->win = ft_mlx_new_window(&status);
	// vars->img.ptr = ft_mlx_new_image(&status);
void	failure_detect(t_status status)
{
	if (!status.fail)
		return ;
	if (status.sucesses-- == 7)
		mlx_destroy_image(status.vars->mlx, status.vars->img.ptr);
	if (status.sucesses-- == 6)
		mlx_destroy_window(status.vars->mlx, status.vars->win);
	if (status.sucesses-- == 5)
		while (status.sucesses-- > 2)
			mlx_destroy_image(status.vars->mlx, status.vars->textures[status.sucesses - 1].ptr);
	if (status.sucesses-- == 1)
		mlx_destroy_display(status.vars->mlx);
		// or free, i dont know
	ft_error(status.err_msg);
	free(status.err_msg);
	status.err_msg = NULL;
	exit(EXIT_FAILURE);
}

void	init_program(t_vars *vars)
{
	t_status	status;

	status.fail = 0;
	status.sucesses = 0;
	status.vars = vars;
	vars->mlx = ft_mlx_init(&status);
	ft_mlx_xpm_file_to_image(&status, vars->data->ea_texture, &vars->textures[0]);
	ft_mlx_xpm_file_to_image(&status, vars->data->no_texture, &vars->textures[1]);
	ft_mlx_xpm_file_to_image(&status, vars->data->so_texture, &vars->textures[2]);
	ft_mlx_xpm_file_to_image(&status, vars->data->we_texture, &vars->textures[3]);
	vars->win = ft_mlx_new_window(&status);
	vars->img.ptr = ft_mlx_new_image(&status);
}
