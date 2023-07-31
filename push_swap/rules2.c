#include "push_swap.h"

void	pa(t_stack *stacka, t_stack *stackb)
{
	int topb;

	ft_printf("pa\n");
	topb = stackb->array[stackb->top - 1];
	stackb->top--;
	stacka->array[stacka->top] = topb;
	stacka->top++;
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	int topa;

	ft_printf("pb\n");
	topa = stacka->array[stacka->top - 1];
	stacka->top--;
	stackb->array[stackb->top] = topa;
	stackb->top++;
}

void	ra(t_stack *stacka)
{
	int top;
	int	i;

	ft_printf("ra\n");
	top = stacka->array[stacka->top - 1];
	i = stacka->top - 1;
	while (i > 0)
	{
		stacka->array[i] = stacka->array[i - 1];
		i--;
	}
	stacka->array[0] = top;
}

void	rb(t_stack *stackb)
{
	int top;
	int	i;

	ft_printf("rb\n");
	top = stackb->array[stackb->top - 1];
	i = stackb->top - 1;
	while (i > 0)
	{
		stackb->array[i] = stackb->array[i - 1];
		i--;
	}
	stackb->array[0] = top;
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	ft_printf("rr\n");
	ra(stacka);
	rb(stackb);
}