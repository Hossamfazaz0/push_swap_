/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:01 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:59:01 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
    int data;
    int index;
    int final_index;
    int push_price;
    bool above;
    bool cheapest;
    struct s_stack *next;
    struct s_stack *prev;
    struct s_stack *target;
} t_stack;



int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str, char c);
char	**ft_join_args(char **argv);
void   ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack *new);
void rotate_a(t_stack **sa);
void rotate_b(t_stack **sb);
void rotate_ab(t_stack **sa, t_stack **sb);
void rotate_reverse_a(t_stack **sa);
void rotate_reverse_b(t_stack **sb);
void rotate_reverse_ab(t_stack **sa, t_stack **sb);
void push_a(t_stack**sa,t_stack**sb);
void push_b(t_stack**sa,t_stack**sb);
void swap_a(t_stack **sa);
void swap_b(t_stack **sb);
void swap_ab(t_stack **sa, t_stack **sb);
void sort_three(t_stack **sa);
void sort(t_stack **sa, t_stack **sb, int *tab, int tab_size,int max);
void sort_tab(int *tab,int len);
#endif