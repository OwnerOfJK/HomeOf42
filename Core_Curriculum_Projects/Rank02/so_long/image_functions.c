/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 22:53:54 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void create_map(t_vars *vars)
{
	t_player	*player;

	int img_width;
    int img_height;
	int mapY;
	int mapX;

	player = malloc(sizeof(*player));
	player->x = 0;
	player->y = 0;
	player->player_xpm = NULL;
	vars->player = player;

	vars->sprites->floor_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/floor.xpm", &img_width, &img_height);
	vars->sprites->path_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/path.xpm", &img_width, &img_height);
	vars->player->player_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &img_width, &img_height);
	vars->sprites->collectible_xpm = mlx_xpm_file_to_image(vars->mlx, "assets/collectible.xpm", &img_width, &img_height);
	mapY = 0;
	while (mapY < vars->y_max)
	{
		mapX = 0;
		while (mapX < vars->x_max)
		{
			if (vars->map[mapY][mapX] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->floor_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			else if (vars->map[mapY][mapX] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->path_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			else if (vars->map[mapY][mapX] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
				vars->player->x = mapX;
				vars->player->y = mapY;
			}
			else if (vars->map[mapY][mapX] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->collectible_xpm, mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
			mapX++;
		}
		mapY++;
	}
}