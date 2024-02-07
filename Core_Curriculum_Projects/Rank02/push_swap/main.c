/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/07 21:47:30 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	sort_numbers(t_list **head_stack_a, t_list **head_stack_b, int argc)
{
	if (argc == 3)
		sort_two(head_stack_a);
	if (argc == 4)
		sort_three(head_stack_a);
	else if (argc > 4)
		sort_all(head_stack_a, head_stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		*argc_pointer;

	head_a = NULL;
	head_b = NULL;
	argc_pointer = &argc;
	if (argc <= 1)
		return (0);
	else
	{
		if (parse_to_linkedlist(argc_pointer, argv, &head_a) == 1)
		{
			if (confirm_order(head_a) == 0)
				sort_numbers(&head_a, &head_b, *argc_pointer);
		}
	}
	ft_lstfree(head_a);
	ft_lstfree(head_b);
	return (0);
}
