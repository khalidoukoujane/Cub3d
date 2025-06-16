/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/06/15 18:52:01 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define RED "\033[31m"
# define RESET "\033[0m"

# define err_msg1 "MLX connection failure !"
# define err_msg2 "Window creation failure !"
# define err_msg3 "Image creation failure !"

# include "general_utils/utils.h"
# include "structs.h"
# include "./minilibx-linux/mlx.h"
# include <limits.h>
# include <stdio.h> // need to remove later
# include <fcntl.h>
# include <math.h>

# define TOP_DIR 0
# define BTM_DIR 1
# define R_DIR 2
# define L_DIR 3

# define PI 3.14159265
# define FOV 0.66

void	ft_error(char *arg);
int		ft_parser(int ac, char **av, t_parsed **data);
char	*get_next_line(int fd);
int     check_config(char  **content);
int		check_map(char **content, int start);
int		is_player(char c);
int		valid_line(char *line);
int		is_surrounded(char **content, int i);
int		is_config_line(char *line);
int		is_color_line(char *line);
int		is_texture_line(char *line);
int		is_whitespace(char c);
int		is_only_whitespace(char *str);
void	skip_newlines(char **content, int *i);
int		grep_data(t_parsed **data);
char	**ft_spliter(char *str, char *charset);
void	fill_colors(char **data, t_color *color);

// init
void	failure_detect(t_status status);
void	init_program(t_vars *vars);

// wrappers
void	*ft_mlx_init(t_status *status);
void	*ft_mlx_new_window(t_status *status);
void	*ft_mlx_new_image(t_status *status);
void	*ft_mlx_xpm_file_to_image(t_status *status, char *filename, t_tex *tex);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// small utils

double	decimal_part(double num);
double	zero_protect(double x);

// ray casting
void	ray_init(t_ray *ray, t_vector origin, double theta);
void	ray_cast(t_vars *vars, t_ray *ray);
void	render(t_vars *vars);

// events
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361

# define W 119
# define A 97
# define S 115
# define D 100

int	    key_hook(int keycode, void *param);

#endif