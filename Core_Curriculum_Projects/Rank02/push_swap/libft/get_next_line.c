/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:16:32 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/23 22:21:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static char	*delegate_static(char *line)
{
	char	*start_of_next;
	ssize_t	line_len;

	line_len = 0;
	while (line[line_len] != '\n' && line[line_len] != '\0')
		line_len++;
	if (line[line_len] == 0 || line[1] == 0)
		return (NULL);
	start_of_next = ft_substr(line, line_len + 1, ft_strlen(line) - line_len);
	if (*start_of_next == 0)
	{
		free(start_of_next);
		start_of_next = NULL;
	}
	line[line_len + 1] = 0;
	return (start_of_next);
}

char	*input_line(int fd, char *start_of_next, char *buffer)
{
	char	*tmp_line;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(start_of_next);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!start_of_next)
			start_of_next = ft_strdup("");
		tmp_line = start_of_next;
		start_of_next = ft_strjoin(tmp_line, buffer);
		free(tmp_line);
		tmp_line = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (start_of_next);
}

char	*get_next_line(int fd)
{
	static char	*start_of_next[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(start_of_next[fd]);
		free(buffer);
		start_of_next[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = input_line(fd, start_of_next[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	start_of_next[fd] = delegate_static(line);
	return (line);
}
