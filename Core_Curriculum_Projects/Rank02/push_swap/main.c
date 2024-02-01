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

void	initiate_linked_list(int argc, char **argv, t_list **head_stack)
{
	t_list	*new_node_stack;
	int		i;

	*head_stack = NULL;
	i = 0;
	while (i < argc - 1)
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

	initiate_linked_list(argc, argv, &head_a);
	initiate_linked_list(argc, argv, &head_b);
	//sa(ft_lstsize(head_a));
	return (0);
}