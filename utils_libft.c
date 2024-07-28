/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:06 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/28 02:06:08 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	int		j;

	len = ft_strlen((char *)s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char *ft_strjoin(char *s1, char *s2) {
    int i = 0, j = 0;
    char *str;

    if (!s2) return NULL;
    if (!s1) s1 = strdup("");
    str = malloc(strlen(s1) + strlen(s2) + 1);
    if (!str) return NULL;
    while (s1[i]) {
        str[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        str[i++] = s2[j++];
    }
    str[i] = '\0';
    free(s1);
    return str;
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
