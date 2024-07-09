/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:42 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:58:42 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_a(t_stack**sa,t_stack**sb)
{
    if(!*sb)
    return ;

   t_stack *tmp = *sb;
    *sb = (*sb)->next;
   tmp->next  = *sa;
   *sa = tmp;
    write(1,"pa\n",3);
}
void push_b(t_stack **sa, t_stack **sb)
{
    if (sa == NULL || *sa == NULL) {
        return; // Handle edge case where stack A is empty
    }
    
    t_stack *tmp = *sa; // Store the top of stack A
    *sa = (*sa)->next;  // Move the top of stack A to the next node
    tmp->next = *sb;    // Point the next of tmp to the top of stack B
    *sb = tmp;          // Move tmp to the top of stack B

    // Optional: Uncomment the next line to print the operation
    write(1, "pb\n", 3);
}

