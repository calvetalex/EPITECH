##
## EPITECH PROJECT, 2019
## FUN_imageCompressor_2019
## File description:
## Makefile
##

NAME	=	imageCompressor

.PHONY: all clean fclean re

all:
	stack build --copy-bins --local-bin-path .
	mv $(NAME)-exe $(NAME)

clean:
	stack clean
	rm -rf ".stack-work"

fclean: clean
	rm -f $(NAME)

re: fclean all
