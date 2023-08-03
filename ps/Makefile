SRCS = push_swap.c rules.c utils.c sortings.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CFLAGS = -Werror -Wall -Wextra
FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	gcc $(CFLAGS) -o push_swap $(OBJS) $(FT_PRINTF)

clean:
	rm -rf *.o

fclean: clean
	rm -rf push_swap

re: fclean all

.PHONY: all clean fclean re