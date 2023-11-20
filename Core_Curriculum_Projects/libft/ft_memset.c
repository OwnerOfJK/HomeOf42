#include <string.h>

void* ft_memset(void* dst, int c, size_t len)
{
    unsigned int i = 0;
    unsigned char *p = (unsigned char *)dst;
    
    while (i < len)
    {
        p[i] = c;
        i++;
    }
    return (dst);
}