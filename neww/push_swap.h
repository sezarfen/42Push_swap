#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "limits.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*stacka;
	int	*stackb;
	int	topa;
	int	topb;
}	t_stack;

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

void	free_all(t_stack *stacks);
void	ft_error(t_stack *stacks);
t_stack	*split_and_check(char **av);
long	ft_atol(const char *str, t_stack *stacks);
void	print_stack(t_stack *stacks);
t_stack *args_and_check(int ac, char **av);
void	check_duplicates(t_stack *stacks);
void	three_sort(t_stack *stacks);
void	four_sort(t_stack *stacks);
void	five_sort(t_stack *stacks);
int		mini_stacka(t_stack *stacks);
int		maxi_stacka(t_stack *stacks);
int		is_sorted(t_stack *stacks);
void	big_sort(t_stack *stacks);
int		midi_stacka(t_stack *stacks, int current);
int		find_cost_in_stacka(t_stack *stacks, int current);
void	get_cheapest_to_top(t_stack *stacks, int cheap_index);


#endif