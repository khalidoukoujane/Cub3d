/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/19 09:28:12 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*ptr;
	void	*px_buffer;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		result;
}				t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	position;
	double		angle;
}				t_player;

typedef struct s_local_vars
{
	int			no_t;
	int			so_t;
	int			we_t;
	int			ea_t;
	int			f_color;
	int			c_color;
}				t_local_vars;

typedef struct s_animation
{
	t_img	frames[8];
	t_img	scaled_frm;
	int		frame_counter;
	int		speed;
	int		curr_frame;
	int		win_w;
	int		win_h;
	int		frame_timer;
}			t_animation;

typedef struct s_parsed
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**file_content;
	char		**map;
	t_vector	map_dimension;
	t_vector	player_pos;
	double		angle;
}				t_parsed;

typedef struct s_tex
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
}				t_tex;

typedef struct s_status	t_status;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_parsed	*data;
	t_img		img;
	t_animation	anim;
	t_player	player;
	t_tex		textures[4];
	t_status	*status;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
	int			key_up;
	int			key_down;
	int			mouse_down;
	int			view;
}				t_vars;

typedef struct s_status
{
	int			sucesses;
	int			fail;
	char		*err_msg;
	t_vars		*vars;
}				t_status;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
	double		tangente;
	t_vector	step;
	t_vector	map;
	t_vector	map_unit;
	t_vector	side_dist;
	double		distance;
	int			hit;
	int			side;

	int			start;
	int			end;
	int			line_len;
}	t_ray;

typedef struct s_equ
{
	double		a;
	double		b;
}				t_equ;

typedef struct s_lv
{
	int	i;
	int	j;
}		t_lv;

typedef struct s_ani_vars
{
	double				s_x;
	double				s_y;
	int					src_w;
	int					src_h;
	int					i;
	int					j;
	unsigned int		color;
}			t_lcl_anim;

#endif