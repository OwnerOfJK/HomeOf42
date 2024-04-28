/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 19:22:45 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *philo_pointer)
{
	t_philo			*philo;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	philo = (t_philo *) philo_pointer;
	printf("%ld %i is_thinking\n", current_time.tv_usec, philo->philo_id);

	// Lock the mutexes in a consistent order
	pthread_mutex_lock(&philo->fork);

	// Check if the next philosopher exists before accessing its fork
	if (philo->next != NULL) {
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %i is_eating\n", current_time.tv_usec, philo->philo_id);
		usleep(1);
		pthread_mutex_unlock(&philo->next->fork);
	} else {
		printf("No adjacent philosopher to the right. Skipping eating.\n");
	}

	pthread_mutex_unlock(&philo->fork);
	printf("%ld %i is_sleeping\n", current_time.tv_usec, philo->philo_id);
	return ((void *)0);
}

void	run_loop(t_table *table)
{
	int		i;
	//t_philo	*tmp;
	t_philo	*current;

	i = 0;
	current = table->philosophers;
	while (current)
	{
		//tmp = philo_at_index(table->philosophers, i);
		if (pthread_create(&table->thread_id[i], NULL, &routine, current) != 0)
			return ;
		usleep(1);
		i++;
		current = current->next;
	}
	current = table->philosophers;
	i = 0;
	while (current)
	{
		if (pthread_join(table->thread_id[i], NULL) != 0) {
			return ;
		}
		usleep(1);
		i++;
		current = current->next;
	}
}

// int mails = 0;
// pthread_mutex_t mutex;

// void* routine() {
//     for (int i = 0; i < 100000; i++) {
// 		pthread_mutex_lock(&mutex);
//         mails++;
// 		pthread_mutex_unlock(&mutex);
//         // read mails
//         // increment
//         // write mails
//     }
// 	return (NULL);
// }

// int main(int argc, char* argv[]) {
//     pthread_t p1, p2;
// 	pthread_mutex_init(&mutex, NULL);
//     if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
//         return 1;
//     }
//     if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
//         return 2;
//     }
//     if (pthread_join(p1, NULL) != 0) {
//         return 3;
//     }
//     if (pthread_join(p2, NULL) != 0) {
//         return 4;
//     }
// 	pthread_mutex_destroy(&mutex);
//     printf("Number of mails: %d\n", mails);
//     return 0;
// }