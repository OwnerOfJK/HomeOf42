void    ft_strclr(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = '\0';
        i++;
    }
}