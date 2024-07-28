/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:44 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/28 03:22:26 by hfazaz           ###   ########.fr       */
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

int skip(char c)
{
    return (c == ' ' || c == '\t');
}

// Function to check if a string segment is a valid number
int is_number(const char *str, int start, int end)
{
    int i = start;
    int has_digit = 0;

    // Check for valid signs
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }

    // Check the rest of the string for numeric characters
    while (i <= end)
    {
        if (!isdigit(str[i]))
            return 0;
        has_digit = 1;
        i++;
    }

    return has_digit;
}

// Function to check if a string contains only valid numbers separated by spaces
int not_number(const char *str)
{
    int i = 0;
    int start = 0;
    int len = strlen(str);
    while (skip(str[i]))
        i++;
    if (i == len)
        return 1;
    i = 0;

    while (i < len)
    {
        while (skip(str[i]) && i < len)
            i++;
        start = i;
        while (!skip(str[i]) && i < len)
            i++;
        if (i > start && !is_number(str, start, i - 1))
            return 1;
        else if (start == i && i < len)
            return 1;
    }

    return 0;
}

int	check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (not_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}
