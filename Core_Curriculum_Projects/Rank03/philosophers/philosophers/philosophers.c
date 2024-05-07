/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 18:03:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	run_philosophers(t_table *table)
{
	int			i;
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread,
			NULL, &philo_monitor, table) != 0)
		return (philo_error(THREAD_CREATE_ERROR, table));
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_create(&table->thread_id[i],
				NULL, &philo_routine, table->philos[i]) != 0)
			return (philo_error(THREAD_CREATE_ERROR, table));
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		return (philo_error(THREAD_JOIN_ERROR, table));
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_join(table->thread_id[i], NULL) != 0)
			return (philo_error(THREAD_JOIN_ERROR, table));
		i++;
	}
	return (EXIT_SUCCESS);
}
