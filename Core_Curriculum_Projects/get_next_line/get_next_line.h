/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:20 by jkaller           #+#    #+#             */
/*   Updated: 2023/12/16 23:28:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char const *str);
char		*ft_strdup(char *str);
char		*ft_strchr(char *s, int c);
void		*ft_memcpy(void *dst, const void *src, size_t len);
char		*ft_strncpy(char *dest, const char *src, int len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
