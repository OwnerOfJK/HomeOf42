/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/15 16:44:11 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// int	reset_image(t_vars *vars)
// {
	
// }

int	clear_and_reset(t_vars *vars)
{
	int	x;
	int	y;

	mlx_clear_window(vars->mlx, vars->win);
	x = 0;
	while (x < LENGTH_MAX)
	{
		y = 0;
		while (y < WIDTH_MAX)
		{
			my_mlx_pixel_put(vars, x, y, DEFAULT_COLOR);
			y++;
		}
		x++;
	}
	//reset_image(vars);
}