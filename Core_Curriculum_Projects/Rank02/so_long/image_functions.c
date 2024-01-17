/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 12:13:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	create_map(t_vars *vars)
{
	char	*xpm_paths[2] = {"assets/floor.xpm", "assets/rails.xpm"};
	void	*imgs[2];
	int		img_width;
	int		img_height;

	for (int i = 0; i < 2; i++)
	{
		imgs[i] = mlx_xpm_file_to_image(vars->mlx, xpm_paths[i], &img_width, &img_height);
		if (!imgs[i])
			return;
	}
	for (int mapY = 0; mapY < LENGTH_MAX; mapY++)
		for (int mapX = 0; mapX < WIDTH_MAX; mapX++)
			mlx_put_image_to_window(vars->mlx, vars->win, imgs[vars->map[mapY][mapX]], mapX * OBJECTS_SIZE, mapY * OBJECTS_SIZE);
}