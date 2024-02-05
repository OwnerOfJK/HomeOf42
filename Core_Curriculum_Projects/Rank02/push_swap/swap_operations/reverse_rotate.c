/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:28:16 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 21:08:38 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rotate_down(t_list **head_stack)
{
	t_list	*last_node;

	if (*head_stack && (*head_stack)->next)
	{
		last_node = ft_lstlast(*head_stack);
		if (last_node->previous)
		{
			last_node->previous->next = NULL;
			last_node->previous = NULL;
			last_node->next = *head_stack;
			(*head_stack)->previous = last_node;
			*head_stack = last_node;
		}
		else
		{
			*head_stack = last_node;
		}
	}
}

void	rra(t_list **head_stack_a, bool flag)
{
	if (head_stack_a && (*head_stack_a)->next)
		rotate_down(head_stack_a);
	if (flag == false)
		ft_printf("rra\n");
}

void	rrb(t_list **head_stack_b, bool flag)
{
	if (head_stack_b && (*head_stack_b)->next)
		rotate_down(head_stack_b);
	if (flag == false)
		ft_printf("rrb\n");
}

void	rrr(t_list **head_stack_a, t_list **head_stack_b, bool flag)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		rra(head_stack_a, flag);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rrb(head_stack_b, flag);
	ft_printf("rrr\n");
}
