/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:48:26 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/29 18:48:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_four(t_stack **sa, t_stack **sb)
{
	while (list_length(*sa) > 3)
	{
		if (find_max_index(*sa, get_max(*sa)) >= (list_length(*sa) / 2))
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
	push_a(sa, sb);
	rotate_a(sa);
}
