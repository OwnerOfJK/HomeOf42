/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/12/16 23:28:08 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

int	deligate_static(char **line, char **start_of_next)
{
	char	*next_line;
	size_t	line_len;

	next_line = ft_strchr(*line, '\n');
	if (next_line == NULL)
	{
		*start_of_next = NULL;
		return (0);
	}
	line_len = next_line - *line + 1;
	*start_of_next = ft_substr(*line, line_len, ft_strlen(*line) - line_len);
	(*line)[line_len] = '\0';
	return (1);
}

char	*input_line(int fd, char *start_of_next, char *buffer)
{
	char	*line;
	char	*tmp_line;
	ssize_t	bytes_read;

	bytes_read = 1;
	line = start_of_next;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp_line = line;
		line = ft_strjoin(tmp_line, buffer);
		free(tmp_line);
		if (tmp_line == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*start_of_next;
	char		*line;
	char		*buffer;

	if (!start_of_next)
	{
		start_of_next = ft_strdup("");
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = input_line(fd, start_of_next, buffer);
	if (line == 0)
	{
		free(buffer);
		return (0);
	}
	if (deligate_static(&line, &start_of_next) == 0)
	{
		free (buffer);
		return (0);
	}
	free(buffer);
	return (line);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		return 1;
	}
	line = NULL;
	while ((line = get_next_line(fd)) != NULL) {
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}