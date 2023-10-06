int ft_wordlen_delim(char *str, char delim)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != delim)
    {
        i++;
    }
    return (i);
}