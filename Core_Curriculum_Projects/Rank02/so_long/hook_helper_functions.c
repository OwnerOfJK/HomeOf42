/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:01:51 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 23:15:52 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	//free(vars->players);
	mlx_loop_end(vars->mlx);
	return (0);
}

// int	mouse_inputs(int button, int x, int y, t_vars *vars)
// {
// 	printf("Mouse clicked %i at coordiante %i / %i\n",button, x, y);
// 	if (button == 1 && vars->player_number < PLAYER_MAX)
// 	{
// 		t_player *newPlayer;
// 		vars->players = realloc(vars->players, (vars->player_number + 1) * sizeof(t_player));
// 		newPlayer = &vars->players[vars->player_number];
// 		newPlayer->x = x;
// 		newPlayer->y = y;
// 		newPlayer->color = PLAYER_COLOR;
// 		vars->player_number++;
// 		my_mlx_pixel_put(vars, x, y, PLAYER_COLOR);
// 	}
// 	return (0);
// }

int	player_movement(int keycode, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->floor_xpm, vars->player->x * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
	if (keycode == 65361) //left
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, (vars->player->x - 1) * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		vars->player->x = vars->player->x - 1;
	}
	else if (keycode == 65363) //right
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, (vars->player->x + 1) * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		vars->player->x = vars->player->x + 1;
	}
	else if (keycode == 65364) //up
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, vars->player->x * OBJECTS_SIZE, (vars->player->y + 1) * OBJECTS_SIZE);
		vars->player->y = vars->player->y + 1;
	}
	else if (keycode == 65362) //down
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, vars->player->x * OBJECTS_SIZE, (vars->player->y - 1) * OBJECTS_SIZE);
		vars->player->y = vars->player->y - 1;
	}
	printf("Key pressed: %d\n", keycode);
	return (0);
}