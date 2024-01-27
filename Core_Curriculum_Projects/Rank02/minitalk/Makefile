# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 15:55:34 by jkaller           #+#    #+#              #
#    Updated: 2024/01/27 16:55:25 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the target executable
NAME = minitalk

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Library files
LIBS = ./libft/libft.a

# Source files
SRCS = client.c server.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
all: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft
	
# Clean intermediate files
clean:
	# Clean libft targets
	make clean -C ./libft
	# Remove object files
	rm -rf $(OBJS)

# Remove all generated files
fclean:
	# Fclean libft targets
	make fclean -C ./libft
	# Remove object files and the target executable
	rm -rf $(OBJS)
	rm -rf server client

# Rebuild the project
re: fclean all

# Specify the phony targets
.PHONY: all libft clean fclean re
