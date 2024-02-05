/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:07 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 21:11:45 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rotate_up(t_list **head_stack)
{
	t_list	*last_node;

	if (*head_stack && (*head_stack)->next)
	{
		last_node = ft_lstlast(*head_stack);
		if (last_node->previous)
		{
			last_node->next = (*head_stack);
			*head_stack = (*head_stack)->next;
			(*head_stack)->previous = NULL;
			last_node->next->previous = last_node;
			last_node->next->next = NULL;
		}
		else
		{
			*head_stack = (*head_stack)->next;
			(*head_stack)->previous = NULL;
			last_node->next = last_node;
		}
	}
}

void	ra(t_list **head_stack_a, bool flag)
{
	if (head_stack_a && (*head_stack_a)->next)
		rotate_up(head_stack_a);
	if (flag == false)
		ft_printf("ra\n");
}

void	rb(t_list **head_stack_b, bool flag)
{
	if (head_stack_b && (*head_stack_b)->next)
		rotate_up(head_stack_b);
	if (flag == false)
		ft_printf("rb\n");
}

void	rr(t_list **head_stack_a, t_list **head_stack_b, bool flag)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		ra(head_stack_a, flag);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rb(head_stack_b, flag);
	ft_printf("rr\n");
}
