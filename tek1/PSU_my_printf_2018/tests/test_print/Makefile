##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile to make and do criterion tests for my_printf()
##

SRC	=	test_printf.c	\
		../../lib/my_printf.c

NAME	=	testing

all:	cmp

cmp:
	gcc -o $(NAME) $(SRC) --coverage -lcriterion -lgcov -Ll ../../libmy.a
	./testing
##gcovr

clean:
	rm -r $(NAME)

fclean:	clean
	mr_clean.sh

re: fclean all
