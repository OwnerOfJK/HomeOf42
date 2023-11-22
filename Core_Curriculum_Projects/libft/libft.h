/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:30 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 16:30:40 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HEADER
#define	LIBFT_HEADER
#include <string.h>

//Function Protoypes
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_islowalpha(int c); //extra
int		ft_isupalpha(int c); //extrac
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strlen(char *str);
int		ft_strlen_const(char const *str);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, int len);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, int len);
int		ft_strlcat(char *dest, const char *src, int len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(char *str, char *substr);
char	*ft_strnstr(char *str, char *substr, int len);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, int len);
int		ft_atoi(const char *str);
void	*ft_memset(void *dst, int c, size_t len);
void	ft_bzero(void *dst, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *src, int c, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
int		ft_wordlen_delim(char *str, char delim); //extra
int		ft_countwords_delim(char *str, char charset); //extra
int		ft_checkchar(char c, char delim); //extra
char	**ft_split(char *str, char *charset);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//int     ft_strequ(char const *s1, char const *s2);
//int     ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
