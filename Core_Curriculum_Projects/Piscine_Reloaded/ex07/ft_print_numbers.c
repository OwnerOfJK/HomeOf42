/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:08:49 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:10:00 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);
void	ft_putchar(char c);

/*
int main(void)
{
    ft_print_numbers();
}
*/

void	ft_print_numbers(void)
{
	int	number;

	number = '0';
	while (number >= '0' && number <= '9')
	{
		ft_putchar(number);
		number++;
	}
}
