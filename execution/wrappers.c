#include "../cub.h"

void	*ft_mlx_init(t_status *status)
{
	void	*result;

	result = mlx_init();
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
	status->err_msg = ft_strdup(err_msg1);
    failure_detect(*status);
	return (result);
}

void	*ft_mlx_new_window(t_status *status)
{
	void	*result;

	result = mlx_new_window(status->vars->mlx, WIDTH, HEIGHT, "Cub trwadi");
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
	status->err_msg = ft_strdup(err_msg2);
    failure_detect(*status);
	return (result);
}

void	*ft_mlx_new_image(t_status *status)
{
	void	*result;

	result = mlx_new_image(status->vars->mlx, WIDTH, HEIGHT);
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
	status->err_msg = ft_strdup(err_msg3);
    failure_detect(*status);
	return (result);
}

void	*ft_mlx_xpm_file_to_image(t_status *status, char *filename, t_tex *tex)
{
	void	*result;

	result = mlx_xpm_file_to_image(status->vars->mlx, filename, &tex->width, &tex->height);
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
	status->err_msg = ft_strjoin(filename, ": Failed to load texture");
    failure_detect(*status);
	tex->ptr = result;
	return (result);
}
