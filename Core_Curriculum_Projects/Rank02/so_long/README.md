## Compilation Command

gcc main.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

valgrind --leak-check=full ./so_long maps/medium.ber
