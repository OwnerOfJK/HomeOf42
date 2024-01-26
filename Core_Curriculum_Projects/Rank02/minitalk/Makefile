# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 15:55:34 by jkaller           #+#    #+#              #
#    Updated: 2024/01/26 15:56:40 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the target executable
NAME = so_long

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -Imlx

# Library files
LIBS = ./libs/libft/libft.a

# Source files
SRCS = main.c create_map.c error_handling.c free_and_close.c map_validity.c map_validity2.c player_movement.c prepare_map_array.c sprites_to_image.c valid_path_checks.c valid_path.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
all: $(NAME)

$(NAME): $(OBJS)
	# Build mlx_linux and libft targets
	make -C ./libs/libft

	# Link the executable
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Clean intermediate files
clean:
	# Clean mlx_linux and libft targets
	make clean -C ./libs/libft

	# Remove object files
	rm -rf $(OBJS)

# Remove all generated files
fclean:
	# Fclean mlx_linux and libft targets
	make fclean -C ./libs/libft

	# Remove object files and the target executable
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Rebuild the project
re: fclean all

# Specify the phony targets
.PHONY: all clean fclean re
