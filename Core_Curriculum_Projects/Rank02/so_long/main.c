/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/25 18:38:42 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libft/libft.h"
#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	close_early(t_vars *vars)
{
	free_map(vars, vars->map);
	free(vars);
	exit(EXIT_SUCCESS);
}

void	start_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->x_max - 1) * OBJECTS_SIZE,
			vars->y_max * OBJECTS_SIZE, "A GAME OF SKYSTRIFE");
	create_map(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (argc == 2)
	{
		if (check_file_format(argv[1]) == 0)
			error_messaging(vars, 7);
		prepare_map_array(argv[1], vars);
		if (check_for_row_length(vars) == 1)
		{
			set_variables(vars);
			if (check_map(vars) == 1)
			{
				start_game(vars);
			}
			else
				close_instance(vars);
		}
	}
	else
		ft_printf("Not the right amount of arguments!");
	free (vars);
	return (0);
}
