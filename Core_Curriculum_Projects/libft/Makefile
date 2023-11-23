NAME = libft.a

SRCS = ft_isascii.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isspace.c \
       ft_isalpha.c ft_islowalpha.c ft_isupalpha.c ft_toupper.c ft_tolower.c \
       ft_strlen.c ft_strlen_const.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
       ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
       ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
       ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
       ft_memchr.c ft_memcmp.c ft_strclr.c ft_striter.c ft_striteri.c \
       ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_itoa.c \
       ft_count_words.c \
       ft_split.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_putstr_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strmap.c \
       ft_strmapi.c ft_strjoin.c ft_strtrim.c \
       ft_strsub.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
