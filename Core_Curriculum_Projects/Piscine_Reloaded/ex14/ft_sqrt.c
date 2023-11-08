/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:17:06 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:18:32 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

/*
int main(void)
{
    int nbr = 400;
    int result = 0;
    result = ft_sqrt(nbr);
    printf("%d", result);
}
*/

int	ft_sqrt(int nb)
{
	int	result;

	result = 1;
	if (nb > 2147483647 || nb < 0)
	{
		return (0);
	}
	while (result <= (nb / 2))
	{
		if ((result * result) == nb)
		{
			return (result);
		}
		else
		{
			result++;
		}
	}
	return (0);
}
