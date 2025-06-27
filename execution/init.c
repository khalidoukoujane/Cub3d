/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:16:47 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/27 13:10:30 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	failure_detect(t_status status)
{
	if (!status.fail)
		return ;
	if (status.sucesses-- == 7)
		mlx_destroy_image(status.vars->mlx, status.vars->img.ptr);
	if (status.sucesses-- == 6)
		mlx_destroy_window(status.vars->mlx, status.vars->win);
	if (status.sucesses-- == 5)
	{
		while (status.sucesses-- > 2)
			mlx_destroy_image(status.vars->mlx,
				status.vars->textures[status.sucesses - 1].ptr);
	}
	if (status.sucesses-- == 1)
		free(status.vars->mlx);
	if (status.err_msg && status.fail != 314)
		ft_error(status.err_msg);
	free(status.err_msg);
	status.err_msg = NULL;
	exit(EXIT_FAILURE);
}

void	init_program(t_vars *vars)
{
	vars->status->fail = 0;
	vars->status->sucesses = 0;
	vars->status->err_msg = NULL;
	vars->status->vars = vars;
	vars->mlx = ft_mlx_init(vars->status);
	ft_mlx_xpm_file_to_image(vars->status, vars->data->ea_texture,
		&vars->textures[0]);
	ft_mlx_xpm_file_to_image(vars->status, vars->data->no_texture,
		&vars->textures[1]);
	ft_mlx_xpm_file_to_image(vars->status, vars->data->we_texture,
		&vars->textures[2]);
	ft_mlx_xpm_file_to_image(vars->status, vars->data->so_texture,
		&vars->textures[3]);
	vars->win = ft_mlx_new_window(vars->status);
	vars->img.ptr = ft_mlx_new_image(vars->status);
	vars->img.px_buffer = mlx_get_data_addr(vars->img.ptr, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	vars->mouse_down = 0;
	vars->player.position = vars->data->player_pos;
	vars->player.angle = vars->data->angle;
	vars->player.position.x = 2;
	vars->player.position.y = 2;
	vars->player.angle = W_ORIENTED;
}
