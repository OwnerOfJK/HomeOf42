/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/30 19:14:27 by jkaller          ###   ########.fr       */
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

	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
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

char	*create_line(char *line, char *buffer, size_t *line_len, char **new_pos)
{
	size_t	part_len;

	*new_pos = ft_strchr(buffer, '\n');
	if (*new_pos)
	{
		part_len = *new_pos - buffer + 1;
		line = concatenate_strings(line, buffer, *line_len, part_len);
		return (line);
	}
	else 
	{
		part_len = ft_strlen(buffer);
		line = concatenate_strings(line, buffer, *line_len, part_len);
		if (!line)
			return (NULL);
		*line_len += part_len;
		return (line);
	}
}

char	*input_line(int fd, char *buffer, size_t *line_len)
{
	char		*line;
	ssize_t		read_check;
	char		*new_pos;

	line = NULL;
	while (1)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check <= 0)
			break ;
		buffer[read_check] = '\0';
		line = create_line(line, buffer, line_len, &new_pos);
		if (new_pos || !line)
			break ;
	}
	if (read_check <= 0 && *line_len == 0)
		return (NULL);
	else
		return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	line_len;
	char			*line;

	buffer = NULL;
	line_len = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	if (buffer == NULL)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL) 
			return (NULL);
	}
	line = input_line(fd, buffer, &line_len);
	if (line == NULL) 
	{
		free(buffer);
		buffer = NULL;
		line_len = 0;
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

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
	return (0);
}
