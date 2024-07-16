#include "../push_swap.h"

void	check_algo(t_stack *sa, t_stack *sb, int *tab, char **argv)
{
	int len;

	len = 0;
	while (*argv[len])
		len++;
	if (check_doubles(tab, len))
	{
		free_stack(sa, sb, argv, tab);
		write(2, "Error\n", 6);
		return ;
	}
	if (len == 3)
		sort_three(&sa);
	else if (len > 5 && len <= 100)
		sort(&sa, &sb, tab, len, len / 4);
	else
		sort(&sa, &sb, tab, len, 30);
	free_stack(sa, sb, argv, tab);
}