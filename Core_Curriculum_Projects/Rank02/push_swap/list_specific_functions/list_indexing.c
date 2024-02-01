#include "../push_swap.h"
#include <unistd.h>

void increment_index(t_list *head_stack)
{
    while (head_stack)
    {
        head_stack->index++;
        head_stack = head_stack->next;
    }
}

void decrement_index(t_list *head_stack)
{
    while (head_stack)
    {
        head_stack->index--;
        head_stack = head_stack->next;
    }
}