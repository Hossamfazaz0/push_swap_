int check_doubles(int *tab,int len)
{
    int	i;
	int	j;
	
	i = 0;
	while(i < len)
	{
		j = 0;
		if(tab[i] == tab[j])
			return 0;
		j++;
	}
	i++;
	return 1;
}
void skip_spaces(char *av)
{
	while(*str && (*str == ' ' || *str == '\t'));
		str++;
}
int is_num(char *av)
{
	while(*av)
	{
		if(*av >= '0' && *av <='9')
			return 1;
		else
			return 0;
	av++;
	}
}
int check_if_numerique(char **av)
{
	int i;

	i = 0;
	while(*av[i]!= '\0')
	{
		skip_spaces(av[i]);
		
		
	}
}