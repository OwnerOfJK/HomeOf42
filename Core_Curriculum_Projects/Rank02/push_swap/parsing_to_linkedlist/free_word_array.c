/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_word_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:33:46 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/07 14:42:42 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>
#include <stdbool.h>

void	free_word_array(char **word_array, int amount_of_words)
{
	int	i;

	i = 0;
	while (i < amount_of_words)
	{
		free(word_array[i]);
		i++;
	}
	free(word_array);
}
