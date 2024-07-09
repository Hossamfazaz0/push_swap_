#include "../push_swap.h"
void rotate_reverse_a(t_stack **sa)
{
    if (!*sa || !(*sa)->next)
        return;
    t_stack *last = *sa;
    t_stack *second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    ft_add_front(sa, last);
    write(1, "rra\n", 4);
}



void rotate_reverse_b(t_stack **sb)
{
    if (!*sb || !(*sb)->next)
        return; 
    
    t_stack *last = *sb;
    t_stack *second_last = NULL;
    
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    
    second_last->next = NULL; 
    ft_add_front(sb, last);
    write(1, "rrb\n", 4);
}


void rotate_reverse_ab(t_stack **sa, t_stack **sb)
{
    rotate_reverse_a(sa);
    rotate_reverse_b(sb);
}
