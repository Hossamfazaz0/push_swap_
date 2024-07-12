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
