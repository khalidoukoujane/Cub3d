/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/06/07 17:57:36 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIDTH 800
# define HEIGHT 600

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

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_parsed	*data;
	t_img		img;
	t_player	player;
}				t_vars;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_vector	step;
	t_vector	map;
	int			hit;
	int			side;
}	t_ray;

#endif