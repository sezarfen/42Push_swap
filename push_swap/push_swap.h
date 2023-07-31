#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_stack
{
	int		*array;
	char	type;
	int		top;
} 		t_stack;

void	my_main(t_stack *stack_a);
void	handle_three(t_stack *stack);
void	sa(t_stack *stacka);
void	sb(t_stack *stackb);
void	ss(t_stack *stacka, t_stack *stackb);
void	pa(t_stack *stacka, t_stack *stackb);
void	pb(t_stack *stacka, t_stack *stackb);
void	ra(t_stack *stacka);
void	rb(t_stack *stackb);
void	rr(t_stack *stacka, t_stack *stackb);
void	rra(t_stack *stacka);
void	rrb(t_stack *stackb);
void	rrr(t_stack *stacka, t_stack *stackb);
void	print_stack(t_stack *stack);
void	handle_five(t_stack *stacka, t_stack *stackb);
void	five_nest(t_stack *stacka, t_stack *stackb, int i_min);

#endif