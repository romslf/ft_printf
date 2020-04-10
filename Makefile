# TODO Add libft makefile
C = gcc

NAME = libftprintf.a

SRCS = src/main.c \
       src/handle_spaces.c \
	   src/options/minus.c \
	   src/options/point.c \
	   src/printers/ft_print_address.c \
	   src/printers/ft_print_char.c \
	   src/printers/ft_print_hex.c \
	   src/printers/ft_print_hexa.c \
	   src/printers/ft_print_nb.c \
	   src/printers/ft_print_str.c \
	   src/printers/ft_print_unsigned.c \
	   src/utils/ft_ullintlen.c \
       src/utils/ft_numlen.c \
       src/utils/len_nbr_base.c \
       src/utils/ft_putchar.c \
	   src/utils/ft_putnbr_base.c \
	   src/utils/ft_putnbr.c \
	   src/utils/ft_putstr.c \
	   src/utils/ft_strlen.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(C) -I src/libftprintf.h -o $@ -c $< $(FLAGS)

bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all