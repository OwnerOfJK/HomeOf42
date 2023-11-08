/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:02:26 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/07 19:09:26 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	error(int nbr)
{
	if (nbr == 1)
	{
		ft_putstr("File name missing. \n");
	}
	if (nbr == 2)
	{
		ft_putstr("Too many arguments. \n");
	}
	if (nbr == 3)
	{
		ft_putstr("Cannot read file. \n");
	}
}

void	ft_display_file(char *file_name)
{
	int		fd;
	int		sz;
	char	buffer[20];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		error(3);
	}
	sz = read(fd, buffer, 20);
	if (sz > 0)
	{
		write(1, buffer, sz);
		ft_putchar('\n');
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		error(1);
	}
	else if (argc > 2)
	{
		error(2);
	}
	else
	{
		ft_display_file(argv[1]);
	}
	return (0);
}
