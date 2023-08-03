#include "push_swap.h"

int	is_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->topa)
	{
		 if (stacks->stacka[i] < stacks->stacka[i + 1])
		 	return (-1);
		i++;
	}
	return (1);
}

void	print_stack(int *stack, int top)
{
	while (top >= 0)
		ft_printf("%d\n", stack[top--]);
}


int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * n);
}