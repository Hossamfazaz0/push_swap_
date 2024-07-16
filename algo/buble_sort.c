/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:58:29 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:58:29 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int *sort_tab(int *tab,int len)
{
    int i = 0;
    int j = 0;
    while(i<len)
    {
        j = 0;
        while (j<len)
        {
            if (tab[i]<tab[j])
            {
                int tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
        
    }
    return tab;
}
