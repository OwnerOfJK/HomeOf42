/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:41 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/07 18:39:20 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(t_table *table, int id)
{
	table->philos[id] = malloc(sizeof(t_philo));
	table->philos[id]->philo_id = id + 1;
	table->philos[id]->recent_meal = get_time();
	table->philos[id]->start_time = get_time();
	table->philos[id]->eating = 0;
	table->philos[id]->meals = 0;
	pthread_mutex_init(&table->forks[id], NULL);
	table->philos[id]->right_fork = &table->forks[id];
	if (id == table->philo_count - 1)
		table->philos[id]->left_fork = &table->forks[0];
	else
		table->philos[id]->left_fork = &table->forks[id + 1];
	table->philos[id]->eating_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->philos[id]->eating_lock, NULL);
	table->philos[id]->death_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->philos[id]->death_lock, NULL);
	table->philos[id]->table = table;
	return (table->philos[id]);
}

t_philo	**init_philo(t_table *table)
{
	int		i;
	int		philo_count;

	philo_count = table->philo_count;
	if (philo_count < 1)
		return (NULL);
	table->philos = (t_philo **)malloc(sizeof(t_philo *) * (philo_count + 1));
	if (!table->philos)
		return (NULL);
	i = 0;
	while (i < philo_count)
	{
		table->philos[i] = new_philo(table, i);
		i++;
	}
	table->philos[philo_count] = NULL;
	return (table->philos);
}

void	init_table_mutex(t_table *table)
{
	table->forks = calloc(sizeof(pthread_mutex_t), table->fork_count);
	if (!table->forks)
		return ;
	table->monitor_death = malloc(sizeof(pthread_mutex_t));
	if (!table->monitor_death)
		return ;
	pthread_mutex_init(table->monitor_death, NULL);
}

t_table	*init_table(char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_count = ft_atoi(argv[1]);
	table->fork_count = table->philo_count;
	table->time_to_die = (u_int64_t)ft_atoi(argv[2]);
	table->time_to_eat = (u_int64_t)ft_atoi(argv[3]);
	table->time_to_sleep = (u_int64_t)ft_atoi(argv[4]);
	table->death_count = 0;
	if (argv[5])
		table->max_meals = ft_atoi(argv[5]);
	else
		table->max_meals = -1;
	table->thread_id = malloc(sizeof(pthread_t) * table->philo_count);
	if (!table->thread_id)
		return (NULL);
	init_table_mutex(table);
	return (table);
}

t_table	*init_data(char *argv[])
{
	t_table	*table;

	table = init_table(argv);
	table->philos = init_philo(table);
	return (table);
}
