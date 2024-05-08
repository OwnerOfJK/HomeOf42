/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_eat_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:29:54 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/08 16:09:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_action(t_philo *philo)
{
	print_message(philo, "is eating");
	pthread_mutex_lock(philo->eating_lock);
	philo->eating = 1;
	philo->recent_meal = get_time();
	philo->meals++;
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->eating_lock);
}

int	philo_uneven_fork(t_philo *philo)
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
	return (EXIT_SUCCESS);
}

int	philo_even_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	return (EXIT_SUCCESS);
}
