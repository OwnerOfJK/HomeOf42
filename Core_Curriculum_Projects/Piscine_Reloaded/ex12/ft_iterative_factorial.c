/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:13:46 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:15:23 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

/*
int main(void)
{
    int nbr = 4;
    int result = 0;
    result = ft_iterative_factorial(nbr);
    printf("%d", result);
}
*/

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb > 2147483647 || nb < 0)
	{
		return (0);
	}
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
