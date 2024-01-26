/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:53 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/26 16:59:59 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

void	signal_handler(int signum, char *message)
{
	if (signum == SIGUSR1)
		printf(message);
	else if (signum == SIGUSR2)
		printf (" The random number is: %d", rand()); 
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		client_input(); //do something here
		signal_handler(SIGUSR1, argv[1]);
		signal(SIGUSR2, signal_handler);
	}
	else
		return (0);
}