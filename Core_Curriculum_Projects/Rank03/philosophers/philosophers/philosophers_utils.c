/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:11:24 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/30 13:11:28 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_for_max_meals(t_table *table)
{
	int	i;
	int	philos_eaten;

	i = 0;
	philos_eaten = 0;
	while (i < table->philo_count)
	{
		if (table->philos[i]->meals >= table->max_meals)
			philos_eaten++;
		i++;
	}
	if (philos_eaten == table->philo_count)
		return (1);
	else
		return (0);
}