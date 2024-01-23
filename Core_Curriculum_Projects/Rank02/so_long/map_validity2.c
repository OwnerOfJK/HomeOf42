/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:36:40 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/23 21:56:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "libs/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	check_for_player(t_vars *vars)
{
	int	p_counter;
	int	i;
	int	j;

	i = 0;
	p_counter = 0;
	while (i < vars->y_max)
	{
		j = 0;
		while (j < vars->x_max)
		{
			p_counter += (vars->map[i][j] == 'P');
			j++;
		}
		i++;
	}
	if (p_counter != 1)
	{
		error_messaging(vars, 2);
		return (0);
	}
	return (1);
}

int	check_for_collectible(t_vars *vars)
{
	int	c_counter;
	int	i;
	int	j;

	i = 0;
	c_counter = 0;
	while (i < vars->y_max)
	{
		j = 0;
		while (j < vars->x_max)
		{
			c_counter += (vars->map[i][j] == 'C');
			j++;
		}
		i++;
	}
	if (c_counter < 1)
	{
		error_messaging(vars, 3);
		return (0);
	}
	return (1);
}
