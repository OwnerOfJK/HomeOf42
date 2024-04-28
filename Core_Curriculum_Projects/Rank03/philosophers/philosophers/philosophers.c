/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:12:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/04/28 11:34:41 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



// void    run_loop(t_philo *philo)
// {
// 	while (philo)
// 	{
// 		// do something
// 		philo = philo->next;
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