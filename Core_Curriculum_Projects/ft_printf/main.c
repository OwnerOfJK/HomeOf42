/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:33:46 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/28 12:57:23 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	j;

	x = ft_printf("mine: %s \n", "hi");
	j = printf("nine: %s \n", "hi");
	printf(" \n mine : %i \noriginal : %i \n", x, j);
	return (0);
}
