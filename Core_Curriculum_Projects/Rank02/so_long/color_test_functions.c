/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:31:37 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 14:31:21 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>

void my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
    char *dst;

    dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	//create_map(vars);
    printf("Pixel placed at coordiante %i / %i\n", x, y);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }



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

// void	my_mlx_area_put(t_data *data, int color)
// {
// 	int	x;
// 	int	y;

// 	color = get_opposite(color);
// 	color = add_shade(0.5, color);
// 	x = LENGTH_MAX * 0.1;
// 	while (x < LENGTH_MAX * 0.9)
// 	{
// 		y = WIDTH_MAX * 0.1;
// 		while (y < WIDTH_MAX * 0.9)
// 		{
// 			my_mlx_pixel_put(data, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }