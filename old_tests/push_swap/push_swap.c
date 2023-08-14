#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int top;

	top = stack->top;
	while (top > 0)
	{
		top--;
		ft_printf("%d\n", stack->array[top]);
	}
}