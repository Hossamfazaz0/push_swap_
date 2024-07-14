#include "../push_swap.h"
int check_doubles(int *tab,int len)
{
    int	i;
	int	j;
	
	i = 0;
	while(i < len)
	{
		j = 0;
		if(tab[i] == tab[j])
			return 1;
		j++;
	}
	i++;
	return 0;
}
void skip_spaces(char *av)
{
	while(*av == ' ' || *av == '\t')
		av++;
}
int is_num(char *av)
{
	int i;
	
	i = 0;

	while(av[i])
	{
		skip_spaces(av);
		if (av[i] == '-' || av[i] == '+')
			i++;
		if(av[i] < '0' || av[i] > '9')
			return 0;
	i++;
	}
	return 1;
}
int check_if_numerique(char **av)
{
	int i;
	
	i = 0;
	while(av[i])
	{
		if(!is_num(av[i]))
		{
			write(2,"Error\n",6);
			return 0;
		}
		i++;
	}
	return 1;

}