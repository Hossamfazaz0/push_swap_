/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:08:53 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/05 01:46:51 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void init_stack(t_stack **sa, char **av)
{
    t_stack *new;
    t_stack *tmp;
    int i = 0;
    while(**av)
    {
        new = malloc(sizeof(t_stack));
        new->data = atoi(*av);
        new->next = NULL;
        if (!*sa)
            *sa = new;
        else
        {
            tmp = *sa;
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
        av++;
    }
}
void print_stack(t_stack *stack)
{
    t_stack *current = stack;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
int main(int ac, char **av)
{
    if (ac < 2)
        return 0;

    t_stack *sa = NULL;
    t_stack *sb = NULL;
    char **av1 = ft_join_args(av);
    
    init_stack(&sa, av1); 
    // printf("Original sa:\n");
    // print_stack(sa); 

    sort_four(&sa,&sb); 
    // printf("After , sa:\n");
    // print_stack(sa);


    return 0;
}



