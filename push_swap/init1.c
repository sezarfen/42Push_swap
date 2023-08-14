/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:32:23 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 13:32:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_init_stacks(t_stack **stacks, int len)
{
	(*stacks) = malloc(sizeof(t_stack));
	if (!(*stacks))
		ft_error((*stacks));
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
	if (av[1][0] == '\0' || av[1][0] == ' ')
		ft_error(stacks);
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
