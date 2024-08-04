/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:48 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/02 04:10:05 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	rotate_a(t_stack **sa)
{
	t_stack	*first;
	t_stack	*last;

	first = *sa;
	*sa = (*sa)->next;
	first->next = NULL;
	last = *sa;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	write(1, "ra\n", 3);
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
