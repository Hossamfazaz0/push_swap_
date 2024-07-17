/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:18 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/17 11:08:34 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_sa(t_stack **sa, t_stack **sb, int *tab, int len)
{
	int	start;
	int	end;

	start = 0;
	if (len > 5 && len <= 100)
		end = len / 4;
	else
		end = 30;
	while (*sa != NULL)
	{
		if ((*sa)->data >= tab[start] && (*sa)->data <= tab[end])
		{
			push_b(sa, sb);
			check_end(&start, &end, len);
		}
		else if ((*sa)->data < tab[start])
		{
			push_b(sa, sb);
			rotate_b(sb);
			check_end(&start, &end, len);
		}
		else if ((*sa)->data > tab[end])
			rotate_a(sa);
	}
}

void	sort_sb(t_stack **sa, t_stack **sb)
{
	int	max_val;
	int	middle;
	int	max_index;

	while (*sb != NULL)
	{
		max_val = get_max(*sb);
		middle = list_length(*sb) / 2;
		max_index = find_max_index(*sb, max_val);
		if (max_index <= middle)
		{
			while ((*sb)->data != max_val)
				rotate_b(sb);
		}
		else
		{
			while ((*sb)->data != max_val)
				rotate_reverse_b(sb);
		}
		push_a(sa, sb);
	}
}

void	sort(t_stack **sa, t_stack **sb, int *tab, int len)
{
	sort_sa(sa, sb, tab, len);
	sort_sb(sa, sb);
}
