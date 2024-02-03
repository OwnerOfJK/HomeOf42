# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:39:56 by jkaller           #+#    #+#              #
#    Updated: 2024/02/03 17:33:04 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the target executable
NAME = push_swap

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Library files
LIBS = ./libft/libft.a

# Source files
SRCS = $(wildcard *.c) $(wildcard swap_operations/*.c) $(wildcard list_specific_functions/*.c) $(wildcard sorting_algo/sort_three_operations/*.c) $(wildcard sorting_algo/sort_five_operations/*.c) $(wildcard sorting_algo/sort_hundred_operations/*.c) $(wildcard sorting_algo/sort_fivehundred_operations/*.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
all: $(NAME)

$(NAME): $(OBJS)
	# Build mlx_linux and libft targets
	make -C ./libft

	# Link the executable
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Clean intermediate files
clean:
	# Clean mlx_linux and libft targets
	make clean -C ./libft

	# Remove object files
	rm -rf $(OBJS)

# Remove all generated files
fclean:
	# Fclean mlx_linux and libft targets
	make fclean -C ./libft

	# Remove object files and the target executable
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Rebuild the project
re: fclean all

# Specify the phony targets
.PHONY: all clean fclean re
