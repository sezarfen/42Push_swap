#include "push_swap.h"

// rra rrb rrr

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

// ra rb rr

void	ra(int *stacka, int topa)
{
	int	temp;

	temp = stacka[topa];
	while (topa > 0)
	{
		stacka[topa] = stacka[topa - 1];
		topa--;
	}
	stacka[0] = temp;
	ft_printf("ra\n");
}

void	rb(int *stackb, int topb)
{
	int	temp;

	temp = stackb[topb];
	while (topb > 0)
	{
		stackb[topb] = stackb[topb - 1];
		topb--;
	}
	stackb[0] = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *stacks)
{
	ft_printf("rr\n");
	ra(stacks->stacka, stacks->topa);
	rb(stacks->stackb, stacks->topb);
}

// pa pb

void	pa(t_stack *stacks)
{
	int	temp;

	ft_printf("pa\n");
	temp = stacks->stackb[stacks->topb];
	stacks->topb--;
	stacks->topa++;
	stacks->stacka[stacks->topa] = temp;
}

void	pb(t_stack *stacks)
{
	int	temp;

	ft_printf("pb\n");
	temp = stacks->stacka[stacks->topa];
	stacks->topa--;
	stacks->topb++;
	stacks->stackb[stacks->topb] = temp;
}

// sa sb ss

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