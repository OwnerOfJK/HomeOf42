# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 14:11:18 by jkaller           #+#    #+#              #
#    Updated: 2024/05/20 14:28:30 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			=		$(wildcard *.c)
PRINTF_SRCS 	= 		$(wildcard printf_utils/*.c)

OBJS			= $(SRCS:.c=.o)
PRINTF_OBJS		= $(PRINTF_SRCS:printf_utils/.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS)
		$(CC) $(CFLAGS) -c $(SRCS) $(PRINTF_SRCS)
		ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS)

clean:
		$(RM) $(OBJS) $(PRINTF_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
