/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 17:00:01 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	parse_to_linkedlist(int argc, char **argv, t_list **head_stack)
{
	t_list	*new_node_stack;
	int		i;

	*head_stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node_stack = ft_lstnew(ft_atoi(argv[i]), i);
		ft_lstadd_back(head_stack, new_node_stack);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	parse_to_linkedlist(argc, argv, &head_a);
	swap(&head_a);
	swap_both(&head_a, &head_b);
	swap_both(&head_a, &head_b);
	swap_both(&head_a, &head_b);
	pb(&head_a, &head_b);
	pa(&head_a, &head_b);
	pa(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	swap(&head_a);
	rotate_up(&head_a);
	rotate_down(&head_a);
	rotate_down(&head_a);
	rotate_down(&head_a);
	rotate_up(&head_a);
	rotate_up(&head_b);
	rotate_down_both(&head_a, &head_b);
	rotate_down_both(&head_a, &head_b);
	rotate_down_both(&head_a, &head_b);
	rotate_up_both(&head_a, &head_b);
	rotate_up_both(&head_a, &head_b);
	rotate_up_both(&head_a, &head_b);
	while (head_a)
	{
		ft_printf("head_a: val %i | index %i\n", head_a->val, head_a->index);
		head_a = head_a->next;
	}
	ft_printf("_______________________\n\n");
	while (head_b)
	{
		ft_printf("head_b: val %i | index %i\n", head_b->val, head_b->index);
		head_b = head_b->next;
	}
	free(head_a);
	free(head_b);
	return (0);
}
