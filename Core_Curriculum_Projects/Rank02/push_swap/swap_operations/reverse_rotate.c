/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:28:16 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 15:41:55 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rra(t_list **head_stack_a)
{
	t_list	*last_node;
	t_list	*prev_node;

	if (*head_stack_a && (*head_stack_a)->next)
	{
		last_node = *head_stack_a;
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
		ft_lstadd_front(head_stack_a, ft_lstnew(last_node->val, 1));
		free(last_node);
	}
	ft_printf("rra\n");
}

void	rrb(t_list **head_stack_b)
{
	t_list	*last_node;
	t_list	*prev_node;

	if (*head_stack_b && (*head_stack_b)->next)
	{
		last_node = *head_stack_b;
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
		ft_lstadd_front(head_stack_b, ft_lstnew(last_node->val, 1));
		free(last_node);
	}
	ft_printf("rrb\n");
}

void	rrr(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		rra(head_stack_a);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rrb(head_stack_b);
}