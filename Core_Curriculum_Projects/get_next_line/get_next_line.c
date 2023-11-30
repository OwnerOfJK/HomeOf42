/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/30 15:00:15 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

char *concatenate_strings(char *str1, char *str2, size_t len1, size_t len2)
{
    char *result;

    result = malloc(len1 + len2 + 1);
    if (result == NULL)
    {
        free(str1);
        return (NULL);
    }
    if (str1)
    {
        ft_memcpy(result, str1, len1);
        free(str1);
    }
    ft_memcpy(result + len1, str2, len2);
    result[len1 + len2] = '\0';
    return (result);
}

char *input_line(int fd, char *buffer)
{
    char *line;
    ssize_t read_check;
    char *newline_pos;
    size_t line_len;
    size_t part_len;

    line = NULL;
    line_len = 0;
    while (1)
    {
        read_check = read(fd, buffer, BUFFER_SIZE);
        if (read_check <= 0)
            return (line_len ? line : NULL);
        buffer[read_check] = '\0';
        newline_pos = ft_strchr(buffer, '\n');
        if (newline_pos)
        {
            part_len = newline_pos - buffer + 1;
            line = concatenate_strings(line, buffer, line_len, part_len);
            return (line);
        }
        else
        {
            line = concatenate_strings(line, buffer, line_len, read_check);
            if (!line)
                return (NULL);
            line_len += read_check;
        }
    }
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    if (!buffer)
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    char *line = input_line(fd, buffer);
    if (!line)
    {
        free(buffer);
        buffer = NULL;
    }
    return (line);
}

int main(void)
{
	int fd;
	char *line;
	
	fd = open("file.txt", O_RDONLY);
	if (fd == -1) 
	{
		return (1);
	}
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}

	close(fd);
	return 0;
}
