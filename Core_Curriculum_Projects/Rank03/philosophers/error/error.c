/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:23:38 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/02 15:14:22 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_error(int err_code, t_table *table)
{
	if (err_code == THREAD_CREATE_ERROR)
		perror("Error with creating thread");
	else if (err_code == THREAD_JOIN_ERROR)
		perror("Error with joining thread");
	free_data(table);
	return (err_code);
}
