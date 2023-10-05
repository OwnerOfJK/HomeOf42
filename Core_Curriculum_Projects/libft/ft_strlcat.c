#include "libft.h"

int ft_strlcat(char *dest, const char *src, int len)
{
    int dest_len = ft_strlen(dest);
    int src_len = ft_strlen(src);
    int to_copy = len - dest_len - 1;
    int i = 0;

    while (src[i] != '\0' && i < to_copy)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest_len + src_len);
}