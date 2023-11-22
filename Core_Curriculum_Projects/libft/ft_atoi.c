/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:40:53 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:41:17 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int sign_amount;
    int result;

    i = 0;
    sign_amount = 0;
    result = 0;
    while (str[i] != '\0')
    {
        if (ft_isspace(str[i]) == 1)
            i++;
        if (str[i] == '+')
        {
            if (sign_amount >= 1)
            {
                return (0);
            }
            sign_amount++;
            i++;
        }
        if (str[i] == '-')
        {
            if (sign_amount >= 1)
            {
                return (0);
            }
            sign_amount++;
            result *= -1;
            i++;
        }
        if (ft_isdigit(str[i]) == 1)
        {
            result = result * 10 + (str[i] - 48);
            i++;
            if (ft_isdigit(str[i]) == 0)
            {
                return (result);
            }
        }
    }
    return (result);
}