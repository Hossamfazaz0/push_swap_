/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:08:53 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/13 01:53:11 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

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

t_stack	*init_stack(t_stack **stack, int *tab,int len)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (i < len)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->data = tab[i];
		new->next = NULL;
		ft_add_back(stack, new);
		i++;
	}
	return (*stack);
}

void	free_stack(t_stack *sa, t_stack *sb, char **av, int *tab)
{
	t_stack	*tmp;
	int		i;

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
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
    free(tab);
}

int *fill_tab(char **argv)
{
    int		i;
    int		*tab;

    i = 0;
    while (*argv[i] != '\0')
        i++;
    tab = (int *)malloc(sizeof(int) * i);
    if (!tab)
        return (NULL);
    i = 0;
    while (*argv[i] != '\0')
    {
        tab[i] = ft_atoi(argv[i]);
        i++;
    }
    return (tab);
}
void check_algo(t_stack *sa,t_stack *sb,int *tab,int len, char **argv)
{
    if (len == 3)
		sort_three(&sa);
	else if (len > 5 && len <= 100)
		sort(&sa, &sb, tab, len, len / 4);
	else
		sort(&sa, &sb, tab, len, 30);
	free_stack(sa, sb, argv,tab);
}
int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_stack *sa;
	t_stack *sb ;
	int len;
	char **argv;
	int *tab;

    len = 0;
    sa = NULL;
    sb = NULL;
	argv = ft_join_args(av);
	if (!argv)
		return (0);
	while (*argv[len] != '\0')
		len++;
	tab = fill_tab(argv);
	sa = init_stack(&sa, tab, len);
	sort_tab(tab, len);
	check_algo(sa,sb,tab,len,argv);
	return (0);
}
