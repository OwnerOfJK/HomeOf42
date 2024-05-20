/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:29:50 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 18:20:24 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_lower_puthexa(long nbr);
int		ft_upper_puthexa(long nbr);
int		ft_putstr(char *s);
int		ft_putptr(unsigned long n);
int		ft_putnbr(long n);
int		ft_putunbr(unsigned long n);
int		ft_strlen(char const *str);

#endif