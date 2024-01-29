/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 20:49:28 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*sa(int argc, int *stack_a)
{
	int	tmp;

	if (argc > 1)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
	}
	return (0);
}

int	*sb(int argc, int *stack_b)
{
	int	tmp;

	if (argc > 1)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
	}
	return (0);
}

int	*ss(int argc, int *stack_a, int *stack_b)
{
	sa(argc, stack_a);
	sb(argc, stack_b);
	return (0);
}
