##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKEFILE
##

SRC =	rush3.c	\
		main.c

NAME = rush3

MAKE = make

TMP = $(SRC:.c=.c~)

all: $(NAME)

$(NAME):
	$(MAKE) -C ./lib/my
	gcc -o $(NAME) $(SRC) -L./lib -lmy

clean:
	$(RM) -f $(OBJ)
	$(MAKE) -C ./lib/my clean
	rm -f ./include/my.h

fclean: clean
	rm -f $(NAME) $(TMP)
	$(MAKE) -C ./lib/my fclean

re: fclean all


