#include "push_swap.h"


void	five_nest(t_stack *stacks, int i_min)
{
	if (i_min >= stacks->topa / 2) // 3 / 2 -> 1
	{
		while (i_min < stacks->topa) // 2 < 3
		{
			ra(stacks->stacka, stacks->topa);
			i_min++;
		}
	}
	else
	{
		while (i_min >= 0)
		{
			rra(stacks->stacka, stacks->topa);
			i_min--;
		}
	}
	pb(stacks);
	if (stacks->topa == 3)
		sort_five(stacks);
	else
	{
		sort_three(stacks->stacka, stacks->topa);
		pa(stacks);
		pa(stacks);
	}
}

void	sort_five(t_stack *stacks)
{
	int	i;
	int	i_min;
	int	min;

	if (is_sorted(stacks) == 1)
		return ;
	i = 0;
	i_min = i;
	min = stacks->stacka[i];
	while (i <= stacks->topa)
	{
		if (min > stacks->stacka[i])
		{
			min = stacks->stacka[i];
			i_min = i;
		}
		i++;
	}
	five_nest(stacks, i_min);
}

void	three_nest(int *stacka, int topa, int i_max)
{
	if (i_max == 2)
	{
		ra(stacka, topa);
		if (stacka[2] > stacka[1])
			sa(stacka, topa);
	}
	else if (i_max == 1)
	{
		rra(stacka, topa);
		if (stacka[2] > stacka[1])
			sa(stacka, topa);
	}
	else
	{
		if (stacka[2] > stacka[1])
			sa(stacka, topa);
	}
}

void	sort_three(int *stacka, int topa)
{
	int	i;
	int	i_max;
	int	max;

	i = 0;
	i_max = 0;
	max = stacka[i];
	while (i <= topa)
	{
		if (max < stacka[i])
		{
			max = stacka[i];
			i_max = i;
		}
		i++;
	} // find the max's index and send it to bottom
	three_nest(stacka, topa, i_max);
}
