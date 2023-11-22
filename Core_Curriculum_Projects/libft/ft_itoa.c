/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:10 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:11 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa(int n)
{
    int counter = 0;
    int temp_n = n;
    if (n == 0)
    {
        char *zero_str = (char *)malloc(2 * sizeof(char));
        zero_str[0] = '0';
        zero_str[1] = '\0';
        return zero_str;
    }
    while (temp_n != 0)
    {
        temp_n = temp_n / 10;
        counter++;
    }
    char *nbr = (char *)malloc((counter + 1) * sizeof(char));
    if (n < 0)
    {
        nbr[0] = '-';
        counter++;
        n = -n;
    }
    nbr[counter] = '\0';
    while (n != 0)
    {
        counter--;
        nbr[counter] = (n % 10) + '0';
        n = n / 10;
    }
    return (nbr);
}