/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:31:37 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/18 14:46:56 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	printf("Pixel placed at coordiante %i / %i\n", x, y);
}