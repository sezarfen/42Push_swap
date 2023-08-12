#include "push_swap.h"

void	split_init_stacks(t_stack **stacks, int len)
{
	(*stacks) = malloc(sizeof(t_stack));
	(*stacks)->stacka = malloc(sizeof(int) * (len));
	(*stacks)->stackb = malloc(sizeof(int) * (len));
	if (!(*stacks)->stacka || !(*stacks)->stackb)
		ft_error((*stacks));
	(*stacks)->topa = -1;
	(*stacks)->topb = -1;
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_stack	*split_and_check(char **av)
{
	t_stack	*stacks;
	char	**split;
	int		i;
	int		slen;

	stacks = NULL;
	split = ft_split(av[1], ' ');
	slen = split_len(split);
	i = 0;
	split_init_stacks(&stacks, slen);
	while (split[i])
	{
		stacks->topa++;
		stacks->stacka[i] = ft_atol(split[slen - i - 1], stacks);
		i++;
	}
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (stacks);
}
