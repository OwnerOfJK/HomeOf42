char *ft_strstr(char *str, char *substr)
{
    int i = 0;
    int j;

    if (*substr == '\0')
    {
        return (str);
    }
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i + j] == substr[j] && str[i + j] != '\0')
        {
            j++;
            if (substr[j] == '\0')
            {
                return(&str[i]);
            }
        }
        i++;
    }
    return (0);
}