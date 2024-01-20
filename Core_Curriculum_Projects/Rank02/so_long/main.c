/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/19 15:57:26 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libft/libft.h"
#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int	check_file_format(char *file_name)
{
	char	*file_format;

	file_format = ".ber";
	if (strcmp(file_name + strlen(file_name) 
			- strlen(file_format), file_format) == 0)
		return (1); // File format is correct
	else
		return (0); // File format is incorrect
}

int	key_press(int key, t_vars *vars)
{
	if (key == 65307)
		close_window(vars);
	else if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
		player_movement(key, vars);
	return (0);
}

// Function to free all allocated memory
void cleanup(t_vars *vars) {
	if (vars->sprites) {
		if (vars->sprites->floor_xpm) {
			mlx_destroy_image(vars->mlx, vars->sprites->floor_xpm);
		}
		if (vars->sprites->barrier_xpm) {
			mlx_destroy_image(vars->mlx, vars->sprites->barrier_xpm);
		}
		if (vars->sprites->collectible_xpm) {
			mlx_destroy_image(vars->mlx, vars->sprites->collectible_xpm);
		}
		free(vars->sprites); // Free the sprites struct itself
		vars->sprites = NULL;
	}
	if (vars->player && vars->player->player_xpm)
	{
		mlx_destroy_image(vars->mlx, vars->player->player_xpm);
		free(vars->player);  // Free the player struct itself
		vars->player = NULL;
	}
	for (int i = 0; i < vars->y_max; ++i) {
		free(vars->map[i]); // Free each string in the map
	}
	free(vars->map); // Free the map array itself
	vars->map = NULL;
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
	vars->map = (char **)malloc((vars->y_max + 1) * sizeof(char *));
	i = 0;
	while (i < vars->y_max)
	{
		vars->map[i] = (char *)malloc((vars->x_max + 1) * sizeof(char));
		read(vars->fd, vars->map[i], vars->x_max);
		vars->map[i][vars->x_max] = '\0';
		i++;
	}
	close(vars->fd);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_vars	vars;
		char	*line;
		
		if (check_file_format(argv[1]) == 0)
			error_messaging(&vars, 5);
		vars.mlx = mlx_init();
		prepare_map_array(argv[1], &vars);
		check_map(&vars);
		vars.win = mlx_new_window(vars.mlx, (vars.x_max - 1) * OBJECTS_SIZE, vars.y_max *OBJECTS_SIZE, "A GAME");
		vars.img = mlx_new_image(vars.mlx, vars.x_max *OBJECTS_SIZE, vars.y_max *OBJECTS_SIZE);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
		//vars.sprites = malloc(sizeof(t_sprites));
		//vars.player = malloc(sizeof(t_player));
		//vars.player->x = 0;
		//vars.player->y = 0;
		//vars.player->health = 3;
		//vars.player = NULL;
		create_map(&vars);
		mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
		mlx_hook(vars.win, 17, 1L<<0, close_window, &vars);
		mlx_loop(vars.mlx);
		cleanup(&vars);
	}
	return (0);
}
