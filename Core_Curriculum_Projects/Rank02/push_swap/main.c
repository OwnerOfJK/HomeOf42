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

int	*parse_number_input(int number_max, char **argv, int *stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ft_printf("argv[0]: %s\n", argv[0]);
	ft_printf("argv[1]: %s\n", argv[1]);
	while (i < number_max)
	{
		ft_printf("argv[i] in loop: %s\n", argv[i]);
		stack_a[j] = ft_atoi(argv[i]);
		ft_printf("stack_a[j] in loop: %i\n", stack_a[j]);
		i++;
		j++;
	}
	return (stack_a);
}


int	*sa(t_list *head_a)
{
	int	tmp;

	if (head_a && head_a->next)
	{
		tmp = head_a->val;
		head_a->val = head_a->next->val;
		head_a->next->val = tmp;
	}
	return (0);
}

void	initiate_linked_list(int argc, char **argv, t_list **head_a)
{
	t_list	*new_node;
	int		i;

	*head_a = NULL;
	i = 0;
	while (i < argc - 1)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&head_a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;

	initiate_linked_list(argc, argv, &head_a);
	sa(ft_lstsize(head_a));
	return (0);
}