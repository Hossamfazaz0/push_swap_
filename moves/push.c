/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:42 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/17 11:09:30 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	if (!*sb)
		return ;
	tmp = *sb;
	*sb = (*sb)->next;
	tmp->next = *sa;
	*sa = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **sa, t_stack **sb)
{
	t_stack	*tmp;

	if (sa == NULL || *sa == NULL)
	{
		return ;
	}
	tmp = *sa;
	*sa = (*sa)->next;
	tmp->next = *sb;
	*sb = tmp;
	write(1, "pb\n", 3);
}
