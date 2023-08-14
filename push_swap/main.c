/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:33:34 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 13:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->topa)
	{
		j = i + 1;
		while (j <= stacks->topa)
		{
			if (stacks->stacka[i] == stacks->stacka[j])
				ft_error(stacks);
			j++;
		}
		i++;
	}
}

t_stack	*check_and_initialize(int ac, char **av)
{
	t_stack	*stacks;
	int		new_av_len;
	char	**new_av;

	stacks = NULL;
	new_av = NULL;
	new_av_len = 0;
	if (ac < 2)
		ft_error(stacks);
	else if (ac == 2)
		stacks = split_and_check(av);
	else if (ac > 2)
	{
		new_av = connect_args(ac, av);
		new_av_len = split_len(new_av);
		stacks = args_and_check(new_av_len, new_av);
	}
	check_duplicates(stacks);
	return (stacks);
}

void	start_sorting(t_stack *stacks)
{
	if (is_sorted(stacks) == 1)
	{
		free_all(stacks);
		exit(1);
	}
	else if (stacks->topa == 1)
		sa(stacks->stacka, stacks->topa);
	else if (stacks->topa == 2)
		three_sort(stacks);
	else if (stacks->topa == 3)
		four_sort(stacks);
	else if (stacks->topa == 4)
		five_sort(stacks);
	else
		big_sort(stacks);
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac > 1)
	{
		stacks = check_and_initialize(ac, av);
		start_sorting(stacks);
		free_all(stacks);
	}
	return (0);
}
