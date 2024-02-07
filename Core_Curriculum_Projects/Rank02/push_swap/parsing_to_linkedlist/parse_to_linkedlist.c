/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_linkedlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:20:47 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/07 23:05:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>
#include <stdbool.h>

int	parse_to_linkedlist(int *argc, char **argv, t_list **head_stack_a)
{
	t_list	*new_node_stack;
	int		i;

	*head_stack_a = NULL;
	if (*argc == 2)
	{
		if (string_of_numbers(argc, argv, head_stack_a) == 0)
			return (0);
	}
	else
	{
		i = 1;
		if (number_check_for_all(*argc, argv) == 0)
			return (0);
		while (i < *argc)
		{
			new_node_stack = ft_lstnew(ft_atoi(argv[i]), NULL, NULL);
			ft_lstadd_back(head_stack_a, new_node_stack);
			i++;
		}
	}
	return (1);
}
