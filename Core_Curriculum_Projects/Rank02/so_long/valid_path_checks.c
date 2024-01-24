/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:04:18 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/24 14:04:54 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

int	possible_or_not(t_vars *vars, int x, int y)
{
	if (vars->map_tmp[y][x] != '1'
		&& vars->map_tmp[y][x] != 'X'
		&& vars->map_tmp[y][x] != 'F')
		return (1);
	return (0);
}

int	check_exit_coordinate(t_vars *vars, int x, int y)
{
	if (x == vars->exit->x && y == vars->exit->y)
		return (1);
	return (0);
}

int	find_exit(t_vars *vars, int x, int y)
{
	if (check_exit_coordinate(vars, x, y) == 1)
		return (1);
	if (vars->map_tmp[y][x] != '1' && vars->map_tmp[y][x] != 'C'
		&& vars->map_tmp[y][x] != 'F')
		vars->map_tmp[y][x] = 'C';
	if (vars->map_tmp[y][x + 1] != '1' && vars->map_tmp[y][x + 1]
		!= 'C' && vars->map_tmp[y][x] != 'F' && find_exit(vars, x + 1, y) == 1)
		return (1);
	if (vars->map_tmp[y][x - 1] != '1' && vars->map_tmp[y][x - 1]
		!= 'C' && vars->map_tmp[y][x] != 'F' && find_exit(vars, x - 1, y) == 1)
		return (1);
	if (vars->map_tmp[y + 1][x] != '1' && vars->map_tmp[y + 1][x]
		!= 'C' && vars->map_tmp[y][x] != 'F' && find_exit(vars, x, y + 1) == 1)
		return (1);
	if (vars->map_tmp[y - 1][x] != '1' && vars->map_tmp[y - 1][x]
		!= 'C' && vars->map_tmp[y][x] != 'F' && find_exit(vars, x, y - 1) == 1)
		return (1);
	return (0);
}

void	check_collectible_coordinate(t_vars *vars, int x, int y)
{
	if (vars->map_tmp[y][x] == 'C')
		vars->tmp_collectible_count -= 1;
}

int	find_all_collectibles(t_vars *vars, int x, int y)
{
	if (possible_or_not(vars, x, y) == 1)
		vars->map_tmp[y][x] = 'X';
	if (possible_or_not(vars, x + 1, y) == 1)
	{
		check_collectible_coordinate(vars, x + 1, y);
		find_all_collectibles(vars, x + 1, y);
	}
	if (possible_or_not(vars, x - 1, y) == 1)
	{
		check_collectible_coordinate(vars, x - 1, y);
		find_all_collectibles(vars, x - 1, y);
	}
	if (possible_or_not(vars, x, y + 1) == 1)
	{
		check_collectible_coordinate(vars, x, y + 1);
		find_all_collectibles(vars, x, y + 1);
	}
	if (possible_or_not(vars, x, y - 1) == 1)
	{
		check_collectible_coordinate(vars, x, y - 1);
		find_all_collectibles(vars, x, y - 1);
	}
	return (0);
}
