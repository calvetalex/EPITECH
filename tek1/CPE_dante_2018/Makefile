##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make / clena / fclean / re
##

all:
	make -C ./generator/
	cp ./generator/generator tournament/

tests_run: fclean
	make tests_run -C ./generator/

tests_rm:
	make tests_rm -C ./generator/

clean:
	make clean -C ./generator/

fclean:	clean
	rm tournament/generator
	make fclean -C ./generator/

debug:
	make debug -C ./generator/

re:	fclean all
