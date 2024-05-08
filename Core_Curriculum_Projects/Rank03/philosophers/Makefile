# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 18:16:09 by jkaller           #+#    #+#              #
#    Updated: 2024/05/08 16:14:19 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the target executable
NAME = philo

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=address

# Source files
SRCS = main.c init/init_data.c free/free_data.c utils/function_utils.c \
 philosophers/philosophers.c philosophers/philosophers_utils.c error/error.c \
 philosophers/philosophers_actions.c philosophers/philosophers_monitor.c \
 philosophers/philosophers_eat_utils.c
 

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
all: $(NAME)

$(NAME): $(OBJS)

	# Link the executable
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean intermediate files
clean:
	# Remove object files
	rm -rf $(OBJS)

# Remove all generated files
fclean:
	# Remove object files and the target executable
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Rebuild the project
re: fclean all

# Specify the phony targets
.PHONY: all clean fclean re