#include "push_swap.h"

void	rra(int *stacka, int topa)
{
	int	temp;
	int	i;

	temp = stacka[0];
	i = 0;
	while (i < topa)
	{
		stacka[i] = stacka[i + 1];
		i++;
	}
	stacka[topa] = temp;
	ft_printf("rra\n");
}

void	rrb(int *stackb, int topb)
{
	int	temp;
	int	i;

	temp = stackb[0];
	i = 0;
	while (i < topb)
	{
		stackb[i] = stackb[i + 1];
		i++;
	}
	stackb[topb] = temp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stacks)
{
	ft_printf("rrr\n");
	rra(stacks->stacka, stacks->topa);
	rrb(stacks->stackb, stacks->topb);
}

void	check_result(long result, t_stack *stacks)
{
	if (result >= 0x80000000 || result < -2147483648)
		ft_error(stacks);
}
