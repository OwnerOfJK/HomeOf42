/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:29:50 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 23:08:09 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

void	ft_putchar(char c);
int		ft_puthexa(unsigned int nbr, int upper_case);
void	ft_putstr(char *s);
int		ft_putptr(void *addr);
void	ft_putdec(double n);
void	ft_putnbr(int n);
void	ft_putstr(char *s);


#endif
