char *ft_strchr(char *str, int c)
{
    while (*str != '\0')
    {
        if(*str == c)
        {
            return(str);
        }
        str++;
    }
    return (0);
}