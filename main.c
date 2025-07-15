/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:28 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/07/15 10:44:05 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_vars		vars;
	t_parsed	data;
	t_status	status;

	vars.data = &data;
	vars.status = &status;
	if (!ft_parser(ac, av, &vars.data))
		return (free_data(&vars), EXIT_FAILURE);
	init_program(&vars);
	render(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, handle_mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 0, handle_mouse_up, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, handle_mouse_move, &vars);
	mlx_loop_hook(vars.mlx, game_loop, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
