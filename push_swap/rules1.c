/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:33:12 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 14:22:09 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stacka, int top)
{
	int	temp;

	temp = stacka[top];
	stacka[top] = stacka[top - 1];
	stacka[top - 1] = temp;
	ft_printf("sa\n");
}

void	sb(int *stackb, int top)
{
	int	temp;

	temp = stackb[top];
	stackb[top] = stackb[top - 1];
	stackb[top - 1] = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *stacks)
{
	sa(stacks->stacka, stacks->topa);
	sb(stacks->stackb, stacks->topb);
}

char	**connect_args(int ac, char **av)
{
	char	**to_return;
	char	*string;
	int		i;

	i = 1;
	string = malloc(sizeof(1));
	string[0] = '\0';
	while (i < ac)
	{
		string = ft_strjoin(string, " ");
		string = ft_strjoin(string, av[i]);
		i++;
	}
	to_return = ft_split(string, ' ');
	free(string);
	return (to_return);
}
