/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:51:30 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/24 22:40:26 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int id, char *argv[])
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_id = id;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->meals = ft_atoi(argv[5]);
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

t_philo	*init_philo(char *argv[])
{
	t_philo	*philo;
	t_philo	*head;
	int		i;
	int		philo_count;

	philo_count = ft_atoi(argv[1]);
	if (philo_count < 1)
		return (NULL);
	i = 1;
	philo = new_philo(i, argv);
	head = philo;
	while (i < philo_count)
	{
		i++;
		philo = new_philo(i, argv);
		add_to_end(&head, philo);
	}
	return (head);
}
