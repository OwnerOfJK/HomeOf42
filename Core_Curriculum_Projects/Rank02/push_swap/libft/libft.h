/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:23:30 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 16:45:09 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define MAX_FD 10

# include <string.h>

//Function Protoypes
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_islowalpha(int c);
int			ft_isupalpha(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlen(char const *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strncpy(char *dest, const char *src, int len);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, int len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strstr(char *str, char *substr);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		*ft_memset(void *dst, int c, size_t len);
void		ft_bzero(void *dst, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *src, int c, size_t size);
int			ft_memcmp(const void *str1, const void *str2, size_t size);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
char		*ft_itoa(int n);
int			ft_count_words(const char *str, char c);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_calloc(size_t count, size_t size);
int			ft_printf(const char *format, ...);
int			pft_putchar(char c);
int			ft_lower_puthexa(long nbr);
int			ft_upper_puthexa(long nbr);
int			pft_putstr(char *s);
int			ft_putptr(unsigned long n);
int			ft_putdec(double n);
int			pft_putnbr(long n);
size_t		ft_getdigits(long n);
int			ft_putunbr(unsigned long n);
int			pft_strlen(char const *str);
char		*get_next_line(int fd);
long long	ft_atoll(const char *str);

#endif
