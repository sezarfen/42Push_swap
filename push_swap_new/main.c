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
				ft_error(stacks);
			j++;
		}
		i++;
	}
}

t_stack	*check_and_initialize(int ac, char **av)
{
	t_stack	*stacks;

	stacks = NULL;
	if (ac < 2)
		ft_error(stacks);
	else if (ac == 2)
		stacks = split_and_check(av);
	else if (ac > 2)
		stacks = args_and_check(ac, av);
	check_duplicates(stacks);
	return (stacks);
}

void	start_sorting(t_stack *stacks)
{
	if (is_sorted(stacks) == 1)
	{
		free_all(stacks);
		exit(1);
	}
	else if (stacks->topa == 2)
		three_sort(stacks);
	else if (stacks->topa == 3)
		four_sort(stacks);
	else if (stacks->topa == 4)
		five_sort(stacks);
	else
		big_sort(stacks);
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	stacks = check_and_initialize(ac, av);
	start_sorting(stacks);
	free_all(stacks);
	return (0);
}
