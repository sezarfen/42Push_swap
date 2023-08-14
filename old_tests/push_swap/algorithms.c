#include "push_swap.h"

void	handle_five();
void	handle_three();

// 1 2 3
// 3 2 1
// 2 1 3
// 2 3 1


// özellikle hangi stack olduğu belli olmadığı için ona
// göre stack->type kısmına bakılabilir.

/*
[2]
[5]
[1]
[3]
[7]


[3]
[7]  
[2]
[5]  [1]


[3]
[7]  
[2]
[5]  [1]


[5]  
[3]  [2]
[7]  [1]

[3]
[5] [2]
[7] [1]

pa();
pa();

[1]
[2]
[3]
[5]
[7]

*/
void	three_nest(t_stack *stack, int i_max)
{  
	if (i_max == 2)
	{
		rb(stack);
		if (stack->array[2] > stack->array[1])
			sb(stack);
	}
	else if (i_max == 1)
	{
		rrb(stack);
		if (stack->array[2] > stack->array[1])
			sb(stack);
	}
	else
	{
		if (stack->array[2] > stack->array[1])
			sb(stack);
	}
}


void	handle_three(t_stack *stack)
{
	int	i_max;
	int	i;
	int	max;

	i = 0;
	i_max = 0;
	max = stack->array[0];
	while (i < 3)
	{
		if (max < stack->array[i])
		{
			max = stack->array[i];
			i_max = i;
		}
		i++;
	}
	three_nest(stack, i_max);
}


/*
[] 4 
[] 3
[] 2
[] 1
[] 0

*/

void	five_nest(t_stack *stacka, t_stack *stackb, int i_min)
{
	if (i_min >= 2) // stacka or stackb
	{
		while (i_min < stacka->top - 1)
		{
			ra(stacka);
			i_min++;
		}
	}
	else
	{
		while (i_min >= 0)
		{
			rra(stacka);
			i_min--;
		}
	}
	pb(stacka, stackb);
	if (stacka->top == 4) // ikinci gönderişten sonra bir daha gönderilemesin diye
		handle_five(stacka, stackb);
}

void	handle_five(t_stack *stacka, t_stack *stackb)
{ // find the min element's index in the list, move to top of the stack and send to stackb
	int	i_min;
	int	i;
	int min;

	i = 0;
	i_min = 0;
	min = stacka->array[0];
	while (i < stacka->top)
	{
		if (min > stacka->array[i])
		{
			min = stacka->array[i];
			i_min = i;
		}
		i++;
	}
	five_nest(stacka, stackb, i_min);
}