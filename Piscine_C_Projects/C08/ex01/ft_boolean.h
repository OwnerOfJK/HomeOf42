#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>
#include <stdbool.h>
char *EVEN_MSG = "I have an even number of arguments.\n";
char *ODD_MSG = "I have an odd number of arguments.\n";
typedef int t_bool; //This statement defines t_bool as an alias for the int data type. It allows you to use t_bool in your code as if it were an int.
bool TRUE = 1;
bool FALSE = 0;
bool SUCCESS = 0;

bool EVEN(int x) {
    if (x % 2 == 0)
    {
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

#endif