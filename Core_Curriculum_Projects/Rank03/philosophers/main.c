/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 12:03:39 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_table	*table, t_philo *philo)
{
	printf("philo_count: %d\n", table->philo_count);
	printf("fork_count: %d\n", table->fork_count);
	printf("time_to_die: %d\n", table->time_to_die);
	printf("time_to_eat: %d\n", table->time_to_eat);
	printf("time_to_sleep: %d\n", table->time_to_sleep);
	printf("max_meals: %d\n", table->max_meals);
	printf("\n");
	while (philo)
	{
		printf("philo_id: %d\n", philo->philo_id);
		printf("has_not_eaten: %d\n", philo->has_not_eaten);
		printf("is_eating: %d\n", philo->is_eating);
		printf("is_sleeping: %d\n", philo->is_sleeping);
		printf("is_thinking: %d\n", philo->is_thinking);
		printf("meals: %d\n", philo->meals);
		printf("\n");
		philo = philo->next;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_table	*table;

	if (argc == 6)
	{
		table = init_table(argv);
		philo = init_philo(table);
		print_data(table, philo);
		//run_loop(philo);
		free_data(table, philo);
	}
	return (0);
}
