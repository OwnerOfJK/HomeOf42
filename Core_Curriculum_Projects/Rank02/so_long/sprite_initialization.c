/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:22:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/20 17:47:19 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->floor_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
}

void	put_barrier(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->barrier_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
}

void	put_danger(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->danger_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
}

void	put_exit(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit->exit_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
	vars->exit->x = x;
	vars->exit->y = y;
}

void	put_collectible(t_vars *vars, int x, int y)
{
	vars->collectible_count += 1;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->collectible_xpm, x * OBJECTS_SIZE, y * OBJECTS_SIZE);
}