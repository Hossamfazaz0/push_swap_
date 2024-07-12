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

t_stack *init_stack(t_stack **stack, char **argv1)
{
    t_stack *new;
    int i = 0;

    while (*argv1[i] != '\0')
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
            return NULL;
        new->data = ft_atoi(argv1[i]);
        new->next = NULL;
        ft_add_back(stack, new);
        i++;
    }
    return *stack;
}
void free_mem(t_stack *sa, t_stack *sb,char **av)
{
    int     i;
    t_stack *tmp;

    i = 0;
    while(av[i])
        free(av[i++]);
    free(av);
    while(sa)
	{
		t_stack *tmp = sa;
		sa = sa->next;
		free(tmp);
	}
    while(sb)
	{
		t_stack *tmp = sb;
		sb = sb->next;
		free(tmp);
	}
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    t_stack *sa = NULL;
	t_stack *sb = NULL;
    int len = 0;
    int tab[len];
    char **argv1;
    
    argv1 = ft_join_args(av);
    if (!argv1)
        return 0;
    while (*argv1[len] != '\0')
        len++;
    sa = init_stack(&sa, argv1);
    sort_tab(tab, len);
    chose_sort(len,sa,sb,tab);
	free_mem(sa,sb,argv1);
    return 0;
}

