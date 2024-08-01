/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:23:42 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/01 01:21:10 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **sa)
{
	int	max;
	int	max_index;

	max = get_max(*sa);
	max_index = find_max_index(*sa, max);
	while (max_index != 2)
	{
		if (max_index == 0)
			rotate_a(sa);
		else
			rotate_reverse_a(sa);
		max_index = find_max_index(*sa, max);
	}
	if ((*sa)->data > (*sa)->next->data)
		swap_a(sa);
}
