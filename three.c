/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:09 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:58:09 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void sort_three(t_stack **sa)
{
    if (!*sa || !(*sa)->next || !(*sa)->next->next)
        return;

    t_stack *first = *sa;
    t_stack *second = (*sa)->next;
    t_stack *third = (*sa)->next->next;

    if (first->data > second->data && second->data < third->data && first->data < third->data)
        swap_a(sa);
    else if (first->data > second->data && second->data > third->data)
    {
        swap_a(sa);
        rotate_reverse_a(sa);
    }
    else if (first->data > second->data && second->data < third->data && first->data > third->data)
        rotate_a(sa);
    else if (first->data < second->data && second->data > third->data && first->data < third->data)
    {
        swap_a(sa);
        rotate_a(sa);
    }
    else if (first->data < second->data && second->data > third->data && first->data > third->data)
        rotate_reverse_a(sa);
}