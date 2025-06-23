/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:22:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/06/23 09:48:41 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->px_buffer + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

double	decimal_part(double num)
{
	return (fabs(num) - (int)fabs(num));
}

double	zero_protect(double x)
{
	double	anything;

	anything = 314;
	if (x == 0)
		return (anything);
	return (x);
}
