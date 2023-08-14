SRCS = main.c init1.c init2.c rules1.c rules2.c rules3.c utils.c sortings1.c sortings2.c big_sort1.c big_sort2.c
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

$(LIBFT):
	@make -C libft

clean:
	rm -rf *.o
	@make -C ft_printf clean
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	@make -C ft_printf fclean
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re