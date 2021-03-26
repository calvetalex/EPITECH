##
## EPITECH PROJECT, 2021
## guimoku
## File description:
## Makefile
##

MODULE	=	guimoku
NAME	=	guimoku-manager

all: build

run:
	python -m $(MODULE)

build:
	cp $(MODULE)/__main__.py $(NAME)
	chmod +x $(NAME)

clean:
	rm -rf $(MODULE)/__pycache__
	rm -rf build

fclean: clean
	rm -f $(NAME)
	rm -rf dist

re: fclean all
