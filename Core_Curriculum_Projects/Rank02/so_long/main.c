/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/14 20:11:26 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	add_shade(double distance, int color)
{
	int	transparency;
	int	red;
	int	green;
	int	blue;

	transparency = get_t(color);
	red = get_r(color);
	green = get_g(color);
	blue = get_b(color);
	red = (int)(red * distance);
	green = (int)(green * distance);
	blue = (int)(blue * distance);
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

int	get_opposite(int color)
{
	int	transparency;
	int	red;
	int	green;
	int	blue;

	transparency = get_t(color);
	red = get_r(color);
	green = get_g(color);
	blue = get_b(color);
	red = (int)(255 - red);
	green = (int)(255 - green);
	blue = (int)(255 - blue);
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

void	my_mlx_area_put(t_data *data, int color)
{
	int	x;
	int	y;

	color = get_opposite(color);
	color = add_shade(0.5, color);
	x = LENGTH_MAX * 0.1;
	while (x < LENGTH_MAX * 0.9)
	{
		y = WIDTH_MAX * 0.1;
		while (y < WIDTH_MAX * 0.9)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_data	img;
	t_vars	vars;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LENGTH_MAX, WIDTH_MAX, "Hello world!");
	//img.img = mlx_new_image(vars.mlx, LENGTH_MAX, WIDTH_MAX);
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	//my_mlx_area_put(&img, 0x0000FF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}