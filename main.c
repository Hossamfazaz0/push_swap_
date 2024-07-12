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
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
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
    int i;

    i = 0;
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

void free_stack(t_stack *sa, t_stack *sb, char **numbers, int *tab)
{
    t_stack *tmp;
    int i;

    i = 0;
    while (sa)
    {
        tmp = sa;
        sa = sa->next;
        free(tmp);
    }
    while (sb)
    {
        tmp = sb;
        sb = sb->next;
        free(tmp);
    }
    while (numbers[i])
        free(numbers[i++]);
    free(numbers);
    free(tab);
}

int *table(char **numbers)
{
    int i;
    int *tab;
    int len;
    int j;

    j = 0;
    i = 0;
    len = 0;
    while (numbers[len])
        len++;
    tab = (int *)malloc(sizeof(int) * len);
    if (!tab)
        return NULL;
    while (i < len)
    {
        tab[i] = ft_atoi(numbers[i]);
        i++;
    }
    tab = sort_tab(tab, len);
    return tab;
}

int main(int ac, char **av)
{
    t_stack *sa;
    t_stack *sb;
    int len;
    char **numbers;
    int *tab;
    
    if (ac < 2)
        return 0;
    sa = NULL;
    sb = NULL;
    numbers = ft_join_args(av);
    if (!numbers)
        return 0;
    tab = table(numbers);

    // sa = init_stack(&sa, numbers);
    // if (len == 3)
    //     sort_three(&sa);
    // else if (len > 5 && len <= 100)
    //     sort(&sa, &sb, tab, len, len / 4);
    // else
    //     sort(&sa, &sb, tab, len, 30);
    //print table
    // calculate the length of the table
    len = 0;
    while (numbers[len])
        len++;
    len--;
    printf("len = %d\n", len);

    free_stack(sa, sb, numbers, tab);
    return 0;
}

