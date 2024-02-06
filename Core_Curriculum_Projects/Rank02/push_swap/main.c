/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 13:31:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		*argc_pointer;

	head_a = NULL;
	head_b = NULL;
	argc_pointer = &argc;
	if (argc <= 1)
		ft_printf("Error \n");
	else
	{
		parse_to_linkedlist(argc_pointer, argv, &head_a);
		if (confirm_order(head_a) == 0)
		{
			if (*argc_pointer == 3)
				sort_two(&head_a);
			if (*argc_pointer == 4)
				sort_three(&head_a);
			else if (*argc_pointer > 4)
				sort_all(&head_a, &head_b);
		}
	}
	print_stacks(head_a, head_b);
	ft_lstfree(head_a);
	ft_lstfree(head_b);
	return (0);
}
