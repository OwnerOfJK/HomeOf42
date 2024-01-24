/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:20:12 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/24 14:06:18 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stddef.h>

void	free_sprites(t_vars *vars)
{
	if (vars->sprites)
	{
		if (vars->sprites->floor_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->floor_xpm);
		if (vars->sprites->barrier_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->barrier_xpm);
		if (vars->sprites->collectible_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->collectible_xpm);
		if (vars->sprites->danger_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->danger_xpm);
		if (vars->sprites->exit_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->exit_xpm);
		if (vars->sprites->player_on_exit_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->player_on_exit_xpm);
		if (vars->sprites->player_xpm)
			mlx_destroy_image(vars->mlx, vars->sprites->player_xpm);
		free(vars->sprites);
		vars->sprites = NULL;
	}
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	free_map(t_vars *vars, char **map_version)
{
	int	i;

	i = 0;
	while (i < vars->y_max)
	{
		free(map_version[i]);
		i++;
	}
	free(map_version);
}

void	free_structs(t_vars *vars)
{
	free(vars->player);
	free(vars->exit);
}

int	close_window(t_vars *vars)
{
	free_sprites(vars);
	free_map(vars, vars->map);
	free_structs(vars);
	free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

void	close_instance(t_vars *vars)
{
	free_structs(vars);
	free_map(vars, vars->map);
	free(vars);
	exit(EXIT_SUCCESS);
}
