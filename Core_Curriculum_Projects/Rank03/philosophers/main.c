/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:17:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/24 22:39:00 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		printf("Philo %d\n", tmp->philo_id);
		printf("Time to die: %d\n", tmp->time_to_die);
		printf("Time to eat: %d\n", tmp->time_to_eat);
		printf("Time to sleep: %d\n", tmp->time_to_sleep);
		printf("Meals: %d\n", tmp->meals);
		tmp = tmp->next;
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (argc == 6)
	{
		philo = init_philo(argv);
		print_philo(philo);
		//run_loop(philo);
		free_philo(philo);
	}
	return (0);
}
