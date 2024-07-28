/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:44 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/28 23:43:19 by hfazaz           ###   ########.fr       */
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
	return (c == ' ' || c == '\t');
}

int	is_number(char *str, int start, int end)
{
	int	i;
	int	has_digit;

	i = start;
	has_digit = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i <= end)
	{
		if (!isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
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
