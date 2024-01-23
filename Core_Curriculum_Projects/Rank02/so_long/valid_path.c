/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:12:00 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/23 22:01:06 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	intialise_tmp_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->map_tmp = (char **)malloc(vars->y_max * sizeof(char *));
	while (i < vars->y_max)
	{
		vars->map_tmp[i] = (char *)malloc((vars->x_max + 1) * sizeof(char));
		j = 0;
		while (j < vars->x_max)
		{
			vars->map_tmp[i][j] = vars->map[i][j];
			j++;
		}
		vars->map_tmp[i][j] = '\0';
		i++;
	}
}

int	check_for_path(t_vars *vars, int x, int y)
{
	intialise_tmp_map(vars);
	find_all_collectibles(vars, x, y);
	if (vars->tmp_collectible_count == 0)
	{
		if (find_exit(vars, x, y) == 1)
		{
			ft_printf("Map passed all checks. Game is launching... \n");
			free_map(vars, vars->map_tmp);
			return (1);
		}
		else
		{
			error_messaging(vars, 10);
			free_map(vars, vars->map_tmp);
			return (0);
		}
	}
	else
	{
		error_messaging(vars, 9);
		free_map(vars, vars->map_tmp);
		return (0);
	}
}
