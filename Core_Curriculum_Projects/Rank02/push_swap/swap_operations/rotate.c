/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:07 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 16:43:45 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rotate_up(t_list **head_stack)
{
	t_list	*first_node;
	t_list	*current_node;

	if (*head_stack && (*head_stack)->next)
	{
		first_node = *head_stack;
		ft_lstadd_back(head_stack, ft_lstnew(first_node->val, ft_lstsize(*head_stack) + 1));
		*head_stack = first_node->next;
		current_node = *head_stack;
		while (current_node)
		{
			current_node->index--;
			current_node = current_node->next;
		}
		free(first_node);
	}
}

void	ra(t_list **head_stack_a)
{
	if (head_stack_a && (*head_stack_a)->next)
	{
		rotate_up(head_stack_a);
		ft_printf("ra\n");
	}
}

void	rb(t_list **head_stack_b)
{
	if (head_stack_b && (*head_stack_b)->next)
	{
		rotate_up(head_stack_b);
		ft_printf("rb\n");
	}
}

void	rr(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		ra(head_stack_a);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rb(head_stack_b);
}
