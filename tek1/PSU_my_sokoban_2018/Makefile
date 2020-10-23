##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make binary file
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
		lib/disp_unsigned.c	\
		lib/my_printf.c

SRC	=	src/my_soko.c	\
		src/my_putnbr.c	\
		src/horizontal_move.c\
		src/find_player.c	\
		src/vertical_move.c	\
		src/iswin.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/disp_use.c

INCL	=	-I include/ -lncurses -Ll ./libmy.a

NAME	=	my_sokoban

OBJ	=	$(LIB:.c=.o)

LIBNAME	=	libmy.a

all:	cmp

cmp:	$(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	gcc -o $(NAME) $(SRC) $(INCL)

clean:
	rm -r $(OBJ)
	mr_clean.sh

fclean:	clean
	rm -rf $(LIBNAME)
	rm -rf $(NAME)

re: fclean all
