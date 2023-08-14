#include "push_swap.h"

int av_checker(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] <= '9' && av[i][j] >= '0'))
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int main(int ac, char **av)
{
	int	i;
	t_stack	*stacka;

	if (ac >= 2)
	{
		if (av_checker(ac, av) == -1)
		{
			write(2, "Error!\n", 7);
			return (1);
		}
		stacka = malloc(sizeof(t_stack));
		stacka->array = malloc(sizeof(int) * (ac - 1));
		stacka->type = 'a';
		stacka->top = 0;
		i = 1;
		while (i < ac) // 6
		{
			stacka->array[stacka->top] = ft_atoi(av[ac - i]);
			stacka->top++;
			i++;
		}
		my_main(stacka);
	}
	else
		write(2, "Error!\n", 7);
	return (0);
}