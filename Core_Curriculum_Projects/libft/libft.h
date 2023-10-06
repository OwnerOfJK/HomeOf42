#ifndef LIBFT_HEADER
#define LIBFT_HEADER

#include <string.h>

//Function Protoypes
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isprint(int c);
int     ft_isspace(int c);
int     ft_isalpha(int c);
int     ft_islowalpha(int c);
int     ft_isupalpha(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
int     ft_strlen(char *str);
char    *ft_strdup(const char *str);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strncpy(char *dest, const char *src, int len);
char    *ft_strcat(char *dest, const char *src);
char    *ft_strncat(char *dest, const char *src, int len);
int     ft_strlcat(char *dest, const char *src, int len);
char    *ft_strchr(char *str, int c);
char    *ft_strrchr(char *str, int c);
char    *ft_strstr(char *str, char *substr);
char    *ft_strnstr(char *str, char *substr, int len);
int     ft_strcmp(const char *str1, const char *str2);
int     ft_strncmp(const char *str1, const char *str2, int len);
int     ft_atoi(const char *str);
void    *ft_memset(void* dst, int c, size_t len);
void    ft_bzero(void *dst, size_t n);
void    *ft_memcpy(void* dst, const void* src, size_t len);
void    *ft_memccpy(void* dst, const void* src, int c, size_t len);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(void *src, int c, size_t size);
int     ft_memcmp(const void *str1, const void *str2, size_t size);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putendl(char const *s);
void    ft_putnbr(int nbr);
char    *ft_itoa(int n);
int     ft_wordlen_delim(char *str, char delim); //extra
int     ft_countwords_delim(char *str, char charset); //extra
int     ft_checkchar(char c, char delim); //extra
char    **ft_split(char *str, char *charset);

#endif