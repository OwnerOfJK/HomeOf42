/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:50:26 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 11:51:51 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo *philo)
{
	t_philo	*tmp;

	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
}

void	free_table(t_table *table)
{
	free(table);
}

void	free_data(t_table *table, t_philo *philo)
{
	free_table(table);
	free_philo(philo);
}
