#include "push_swap.h"

int av_checker(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] <= '9' && av[i][j] >= '0'))
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int main(int ac, char **av)
{
	int	i;
	t_stack	*stacks;

	if (ac >= 2)
	{
		if (av_checker(ac, av) == -1)
		{
			write(2, "Error!\n", 7);
			return (1);
		}
		stacks = malloc(sizeof(t_stack));
		stacks->stacka = malloc(sizeof(int) * (ac - 1));
		stacks->stackb = malloc(sizeof(int) * (ac - 1));
		stacks->topa = -1;
		stacks->topb = -1;
		i = 1;
		while (i < ac)
		{
			stacks->topa++;
			stacks->stacka[stacks->topa] = ft_atoi(av[ac - i]);
			i++;
		}
		sort_three(stacks->stacka, stacks->topa);
		print_stack(stacks->stacka, stacks->topa);
	}
	else
		write(2, "Error!\n", 7);
	return (0);
}