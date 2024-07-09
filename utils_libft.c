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
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
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

