/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:45 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/23 21:17:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	set_locations(t_vars *vars, int map_x, int map_y)
{
	while (map_y < vars->y_max)
	{
		map_x = 0;
		while (map_x < vars->x_max)
		{
			if (vars->map[map_y][map_x] == 'P')
			{
				vars->player->x = map_x;
				vars->player->y = map_y;
			}
			if (vars->map[map_y][map_x] == 'E')
			{
				vars->exit->x = map_x;
				vars->exit->y = map_y;
			}
			if (vars->map[map_y][map_x] == 'C')
				vars->collectible_count += 1;
			map_x++;
		}
		map_y++;
	}
}

void	set_variables(t_vars *vars)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	vars->player = (t_player *)malloc(sizeof(t_player));
	vars->exit = (t_exit *)malloc(sizeof(t_exit));
	vars->collectible_count = 0;
	vars->moves = 0;
	set_locations(vars, map_x, map_y);
}

void	error_messaging(t_vars *vars, int error_number)
{
	if (error_number == 1)
		ft_printf("Error: There is no exit on the map!\n");
	if (error_number == 2)
		ft_printf("Error: There is more than one exit on the map!\n");
	if (error_number == 3)
		ft_printf("Error: There is more than one player on the map!\n");
	if (error_number == 4)
		ft_printf("Error: There is no player on the map!\n");
	if (error_number == 5)
		ft_printf("Error: Less than 1 Collectible on the map!\n");
	if (error_number == 6)
		ft_printf("Error: Map is not surrounded by walls!\n");
	if (error_number == 7)
		ft_printf("Error: File Format is not .ber!\n");
	if (error_number == 8)
		ft_printf("Error: Map is not a rectangle!\n");
	if (error_number == 9)
		ft_printf("Error: Not all Collectibles reachable!\n");
	if (error_number == 10)
		ft_printf("Error: Exit not reachable!\n");
	if (error_number == 11)
		ft_printf("Error: Invalid Character!\n");
	close_instance(vars);
}

void	check_map(t_vars *vars)
{
	check_for_player_collectible(vars);
	check_for_exit(vars);
	check_for_walls(vars);
	check_for_rectangle(vars);
	check_for_invalid_character(vars);
	vars->tmp_collectible_count = vars->collectible_count;
	check_for_path(vars, vars->player->x, vars->player->y);
}
