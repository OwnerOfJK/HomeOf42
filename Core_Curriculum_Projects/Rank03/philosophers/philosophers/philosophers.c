/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/29 18:49:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_loop(void *philo_pointer)
{
	t_philo			*philo;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	philo = (t_philo *) philo_pointer;
	printf("%ld %i is_thinking\n", current_time.tv_usec, philo->philo_id);

	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %i is_eating\n", current_time.tv_usec, philo->philo_id);
	usleep(philo->table->time_to_eat);

	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%ld %i is_sleeping\n", current_time.tv_usec, philo->philo_id);
	return ((void *)0);
}

void	run_philosophers(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_create(&table->thread_id[i], NULL, &run_loop, table->philos[i]) != 0)
			return ;
		i++;
		usleep(1);
	}
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_join(table->thread_id[i], NULL) != 0)
			return ;
		i++;
		usleep(1);
	}
}


