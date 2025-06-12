#include "../cub.h"

void	*ft_mlx_init(t_status *status)
{
	void	*result;

	result = mlx_init();
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
    failure_detect(*status);
	return (result);
}

void	*ft_mlx_new_window(t_status *status)
{
	void	*result;

	result = mlx_new_window(status->vars->mlx, WIDTH, HEIGHT, "Cub trwadi");
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
    failure_detect(*status);
	return (result);
}

void	*ft_mlx_new_image(t_status *status)
{
	void	*result;

	result = mlx_new_image(status->vars->mlx, WIDTH, HEIGHT);
	status->fail |= result == NULL;
	status->sucesses += result != NULL;
    failure_detect(*status);
	return (result);
}
