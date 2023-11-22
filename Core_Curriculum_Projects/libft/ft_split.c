/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:43:11 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:43:12 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int word_count = ft_countwords_delim(str, *charset);
    char **string_array = (char **)malloc((word_count + 1) * sizeof(char*));
    if (string_array == NULL)
    {
        return (0);
    }
    while (str[i] != '\0')
    {
        while (ft_checkchar(str[i], *charset) == 1 && str[i] != '\0') // Skip the delimiters
        {
            i++;
        }
        if (str[i] != '\0') // If there is a word
        {
            int len = ft_wordlen_delim(&str[i], *charset); // Calculate the word length
            string_array[j] = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the word + null terminating character
            if (string_array[j] == NULL) // Check for allocation failure
            {
                return (NULL);
            }
            k = 0;
            while (ft_checkchar(str[i], *charset) == 0 && str[i] != '\0')
            {
                string_array[j][k] = str[i];
                k++;
                i++;
            }
            string_array[j][k] = '\0';
            j++;
        }
    }
    string_array[j] = NULL;
    return (string_array);
}

int main(void)
{
    int i = 0;
    char **test_string_array;
    int word_count = 0;
    char delim = '-';
    char str[] = "What-is----going-on";
    word_count = ft_countwords_delim(str, '-');
    test_string_array = ft_split(str, &delim);
    if (test_string_array == NULL)
    {
        return (0);
    }
    printf("%d\n", word_count);
    printf("%s\n", test_string_array[3]);
    while (i < word_count)
    {
        free(test_string_array[i]);
        i++;
    }
    free(test_string_array);
}