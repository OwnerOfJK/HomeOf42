/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:01:51 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/22 20:16:21 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	//free(vars->players);
	return (0);
}

int	check_conditions(t_vars *vars, int new_x, int new_y)
{
	char	map_value;

	map_value = vars->map[new_y][new_x];
	if (map_value == '1')
		return (0);
	else if (new_x == vars->exit->x && new_y == vars->exit->y && vars->collectible_count == 0)
		close_window(&vars);
	else if (map_value == '0' || map_value == 'P' || map_value == 'E')
		return (1);
	else if (map_value == 'F')
	{
		printf("You got killed. Try harder next time.");
		close_window(&vars);
	}
	else if (vars->map[new_y][new_x] == 'C')
	{
		vars->collectible_count -= 1;
		vars->map[new_y][new_x] = '0';
		printf("collectible count: %i \n", vars->collectible_count);
		return (1);
	}
	return (0);
}

int	player_movement(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player->x + (keycode == 65363) - (keycode == 65361);
	new_y = vars->player->y + (keycode == 65364) - (keycode == 65362);
	if (check_conditions(vars, new_x, new_y) == 1)
	{
		ft_printf("Current Number of Movements: %i \n", (1 + vars->moves++));
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->floor_xpm,
			vars->player->x * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->player_xpm,
			new_x * OBJECTS_SIZE, new_y * OBJECTS_SIZE);
		if (new_x == vars->exit->x && new_y == vars->exit->y)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->player_on_exit_xpm,
				new_x * OBJECTS_SIZE, new_y * OBJECTS_SIZE);
		if (vars->player->x == vars->exit->x && vars->player->y == vars->exit->y)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->exit_xpm,
				vars->player->x * OBJECTS_SIZE, vars->player->y * OBJECTS_SIZE);
		vars->player->x = new_x;
		vars->player->y = new_y;
	}
	return (0);
}
