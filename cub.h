/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:53 by khoukouj          #+#    #+#             */
/*   Updated: 2025/07/17 11:08:09 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIDTH 1400
# define HEIGHT 900

# define MINI_WIDTH 400
# define MINI_HEIGHT 200

# define RED "\033[31m"
# define RESET "\033[0m"

# define ERR_MSG1 "MLX connection failure !"
# define ERR_MSG2 "Window creation failure !"
# define ERR_MSG3 "Image creation failure !"

# define N_ORIENTED 4.71225 // 3pi/2
# define E_ORIENTED 0
# define S_ORIENTED 1.57075 // pi/2
# define W_ORIENTED PI

# include "general_utils/utils.h"
# include "structs.h"
// # include "./minilibx-linux/mlx.h"
# include <mlx.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h> //need to be removed later

# define MAP_ERR_MSG "Map error: invalid element in or after the map"
# define TOP_DIR 0
# define BTM_DIR 1
# define R_DIR 2
# define L_DIR 3

# define FOV 1.04
// animation 
void			ft_load_frames(t_vars *v);
char			**handle_clr_part(char *line);
unsigned int	ft_get_color(t_img *img, int x, int y);
void			setup_scaled_frame(t_vars *v);
void			setup_animation(t_vars *v);
void			animation(t_vars *v);
void			ft_error(char *arg);
void			init_data(t_parsed **data);
void			free_data(t_vars *ptr);
void			ft_close_fds(int *fds);
int				do_textures_checks(t_parsed **data);
int				copy_map(t_parsed **data, char **content, int i);
int				get_player_pos(t_parsed **data);
int				do_conf_checks(t_parsed **data);
int				is_match_of(char c, char *line);
int				ft_parser(int ac, char **av, t_parsed **data);
char			*get_next_line(int fd);
int				check_config(char **content);
int				check_map(char **content, int start);
int				is_player(char c);
int				valid_line(char *line);
int				is_surrounded(char **content, int i);
int				is_config_line(char *line);
int				is_color_line(char *line);
int				is_texture_line(char *line);
int				is_whitespace(char c);
int				is_only_whitespace(char *str);
void			skip_newlines(char **content, int *i);
int				grep_data(t_parsed **data);
char			**ft_spliter(char *str, char *charset);
void			fill_colors(char **data, t_color *color);
int				free_splited(char **ss);

// init
void			failure_detect(t_status status);
void			init_program(t_vars *vars);

// wrappers
void			*ft_mlx_init(t_status *status);
void			*ft_mlx_new_window(t_status *status);
void			*ft_mlx_new_image(t_status *status);
void			*ft_mlx_xpm_file_to_image(t_status *status,
					char *filename, t_tex *tex);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

// small utils

double			decimal_part(double num);
double			zero_protect(double x);

// ray casting
void			ray_init(t_ray *ray, t_vector origin, double theta);
void			ray_cast(t_vars *vars, t_ray *ray);
double			get_side_vec(t_ray *ray, t_vector vec);
void			render(t_vars *vars);
int				collision(t_vars *vars);

// equations bro !!
t_equ			linear_equ(t_ray ray);
double			solve_equs(t_equ equ, t_ray ray);

// events
// #define ESC   65307   // Escape key
// #define RIGHT 65363   // Right arrow
// #define LEFT  65361   // Left arrow
// #define W     119     // 'w'
// #define A     97      // 'a'
// #define S     115     // 's'
// #define D     100     // 'd'

// events (macOS keycodes)
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_DESTROY	17

int				handle_mouse_down(int button, int x, int y, void *param);
int				handle_mouse_up(int button, int x, int y, void *param);
int				handle_mouse_move(int x, int y, void *param);
int				handle_close(t_vars *vars);

// smooth criminal 
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
int				game_loop(t_vars *vars);
int				get_minimap_color(t_vars *vars, int x, int y);

#endif