##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

LIB	=	./my_putchar.c	\
		./my_getnbr.c	\
		./my_putstr.c	\
		./my_revstr.c	\
		./my_strcat.c	\
		./my_strcmp.c	\
		./my_strlen.c	\
		./my_swap.c	\
		./my_putnbr.c	\
		./my_isneg.c	\
		./my_strcpy.c	\
		./str_to_int.c	\
		./my_str_isnum.c	\
		./my_str_isprintable.c	\
		./my_strstr.c	\
		./my_strdup.c	\
		./free_array.c	\
		./str_to_word_array.c	\

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
