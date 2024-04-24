/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:21:49 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/24 22:36:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	int		philo_id;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals;
	struct	s_philo	*next;
	struct	s_philo	*prev;
}	t_philo;

t_philo	*init_philo(char *argv[]);
void	free_philo(t_philo *philo);
int		ft_atoi(const char *str);

#endif