#include "../push_swap.h"

void push_a(t_stack**sa,t_stack**sb)
{
    if(!*sb)
    return ;

    t_stack*tmp = *sb;
    ft_add_front(sa,tmp);
    *sb = tmp->next;
    write(1,"pa\n",3);
}
void push_b(t_stack **sb, t_stack **sa)
{
    if (!*sa)
        return;
    t_stack *tmp = *sa;
    *sa = (*sa)->next; 
    ft_add_front(sb, tmp);
    write(1, "pb\n", 3);
}
