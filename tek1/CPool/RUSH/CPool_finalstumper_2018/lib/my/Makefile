##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## COMPILL ALL .C
##

SRC = my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strlen.c \
	str_to_int.c 

OBJ = $(SRC:.c=.o)

TMP = $(SRC:.c=.c~)

NAME = libmy.a

CP = cp

RM = rm

ARRC = ar rc 

all: $(NAME)

$(NAME):	$(OBJ)
	$(ARRC) ../$(NAME) $(OBJ)
	$(CP) my.h ../../include/my.h

clean:
	$(RM) -f $(OBJ)

fclean: clean
	rm -f ../$(NAME) $(TMP)

re: fclean all
