/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:53:38 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/07 23:04:54 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>
#include <stdbool.h>

void	free_word_array(char **word_array, int amount_of_words)
{
	int	i;

	i = 0;
	while (i < amount_of_words)
	{
		free(word_array[i]);
		i++;
	}
	free(word_array);
}

bool	string_has_duplicate_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
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

int	string_is_valid_number(const char *str)
{
	long long	num;
	int			i;

	i = 0;
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

int	string_check_for_all(int argc, char **argv, int argv_index)
{
	while (argv_index < argc)
	{
		if (!string_is_valid_number(argv[argv_index]) 
			|| string_has_duplicate_numbers(argc, argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		argv_index++;
	}
	return (1);
}

int	string_of_numbers(int *argc, char **argv, t_list **head_stack_a)
{
	t_list	*new_node_stack;
	char	**word_array;
	int		amount_of_numbers;
	int		i;

	i = 0;
	amount_of_numbers = ft_count_words(argv[1], ' ');
	word_array = ft_split(argv[1], ' ');
	if (!word_array)
		return (0);
	if (string_check_for_all(amount_of_numbers, word_array, 0) == 0)
	{
		free_word_array(word_array, amount_of_numbers);
		return (0);
	}
	while (i < amount_of_numbers)
	{
		new_node_stack = ft_lstnew(ft_atoi(word_array[i]), NULL, NULL);
		ft_lstadd_back(head_stack_a, new_node_stack);
		free(word_array[i]);
		i++;
	}
	*argc = amount_of_numbers;
	free(word_array);
	return (1);
}
