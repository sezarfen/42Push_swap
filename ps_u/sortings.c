#include "push_swap.h"

/*
[4]
[6]
[1]
[3]		[11]
[9]		[7]
[5]		[2]
*/
// aralık sayıyı bulan bir algoritma yazıladabilir

// pb pb ile başlanabilir
void	big_sort(t_stack *stacks)
{
	int	current_a;
	int	indexb;

	current_a = stacks->stacka[stacks->topa];
	indexb = 0;
	if(current_a > get_max_b(stacks, &indexb))
	{
		get_max_to_top(stacks, indexb);
		pb(stacks);
	}
	else if (current_a < get_min_b(stacks, &indexb))
	{
		get_max_to_top(stacks, indexb);
		pb(stacks);
		rb(stacks->stackb, stacks->topb);
	}
	else // ara bir sayı geldiğini anlayabiliriz
	{
		get_mid_to_top(stacks, current_a);
		pb(stacks);
		if (stacks->topa == -1)
		{
			get_max_b(stacks, &indexb);
			get_max_to_top(stacks, indexb);
		}
		else
		{
			rb(stacks->stackb, stacks->topb);
			rb(stacks->stackb, stacks->topb);
		}
	}
}

void	get_mid_to_top(t_stack *stacks, int current)
{
	int	i;
	int	indexm;
	int	mid;
	int	flag;

	indexm = 0;
	i = 0;
	mid = 0;
	flag = 0;
	while (i <= stacks->topb)
	{
		mid = stacks->stackb[i];
		if (current > mid && flag < mid)
		{
			flag = mid;
			indexm = i;
		}
		i++;
	}

	if (indexm >= stacks->topb / 2)
	{
		while (indexm < stacks->topb)
		{
			rb(stacks->stackb, stacks->topb);
			indexm++;
		}
	}
	else
	{
		while (indexm >= 0)
		{
			rrb(stacks->stackb, stacks->topb);
			indexm--;
		}
	}
}


void	get_max_to_top(t_stack *stacks, int indexb)
{
	if (indexb >= stacks->topb / 2)
	{
		while (indexb < stacks->topb)
		{
			rb(stacks->stackb, stacks->topb);
			indexb++;
		}
	}
	else
	{
		while (indexb >= 0)
		{
			rrb(stacks->stackb, stacks->topb);
			indexb--;
		}
	}
}

int	get_min_b(t_stack *stacks, int *indexb)
{
	int	i;
	int	min;

	i = 0;
	min = stacks->stackb[i];
	while (i <= stacks->topb)
	{
		if (min > stacks->stackb[i])
		{
			min = stacks->stackb[i];
			*indexb = i;
		}
		i++;
	}
	return (min);
}

int	get_max_b(t_stack *stacks, int *indexb)
{
	int	i;
	int	max;

	i = 0;
	max = stacks->stackb[i];
	while (i <= stacks->topb)
	{
		if (max < stacks->stackb[i])
		{
			max = stacks->stackb[i];
			*indexb = i;
		}
		i++;
	}
	return (max);
}


/*

int	get_min_b(t_stack *stacks, int *index_minb)
{
	int	i;
	int	min;

	i = 0;
	*index_minb = i;
	min = stacks->stackb[i];
	while (i < stacks->topb)
	{
		if (min > stacks->stackb[i])
		{
			min = stacks->stackb[i];
			*index_minb = i;
		}
		i++;
	}
	return (min);
}


int	get_max_b(t_stack *stacks, int *index_mb)
{
	int	i;
	int	max;

	i = 0;
	*index_mb = i;
	max = stacks->stackb[i];
	while (i < stacks->topb)
	{
		if (max < stacks->stackb[i])
		{
			max = stacks->stackb[i];
			*index_mb = i;
		}
		i++;
	}
	return (max);
}

void	get_b_max_to_top(t_stack *stacks, int index_mb)
{
	if (index_mb >= stacks->topb / 2)
	{
		while (index_mb <= stacks->topb)
		{
			rb(stacks->stackb, stacks->topb);
			index_mb++;
		}
	}
	else
	{
		while (index_mb > 0)
		{
			rrb(stacks->stackb, stacks->topb);
			index_mb--;
		}
	}
}

void	get_middle_to_top(t_stack *stacks, int value)
{
	int	i;
	int	index;
	int	mid;
	int	current;

	i = 0;
	index = 0;
	current = 0;
	mid = stacks->stacka[i];
	while (i < stacks->topb)
	{
		current = stacks->stacka[i];
		if (value > current && current > mid)
		{
			mid = current;
			index = i;
		}
		i++;
	}

	if (index > stacks->topb / 2)
	{
		while (index <= stacks->topb)
		{
			rb(stacks->stackb, stacks->topb);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rrb(stacks->stackb, stacks->topb);
			index--;
		}
	}
}

void	big_sort(t_stack *stacks)
{
	int	maxb;
	int	minb;
	int	index_minb;
	int	index_maxb;

	pb(stacks);
	pb(stacks);
	index_maxb = 0;
	index_minb = 0;
	maxb = get_max_b(stacks, &index_maxb);
	minb = get_min_b(stacks, &index_minb);

	if (stacks->stacka[stacks->topa] > maxb)
	{
		get_b_max_to_top(stacks, index_maxb);
		pb(stacks);
	}
	else if (stacks->stacka[stacks->topa] < minb)
	{
		get_b_max_to_top(stacks, index_maxb);
		pb(stacks);
	}
	else
	{
		get_middle_to_top(stacks, stacks->stacka[stacks->topa]);
		pb(stacks);
	}
}
*/


/*
void	basic_sort(t_stack *stacks)
{
	int	i;
	int	i_min;
	int	min;

	i = stacks->topa;
	i_min = stacks->topa;
	min = stacks->stacka[stacks->topa];
	while (is_sorted(stacks) == -1)
	{
		while (i >= 0)
		{
			if (min > stacks->stacka[i])
			{
				min = stacks->stacka[i];
				i_min = i;
			}
			i--;
		}
		if (i_min == stacks->topa)
			pb(stacks);
		else if (i_min >= stacks->topa / 2)
		{
			while (i_min < stacks->topa)
			{
				ra(stacks->stacka, stacks->topa);
				i_min++;
			}
			pb(stacks);
		}
		else
		{
			while (i_min >= 0)
			{
				rra(stacks->stacka, stacks->topa);
				i_min--;
			}
			pb(stacks);
		}
		i_min = stacks->topa;
		i = stacks->topa;
		min = stacks->stacka[i];
	}
	while (stacks->topb >= 0)
		pa(stacks);
}

*/
