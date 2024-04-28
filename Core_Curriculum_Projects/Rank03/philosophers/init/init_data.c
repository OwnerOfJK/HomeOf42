/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:41 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 12:02:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int id, t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_id = id;
	philo->has_not_eaten = 0;
	philo->is_eating = 0;
	philo->is_sleeping = 0;
	philo->is_thinking = true;
	philo->meals = 0;
	philo->table = table;
	philo->next = NULL;
	philo->prev = NULL;
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
	philo = new_philo(i, table);
	head = philo;
	while (i < philo_count)
	{
		i++;
		philo = new_philo(i, table);
		add_to_end(&head, philo);
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
	return (table);
}
