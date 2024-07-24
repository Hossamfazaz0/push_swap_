/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:44 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/24 09:54:42 by hfazaz           ###   ########.fr       */
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

void	skip_spaces(char **av)
{
	while (**av == ' ' || **av == '\t')
		(*av)++;
}

int	is_num(char *av)
{
	int	i;

	i = 0;
	skip_spaces(&av);
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_numerique(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]) || ft_atoi(av[i]) > 2147483647)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
void print_error()
{
	write(2, "Error\n", 6);
	exit(1);
}