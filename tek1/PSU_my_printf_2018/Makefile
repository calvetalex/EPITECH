##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

LIB	=	lib/my_putchar.c	\
		lib/my_getnbr.c	\
		lib/my_putstr.c	\
		lib/my_revstr.c	\
		lib/my_strcat.c	\
		lib/my_strcmp.c	\
		lib/my_strlen.c	\
		lib/my_swap.c	\
		lib/my_put_nbr.c	\
		lib/sum_stdarg.c	\
		lib/disp_stdarg.c	\
		lib/convert_to_bin.c	\
		lib/disp_hexa.c	\
		lib/disp_binary.c	\
		lib/disp_oct.c	\
		lib/disp_nonprintable.c	\
		lib/disp_membase.c	\
		lib/my_printf.c

OBJ	=	$(LIB:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
