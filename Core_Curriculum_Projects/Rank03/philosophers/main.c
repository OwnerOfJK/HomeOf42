/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 17:59:31 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_inputs(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
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
		if (check_inputs(argc, argv) == EXIT_FAILURE)
			return (0);
		table = init_data(argv);
		run_philosophers(table);
		free_data(table);
	}
	return (0);
}
