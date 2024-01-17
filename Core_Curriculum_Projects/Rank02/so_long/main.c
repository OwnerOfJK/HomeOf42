/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 21:27:07 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libft/libft.h"
#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else
		player_movement(keycode, vars);
	return (0);
}

void	prepare_map_array(char *path_to_map, t_vars *vars)
{
	char	*line;
	int		i;

	vars->fd = open(path_to_map, O_RDONLY);
	line = get_next_line(vars->fd);
	vars->y_max = 1;
	vars->x_max = ft_strlen(line);
	free(line);
	while (get_next_line(vars->fd) != NULL)
		vars->y_max++;
	close(vars->fd);
	vars->fd = open(path_to_map, O_RDONLY);
	vars->map = (char **)malloc(vars->y_max * sizeof(char *));
	i = 0;
	while (i < vars->y_max)
	{
		vars->map[i] = (char *)malloc((vars->x_max + 1) * sizeof(char));
		read(vars->fd, vars->map[i], vars->x_max);
		vars->map[i][vars->x_max] = '\0';
		i++;
	}
	close(vars->fd);
	for (int i = 0; i < vars->y_max; i++)
	{
		for (int j = 0; j < vars->x_max; j++)
			printf("%c", vars->map[i][j]);
	}
}

int	main(void)
{
	t_vars	vars;
	char	*line;
	

	// create window
	vars.mlx = mlx_init();
	prepare_map_array("maps/small.txt", &vars);


	
	// Create a new image
	vars.win = mlx_new_window(vars.mlx, vars.x_max * OBJECTS_SIZE, vars.y_max *OBJECTS_SIZE, "A GAME");
	vars.img = mlx_new_image(vars.mlx, vars.x_max *OBJECTS_SIZE, vars.y_max *OBJECTS_SIZE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	


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
