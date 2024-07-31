/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosing_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:59 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/31 00:56:49 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(t_stack *sa)
{
	t_stack	*tmp;

	tmp = sa;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
		write(2, "Error\n", 6);
		free_stack(sa, sb, argv, tab);
	}
	if (check_sorted(sa))
		free_stack(sa, sb, argv, tab);
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
	else if (len > 100 && len <= 500)
		sort(&sa, &sb, tab, len);
	free_stack(sa, sb, argv, tab);
}
