/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/31 18:06:36 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	parse_to_empty_linkedlist(int argc, t_list **head_stack)
{
	t_list	*new_node_stack;
	int		i;

	*head_stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node_stack = ft_lstnew(0, i);
		ft_lstadd_back(head_stack, new_node_stack);
		i++;
	}
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

	parse_to_linkedlist(argc, argv, &head_a);
	parse_to_empty_linkedlist(argc, &head_b);
	//swap(&head_a);
	// swap(&head_a);
	pb(&head_a, &head_b);
	//rotate_up(&head_a);
	while (head_a)
    {
		ft_printf("value of head_a: %i\n", head_a->val);
		//ft_printf("index of head_a: %i\n", head_a->index);
        head_a = head_a->next;
    }
	while (head_b)
    {
		ft_printf("value of head_b: %i\n", head_b->val);
		//ft_printf("index of head_b: %i\n", head_b->index);
        head_b = head_b->next;
    }
	return (0);
}
