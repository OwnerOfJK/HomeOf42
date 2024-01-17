# Makefile for so_long

# Compiler
CC = gcc

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJ = $(SRCS:.c=.o)

# Output binary
TARGET = game

# mlx_linux directory
MLX_DIR = libs/mlx_linux
LIBFT_DIR = libs/libft

# Compiler flags
EFLAGS = -Wall -Wextra -Werror
CFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

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