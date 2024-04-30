/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:21:49 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/30 16:31:37 by jkaller          ###   ########.fr       */
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
# include <stdint.h>
# include <sys/types.h>

/* System error */
# define EXIT_SUCCESS			0
# define THREAD_CREATE_ERROR	1
# define THREAD_JOIN_ERROR		2

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				philo_id;
	u_int64_t		has_not_eaten;
	u_int64_t		is_eating;
	u_int64_t		is_sleeping;
	u_int64_t		is_thinking;
	int				meals;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				philo_count;
	int				fork_count;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				death_count;
	int				max_meals;
	pthread_t		*thread_id;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}	t_table;


/* Data Handling*/
t_table		*init_data(char *argv[]);
void		free_data(t_table *table);

/* Philosopher */
int			run_philosophers(t_table *table);

/* Utils */
int			ft_atoi(const char *str);
int			check_for_max_meals(t_table *table);
u_int64_t	get_time(void);

/* Error Handling */
int			philo_error(int err_code);

#endif