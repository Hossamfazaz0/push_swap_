/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:42 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/01 02:28:58 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	tmp = *sb;
	*sb = (*sb)->next;
	tmp->next = *sa;
	*sa = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	tmp = *sa;
	*sa = (*sa)->next;
	tmp->next = *sb;
	*sb = tmp;
	write(1, "pb\n", 3);
}
