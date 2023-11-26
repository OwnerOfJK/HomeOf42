/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:05:17 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 18:56:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	find_max(int n, ...)
{
	int index = 0;
	int max = 0;
	va_list args;

	va_start(args, n);

	while (index < n)
	{
		int current = va_arg(args, int);
		if (current > max)
		{
			max = current;
		}
		index++;
	}
	va_end(args);
	return (max);
	//printf("%d \n", max);
}

int	main(void)
{
	int max = find_max(6, 1, 2, 3, 4, 5, 6);
	printf("%d",max);
	return (0);
}
//va_arg is pointing to the first value, and everytime its called it points to the next.
