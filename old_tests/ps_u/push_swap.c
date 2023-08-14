#include "push_swap.h"

void	free_all(t_stack *stacks)
{
	free(stacks->stacka);
	free(stacks->stackb);
	free(stacks);
}

void	set_stacks(t_stack **stacks, int ac, char **av)
{
	int	i;

	*stacks = malloc(sizeof(t_stack));
	(*stacks)->stacka = malloc(sizeof(int) * (ac - 1));
	(*stacks)->stackb = malloc(sizeof(int) * (ac - 1));
	(*stacks)->topa = -1;
	(*stacks)->topb = -1;
	i = 1;
	while (i < ac)
	{
		(*stacks)->topa++;
		(*stacks)->stacka[(*stacks)->topa] = (int)ft_atoi(av[ac - i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac < 2)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	av_checker(ac, av);
	stacks = NULL;
	set_stacks(&stacks, ac, av);
	check_duplicates(stacks);
	if (is_sorted(stacks) == 1)
	{
		write(1, "Already Sorted :)", 17);
		return (0);
	}
	else if (stacks->topa == 4)
		sort_five(stacks);
	else if (stacks->topa == 2)
		sort_three(stacks->stacka, stacks->topa);
	else
	{
		pb(stacks);
		pb(stacks);
		while (stacks->topa >= 0)
			big_sort(stacks);
		while (stacks->topb >= 0)
			pa(stacks);
	}
	print_stack(stacks->stacka, stacks->topa);
	free_all(stacks);
	return (0);
}
