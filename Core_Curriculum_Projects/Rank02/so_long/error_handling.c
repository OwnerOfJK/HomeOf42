/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:45 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/20 17:09:20 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

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
		ft_printf("Error: Map is not a triangle!\n");
	if (error_number == 9)
		ft_printf("Error: No valid path!\n");
	//close_window(vars);
}

void check_map(t_vars *vars)
{
    // int i;
    // i = 0;
    // vars->map_visited = (int **)malloc(vars->y_max * sizeof(int *));
    // while (i < vars->y_max)
    // {
    //     // Allocate memory for each row
    //     vars->map_visited[i] = (int *)malloc(vars->x_max * sizeof(int));

    //     // Initialize the row
    //     int j = 0;
    //     while (j < vars->x_max)
    //     {
    //         vars->map_visited[i][j] = 0;
    //         j++;
    //     }
    //     i++;
    // }

    check_for_player_collectible(vars);
    check_for_exit(vars);
    check_for_walls(vars);
    check_for_rectangle(vars);

    // if (check_for_path(vars, vars->player->x, vars->player->y) == 0)
    //     error_messaging(vars, 9);
}
