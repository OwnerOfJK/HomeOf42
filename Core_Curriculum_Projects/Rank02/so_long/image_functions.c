/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:31:48 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/15 17:36:58 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	create_image(t_vars *vars, char *xpm_path, int mapX, int mapY)
{
	create_walls;
	create_collectibles;
	
	// char	*relative_path = "assets/sumrot.xpm";
    // Load the XPM file
    void	*img;
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(vars->mlx, xpm_path, &img_width, &img_height);
    if (!img) {
        ft_putstr_fd("Error\nFailed to load image.\n", 2);
        return ;
    }

    // Put the image to the desired coordinates on the map
    mlx_put_image_to_window(vars->mlx, vars->win, img, mapX * TILE_SIZE, mapY * TILE_SIZE);
}

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
	//create_image(vars);
}