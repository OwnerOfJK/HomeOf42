/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/02 16:47:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_data(t_table	*table)
// {
// 	int	i;

// 	printf("philo_count: %d\n", table->philo_count);
// 	printf("fork_count: %d\n", table->fork_count);
// 	printf("time_to_die: %d\n", table->time_to_die);
// 	printf("time_to_eat: %d\n", table->time_to_eat);
// 	printf("time_to_sleep: %d\n", table->time_to_sleep);
// 	printf("death_count: %d\n", table->death_count);
// 	printf("max_meals: %d\n", table->max_meals);
// 	printf("\n");
// 	i = 0;
// 	while (i < table->philo_count)
// 	{
// 		printf("philo_id: %d\n", table->philos[i]->philo_id);
// 		printf("recent_meal: %d\n", table->philos[i]->recent_meal);
// 		printf("is_eating: %d\n", table->philos[i]->is_eating);
// 		printf("is_sleeping: %d\n", table->philos[i]->is_sleeping);
// 		printf("is_thinking: %d\n", table->philos[i]->is_thinking);
// 		printf("meals: %d\n", table->philos[i]->meals);
// 		printf("\n");
// 		i++;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc == 6 || argc == 5)
	{
		table = init_data(argv);
		//print_data(table);
		run_philosophers(table);
		free_data(table);
	}
	return (0);
}
