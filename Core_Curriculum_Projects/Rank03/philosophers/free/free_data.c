/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:50:26 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 18:39:16 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo **philo)
{
	int		i;

	i = 0;
	while (philo[i])
	{
		pthread_mutex_destroy(philo[i]->eating_lock);
		pthread_mutex_destroy(philo[i]->death_lock);
		free(philo[i]->eating_lock);
		free(philo[i]->death_lock);
		free(philo[i]);
		i++;
	}
	free(philo);
}

void	free_table(t_table *table)
{
	free_philo(table->philos);
	free(table->thread_id);
	pthread_mutex_destroy(table->forks);
	pthread_mutex_destroy(table->monitor_death);
	free(table->forks);
	free(table->monitor_death);
	free(table);
}

void	free_data(t_table *table)
{
	free_table(table);
}
