/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:08:53 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/24 09:56:12 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_stack **stack, int *tab, int len)
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
	exit(0);
}

int	*fill_tab(char **argv)
{
	int	i;
	int	*tab;

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

int check(char **str)
{
    int i;
    int j;
    int sign;

    i = 1;
    while (str[i])
    {
        j = 0;
        sign = 0;
        while (str[i][j] == ' ' || str[i][j] == '\t')
            j++;
        if (str[i][j] == '\0') return 0;
        while (str[i][j])
        {
            if (str[i][j] == '-' || str[i][j] == '+')
            {
                if (sign) return 0;  
                sign = 1;
                j++;
                if (str[i][j] == '\0') return 0; 
            }
            else if (str[i][j] == ' ' || str[i][j] == '\t')
            {
                while (str[i][j] == ' ' || str[i][j] == '\t')
                    j++;
                if (str[i][j] && (str[i][j] < '0' || str[i][j] > '9'))
                    return 0;
            }
             if (str[i][j] < '0' || str[i][j] > '9')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	int		len;
	char	**argv;
	int		*tab;

	len = 0;
	sa = NULL;
	sb = NULL;
	if (ac < 2)
		return (0);
	
	argv = ft_join_args(av);
	while (*argv[len] != '\0')
		len++;
	if (!argv)
		return (0);
	tab = fill_tab(argv);
	if (!check(av) || check_doubles(tab, len))
	{
		write(2, "Error\n", 6);
		free_stack(sa, sb, argv, tab);
		
	}
		
	if (!check_if_numerique(argv) || len < 3)
		free_stack(sa, sb, argv, tab);
	sa = init_stack(&sa, tab, len);
	sort_tab(tab, len);
	check_algo(sa, sb, tab, argv);
}
