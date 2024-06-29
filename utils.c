#include "push_swap.h"

char	**ft_join_args(char **argv)
{
	char	*tmp;
	char	*str;
	char	**res;
	int		i;

	i = 1;
	tmp = ft_strdup(" ");
	while (argv[i])
	{
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = ft_strjoin(str, " \0");
		free(str);
		i++;
	}
	res = ft_split(tmp, ' ');
	free(tmp);
	return (res);
}
