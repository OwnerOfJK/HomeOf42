/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:43:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/28 16:37:16 by jkaller          ###   ########.fr       */
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

void	initiate_linked_list(int argc, char **argv)
{
	node_t * head = NULL;
	head = (node_t *) malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 1;
	head->next = NULL;
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	i;

	ft_printf("argv[0]: %s\n", argv[0]);
	ft_printf("argv[1]: %s\n", argv[1]);
	i = 0;
	initiate_linked_list(argc, argv);
	stack_a = (int *)malloc(argc * sizeof(int *));
	stack_b = (int *)malloc(argc * sizeof(int *));
	parse_number_input(argc, argv, stack_a);
	parse_number_input(argc, argv, stack_b);
	sa(argc, stack_a);
	// sb(argc, stack_b);
	// ss(argc, stack_a, stack_b);
	pa(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (i < argc - 1)
	{
		ft_printf("%i", stack_a[i]);
		ft_printf("%i", stack_b[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}