void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i = 0;
    while (s[i] != '\0')
    {
        f(i, &s[i]);
        i++;
    }
}