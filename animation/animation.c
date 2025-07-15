/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:53:30 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/15 16:04:01 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	setup_animation(t_vars *v)
{
	v->anim.win_w = WIDTH;
	v->anim.win_h = HEIGHT;
	ft_load_frames(v);
	setup_scaled_frame(v);
	v->anim.frame_timer = 0;
	v->anim.curr_frame = 0;
}

void	scale_frame_to_window(t_vars *v, t_img *frame, t_img *s_frame)
{
	t_lcl_anim	it;

	it.s_x = (double)frame->w / v->anim.win_w;
	it.s_y = (double)frame->h / v->anim.win_h;
	it.i = 0;
	while (it.i < v->anim.win_h)
	{
		it.j = 0;
		while (it.j < v->anim.win_w)
		{
			it.src_w = (int)(it.j * it.s_x);
			it.src_h = (int)(it.i * it.s_y);
			it.color = ft_get_color(frame, it.src_w, it.src_h);
			my_mlx_pixel_put(s_frame, it.j, it.i, it.color);
			it.j++;	
		}
		it.i++;
	}
}

void	animation(t_vars *v)
{
	v->anim.frame_timer++;
	if (v->anim.frame_timer >= v->anim.speed)
	{
		v->anim.frame_timer = 0;
		v->anim.curr_frame = (v->anim.curr_frame + 1) % v->anim.frame_counter;
	}
	scale_frame_to_window(v, &v->anim.frames[v->anim.curr_frame], &v->anim.scaled_frm);
	mlx_put_image_to_window(v->mlx, v->win, v->anim.scaled_frm.ptr, 0, 0);
}
