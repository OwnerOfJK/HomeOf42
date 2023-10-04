#include "libft.h"

int ft_atoi(const char *str)
{
    int i = 0;
    int sign_amount = 0;
    int result = 0;

    while (str[i] != '\0')
    {
        if (ft_isspace(str[i]) == 1)
        {
            i++;
        }
        if (str[i] == '+')
        {
            if (sign_amount >= 1)
            {
                return (0);
            }
            sign_amount++;
            i++;
        }
        if (str[i] == '-')
        {
            if (sign_amount >= 1)
            {
                return (0);
            }
            sign_amount++;
            result *= -1;
            i++;
        }
        if (ft_isdigit(str[i]) == 1)
        {
            result = result * 10 + (str[i] - 48);
            i++;
            if (ft_isdigit(str[i]) == 0)
            {
                return (result);
            }
        }
    }
    return (result);
}