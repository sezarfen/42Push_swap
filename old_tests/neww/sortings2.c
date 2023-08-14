#include "push_swap.h"

void	five_sort(t_stack *stacks)
{
	int	min;

	min = mini_stacka(stacks);
	if (min >= 2)
	{
		while (min < stacks->topa)
		{
			ra(stacks->stacka, stacks->topa);
			min++;
		}
	}
	else
	{
		while (min >= 0)
		{
			rra(stacks->stacka, stacks->topa);
			min--;
		}
	}
	pb(stacks);
	four_sort(stacks);
	pa(stacks);
}