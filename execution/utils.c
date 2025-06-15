#include "../cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->px_buffer + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
