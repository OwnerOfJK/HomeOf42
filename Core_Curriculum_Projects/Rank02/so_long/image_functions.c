/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 21:22:57 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void create_map(t_vars *vars)
{
	t_sprites sprite;

	int img_width;
    int img_height;
	int mapY;
	int mapX;

	sprite.floor_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/floor.xpm", &img_width, &img_height);
	sprite.path_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/path.xpm", &img_width, &img_height);
	sprite.player_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &img_width, &img_height);
	sprite.collectible_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/collectible.xpm", &img_width, &img_height);
	mapY = 0;
	while (mapY < vars->y_max)
	{
		mapX = 0;
		while (mapX < vars->x_max)
		{
			if (vars->map[mapY][mapX] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.floor_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			else if (vars->map[mapY][mapX] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.path_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			else if (vars->map[mapY][mapX] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.player_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			else if (vars->map[mapY][mapX] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, sprite.collectible_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			mapX++;
		}
		mapY++;
	}
}