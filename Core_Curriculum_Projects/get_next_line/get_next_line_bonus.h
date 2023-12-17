/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:16:29 by jkaller           #+#    #+#             */
/*   Updated: 2023/12/17 15:23:03 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_FD 10240

# include <stddef.h>

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char const *str);
char		*ft_strdup(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strncpy(char *dest, const char *src, int len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif