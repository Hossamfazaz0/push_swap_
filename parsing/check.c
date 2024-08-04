/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:44 by hfazaz            #+#    #+#             */
/*   Updated: 2024/08/04 06:29:00 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_doubles(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	skip(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	is_number(char *str, int start, int end)
{
	int	i;

	i = start;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i > end)
		return (0);
	while (i <= end)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	not_number(char *str)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	start = 0;
	len = ft_strlen(str);
	while (skip(str[i]))
		i++;
	if (i == len)
		return (1);
	i = 0;
	while (i < len)
	{
		while (skip(str[i]) && i < len)
			i++;
		start = i;
		while (!skip(str[i]) && i < len)
			i++;
		if (i > start && !is_number(str, start, i - 1))
			return (1);
		else if (start == i && i < len)
			return (1);
	}
	return (0);
}

int	check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (not_number(str[i]) || ft_atoi(str[i]) > INT_MAX
			|| ft_atoi(str[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
