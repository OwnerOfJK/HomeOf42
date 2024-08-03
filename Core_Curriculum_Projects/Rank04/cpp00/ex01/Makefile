# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:28:32 by jkaller           #+#    #+#              #
#    Updated: 2024/05/11 16:04:50 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the target executable
NAME = phonebook

# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Source files
SRCS = phonebook.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

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