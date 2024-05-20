# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 14:11:18 by jkaller           #+#    #+#              #
#    Updated: 2024/05/20 15:13:28 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = $(wildcard *.c)
PRINTF_SRCS = $(wildcard printf_utils/*.c)

OBJS        = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror
NAME        = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS)
	$(AR) rcs $(NAME) $(OBJS) $(PRINTF_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

printf_utils/%.o: printf_utils/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
