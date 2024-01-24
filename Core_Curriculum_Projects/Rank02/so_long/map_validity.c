/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:12:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/24 14:09:38 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

int	check_for_rectangle(t_vars *vars)
{
	if (vars->y_max >= vars->x_max)
	{
		error_messaging(vars, 8);
		return (0);
	}
	return (1);
}

int	check_for_exit(t_vars *vars)
{
	int	e_counter;
	int	i;
	int	j;

	i = 0;
	e_counter = 0;
	while (i < vars->y_max)
	{
		j = 0;
		while (j < vars->x_max)
		{
			e_counter += (vars->map[i][j] == 'E');
			j++;
		}
		i++;
	}
	if (e_counter != 1)
	{
		error_messaging(vars, 1);
		return (0);
	}
	return (1);
}

int	check_for_walls(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->x_max - 1)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->y_max - 1][i] != '1')
		{
			error_messaging(vars, 6);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < vars->y_max - 1)
	{
		if (vars->map[i][0] != '1' || vars->map[i][vars->x_max - 2] != '1')
		{
			error_messaging(vars, 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_for_invalid_character(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->y_max)
	{
		j = 0;
		while (j < vars->x_max)
		{
			if (vars->map[i][j] != 'P' && vars->map[i][j] != 'E'
				&& vars->map[i][j] != 'C' && vars->map[i][j] != '1'
				&& vars->map[i][j] != '0' && vars->map[i][j] != 'F'
				&& vars->map[i][j] != '\n' && vars->map[i][j] != '\0')
			{
				ft_printf("Error: Invalid Character!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
