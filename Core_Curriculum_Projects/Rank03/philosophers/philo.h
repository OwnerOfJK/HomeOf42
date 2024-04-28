/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:21:49 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 18:59:43 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				has_not_eaten;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				meals;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	fork;
	//struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				philo_count;
	int				fork_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	pthread_t		*thread_id;
	t_philo			*philosophers;
}	t_table;


/* Data Handling*/
t_table	*init_table(char *argv[]);
t_philo	*init_philo(t_table *table);
void	free_data(t_table *table);

/* Philosopher */
void	run_loop(t_table *table);
t_philo	*philo_at_index(t_philo *philo, int index);

/* Utils */
int		ft_atoi(const char *str);

#endif