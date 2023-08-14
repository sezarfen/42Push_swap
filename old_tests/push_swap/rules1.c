#include "push_swap.h"

void	sa(t_stack *stacka)
{
	int	temp;

	ft_printf("sa\n");
	temp = stacka->array[stacka->top - 1];
	stacka->array[stacka->top - 1] = stacka->array[stacka->top - 2];
	stacka->array[stacka->top - 2] = temp;
}

void	sb(t_stack *stackb)
{
	int	temp;

	ft_printf("sb\n");
	temp = stackb->array[stackb->top - 1];
	stackb->array[stackb->top - 1] = stackb->array[stackb->top - 2];
	stackb->array[stackb->top - 2] = temp;
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	ft_printf("ss\n");
	sa(stacka);
	sb(stackb);
}
