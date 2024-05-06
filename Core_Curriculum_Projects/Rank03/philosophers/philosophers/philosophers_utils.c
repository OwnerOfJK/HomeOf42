/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:11:24 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/06 18:14:09 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_for_death(t_table *table)
{
	int	i;
	u_int64_t	time;

	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_lock(table->philos[i]->eating_lock);
		time = get_time();
		if (time - table->philos[i]->recent_meal > table->time_to_die)
		{
			pthread_mutex_unlock(table->philos[i]->death_lock);
			printf("%lu %d died\n", get_time() - table->philos[i]->start_time, i + 1);
			table->death_count = 1;
			pthread_mutex_unlock(table->philos[i]->death_lock);
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
	if (philos_eaten == (table->philo_count - 1))
	{
		pthread_mutex_lock(table->philos[table->philo_count - 1]->death_lock);
		table->death_count = 1;
		pthread_mutex_unlock(table->philos[table->philo_count - 1]->death_lock);
		return (1);
	}
	else
		return (0);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->death_count > 0)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
