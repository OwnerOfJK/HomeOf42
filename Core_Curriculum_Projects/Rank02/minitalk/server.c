/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:53 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 16:39:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	print_decoded_message(int signum)
{
	static int				bit_index = 0;
	static unsigned char	received_char = 0;

	if (signum == SIGUSR1)
		received_char |= (1 << bit_index);
	else if (signum == SIGUSR2)
		received_char |= (0 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		ft_putchar_fd(received_char, 1);
		bit_index = 0;
		received_char = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = print_decoded_message;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID of server: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
