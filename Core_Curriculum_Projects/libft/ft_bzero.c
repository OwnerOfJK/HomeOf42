#include <strings.h>

void ft_bzero(void *dst, size_t n)
{
    unsigned int i = 0;
    unsigned char *p = (unsigned char *)dst;

    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}