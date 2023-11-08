/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:06:12 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 18:08:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);
void	ft_putchar(char c);

/*
int main(void)
{
    ft_print_alphabet();
}
*/

void	ft_print_alphabet(void)
{
	int	letter;

	letter = 'a';
	while (letter >= 'a' && letter <= 'z')
	{
		ft_putchar(letter);
		letter++;
	}
}
