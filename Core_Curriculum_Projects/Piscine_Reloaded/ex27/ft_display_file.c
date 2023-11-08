/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:08:21 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/08 20:12:45 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		yolo;
	char	c;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "File name missing.\n", 19);
		if (argc > 2)
			write(1, "Too many arguments.\n", 20);
		return (1);
	}
	yolo = open(argv[1], O_RDONLY);
	while (read(yolo, &c, 1) != 0)
		write(1, &c, 1);
	close(yolo);
	return (0);
}
