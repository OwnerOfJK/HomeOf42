/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/18 19:19:33 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	put_player(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player->player_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
	vars->player->x = x;
	vars->player->y = y;
}

void	init_variables(t_vars *vars)
{
	int			img_width;
	int			img_height;
	t_player	*player;

	player = malloc(sizeof(*player));
	player->x = 0;
	player->y = 0;
	player->health = 3;
	player->player_xpm = NULL;
	vars->player = player;
	vars->collectible_count = 0;
	vars->sprites = malloc(sizeof(*vars->sprites));
	vars->sprites->floor_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/floor.xpm", &img_width, &img_height);
	vars->sprites->barrier_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/barrier.xpm", &img_width, &img_height);
	vars->player->player_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/player.xpm", &img_width, &img_height);
	vars->sprites->collectible_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible.xpm", &img_width, &img_height);
	vars->sprites->exit_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/exit.xpm", &img_width, &img_height);
	vars->sprites->danger_xpm = mlx_xpm_file_to_image
		(vars->mlx, "assets/danger.xpm", &img_width, &img_height);
}

void	create_map(t_vars *vars)
{
	int		map_x;
	int		map_y;
	void	(*put_functions[128])(t_vars *vars, int x, int y);

	init_variables(vars);
	ft_memset(put_functions, 0, sizeof(put_functions));
	put_functions['0'] = put_floor;
	put_functions['1'] = put_barrier;
	put_functions['F'] = put_danger;
	put_functions['E'] = put_exit;
	put_functions['P'] = put_player;
	put_functions['C'] = put_collectible;
	map_y = 0;
	while (map_y < vars->y_max)
	{
		map_x = 0;
		while (map_x < vars->x_max)
		{
			if (put_functions[(unsigned char)vars->map[map_y][map_x]])
				put_functions[(unsigned char)
					vars->map[map_y][map_x]](vars, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
}
