#ifndef LIBFT_HEADER
#define LIBFT_HEADER

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

int     ft_atoi(const char *str);

#endif