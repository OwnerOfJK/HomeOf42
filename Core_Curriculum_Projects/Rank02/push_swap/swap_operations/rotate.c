/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:07 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 20:15:08 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	rotate_up(t_list **head_stack)
{
    t_list *last_node;

    if (*head_stack && (*head_stack)->next)
    {
        last_node = *head_stack;
        while (last_node->next)
        {
            last_node->index++;
            last_node = last_node->next;
        }
        ft_lstadd_front(head_stack, ft_lstnew(last_node->val, 1));
        delete_list(last_node);
    }
}

void	rotate_up_both(t_list **head_stack_a, t_list **head_stack_b)
{
    if (head_stack_a && *head_stack_a && (*head_stack_a)->next &&
        head_stack_b && *head_stack_b && (*head_stack_b)->next)
	{
        rotate_up(head_stack_a);
        rotate_up(head_stack_b);
    }
}

void	rotate_down(t_list **head_stack)
{
    t_list *first_node;

    if (*head_stack && (*head_stack)->next)
    {
        first_node = (*head_stack);
        delete_list(first_node);
        while (first_node->next)
        {
            first_node->index--;
            first_node = first_node->next;
        }
        ft_lstadd_back(head_stack, ft_lstnew(first_node->val, ft_lstsize(*head_stack) + 1));
    }
}

void	rotate_down_both(t_list **head_stack_a, t_list **head_stack_b)
{
    if (head_stack_a && *head_stack_a && (*head_stack_a)->next &&
        head_stack_b && *head_stack_b && (*head_stack_b)->next)
	{
        rotate_down(head_stack_a);
        rotate_down(head_stack_b);
    }
}