#include "../cub.h"

// void	draw_line(t_vars *vars, int x, t_ray ray)
// {
// 	int		start;
// 	int		end;
// 	int		length;

// 	length = HEIGHT / ray.distance;
// 	if (length > HEIGHT) length = HEIGHT;
// 	start = (HEIGHT - length) / 2;
// 	end = HEIGHT - start;
// 	while (start < end)
// 	{
// 		// color is f(side)
// 		mlx_pixel_put(vars->mlx, vars->win, x, start, 0xFFFFFF);
// 		start++;
// 	}
// }

// void	render(t_vars *vars)
// {
// 	t_ray		ray;
// 	int			x;

// 	x = 0;
// 	while (x < HEIGHT)
// 	{
// 		ray_init(&ray, vars->player.position, vars->player.angle + (x / HEIGHT * 360));
// 		ray_cast(vars, &ray);
// 		draw_line(vars, x, ray);
// 		x++;
// 	}
// }



#include "../cub.h"
#include <math.h>

#define FOV 0.66

int	get_wall_color(int side, int y, int wall_height, int tex_width, int tex_height, int *wall_data)
{
	int tex_y;
	int color;
	

	// Map screen y to texture y
	tex_y = (y * tex_height) / wall_height;

	// Clamp to texture height
	if (tex_y < 0) tex_y = 0;
	if (tex_y >= tex_height) tex_y = tex_height - 1;

	// Sample vertical column (assuming 1D texture for simplification)
	color = wall_data[tex_y * tex_width];  // assuming column x = 0

	if (side == 1)
		color = (color >> 1) & 0x7F7F7F; // darken for shading

	return color;
}

void draw_line(t_vars *vars, int x, t_ray ray, int tex_width, int tex_height, int *wall_data)
{
    int start;
    int end;
    int length;
    int color;

    length = HEIGHT / ray.distance;
    if (length > HEIGHT)
        length = HEIGHT;
    start = (HEIGHT - length) / 2;
    end = start + length;



    while (start < end)
    {
        color = get_wall_color(ray.side, start, length, tex_width, tex_height, wall_data);
        mlx_pixel_put(vars->mlx, vars->win, x, start, color);
        start++;
    }
}

void render(t_vars *vars)
{
    t_ray ray;
    int x;




	int			*wall_data;
	void		*wall_img;
	int			bpp, size_line, endian;
	int			tex_width, tex_height;

	wall_img = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &tex_width, &tex_height);
	if (wall_img == NULL)
		exit(1);
	wall_data = (int *)mlx_get_data_addr(wall_img, &bpp, &size_line, &endian);



    x = 0;
	mlx_clear_window(vars->mlx, vars->win);
    while (x < WIDTH)
    {
        double camera_x = 2 * x / (double)WIDTH - 1; // value from -1 to 1
        double ray_angle = vars->player.angle + atan(camera_x * FOV); // perspective correction
        ray_init(&ray, vars->player.position, ray_angle);
        ray_cast(vars, &ray);
        draw_line(vars, x, ray, tex_width, tex_height, wall_data);
        x++;
    }
}

