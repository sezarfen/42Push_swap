#include "push_swap.h"



/*

[2]
[3]
[1]

[3]
[2]
[1]


[3]
[2]
[1]

*/

void	five_nest(int *stacka, int topa, int i_min, t_stack *stacks)
{
	if (i_min >= topa / 2)
	{
		while (i_min < topa)
		{
			ra(stacka, topa);
			i_min++;
		}
	}
	else
	{
		while (i_min >= 0)
		{
			rra(stacka, topa);
			i_min--;
		}
	}
	pb(stacks);
}

void	sort_five(int *stacka, int topa, t_stack *stacks)
{
	int	i;
	int	i_min;
	int	min;

	i = 0;
	i_min = i;
	min = stacka[i];
	while (i <= topa)
	{
		if (min > stacka[i])
		{
			min = stacka[i];
			i_min = i;
		}
		i++;
	}
	five_nest(stacka, topa, i_min, stacks);
}

void	sort_nest(int *stacka, int topa, int i_max)
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
	sort_nest(stacka, topa, i_max);
}


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