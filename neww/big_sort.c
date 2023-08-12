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

int get_min_stacka(t_stack *stacks)
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

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	find_cost_in_stacka(t_stack *stacks, int current)
{
	int	mina;
	int	maxa;
	int	cost;
	int	min_i;
	int	mid_i;

	mina = get_min_stacka(stacks);
	maxa = get_max_stacka(stacks);
	min_i = mini_stacka(stacks);
	mid_i = midi_stacka(stacks, current);
	cost = 0;
	if (current < mina || current > maxa)
	{
		if (min_i >= stacks->topa / 2)
			cost += stacks->topa - min_i;
		else
			cost += min_i + 1;
	}
	//else if ()
	//{
	//	if (min_i >= stacks->topa / 2)
	//		cost += stacks->topa - min_i;
	//	else
	//		cost += min_i + 1;
	//}
	else
	{
		if (mid_i >= stacks->topa / 2)
			cost += stacks->topa - mid_i;
		else
			cost += mid_i + 1;
	}
	return (cost);
}

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
		cost += find_cost_in_stacka(stacks, stacks->stackb[i]); // şu anki elemanın a daki konumunu en üste getirmek için harcanacak sayı
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
 // 35
/*            [COST]
8 [653]         0
7 [34]			1
6 [32]			2
5 [6123]		3
4 [563] 		4		//  stacks->topb / 2 
3 [65]			4
2 [77]			3
1 [78]			2
0 [45] 			1
*/

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

	while (stacks->topa != 2) // != 4 de yapılabilir , five_sort için
		pb(stacks);
	three_sort(stacks);
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
		ra(stacks->stacka, stacks->topa);
	}
	else
	{
		while (is_sorted(stacks) != 1)
			rra(stacks->stacka, stacks->topa);
	}
}
