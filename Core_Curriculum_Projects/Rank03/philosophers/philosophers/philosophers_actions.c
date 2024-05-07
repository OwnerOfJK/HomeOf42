/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:32:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 18:33:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (dead_loop(philo) == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	printf("%ld %i has taken a fork\n",
		get_time() - philo->start_time, philo->philo_id);
	if (philo->table->philo_count == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	if (dead_loop(philo) == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	printf("%ld %i has taken a fork\n",
		get_time() - philo->start_time, philo->philo_id);
	philo->eating = 1;
	printf("%ld %i is eating\n",
		get_time() - philo->start_time, philo->philo_id);
	pthread_mutex_lock(philo->eating_lock);
	philo->recent_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(philo->eating_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	if (dead_loop(philo) == 1)
		return ;
	printf("%ld %i is sleeping\n",
		get_time() - philo->start_time, philo->philo_id);
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	if (dead_loop(philo) == 1)
		return ;
	printf("%ld %i is thinking\n",
		get_time() - philo->start_time, philo->philo_id);
}

void	*philo_routine(void *philo_pointer)
{
	t_philo			*philo;

	philo = (t_philo *) philo_pointer;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		if (dead_loop(philo) == 1)
			break ;
		philo_sleep(philo);
		if (dead_loop(philo) == 1)
			break ;
		think(philo);
		if (dead_loop(philo) == 1)
			break ;
	}
	return (philo_pointer);
}
