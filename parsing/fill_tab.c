#include "../push_swap.h"
void fill_tab(char **av,int len,int *tab)
{
    int	i;
	len = 0;
    while(i < len)
		tab[i++] = ft_atoi(av[i]);
}