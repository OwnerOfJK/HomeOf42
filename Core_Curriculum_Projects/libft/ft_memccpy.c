#include <string.h>

void* ft_memccpy(void* dst, const void* src, int c, size_t len)
{
    int i = 0;
    unsigned char *p_dst = (unsigned char *)dst;
    unsigned const char *p_src = (unsigned const char *)src;
    unsigned char uc = (unsigned char)c;
    
    while (i < len)
    {
        p_dst[i] = p_src[i];
        i++;
        if (p_src[i] == c)
        {
            return (&p_dst[i]);
        }
    }
    return (0);
}