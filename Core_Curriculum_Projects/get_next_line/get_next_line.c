/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/29 12:24:15 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	int		chars_read;
	char	*buffer;
	char	*next_line;
	int		size;
	int		i;

	i = 0;
	size = 0;
	buffer = (char *)malloc(1 * sizeof(char));
	next_line = (char *)malloc(size + 1 * sizeof(char));
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	chars_read = read(fd, buffer, 1);
	while (chars_read != 0 && buffer[i] != '\n')
	{
		next_line[size] = *buffer;
		read(fd, buffer, 1);
		size++;
	}
	buffer[chars_read] = '\0';
	printf("%s \n", next_line);
	return (buffer);
}

int	main(void)
{
	int	fd;
	get_next_line(fd);
	//get_next_line(fd);
	return (0);
}
