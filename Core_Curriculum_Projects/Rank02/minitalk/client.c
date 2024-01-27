/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:56 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 16:28:39 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_encoded_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_encoded_message(pid, argv[2]);
		return (1);
	}
	else
		ft_printf("Input Variables have an issue");
	return (0);
}
