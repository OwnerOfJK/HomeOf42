/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 22:07:34 by jkaller          ###   ########.fr       */
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
		new_node_stack = ft_lstnew(ft_atoi(argv[i]), NULL, NULL);
		ft_lstadd_back(head_stack, new_node_stack);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	parse_to_linkedlist(argc, argv, &head_a);
	if (argc == 4)
		sort_three(&head_a);
	if (argc == 6)
		sort_five(&head_a, &head_b);
	if (argc > 5)
		sort_all(&head_a, &head_b);
	ft_lstfree(head_a);
	ft_lstfree(head_b);
	return (0);
}
