/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:08:53 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/26 05:54:17 by hfazaz           ###   ########.fr       */
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
int to_skip(char c) {
    if (c == ' '  || c == '\t' || c == '-' || c == '+')
        return 1;
    else
        return 0;
}

int is_no_digit(char *str) {
    int i = 0;
    int len = ft_strlen(str);

    while (len > 0 && to_skip(str[len - 1])) {
        len--;
    }

    if (len == 0)
        return 1;

    while (i < len) {
        if (to_skip(str[i])) {
            i++;
	
        } if (str[i] < '0' || str[i] > '9') {
            return 1;
        } else {
            i++;
        }
    }
    return 0;
}
	int check(char **str)
	{
	    int i =1;
	    while(str[i])
	    {
	        if(!is_no_digit(str[i]))
	            i++;
	        else
	        {
	            write(2,"Error\n",6);
	            return 0;        
		}
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

	(void) ac;
	len = 0;
	sa = NULL;
	sb = NULL;
	check(av);
	argv = ft_join_args(av);
	if (!argv)
		return (0);
	while (*argv[len] != '\0')
		len++;
	
	tab = fill_tab(argv);
	sa = init_stack(&sa, tab, len);
	sort_tab(tab, len);
	check_algo(sa, sb, tab, argv);
}
