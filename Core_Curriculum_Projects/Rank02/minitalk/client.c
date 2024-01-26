/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:56 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/26 16:59:30 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

int	client_input(void)
{
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
}