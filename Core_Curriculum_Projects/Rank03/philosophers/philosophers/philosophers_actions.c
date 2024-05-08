/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:32:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/08 17:14:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	if (philo->table->philo_count == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	philo->eating = 1;
	print_message(philo, "is eating");
	pthread_mutex_lock(philo->eating_lock);
	philo->recent_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(philo->eating_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (EXIT_SUCCESS);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	*philo_routine(void *philo_pointer)
{
	t_philo			*philo;

	philo = (t_philo *) philo_pointer;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (alive_status(philo) == 0)
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (philo_pointer);
}
