/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:55:03 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/07 22:52:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>
#include <stdbool.h>

bool	numbers_have_duplicate_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	is_valid_number(char *str)
{
	long long	num;
	int			i;
	int			j;

	i = 0;
	j = 0;
	num = ft_atoll(&str[i]);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
		if (ft_isdigit(str[i - 2]))
			return (0);
	}
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (str[i] == '\0');
}

int	number_check_for_all(int argc, char **argv)
{
	int	i;

	i = 1;
	if (numbers_have_duplicate_numbers(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
