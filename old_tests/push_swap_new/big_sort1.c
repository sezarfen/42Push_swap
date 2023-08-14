#include "push_swap.h"

int	find_cheapest_index(t_stack *stacks)
{
	int		i;
	int		index;
	int		cost;
	long	temp_cost;

	i = 0;
	cost = 0;
	index = 0;
	temp_cost = LONG_MAX;
	while (i <= stacks->topb)
	{
		cost += find_cost_in_stacka(stacks, stacks->stackb[i]);
		if (i >= stacks->topb / 2)
			cost += stacks->topb - i;
		else
			cost += i + 1;
		if (temp_cost > cost)
		{
			temp_cost = cost;
			index = i;
		}
		cost = 0;
		i++;
	}
	return (index);
}

void	get_to_top(t_stack *stacks, int i)
{
	if (i >= stacks->topa / 2)
	{
		while (i < stacks->topa)
		{
			ra(stacks->stacka, stacks->topa);
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			rra(stacks->stacka, stacks->topa);
			i--;
		}
	}
}

void	perform_for_cheapest(t_stack *stacks, int ci)
{
	int	current;
	int	i;

	i = 0;
	current = stacks->stackb[ci];
	if (current > get_max_stacka(stacks) || current < get_min_stacka(stacks))
	{
		i = mini_stacka(stacks);
		get_to_top(stacks, i);
		get_cheapest_to_top(stacks, ci);
		pa(stacks);
	}
	else
	{
		i = midi_stacka(stacks, current);
		get_to_top(stacks, i);
		get_cheapest_to_top(stacks, ci);
		pa(stacks);
	}
}

void	get_cheapest_to_top(t_stack *stacks, int cheap_index)
{
	int	i;

	i = cheap_index;
	if (i >= stacks->topb / 2)
	{
		while (i < stacks->topb)
		{
			rb(stacks->stackb, stacks->topb);
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			rrb(stacks->stackb, stacks->topb);
			i--;
		}
	}
}

void	big_sort(t_stack *stacks)
{
	int	cheap_index;
	int	maxi;

	while (stacks->topa != 4)
		pb(stacks);
	five_sort(stacks);
	while (stacks->topb >= 0)
	{
		cheap_index = find_cheapest_index(stacks);
		perform_for_cheapest(stacks, cheap_index);
	}
	maxi = maxi_stacka(stacks);
	if (maxi >= stacks->topa / 2)
	{
		while (is_sorted(stacks) != 1)
			ra(stacks->stacka, stacks->topa);
		if (is_sorted(stacks) != 1)
			ra(stacks->stacka, stacks->topa);
	}
	else
	{
		while (is_sorted(stacks) != 1)
			rra(stacks->stacka, stacks->topa);
	}
}
