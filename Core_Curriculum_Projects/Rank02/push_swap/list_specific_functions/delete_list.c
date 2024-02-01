#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void delete_list(t_list *lst)
{

    t_list *prev_node = NULL;
    t_list *current_node = lst;

    if (lst)
    {
        while (current_node && current_node->next)
        {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (prev_node)
        {
            prev_node->next = NULL;
        }
        free(lst);
    }
}