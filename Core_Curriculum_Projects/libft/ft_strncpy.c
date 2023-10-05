char *ft_strncpy(char *dest, const char *src, int len)
{
    int i = 0;
    while (i < len)
    {
        if (src[i] != '\0')
        {
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '\0';
        }
        i++;
    }
    return (dest);
}