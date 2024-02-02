/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:07 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 18:37:43 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rotate_down(t_list **head_stack)
{
	t_list	*last_node;
	t_list	*prev_node;

	if (*head_stack && (*head_stack)->next)
	{
		last_node = *head_stack;
		//increment_index((*head_stack)->next);
		while (last_node->next)
		{
			last_node->index++;
			prev_node = last_node;
			last_node = last_node->next;
		}
		if (prev_node)
		{
			prev_node->next = NULL;
			free(prev_node->next);
		}
		ft_lstadd_front(head_stack, ft_lstnew(last_node->val, 1));
		free(last_node);
	}
	ft_printf("rotate_down\n");
}

void	rotate_down_both(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		rotate_down(head_stack_a);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rotate_down(head_stack_b);
}

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
	ft_printf("rotate_up\n");
}

void	rotate_up_both(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		rotate_up(head_stack_a);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rotate_up(head_stack_b);
}
