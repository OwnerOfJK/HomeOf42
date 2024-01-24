/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:33:04 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/24 12:53:22 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libft/libft.h"
#include "libs/mlx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	define_y_max(t_vars *vars)
{
	char	*line;

	while (1)
	{
		line = get_next_line(vars->fd);
		if (line == NULL)
			break ;
		vars->y_max++;
		free(line);
	}
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
	define_y_max(vars);
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
