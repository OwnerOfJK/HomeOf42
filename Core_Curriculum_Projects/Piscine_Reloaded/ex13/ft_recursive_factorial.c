/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:15:40 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:16:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb);

/*
int main(void)
{
    int nbr = 4;
    int result = 0;
    result = ft_recursive_factorial(nbr);
    printf("%d", result);
}
*/

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb > 2147483647 || nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}
