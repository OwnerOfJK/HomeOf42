/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:33:46 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 21:31:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	j;
  	int array[5] = { 1, 4, 5 };
    size_t size = sizeof(array);

	x = ft_printf("mine: %c %zu %i \n", '0', size, 4);
	j = printf("mine: %c %zu %i \n", '0', size, 4);
	printf(" \n mine : %i \noriginal : %i \n", x, j);
	return (0);
}
