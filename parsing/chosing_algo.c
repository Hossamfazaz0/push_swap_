/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosing_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:59 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/27 12:41:30 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **sa)
{
	if ((*sa)->data > (*sa)->next->data)
		swap_a(sa);
}

void	check_algo(t_stack *sa, t_stack *sb, int *tab, char **argv)
{
	int	len;

	len = 0;
	while (*argv[len])
		len++;
	if (check_doubles(tab, len))
	{
		free_stack(sa, sb, argv, tab);
		write(2, "Error\n", 6);
		return ;
	}
	if (len == 2)
		sort_two(&sa);
	else if (len == 3)
		sort_three(&sa);
	else if (len == 4)
		sort_four(&sa, &sb);
	else if (len == 5)
		sort_five(&sa, &sb);
	else if (len > 5 && len <= 100)
		sort(&sa, &sb, tab, len);
	else
		sort(&sa, &sb, tab, len);
	free_stack(sa, sb, argv, tab);
}
