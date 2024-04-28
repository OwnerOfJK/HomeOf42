/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:41 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 19:13:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_id = id;
	philo->has_not_eaten = 0;
	philo->is_eating = 0;
	philo->is_sleeping = 0;
	philo->is_thinking = 0;
	philo->meals = 0;
	philo->next = NULL;
	philo->prev = NULL;
	pthread_mutex_init(&philo->fork, NULL);
	return (philo);
}

void	add_to_end(t_philo **head, t_philo *new)
{
	t_philo	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_philo	*init_philo(t_table *table)
{
	t_philo	*philo;
	t_philo	*head;
	int		i;
	int		philo_count;

	philo_count = table->philo_count;
	if (philo_count < 1)
		return (NULL);
	i = 1;
	philo = new_philo(i);
	head = philo;
	while (i++ < philo_count)
	{
		philo->next = new_philo(i);
		philo->next->prev = philo;
		philo = philo->next;
	}
	return (head);
}

t_table	*init_table(char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_count = ft_atoi(argv[1]);
	table->fork_count = table->philo_count;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->max_meals = ft_atoi(argv[5]);
	table->thread_id = malloc(sizeof(pthread_t) * table->philo_count);
	if (!table->thread_id)
		return (NULL);
	table->philosophers = init_philo(table);
	return (table);
}
