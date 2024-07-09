/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:59:06 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/09 15:59:06 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(char *str)
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
	int	len;
	int	j;

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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int	len_s1;
	int	len_s2;
	int	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	p = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}
char	**ft_split(char *str, char c)
{
    char	**res;
    int		i;
    int		j;
    int		k;

    i = 0;
    j = 0;
    res = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
    if (!res)
        return (NULL);
    while (str[i])
    {
        k = 0;
        res[j] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
        if (!res[j])
            return (NULL);
        while (str[i] == c)
            i++;
        while (str[i] && str[i] != c)
            res[j][k++] = str[i++];
        res[j][k] = '\0';
        j++;
    }
    res[j] = NULL;
    return (res);
}
int ft_lstsize(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

