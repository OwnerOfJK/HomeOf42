int ft_isspace(int c)
{
    if (c == ' ' || (c >= '\t' && c <= '\r'))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}