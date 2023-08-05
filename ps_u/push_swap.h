#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_stack
{
	int	*stacka;
	int	*stackb;
	int	topa;
	int	topb;
}		t_stack;

void	print_stack(int *stack, int top);
void 	av_checker(int ac, char **av);
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
//void	basic_sort(t_stack *stacks);
void	sort_three(int *stacka, int topa);
void	sort_five(t_stack *stacks); // sort five also sorts for 4 elements
void	check_duplicates(t_stack *stacka);
void	big_sort(t_stack *stacks);
void	free_all(t_stack *stacks);
void	get_mid_to_top(t_stack *stacks, int current);
void	get_max_to_top(t_stack *stacks, int indexb);
int		get_max_b(t_stack *stacks, int *indexb);
int		get_min_b(t_stack *stacks, int *indexb);

#endif