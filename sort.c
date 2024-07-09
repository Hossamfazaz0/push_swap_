/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:18 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:58:18 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdio.h>

int list_length(t_stack *stack) {
    int length = 0;
    t_stack *current = stack;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

int get_max(t_stack *stack) {
    int max = INT_MIN;
    t_stack *current = stack;
    while (current) {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

void sort(t_stack **sa, t_stack **sb, int *tab, int tab_size,int max) {
    int start = 0;
    int end = max;

    while (*sa != NULL) {
        if ((*sa)->data >= tab[start] && (*sa)->data <= tab[end]) {
            push_b(sa, sb);
            start++;
            end++;
            if (end >= tab_size) {
                end = tab_size - 1;
            }
        } else if ((*sa)->data < tab[start]) {
            push_b(sa, sb);
            rotate_b(sb);
            start++;
            end++;
            if (end >= tab_size) {
                end = tab_size - 1;
            }
        } else if ((*sa)->data > tab[end]) {
            rotate_a(sa);
        }
    }

    while (*sb != NULL) {
        int max_val = get_max(*sb);
        int middle = list_length(*sb) / 2;
        int max_index = 0;
        t_stack *current = *sb;

        while (current) {
            if (current->data == max_val)
                break;
            max_index++;
            current = current->next;
        }

        if (max_index <= middle) {
            while ((*sb)->data != max_val)
                rotate_b(sb);
        } else {
            while ((*sb)->data != max_val)
                rotate_reverse_b(sb);
        }
        push_a(sa, sb);
    }
}
    // t_stack *current = *sa;
//     while (current) {
//         printf("%d\n", current->data);
//         current = current->next;
//     }

//     current = *sb;
//     while (current) {
//         printf(" %d\n", current->data);
//         current = current->next;
//     } 

