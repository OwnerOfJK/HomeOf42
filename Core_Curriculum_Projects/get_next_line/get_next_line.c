/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:23 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/28 19:12:26 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		chars_read;
	char	*buffer;
	int		size;
	int		i;

	buffer = (char *)malloc(1 * sizeof(char));
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((chars_read = read(fd, buffer, 1)) != 0 && *buffer != '\n')
	{
		buffer[chars_read] = '\0';
		//printf("Those bytes are as follows: %c \n", buffer[i]);
		// while (buffer[i] != '\n')
		// {

		// 	i++;
		// }
		printf("called read(%d, buffer, 50). returned that %d bytes were read.\n", fd, chars_read);
		printf("Those bytes are as follows: %s \n", buffer);
		buffer++;
	}
	// while (*buffer != '\n')
	// 	size++;
	return (buffer);
}

int	main(void)
{
	int	fd;
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}
