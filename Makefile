NAME = push_swap

CC = cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = main/main.c \
		  op/ft_push_a.c \
		  op/ft_push_b.c \
		  op/ft_swap_a.c \
		  op/ft_swap_b.c \
		  op/ft_swap_a_and_b.c \
		  op/ft_rotate_a.c \
		  op/ft_rotate_b.c \
		  op/ft_rotate_a_and_b.c \
		  op/ft_reverse_rotate_a.c \
		  op/ft_reverse_rotate_b.c \
		  op/ft_reverse_rotate_a_and_b.c \
		  strategy/ft_simple_strategy.c \
		  strategy/ft_medium_strategy.c \
		  strategy/ft_disorder.c \
		  main/utils.c \
		  main/utils2.c \
		  strategy/index_normalization.c \
		  strategy/merge_sort.c \
		  strategy/radix_sort.c \
		  strategy/ft_adaptive_strategy.c \
		  main/ft_parsing.c \
		  bench/ft_bench.c \
		  bench/ft_bench_print.c \
		  main/ft_flags.c \
		  op/ft_op_helper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c Push_Swap.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
