/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:01:51 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/18 15:45:44 by jkaller          ###   ########.fr       */
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

int	check_conditions(t_vars *vars, int new_x, int new_y)
{
	printf("New Player Location: x: %i / y: %i \n", new_x, new_y);
	if (vars->map[new_y][new_x] == '1')
		return (0);
	else if (vars->map[new_y][new_x] == '0')
		return (1);
	else if (vars->map[new_y][new_x] == 'P')
		return (1);
	else if (vars->map[new_y][new_x] == 'F')
	{
		vars->player->health -= 1;
		printf("You got attacked. Health remaining: %i \n", vars->player->health);
		return (0);
	}
	else if (vars->map[new_y][new_x] == 'C')
	{
		vars->collectible_count -= 1;
		vars->map[new_y][new_x] = '0';
		printf("collectible count: %i \n", vars->collectible_count);
		return (1);
	}
	else if (vars->map[new_y][new_x] == 'E' && vars->collectible_count == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->floor_xpm, vars->player->x * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, new_x * OBJECTS_SIZE, new_y * OBJECTS_SIZE);
		close_window(&vars);
	}
	return (0);
}

int	player_movement(int keycode, t_vars *vars)
{
	int new_x;
	int new_y;

	new_x = vars->player->x;
	new_y = vars->player->y;
	printf("Player Location: x: %i / y: %i \n", vars->player->x, vars->player->y);
	if (keycode == 65361) // left
		new_x = vars->player->x - 1;
	else if (keycode == 65363) // right
		new_x = vars->player->x + 1;
	else if (keycode == 65364) // up
		new_y = vars->player->y + 1;
	else if (keycode == 65362) // down
		new_y = vars->player->y - 1;
	if (check_conditions(vars, new_x, new_y) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->floor_xpm, vars->player->x * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->player_xpm, new_x * OBJECTS_SIZE, new_y * OBJECTS_SIZE);
		vars->player->x = new_x;
		vars->player->y = new_y;
	}
	printf("Key pressed: %d\n", keycode);
	return (0);
}