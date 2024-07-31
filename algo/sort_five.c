/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:48:23 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/31 00:57:06 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack **sa, t_stack **sb)
{
	while (list_length(*sa) > 3)
	{
		if (find_max_index(*sa, get_max(*sa)) > (list_length(*sa) / 2))
		{
			while (find_max_index(*sa, get_max(*sa)) > 0)
				rotate_reverse_a(sa);
		}
		else
		{
			while (find_max_index(*sa, get_max(*sa)) > 0)
				rotate_a(sa);
		}
		push_b(sa, sb);
	}
	sort_three(sa);
	while (*sb)
	{
		push_a(sa, sb);
		rotate_a(sa);
	}
}
