# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:39:56 by jkaller           #+#    #+#              #
#    Updated: 2024/01/22 14:44:18 by jkaller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc -g

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJ = $(SRCS:.c=.o)

# Output binary
TARGET = so_long

# mlx_linux directory
MLX_DIR = libs/mlx_linux
LIBFT_DIR = libs/libft

# Compiler flags
EFLAGS = -Wall -Wextra -Werror
CFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -fPIE

all: mlx_linux $(TARGET)

# Build mlx_linux target
mlx_linux:
	$(MAKE) -C $(MLX_DIR)

# Build libft target
libft:
	$(MAKE) -C $(LIBFT_DIR)

$(TARGET): $(OBJ) mlx_linux libft
	$(CC) $(EFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(CFLAGS) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: all mlx_linux libft clean
