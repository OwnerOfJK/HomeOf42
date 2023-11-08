/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:57 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:12:42 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

/*
int main(void)
{
    int nbr1 = 5;
    int nbr2 = 6;
    ft_swap(&nbr1, &nbr2);
    printf("%d", nbr1);
}
*/

void	ft_swap(int *a, int *b)
{
	int	temp_int;

	temp_int = *a;
	*a = *b;
	*b = temp_int;
}
