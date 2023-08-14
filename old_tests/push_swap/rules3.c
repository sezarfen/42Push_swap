#include "push_swap.h"

// rra rrb rrr
void	rra(t_stack *stacka)
{
	int	i;
	int	temp;

	ft_printf("rra\n");
	temp = stacka->array[0];
	i = 0;
	while (i < stacka->top)
	{
		stacka->array[i] = stacka->array[i + 1];
		i++;
	}
	stacka->array[i - 1] = temp;
}
void	rrb(t_stack *stackb)
{
	int	i;
	int	temp;

	ft_printf("rrb\n");
	temp = stackb->array[0];
	i = 0;
	while (i < stackb->top)
	{
		stackb->array[i] = stackb->array[i + 1];
		i++;
	}
	stackb->array[i - 1] = temp;
}
void	rrr(t_stack *stacka, t_stack *stackb)
{
	ft_printf("rrr\n");
	rra(stacka);
	rrb(stackb);
}