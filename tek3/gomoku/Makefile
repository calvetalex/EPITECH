##
## EPITECH PROJECT, 2021
## gomoku
## File description:
## Makefile
##

NAME	=	pbrain-gomoku-ai

all:
ifeq ($(OS),Windows_NT)
	python3 compiler.py
else
	cp brain.py pbrain-gomoku-ai
	chmod +x pbrain-gomoku-ai
endif

clean:
	rm -rf *~


fclean:	clean
	rm -rf ./build
	rm -rf ./dist
	rm -rf ${NAME}*

re: fclean all
