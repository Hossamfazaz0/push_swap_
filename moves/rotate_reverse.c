/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:45 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:58:45 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_reverse_a(t_stack **sa)
{
	t_stack	*tmp;

	if (!*sa || !(*sa)->next)
		return ;
	tmp = *sa;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_add_front(sa, tmp->next);
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rotate_reverse_b(t_stack **sb)
{
	t_stack	*tmp;

	if (!*sb || !(*sb)->next)
		return ;
	tmp = *sb;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_add_front(sb, tmp->next);
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rotate_reverse_ab(t_stack **sa, t_stack **sb)
{
	rotate_reverse_a(sa);
	rotate_reverse_b(sb);
	write(1, "rrr\n", 4);
}
