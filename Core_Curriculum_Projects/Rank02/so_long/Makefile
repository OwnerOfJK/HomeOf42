# Makefile for so_long

# Compiler
CC = gcc

# Source files
SRCS = $(wildcard *.c)

# Output binary
TARGET = game

# mlx_linux directory
MLX_DIR = mlx_linux

# Compiler flags
CFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

all: mlx_linux $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $^ $(CFLAGS) -o $@

# Build mlx_linux target
mlx_linux:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(TARGET)
	$(MAKE) -C $(MLX_DIR) clean

.PHONY: all mlx_linux clean
