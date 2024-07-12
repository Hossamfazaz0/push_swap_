/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:08:53 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 00:49:09 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (isspace(str[i])) 
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}

t_stack *init_stack(t_stack **stack, char **numbers)
{
    t_stack *new;
    int i = 0;

    while (*numbers[i] != '\0')
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
            return NULL;
        new->data = ft_atoi(numbers[i]);
        new->next = NULL;
        ft_add_back(stack, new);
        i++;
    }
    return *stack;
}
void free_stack(t_stack *sa,t_stack *sb ,char **numbers)
{
	t_stack *tmp;
	int	i;

	i = 0;
	while(sa)
	{
		tmp = sa;
		sa = sa->next;
		free(tmp);
	}
	while(sb)
	{
		tmp = sb;
		sb = sb->next;
		free(tmp);
	}
	while (numbers[i])
        free(numbers[i++]);
    free(numbers);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    t_stack *sa = NULL;
    t_stack *sb = NULL;
    int len = 0;
    char **numbers;
    int i = 0;
    numbers = ft_join_args(av);
    if (!numbers)
        return 0;
    while (*numbers[len] != '\0')
        len++;
    int tab[len];
    while (i < len)
        tab[i++] = ft_atoi(numbers[i]);
    sa = init_stack(&sa, numbers);
    i = 0;
    
    sort_tab(tab, len);
    if(len == 3)
        sort_three(&sa);
    else if(len > 5 && len <= 100)
        sort(&sa, &sb,tab,len,len/4);
    else
        sort(&sa, &sb,tab,len,30);
	free_stack(sa,sb,numbers);
    return 0;
}
