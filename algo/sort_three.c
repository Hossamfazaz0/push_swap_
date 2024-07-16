/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:23:42 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/16 18:27:21 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **sa)
{
	int	a;
	int	b;
	int	c;

	if (!*sa || !(*sa)->next || !(*sa)->next->next)
		return ;
	a = (*sa)->data;
	b = (*sa)->next->data;
	c = (*sa)->next->next->data;
	if (a > b && b < c && a < c)
		swap_a(sa);
	else if (a > b && b > c)
	{
		swap_a(sa);
		rotate_reverse_a(sa);
	}
	else if (a > b && b < c && a > c)
		rotate_a(sa);
	else if (a < b && b > c && a < c)
	{
		swap_a(sa);
		rotate_a(sa);
	}
	else if (a < b && b > c && a > c)
		rotate_reverse_a(sa);
}
