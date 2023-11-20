#include <string.h>

void *ft_memchr(void *src, int c, size_t size)
{
    unsigned int i = 0;
    unsigned char *p = (unsigned char*)src;

    while (i < size)
    {
        if (p[i] == c)
        {
            return (&p[i]);
        }
        i++;
    }
    return (0);
}