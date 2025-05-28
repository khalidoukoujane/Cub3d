/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/05/27 13:07:24 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIDTH
# define HEIGHT

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

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_player
{
	t_coord		position;
	double		angle;
}				t_player;

typedef struct s_parsed
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**file_content;
}				t_parsed;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_parsed	*data;
	t_img		img;
	t_player	player;
}				t_vars;

#endif