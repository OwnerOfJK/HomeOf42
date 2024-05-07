/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_monitor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:16:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 13:32:51 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_monitor(void *table_pointer)
{
	t_table			*table;

	table = (t_table *)table_pointer;
	while (1)
	{
		if (check_for_death(table) == 1 || check_for_max_meals(table) == 1)
			break ;
	}
	return (table_pointer);
}
