/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 16:45:01 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	confirm_order(t_list *head_stack)
{
	while (head_stack && head_stack->next)
	{
		if (head_stack->val > head_stack->next->val)
			return (0);
		head_stack = head_stack->next;
	}
	return (1);
}

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
	//int		required_operations;

	head_a = NULL;
	head_b = NULL;
	parse_to_linkedlist(argc, argv, &head_a);

	//just for testing
	sa(&head_a);
	ss(&head_a, &head_b);
	ss(&head_a, &head_b);
	ss(&head_a, &head_b);
	pb(&head_a, &head_b);
	pa(&head_a, &head_b);
	pa(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	sa(&head_a);
	ra(&head_a);
	rra(&head_a);
	rra(&head_a);
	rra(&head_a);
	ra(&head_a);
	rb(&head_b);
	rr(&head_a, &head_b);
	rr(&head_a, &head_b);
	rr(&head_a, &head_b);
	rrr(&head_a, &head_b);
	rr(&head_a, &head_b);
	rrr(&head_a, &head_b);

	// if (argc == 4)
	// {
	// 	required_operations = sort_three(&head_a);
	// 	ft_printf("To solve, it required %i steps!\n", required_operations);
	// }
	// if (argc == 6)
	// {
	// 	required_operations = sort_five(&head_a, &head_b);
	// 	ft_printf("To solve, it required %i steps!\n", required_operations);
	// }
	// if (argc == 101)
	// {
	// 	required_operations = sort_hundred(&head_a, &head_b);
	// 	ft_printf("To solve, it required %i steps!\n", required_operations);
	// }
	// if (argc == 501)
	// {
	// 	required_operations = sort_fivehundred(&head_a, &head_b);
	// 	ft_printf("To solve, it required %i steps!\n", required_operations);
	// }

	// just for printing
	t_list *current_a = head_a;
	while (current_a)
	{
		ft_printf("head_b: val %i | index %i\n", current_a->val, current_a->index);
		t_list *next_a = current_a->next;  // Declare next_a inside the loop
		free(current_a);
		current_a = next_a;
	}
	ft_printf("______________________________\n\n");
	t_list *current_b = head_b;
	while (current_b)
	{
		ft_printf("head_b: val %i | index %i\n", current_b->val, current_b->index);
		t_list *next_b = current_b->next;  // Declare next_b inside the loop
		free(current_b);
		current_b = next_b;
	}


	//freeing (comment out since we free during print)
    // ft_lstfree(head_a);
    // ft_lstfree(head_b);
	return (0);
}
