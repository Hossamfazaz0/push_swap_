/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:12 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/02 06:10:55 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_join_args(char **argv)
{
	char	*str;
	char	**res;
	int		i;

	i = 1;
	str = ft_strdup(" ");
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " \0");
		i++;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		k = 0;
		res[j] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!res[j])
			return (NULL);
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			res[j][k++] = str[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = NULL;
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
