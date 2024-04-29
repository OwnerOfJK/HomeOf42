/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/29 17:52:51 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../philo.h"

// void	*run_loop(void *table_pointer)
// {
// 	t_table			*table;
// 	struct timeval	current_time;

// 	gettimeofday(&current_time, NULL);
// 	table = (t_table *) table_pointer;
// 	printf("%ld %i is_thinking\n", current_time.tv_usec, table->philosophers->philo_id);

// 	// Lock the mutexes in a consistent order
// 	pthread_mutex_lock(&table->philosophers->fork);

// 	// Check if the next philosopher exists before accessing its fork
// 	if (table->philosophers->next != NULL) {
// 		pthread_mutex_lock(&table->philosophers->next->fork);
// 		printf("%ld %i is_eating\n", current_time.tv_usec, table->philosophers->philo_id);
// 		usleep(1);
// 		pthread_mutex_unlock(&table->philosophers->next->fork);
// 	} else {
// 		pthread_mutex_lock(&table->philosophers->next->fork);
// 		printf("No adjacent philosopher to the right. Skipping eating.\n");
// 	}

// 	pthread_mutex_unlock(&table->philosophers->fork);
// 	printf("%ld %i is_sleeping\n", current_time.tv_usec, table->philosophers->philo_id);
// 	return ((void *)0);
// }

// void	run_philosophers(t_table *table)
// {
// 	int		i;
// 	//t_philo	*tmp;
// 	t_philo	*header;

// 	i = 0;
// 	header = table->philosophers;
// 	while (table->philosophers)
// 	{
// 		//tmp = philo_at_index(table->philosophers, i);
// 		if (pthread_create(&table->thread_id[i], NULL, &run_loop, table) != 0)
// 			return ;
// 		usleep(1);
// 		i++;
// 		table->philosophers = table->philosophers->next;
// 	}
// 	table->philosophers = header;
// 	i = 0;
// 	while (table->philosophers)
// 	{
// 		if (pthread_join(table->thread_id[i], NULL) != 0) {
// 			return ;
// 		}
// 		usleep(1);
// 		i++;
// 		table->philosophers = table->philosophers->next;
// 	}
// }

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