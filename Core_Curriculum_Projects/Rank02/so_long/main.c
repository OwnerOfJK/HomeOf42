/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 13:11:52 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <string.h>

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else
		player_movement(keycode, vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	// create window
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LENGTH_MAX, WIDTH_MAX, "A GAME");

	// Create a new image
	vars.img = mlx_new_image(vars.mlx, LENGTH_MAX, WIDTH_MAX);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	
    // create map
    int map[LENGTH_MAX][WIDTH_MAX] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
    };  
    memcpy(vars.map, map, sizeof(map));
    create_map(&vars);

	//Initialise player variables
	vars.players = NULL;
	vars.player_number = 0;
	
	//input listener
	//mlx_loop_hook(vars.win, render_next_frame, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.win, 17, 1L<<0, close_window, &vars);
	mlx_mouse_hook(vars.win, mouse_inputs, &vars);
	mlx_loop(vars.mlx);
	return (0);
}



// int	render_next_frame(t_vars *vars)
// {
// 	t_vars *vars = (t_vars *)vars;

	
	
// 	vars.img = mlx_new_image(vars->mlx, LENGTH_MAX, WIDTH_MAX);
// 	//img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 			&img.line_length, &img.endian);
// 	my_mlx_area_put(&img, 0x0000FF);
// 	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	
// }