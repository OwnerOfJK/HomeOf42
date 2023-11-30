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

char	*concatenate_strings(char *str1, char *str2, size_t len1, size_t len2)
{
	char	*result;

	result = malloc(len1 + len2 + 1);
	if (result == NULL)
	{
		free(str1);
		return (NULL);
	}
	ft_memcpy(result, str1, len1);
	ft_memcpy(result + len1, str2, len2);
	result[len1 + len2] = '\0';
	free(str1);
	return (result);
}

char	*input_line(int fd, char *buffer)
{
	char		*line;
	ssize_t		read_check;
	char		*newline_pos;
	size_t		line_len;
	size_t		part_len;

	read_check = 1;
	line_len = 0;
	while (read_check > 0)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1) 
			return (NULL);
		buffer[read_check] = '\0';
		newline_pos = ft_strchr(buffer, '\n');
		if (newline_pos != NULL)
		{
			part_len = newline_pos - buffer;
			line = concatenate_strings(line, buffer, line_len, part_len);
			break ;
		}
		else
		{
			line = concatenate_strings(line, buffer, line_len, read_check);
			line_len += read_check;
		}
	}
	printf("test %s", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	next_char;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = input_line(fd, buffer);
	free (buffer);
	buffer = NULL;
	if (line == NULL)
		return (0);
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
