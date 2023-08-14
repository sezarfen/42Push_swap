/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:32:12 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 13:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_init_stacks(t_stack **stacks, int ac)
{
	(*stacks) = malloc(sizeof(t_stack));
	if (!(*stacks))
		ft_error((*stacks));
	(*stacks)->stacka = malloc(sizeof(int) * (ac));
	(*stacks)->stackb = malloc(sizeof(int) * (ac));
	if (!(*stacks)->stacka || !(*stacks)->stackb)
		ft_error((*stacks));
	(*stacks)->topa = -1;
	(*stacks)->topb = -1;
}

t_stack	*args_and_check(int ac, char **av)
{
	t_stack	*stacks;
	int		i;

	stacks = NULL;
	args_init_stacks(&stacks, ac);
	i = 0;
	while (i < ac)
	{
		stacks->topa++;
		stacks->stacka[i] = ft_atol(av[ac - i - 1], stacks);
		i++;
	}
	while (i >= 0)
	{
		free(av[i]);
		i--;
	}
	free(av);
	return (stacks);
}
