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

	if (ac >= 2)
	{
		if (av_checker(ac, av) == -1)
		{
			write(2, "Error!\n", 7);
			return (1);
		}
		stacks = NULL;
		set_stacks(&stacks, ac, av);
		if (stacks->topa == 4)
			sort_five(stacks);
		else if (stacks->topa == 2)
			sort_three(stacks->stacka, stacks->topa);
		print_stack(stacks->stacka, stacks->topa);
		free_all(stacks);
	}
	else
		write(2, "Error!\n", 7);
	return (0);
}