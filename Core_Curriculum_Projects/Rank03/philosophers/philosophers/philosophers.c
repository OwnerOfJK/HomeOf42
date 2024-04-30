/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/30 17:31:17 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*run_loop(void *philo_pointer)
{
	t_philo			*philo;
	struct timeval	current_time;
	struct timeval	starting_time;
	u_int64_t		elapsed_time;

	gettimeofday(&starting_time, NULL);
	philo = (t_philo *) philo_pointer;
	while (philo->table->death_count == 0 && check_for_max_meals(philo->table) == 0)
	{
		gettimeofday(&current_time, NULL);
		elapsed_time = (current_time.tv_usec - starting_time.tv_usec) / 1000;
		if (elapsed_time >= philo->table->time_to_die)
		{
			philo->table->death_count++;
			printf("%ld %i died\n", current_time.tv_usec / 1000, philo->philo_id);
			return ((void *)0);
		}
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %i has taken a fork\n", current_time.tv_usec / 1000, philo->philo_id);
		printf("%ld %i is eating\n", current_time.tv_usec / 1000, philo->philo_id);
		philo->meals++;
		usleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("%ld %i is thinking\n", starting_time.tv_usec / 1000, philo->philo_id);
		printf("%ld %i is sleeping\n", current_time.tv_usec / 1000, philo->philo_id);
		usleep(philo->table->time_to_sleep);
	}
	return ((void *)0);
}

int	run_philosophers(t_table *table)
{
	int		i;

	while (table->death_count == 0 && check_for_max_meals(table) == 0)
	{
		i = 0;
		while (i < table->philo_count)
		{
			if (pthread_create(&table->thread_id[i],
					NULL, &run_loop, table->philos[i]) != 0)
				return (philo_error(THREAD_CREATE_ERROR));
			i++;
			usleep(1);
		}
		i = 0;
		while (i < table->philo_count)
		{
			if (pthread_join(table->thread_id[i], NULL) != 0)
				return (philo_error(THREAD_JOIN_ERROR));
			i++;
			usleep(1);
		}
	}
	return (EXIT_SUCCESS);
}

