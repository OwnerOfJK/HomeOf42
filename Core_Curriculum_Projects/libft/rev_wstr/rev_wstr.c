/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:31:53 by jkaller           #+#    #+#             */
/*   Updated: 2023/12/20 11:19:04 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(int c);
char	*rev_wstr(char *str);
int		ft_strlen(char *str);
void	ft_pustr(char *str);

int	main(int argc, char **argv)
{
	char	*result;
	
	if (argc == 2)
	{
		result = rev_wstr(argv[1]);
		ft_pustr(result);
	}
	else
		ft_putchar('\n');
	return (0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_pustr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	while (str[i] != '\0')
		i++;
	return (i);
}

char	*rev_wstr(char *str)
{
	int		i;
	int		start;
	int 	j;
	int		str_len;
	char	*result_string;

	i = 0;
	j = 0;
	str_len = ft_strlen(str);
	result_string = (char *)malloc((str_len + 1) * sizeof(char));
	while (i <= str_len)
	{
		if (i == str_len || str[str_len - 1] == ' ' || str[str_len - 1] == '\t')
		{
			start = str_len;
			while (str[start] != '\0' && str[start] != ' ' && str[start] != '\t')
			{
				result_string[j] = str[start];
				start++;
				j++;
			}
			result_string[j] = ' ';
			j++;
		}
		str_len--;
	}
	result_string[j - 1] = '\0';
	return (result_string);
}