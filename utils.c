/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:12 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:59:12 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_join_args(char **argv)
{
	char	*tmp;
	char	*str;
	char	**res;
	int		i;

	i = 1;
	tmp = ft_strdup(" ");
	while (argv[i])
	{
		str = ft_strjoin(tmp, argv[i]);
		tmp = ft_strjoin(str, " \0");
		i++;
	}
	res = ft_split(tmp, ' ');
	free(tmp);

	return (res);
}

void	ft_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}
void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}