#include "libftprintf.h"
#include <stdio.h>

int main() {
	//int var = 8;
	//int *ptr = &var;
	int x,j;
	x = ft_printf("%c", '0');
	j = printf("%c", '0');

    //x = ft_printf("This is a test: %c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'A', "Hello", ptr, 42, 54, 34, 255, 255);
	//j = printf("This is a test: %c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'A', "Hello", ptr, 42, 54, 34, 255, 255);
	printf(" \n mine : %i \noriginal : %i \n", x, j);
    return 0;
}
