/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:32:48 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 13:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stacks)
{
	int	temp;

	ft_printf("pa\n");
	temp = stacks->stackb[stacks->topb];
	stacks->topb--;
	stacks->topa++;
	stacks->stacka[stacks->topa] = temp;
}

void	pb(t_stack *stacks)
{
	int	temp;

	ft_printf("pb\n");
	temp = stacks->stacka[stacks->topa];
	stacks->topa--;
	stacks->topb++;
	stacks->stackb[stacks->topb] = temp;
}

void	ra(int *stacka, int topa)
{
	int	temp;

	temp = stacka[topa];
	while (topa > 0)
	{
		stacka[topa] = stacka[topa - 1];
		topa--;
	}
	stacka[0] = temp;
	ft_printf("ra\n");
}

void	rb(int *stackb, int topb)
{
	int	temp;

	temp = stackb[topb];
	while (topb > 0)
	{
		stackb[topb] = stackb[topb - 1];
		topb--;
	}
	stackb[0] = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *stacks)
{
	ft_printf("rr\n");
	ra(stacks->stacka, stacks->topa);
	rb(stacks->stackb, stacks->topb);
}
