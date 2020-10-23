##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

LIB	=	./my_putchar.c	\
		./my_putstr.c	\
		./my_strcmp.c	\
		./my_strlen.c	\
		./my_putnbr.c	\
		./str_to_int.c	\
		./my_str_isnum.c	\

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
