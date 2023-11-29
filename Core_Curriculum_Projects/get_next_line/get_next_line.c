/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/29 19:35:23 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char	*print_line(int fd, char *buffer)
{
	//int			chars_read;
	char		*next_line;
	int			size;
	int			i;

	i = 0;
	size = 0;
	buffer = (char *)malloc(1 * sizeof(char));
	next_line = (char *)malloc(size + 1 * sizeof(char));
	read(fd, buffer, 1);
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		next_line[size] = buffer[i];
		read(fd, buffer, 1);
		size++;
	}
	next_line[size] = '\0';
	printf("%s \n", next_line);
	return (&buffer[i]);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (buffer == NULL)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		if (buffer == NULL)
		{
			return (NULL);
		}
	}
	buffer = print_line(fd, buffer);
	if (buffer[0] != '\0' && buffer[0] != '\n')
	{
		line = buffer;
		buffer = print_line(fd, buffer);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	//char 	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	printf("%s", get_next_line(fd));
	//get_next_line(fd);
	//get_next_line(fd);
						
	// while ((line = get_next_line(fd)) != NULL) {
	// 	printf("Line: %s\n", line);
	// }
	close(fd);
	return (0);
}
