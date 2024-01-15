/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/15 21:19:45 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	create_map(t_vars *vars)
{
	char	*xpm_paths[2] = {"assets/floor.xpm", "assets/rails.xpm"};
	void	*imgs[2];
	int		img_width;
	int		img_height;

	for (int i = 0; i < 2; i++)
	{
		imgs[i] = mlx_xpm_file_to_image(vars->mlx, xpm_paths[i], &img_width, &img_height);
		if (!imgs[i])
			return;
	}
	for (int mapY = 0; mapY < LENGTH_MAX; mapY++)
		for (int mapX = 0; mapX < WIDTH_MAX; mapX++)
			mlx_put_image_to_window(vars->mlx, vars->win, imgs[vars->map[mapY][mapX]], mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
}

int	clear_and_reset(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < LENGTH_MAX)
	{
		y = 0;
		while (y < WIDTH_MAX)
		{
			my_mlx_pixel_put(vars, x, y, DEFAULT_COLOR);
			y++;
		}
		x++;
	}
	create_map(vars);
}