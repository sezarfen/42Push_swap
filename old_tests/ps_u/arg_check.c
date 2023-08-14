#include "push_swap.h"

void	check_duplicates(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->topa)
	{
		j = i + 1;
		while (j <= stacks->topa)
		{
			if (stacks->stacka[i] == stacks->stacka[j])
			{
				write(2, "Error!\n", 7);
				free_all(stacks);
				exit(1);				
			}
			j++;
		}
		i++;
	}
}

void check_single_arg(char **av)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(av[1], ' ');
	i = 0;
	j = 0;
	while (split[i])
	{
		while (split[i][j])
		{
			if (!(split[i][j] <= '9' && split[i][j] >= '0'))
			{
				write(2, "Error!\n", 7);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void av_checker(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (ac == 2)
		return (check_single_arg(av));
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] <= '9' && av[i][j] >= '0'))
			{
				write(2, "Error!\n", 7);
				exit(1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}