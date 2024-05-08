/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:11:24 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/08 16:13:09 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_for_death(t_table *table)
{
	int		i;
	size_t	time;

	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_lock(table->philos[i]->eating_lock);
		time = get_time();
		if (time - table->philos[i]->recent_meal
			>= table->time_to_die && table->philos[i]->eating == 0)
		{
			pthread_mutex_lock(table->monitor_death);
			printf("%lu %d died\n",
				get_time() - table->philos[i]->start_time,
				table->philos[i]->philo_id);
			table->death_count++;
			pthread_mutex_unlock(table->monitor_death);
			pthread_mutex_unlock(table->philos[i]->eating_lock);
			return (1);
		}
		pthread_mutex_unlock(table->philos[i]->eating_lock);
		i++;
	}
	return (0);
}

int	check_for_max_meals(t_table *table)
{
	int	i;
	int	philos_eaten;

	i = 0;
	philos_eaten = 0;
	if (table->max_meals == -1)
		return (0);
	while (i < table->philo_count)
	{
		pthread_mutex_lock(table->philos[i]->eating_lock);
		if (table->philos[i]->meals >= table->max_meals)
			philos_eaten++;
		pthread_mutex_unlock(table->philos[i]->eating_lock);
		i++;
	}
	if (philos_eaten == table->philo_count)
	{
		pthread_mutex_lock(table->monitor_death);
		table->death_count++;
		pthread_mutex_unlock(table->monitor_death);
		return (1);
	}
	return (0);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->table->monitor_death);
	if (philo->table->death_count > 0)
	{
		pthread_mutex_unlock(philo->table->monitor_death);
		return (1);
	}
	pthread_mutex_unlock(philo->table->monitor_death);
	return (0);
}

int	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->print_lock);
	if (dead_loop(philo) == 1)
	{
		pthread_mutex_unlock(philo->print_lock);
		return (EXIT_FAILURE);
	}
	printf("%ld %i %s\n",
		get_time() - philo->start_time, philo->philo_id, message);
	pthread_mutex_unlock(philo->print_lock);
	return (EXIT_SUCCESS);
}
