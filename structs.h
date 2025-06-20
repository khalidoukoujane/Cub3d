/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/06/15 18:00:24 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIDTH 1024
# define HEIGHT 900

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void	*ptr;
	void	*px_buffer;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
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

typedef	struct s_local_vars
{
	int	no_t;
    int	so_t;
    int	we_t;
    int	ea_t;
	int	f_color;
    int	c_color;
}		t_local_vars;

typedef struct s_parsed
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**file_content;
	char	**map;
}				t_parsed;

typedef struct s_tex
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
}				t_tex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_parsed	*data;
	t_img		img;
	t_player	player;
	t_tex		textures[4];
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
	t_vector	step;
	t_vector	map;
	t_vector	map_unit;
	t_vector	side_dist;
	double		distance;
	int			hit;
	int			side;

	int			start;
	int			end;
}	t_ray;

#endif