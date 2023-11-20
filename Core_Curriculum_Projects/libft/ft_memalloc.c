#include <stdlib.h>

void    *ft_memalloc(size_t size)
{
    size_t i = 0;
    char *memory_area = malloc(size * sizeof(char));
    if (memory_area == NULL)
    {
        return (NULL);
    }
    while (i < size)
    {
        memory_area[i] = 0;
        i++;
    }
    return (memory_area);
}