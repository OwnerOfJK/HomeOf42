/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:12:00 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/22 20:18:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (vars->map_tmp[y][x] != '1' && vars->map_tmp[y][x] != 'C' && vars->map_tmp[y][x] != 'P')
		vars->map_tmp[y][x] = 'C';
	if (vars->map_tmp[y][x + 1] != '1' && vars->map_tmp[y][x + 1]
		!= 'C' && find_exit(vars, x + 1, y) == 1)
		return (1);
	if (vars->map_tmp[y][x - 1] != '1' && vars->map_tmp[y][x - 1]
		!= 'C' && find_exit(vars, x - 1, y) == 1)
		return (1);
	if (vars->map_tmp[y + 1][x] != '1' && vars->map_tmp[y + 1][x]
		!= 'C' && find_exit(vars, x, y + 1) == 1)
		return (1);
	if (vars->map_tmp[y - 1][x] != '1' && vars->map_tmp[y - 1][x]
		!= 'C' && find_exit(vars, x, y - 1) == 1)
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
	if (vars->map_tmp[y][x] != '1' && vars->map_tmp[y][x] != 'X' && vars->map_tmp[y][x] != 'P')
		vars->map_tmp[y][x] = 'X';
	if (vars->map_tmp[y][x + 1] != '1' && vars->map_tmp[y][x + 1] != 'X')
	{
		check_collectible_coordinate(vars, x + 1, y);
		find_all_collectibles(vars, x + 1, y);
	}
	if (vars->map_tmp[y][x - 1] != '1' && vars->map_tmp[y][x - 1] != 'X')
	{
		check_collectible_coordinate(vars, x - 1, y);
		find_all_collectibles(vars, x - 1, y);
	}
	if (vars->map_tmp[y + 1][x] != '1' && vars->map_tmp[y + 1][x] != 'X')
	{
		check_collectible_coordinate(vars, x, y + 1);
		find_all_collectibles(vars, x, y + 1);
	}
	if (vars->map_tmp[y - 1][x] != '1' && vars->map_tmp[y - 1][x] != 'X')
	{
		check_collectible_coordinate(vars, x, y - 1);
		find_all_collectibles(vars, x, y - 1);
	}
	return (0);
}

void	check_for_path(t_vars *vars, int x, int y)
{
	find_all_collectibles(vars, x, y);
	if (vars->tmp_collectible_count == 0)
	{
		if (find_exit(vars, x, y) == 1)
		{
			ft_printf("yeeeey");
		}
		else
			error_messaging(vars, 10);
	}
	else
		error_messaging(vars, 9);
}
