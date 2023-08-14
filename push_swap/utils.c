/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:32:57 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/08/14 13:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str, t_stack *stacks)
{
	int		i;
	int		n;
	long	result;

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
	if (!str[i])
		ft_error(stacks);
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i++] - 48;
		check_result(result, stacks);
	}
	if (!(str[i] <= '9' && str[i] >= '0') && str[i])
		ft_error(stacks);
	return (result * n);
}

void	free_all(t_stack *stacks)
{
	if (stacks)
	{
		free(stacks->stacka);
		stacks->stacka = NULL;
		free(stacks->stackb);
		stacks->stackb = NULL;
		free(stacks);
		stacks = NULL;
	}
}

void	ft_error(t_stack *stacks)
{
	write(2, "Error\n", 6);
	free_all(stacks);
	exit(1);
}

void	print_stack(t_stack *stacks)
{
	int	i;

	i = stacks->topa + 1;
	while (i--)
		ft_printf("%d\n", stacks->stacka[i]);
}

int	is_sorted(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->topa)
	{
		j = i + 1;
		while (j <= stacks->topa)
		{
			if (stacks->stacka[i] < stacks->stacka[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
