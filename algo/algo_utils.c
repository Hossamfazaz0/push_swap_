/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:44:12 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/02 01:48:52 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_length(t_stack *stack)
{
	int		length;
	t_stack	*current;

	length = 0;
	current = stack;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	max = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

void	check_end(int *start, int *end, int tab_size)
{
	(*start)++;
	(*end)++;
	if (*end == tab_size)
		*end = tab_size - 1;
}

int	find_max_index(t_stack *sb, int max_val)
{
	int		max_index;
	t_stack	*current;

	max_index = 0;
	current = sb;
	while (current)
	{
		if (current->data == max_val)
			break ;
		max_index++;
		current = current->next;
	}
	return (max_index);
}
