#include "../push_swap.h"

void sort_four(t_stack **sa, t_stack **sb)
{
    if (!sa || !*sa)
        return;

    push_b(sb, sa);
    sort_three(sa);

    t_stack *first = (*sa);
    t_stack *second = (*sa)->next;
    t_stack *third = (*sa)->next->next;

    if ((*sb)->data < first->data)
    {
        push_a(sa, sb);
    }
    else if ((*sb)->data > first->data && (*sb)->data < second->data)
    {
        rotate_a(sa);
        push_a(sa, sb);
        rotate_reverse_a(sa);
    }
    else if ((*sb)->data > second->data && (*sb)->data < third->data)
    {
        rotate_a(sa);
        rotate_a(sa);
        push_a(sa, sb);
        rotate_reverse_a(sa);
        rotate_reverse_a(sa);
    }
    else
    {
        push_a(sa, sb);
        rotate_a(sa);
    }
}