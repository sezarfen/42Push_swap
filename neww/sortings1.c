#include "push_swap.h"

// maxi and mini are for namely "max index" and "min index"

int	midi_stacka(t_stack *stacks, int current) // kendinden büyük en küçüğü bulmalı
{
	int		i;
	int		index;
	long	temp;

	i = 0;
	index = 0;
	temp = LONG_MAX;
	while (i <= stacks->topa)
	{
		if (stacks->stacka[i] > current && stacks->stacka[i] < temp)
		{
			temp = stacks->stacka[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	maxi_stacka(t_stack *stacks)
{
	int	i;
	int	index;
	int	max;

	i = 0;
	index = 0;
	max = stacks->stacka[i];
	while (i <= stacks->topa)
	{
		if (max < stacks->stacka[i])
		{
			max = stacks->stacka[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	three_sort(t_stack *stacks)
{
	int	max;

	max = maxi_stacka(stacks);
	if (max == 0)
	{
		if (stacks->stacka[2] > stacks->stacka[1])
			sa(stacks->stacka, stacks->topa);
	}
	else if (max == 1)
	{
		rra(stacks->stacka, stacks->topa);
		if (stacks->stacka[2] > stacks->stacka[1])
			sa(stacks->stacka, stacks->topa);
	}
	else
	{
		ra(stacks->stacka, stacks->topa);
		if (stacks->stacka[2] > stacks->stacka[1])
			sa(stacks->stacka, stacks->topa);
	}
}

int	mini_stacka(t_stack *stacks)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = stacks->stacka[i];
	while (i <= stacks->topa)
	{
		if (min > stacks->stacka[i])
		{
			min = stacks->stacka[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	four_sort(t_stack *stacks)
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
	three_sort(stacks);
	pa(stacks);
}
/*
[]
"[]"
[]
[]
*/