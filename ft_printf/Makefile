CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_print_char.c ft_printf.c ft_print_hex_in_low.c ft_print_hex_in_upper.c \
      ft_print_num.c ft_print_pointer.c ft_print_string.c ft_print_unsigned_int.c

OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)


%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
