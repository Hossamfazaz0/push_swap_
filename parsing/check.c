/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:44 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/27 12:39:13 by hfazaz           ###   ########.fr       */
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

int	to_skip(char c)
{
	if (c == ' ' || c == '\t' || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	check_dup(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' || str[i
					+ 1] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_no_digit(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (len > 0 && to_skip(str[len - 1]))
	{
		len--;
	}
	if (len == 0 || check_dup(str))
		return (1);
	while (i < len)
	{
		if (to_skip(str[i]))
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		else
			i++;
	}
	return (0);
}

int	check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (is_no_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
