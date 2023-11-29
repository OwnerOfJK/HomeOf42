# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 19:30:10 by jkaller           #+#    #+#              #
#    Updated: 2023/11/29 19:30:27 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -c $(SRCS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re