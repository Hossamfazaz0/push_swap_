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

t_stack *init_stack(t_stack **stack, char **matrix)
{
    t_stack *new;
    int i = 0;

    while (*matrix[i] != '\0')
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
            return NULL;
        new->data = ft_atoi(matrix[i]);
        new->next = NULL;
        ft_add_back(stack, new);
        i++;
    }
    return *stack;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;

    char **matrix;
    matrix = ft_join_args(av);
    if (!matrix)
        return 0;
    int len = 0;
    while (*matrix[len] != '\0')
        len++;
    int tab[len];
    int i = 0;
    while (i < len)
    {
        tab[i] = ft_atoi(matrix[i]);
        i++;
    }
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    i= 0 ;
    stack_a = init_stack(&stack_a, matrix);
    sort_tab(tab, len);
    if(len == 3)
        sort_three(&stack_a);
    else if(len > 5 && len <= 100)
        sort(&stack_a, &stack_b,tab,len,len/4);
    else
        sort(&stack_a, &stack_b,tab,len,30);
    while(*matrix)
    {
        free(*matrix);
        matrix++;
    }
    free(matrix);
    return 0;
   
}
