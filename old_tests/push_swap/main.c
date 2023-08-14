#include "push_swap.h"


/*
typedef struct s_stack
{
	int		*array;
	char	type;
	int		top;
} 		t_stack;
*/


void	my_main(t_stack *stacka)
{
	t_stack *stackb;
	
	stackb = malloc(sizeof(t_stack));
	stackb->array = malloc(sizeof(int) * (stacka->top));
	stackb->top = 0;
	stackb->type = 'b';

	ft_printf(">>>>>stack a<<<<<\n");
	print_stack(stacka);
	ft_printf(">>>>>handle_five<<<<<\n");
	handle_five(stacka, stackb);
	handle_three(stacka);
	pa(stacka, stackb);
	pa(stacka, stackb);
	ft_printf(">>>>>check<<<<<\n");
	print_stack(stacka);

}