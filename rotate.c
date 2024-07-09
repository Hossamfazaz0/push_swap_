#include "../push_swap.h"
void rotate_a(t_stack **sa)
{
    if (!*sa || !(*sa)->next)
        return;
    t_stack *tmp = *sa;
    *sa = (*sa)->next;
    tmp->next = NULL;
    ft_add_back(sa, tmp);
    write(1, "ra\n", 3);
}
void rotate_b(t_stack **sb)
{
    if (!*sb || !(*sb)->next)
        return;
    t_stack *tmp = *sb;
    *sb = (*sb)->next;
    tmp->next = NULL;
    ft_add_back(sb, tmp);
    write(1, "rb\n", 3);
}
void rotate_ab(t_stack **sa, t_stack **sb)
{
    rotate_a(sa);
    rotate_b(sb);
    write(1, "rr\n", 3);
}
