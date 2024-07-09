#include"../push_swap.h"
void swap_a(t_stack **sa)
{
    if (!*sa || !(*sa)->next)
        return;
    t_stack *tmp = *sa;
    *sa = (*sa)->next;
    tmp->next = (*sa)->next;
    (*sa)->next = tmp;
    write(1, "sa\n", 3);
}

void swap_b(t_stack **sb)
{
    if (!*sb || !(*sb)->next)
        return;
    t_stack *tmp = *sb;
    *sb = (*sb)->next;
    tmp->next = (*sb)->next;
    (*sb)->next = tmp;
    write(1, "sb\n", 3);
}

void swap_ab(t_stack **sa, t_stack **sb)
{
    swap_a(sa);
    swap_b(sb);
    write(1, "ss\n", 3);
}
