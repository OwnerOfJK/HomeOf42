/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 17:14:22 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_inputs(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error: Non-numeric values are not allowed\n");
				return (EXIT_FAILURE);
			}
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Error: Negative or NULL values are not allowed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc == 6 || argc == 5)
	{
		if (check_inputs(argv) == EXIT_FAILURE)
			return (0);
		table = init_data(argv);
		run_philosophers(table);
		free_data(table);
	}
	return (0);
}
