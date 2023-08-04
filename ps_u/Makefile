SRCS = push_swap.c rules.c utils.c sortings.c arg_check.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CFLAGS = -Werror -Wall -Wextra
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	gcc $(CFLAGS) -o push_swap $(OBJS) $(FT_PRINTF) $(LIBFT)

$(FT_PRINTF):
	@make -C ft_printf

clean:
	rm -rf *.o
	@make -C ft_printf clean

fclean: clean
	rm -rf push_swap
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re