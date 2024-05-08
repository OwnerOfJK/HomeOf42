/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:32:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/08 16:08:05 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
	{
		if (philo_uneven_fork(philo) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		philo_even_fork(philo);
	eat_action(philo);
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	return (EXIT_SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
	return (EXIT_SUCCESS);
}

int	think(t_philo *philo)
{
	print_message(philo, "is thinking");
	return (EXIT_SUCCESS);
}

void	*philo_routine(void *philo_pointer)
{
	t_philo			*philo;

	philo = (t_philo *) philo_pointer;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		if (dead_loop(philo) == 1)
			break ;
		if (eat(philo) == EXIT_FAILURE)
			break ;
		if (dead_loop(philo) == 1)
			break ;
		if (philo_sleep(philo) == EXIT_FAILURE)
			break ;
		if (dead_loop(philo) == 1)
			break ;
		if (think(philo) == EXIT_FAILURE)
			break ;
	}
	return (philo_pointer);
}
