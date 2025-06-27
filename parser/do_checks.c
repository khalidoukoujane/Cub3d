// header goes here

#include "../cub.h"

int	do_colors_checks(t_parsed **data)
{
	if ((*data)->ceiling_color.r < 0 || (*data)->ceiling_color.r > 255)
		return (-1);
	else if ((*data)->ceiling_color.g < 0 || (*data)->ceiling_color.g > 255)
		return (-1);
	else if ((*data)->ceiling_color.b < 0 || (*data)->ceiling_color.b > 255)
		return (-1);
	else if ((*data)->floor_color.g < 0 || (*data)->floor_color.g > 255)
		return (-1);
	else if ((*data)->floor_color.b < 0 || (*data)->floor_color.b > 255)
		return (-1);
	else if ((*data)->floor_color.r < 0 || (*data)->floor_color.r > 255)
		return (-1);
}

void	ft_close_fds(int *fds)
{
	int	i;

	i = 0;
	while (i < 4)
		close(fds[i++]);
}

int	do_textures_checks(t_parsed **data)
{
	int	fds[4];

	fds[0] = open((*data)->no_texture, O_RDONLY);
	fds[1] = open((*data)->so_texture, O_RDONLY);
	fds[2] = open((*data)->we_texture, O_RDONLY);
	fds[3] = open((*data)->ea_texture, O_RDONLY);
	if (fds[0] < 0 || fds[1] < 0 || fds[2] < 0 || fds[3] < 0)
		return (ft_close_fds(fds), -1);
	return (ft_close_fds(fds), 0);
}

int do_conf_checks(t_parsed **data)
{
	if (do_textures_checks(data) == -1)
		return (ft_error("textures not found"), -1);
	if (do_colors_checks(data) == -1)
		return (ft_error("colors overflow error [0, 255]"), -1);
	return (0);
}
