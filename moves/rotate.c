/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:48 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/01 02:43:53 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **sb)
{
	t_stack	*first;
	t_stack	*last;

	first = *sb;
	*sb = (*sb)->next;
	first->next = NULL;
	last = *sb;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **sa, t_stack **sb)
{
	rotate_a(sa);
	rotate_b(sb);
	write(1, "rr\n", 3);
}
