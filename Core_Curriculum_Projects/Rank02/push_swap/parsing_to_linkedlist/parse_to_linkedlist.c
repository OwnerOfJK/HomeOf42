/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_linkedlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:20:47 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 13:59:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

int	check_for_chars(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!((*argv[i] >= 48) && (*argv[i] <= 57)))
		{			
			ft_printf("Error \n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	handle_string_of_numbers(int *argc, char **argv, t_list **head_stack_a)
{
	t_list	*new_node_stack;
	char	**word_array;
	int		amount_of_numbers;
	int		i;

	i = 0;
	amount_of_numbers = ft_count_words(argv[1], ' ');
	word_array = ft_split(argv[1], ' ');
	if (check_for_chars(amount_of_numbers, word_array) == 0)
		return ;
	while (i < amount_of_numbers)
	{
		new_node_stack = ft_lstnew(ft_atoi(word_array[i]), NULL, NULL);
		ft_lstadd_back(head_stack_a, new_node_stack);
		free(word_array[i]);
		i++;
	}
	*argc = amount_of_numbers;
	free(word_array);
}

void	parse_to_linkedlist(int *argc, char **argv, t_list **head_stack_a)
{
	t_list	*new_node_stack;
	int		i;

	*head_stack_a = NULL;
	if (*argc == 2)
		handle_string_of_numbers(argc, argv, head_stack_a);
	else
	{
		i = 1;
		if (check_for_chars(*argc, argv) == 0)
			return ;
		while (i < *argc)
		{
			if (!(*argv[i] > 48) && (*argv[i] < 57))
				return ;
			new_node_stack = ft_lstnew(ft_atoi(argv[i]), NULL, NULL);
			ft_lstadd_back(head_stack_a, new_node_stack);
			i++;
		}
	}
}
