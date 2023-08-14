#include "push_swap.h"

int	is_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->topa)
	{
		 if (stacks->stacka[i] < stacks->stacka[i + 1])
		 	return (-1);
		i++;
	}
	return (1);
}

void	print_stack(int *stack, int top)
{
	while (top >= 0)
		ft_printf("%d\n", stack[top--]);
}