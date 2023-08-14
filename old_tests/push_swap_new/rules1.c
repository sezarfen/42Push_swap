#include "push_swap.h"

void	sa(int *stacka, int top)
{
	int	temp;

	temp = stacka[top];
	stacka[top] = stacka[top - 1];
	stacka[top - 1] = temp;
	ft_printf("sa\n");
}

void	sb(int *stackb, int top)
{
	int	temp;

	temp = stackb[top];
	stackb[top] = stackb[top - 1];
	stackb[top - 1] = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *stacks)
{
	sa(stacks->stacka, stacks->topa);
	sb(stacks->stackb, stacks->topb);
}
