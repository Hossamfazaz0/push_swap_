/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:52 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/01 02:24:02 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **sa)
{
	t_stack	*tmp;

	tmp = *sa;
	*sa = (*sa)->next;
	tmp->next = (*sa)->next;
	(*sa)->next = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **sb)
{
	t_stack	*tmp;

	tmp = *sb;
	*sb = (*sb)->next;
	tmp->next = (*sb)->next;
	(*sb)->next = tmp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **sa, t_stack **sb)
{
	swap_a(sa);
	swap_b(sb);
	write(1, "ss\n", 3);
}
