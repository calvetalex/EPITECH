##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## COMPILL ALL .C
##

SRC = pres.c 

OBJ = $(SRC:.c=.o)

TMP = $(SRC:.c=.c~)

NAME =	presentation

CP = cp

RM = rm

ARRC = ar rc 

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L../../lib -lmy

clean:
	$(RM) -f $(OBJ)

fclean: clean
	rm -f ../$(NAME) $(TMP)

re: fclean all
