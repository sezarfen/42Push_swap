#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*stacka;
	int	*stackb;
	int	topa;
	int	topb;
}		t_stack;


int		ft_atoi(const char *str);
void	print_stack(int *stack, int top);
int 	av_checker(int ac, char **av);
void	sa(int *stacka, int top);
void	sb(int *stackb, int top);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	ra(int *stacka, int topa);
void	rb(int *stackb, int topb);
void	rr(t_stack *stacks);
void	rra(int *stacka, int topa);
void	rrb(int *stackb, int topb);
void	rrr(t_stack *stacks);
int		is_sorted(t_stack *stacks);
void	sort(t_stack *stacks);
void	sort_three(int *stacka, int topa);

#endif