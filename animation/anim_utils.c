/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:07:44 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/16 09:17:23 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned int	ft_get_color(t_img *img, int x, int y)
{
	char	*src_clr;

	src_clr = img->px_buffer + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)src_clr);
}

void	setup_scaled_frame(t_vars *v)
{
	v->anim.scaled_frm.ptr = mlx_new_image(v->mlx, v->anim.win_w, \
		v->anim.win_h);
	if (!v->anim.scaled_frm.ptr)
		exit(1);
	v->anim.scaled_frm.px_buffer = mlx_get_data_addr(v->anim.scaled_frm.ptr, \
		&v->anim.scaled_frm.bpp, &v->anim.scaled_frm.line_len, \
		&v->anim.scaled_frm.endian);
	v->anim.scaled_frm.w = v->anim.win_w;
	v->anim.scaled_frm.h = v->anim.win_h;
}

static void	clean_up(t_vars *v, int i)
{
	while (--i >= 0)
		mlx_destroy_image(v->mlx, v->anim.frames[i].ptr);
	v->status->fail = 1;
	v->status->err_msg = ft_strdup("memory error");
	mlx_destroy_window(v->mlx, v->win);
	failure_detect(*v->status);
}

void	ft_load_frames(t_vars *v)
{
	char	*frames[7];
	int		i;

	frames[0] = "texture/player_frames/1.xpm";
	frames[1] = "texture/player_frames/2.xpm";
	frames[2] = "texture/player_frames/3.xpm";
	frames[3] = "texture/player_frames/4.xpm";
	frames[4] = "texture/player_frames/5.xpm";
	frames[5] = "texture/player_frames/6.xpm";
	frames[6] = "texture/player_frames/7.xpm";
	i = -1;
	v->anim.frame_counter = 7;
	v->anim.speed = 2;
	v->anim.frame_timer = 0;
	while (++i < v->anim.frame_counter)
	{
		v->anim.frames[i].ptr = mlx_xpm_file_to_image(v->mlx, frames[i], \
							&v->anim.frames[i].w, &v->anim.frames[i].h);
		if (!v->anim.frames[i].ptr)
			clean_up(v, i);
		v->anim.frames[i].px_buffer = mlx_get_data_addr(v->anim.frames[i].ptr, \
					&v->anim.frames[i].bpp, \
					&v->anim.frames[i].line_len, &v->anim.frames[i].endian);
	}
}
