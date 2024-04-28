/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 19:08:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_table	*table)
{
	printf("philo_count: %d\n", table->philo_count);
	printf("fork_count: %d\n", table->fork_count);
	printf("time_to_die: %d\n", table->time_to_die);
	printf("time_to_eat: %d\n", table->time_to_eat);
	printf("time_to_sleep: %d\n", table->time_to_sleep);
	printf("max_meals: %d\n", table->max_meals);
	printf("\n");
	while (table->philosophers)
	{
		printf("philo_id: %d\n", table->philosophers->philo_id);
		printf("has_not_eaten: %d\n", table->philosophers->has_not_eaten);
		printf("is_eating: %d\n", table->philosophers->is_eating);
		printf("is_sleeping: %d\n", table->philosophers->is_sleeping);
		printf("is_thinking: %d\n", table->philosophers->is_thinking);
		printf("meals: %d\n", table->philosophers->meals);
		printf("\n");
		table->philosophers = table->philosophers->next;
	}
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc == 6)
	{
		table = init_table(argv);
		//print_data(table);
		run_loop(table);
		free_data(table);
	}
	return (0);
}
