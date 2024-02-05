/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 20:57:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	pa(t_list **head_stack_a, t_list **head_stack_b)
{
	t_list	*node_to_push;

	if (head_stack_b && *head_stack_b)
	{
		node_to_push = *head_stack_b;
		*head_stack_b = (*head_stack_b)->next;
		if (*head_stack_b)
			(*head_stack_b)->previous = NULL;
		node_to_push->previous = NULL;
		if (*head_stack_a)
		{
			node_to_push->next = *head_stack_a;
			(*head_stack_a)->previous = node_to_push;
		}
		else
			node_to_push->next = NULL;
		*head_stack_a = node_to_push;
	}
	ft_printf("pa\n");
}

void	pb(t_list **head_stack_a, t_list **head_stack_b)
{
	t_list	*node_to_push;

	if (head_stack_a && *head_stack_a)
	{
		node_to_push = *head_stack_a;
		*head_stack_a = (*head_stack_a)->next;
		if (*head_stack_a)
			(*head_stack_a)->previous = NULL;
		node_to_push->previous = NULL;
		if (*head_stack_b)
		{
			node_to_push->next = *head_stack_b;
			(*head_stack_b)->previous = node_to_push;
		}
		else
			node_to_push->next = NULL;
		*head_stack_b = node_to_push;
	}
	ft_printf("pb\n");
}

