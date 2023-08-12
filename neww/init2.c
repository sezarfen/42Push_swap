#include "push_swap.h"

void	args_init_stacks(t_stack **stacks, int ac)
{
	(*stacks) = malloc(sizeof(t_stack));
	(*stacks)->stacka = malloc(sizeof(int) * (ac - 1));
	(*stacks)->stackb = malloc(sizeof(int) * (ac - 1));
	if (!(*stacks)->stacka || !(*stacks)->stackb)
		ft_error((*stacks));
	(*stacks)->topa = -1;
	(*stacks)->topb = -1;
}

t_stack *args_and_check(int ac, char **av)
{
	t_stack *stacks;
	int		i;

	stacks = NULL;
	args_init_stacks(&stacks, ac);
	i = 1;
	while (i < ac)
	{
		stacks->topa++;
		stacks->stacka[i - 1] = ft_atol(av[ac - i], stacks);
		i++;
	}
	return (stacks);
}