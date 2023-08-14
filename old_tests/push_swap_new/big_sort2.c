#include "push_swap.h"

int	get_max_stacka(t_stack *stacks)
{
	int	i;
	int	max;

	i = 0;
	max = stacks->stacka[i];
	while (i <= stacks->topa)
	{
		if (max < stacks->stacka[i])
			max = stacks->stacka[i];
		i++;
	}
	return (max);
}

int	get_min_stacka(t_stack *stacks)
{
	int	i;
	int	min;

	i = 0;
	min = stacks->stacka[i];
	while (i <= stacks->topa)
	{
		if (min > stacks->stacka[i])
			min = stacks->stacka[i];
		i++;
	}
	return (min);
}

int	find_cost_in_stacka(t_stack *stacks, int current)
{
	int	mina;
	int	cost;
	int	min_i;
	int	mid_i;

	mina = get_min_stacka(stacks);
	min_i = mini_stacka(stacks);
	mid_i = midi_stacka(stacks, current);
	cost = 0;
	if (current < mina || current > get_max_stacka(stacks))
	{
		if (min_i >= stacks->topa / 2)
			cost += stacks->topa - min_i;
		else
			cost += min_i + 1;
	}
	else
	{
		if (mid_i >= stacks->topa / 2)
			cost += stacks->topa - mid_i;
		else
			cost += mid_i + 1;
	}
	return (cost);
}
