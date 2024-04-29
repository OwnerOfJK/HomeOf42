/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:50:26 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/29 18:19:03 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo **philo)
{
	int		i;

	i = 0;
	while (philo[i])
	{
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
	free(table->forks);
	free(table);
}

void	free_data(t_table *table)
{
	free_table(table);
}
