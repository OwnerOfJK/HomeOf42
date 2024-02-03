/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:07 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 15:41:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	ra(t_list **head_stack_a)
{
	t_list	*first_node;
	t_list	*current_node;

	if (*head_stack_a && (*head_stack_a)->next)
	{
		first_node = *head_stack_a;
		ft_lstadd_back(head_stack_a, ft_lstnew(first_node->val, ft_lstsize(*head_stack_a) + 1));
		*head_stack_a = first_node->next;
		current_node = *head_stack_a;
		while (current_node)
		{
			current_node->index--;
			current_node = current_node->next;
		}
		free(first_node);
	}
	ft_printf("ra\n");
}

void	rb(t_list **head_stack_b)
{
	t_list	*first_node;
	t_list	*current_node;

	if (*head_stack_b && (*head_stack_b)->next)
	{
		first_node = *head_stack_b;
		ft_lstadd_back(head_stack_b, ft_lstnew(first_node->val, ft_lstsize(*head_stack_b) + 1));
		*head_stack_b = first_node->next;
		current_node = *head_stack_b;
		while (current_node)
		{
			current_node->index--;
			current_node = current_node->next;
		}
		free(first_node);
	}
	ft_printf("rb\n");
}

void	rr(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
		ra(head_stack_a);
	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
		rb(head_stack_b);
}
