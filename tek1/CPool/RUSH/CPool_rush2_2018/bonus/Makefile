##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil and create exe
##

SRC	=	../lib/my/my_getnbr.c	\
		../lib/my/my_putchar.c	\
		../lib/my/my_put_nbr.c	\
		../lib/my/my_putstr.c	\
		../lib/my/my_strcmp.c	\
		../lib/my/my_strcpy.c	\
		../lib/my/my_strlen.c	\
		../lib/my/my_strncmp.c	\
		../lib/my/my_strncmp.c	\
		../lib/my/my_strncpy.c	\
		../lib/my/my_strstr.c	\
		../lib/my/my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o rush2 main.c ../step3.c -L. -lmy
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
