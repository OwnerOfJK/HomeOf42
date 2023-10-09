int ft_strnequ(char const *s1, char const *s2, size_t n);
{
    size_t i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
    {
        i++;
    }
    if (s1[i] == s2[i])
    {
        return (1);
    }
    else
    {
        return (0);
    }
}