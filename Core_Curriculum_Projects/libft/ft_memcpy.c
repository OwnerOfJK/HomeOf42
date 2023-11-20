#include <string.h>

void* ft_memcpy(void* dst, const void* src, size_t len)
{
    unsigned int i = 0;
    unsigned char *p_dst = (unsigned char *)dst;
    unsigned const char *p_src = (unsigned const char *)src;
    
    while (i < len)
    {
        p_dst[i] = p_src[i];
        i++;
    }
    return (dst);
}