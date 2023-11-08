/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:13:16 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:13:32 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

/*
int main(void)
{
    int nbr1 = 6;
    int nbr2 = 5;
    int div = 0;
    int mod = 0;
    ft_div_mod(nbr1, nbr2, &div, &mod);
    printf("%d", mod);
}
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
