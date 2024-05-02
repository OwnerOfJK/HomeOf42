/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:32:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/02 16:47:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%ld %i has taken a fork\n", get_time(), philo->philo_id);
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %i has taken a fork\n", get_time(), philo->philo_id);
	} 
	else 
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %i has taken a fork\n", get_time(), philo->philo_id);
		pthread_mutex_lock(philo->right_fork);
		printf("%ld %i has taken a fork\n", get_time(), philo->philo_id);
	}
	printf("%ld %i is eating\n", get_time(), philo->philo_id);
	pthread_mutex_lock(philo->eating_lock);
	philo->recent_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(philo->eating_lock);
	usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	printf("%ld %i is sleeping\n", get_time(), philo->philo_id);
	usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	printf("%ld %i is thinking\n", get_time(), philo->philo_id);
}

void	*philo_routine(void *philo_pointer)
{
	t_philo			*philo;

	philo = (t_philo *) philo_pointer;
	if (philo->philo_id % 2 == 0)
		usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	// while (1)
    // {   
    //     if(dead_loop(philo))
    //         break;
    //     eat(philo);
    //     if(dead_loop(philo))
    //         break;
    //     philo_sleep(philo);
    //     if(dead_loop(philo))
    //         break;
    //     think(philo);
    // }   
	return (philo_pointer);
}