##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make / clena / fclean / re
##

## --------- COLOR ------##

DEFAULT	=	"\033[00m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
YELLOW	=	"\033[1;7;25;33m"
MAGENTA	=	"\033[1;3;4;35m"
ERROR	=	"\033[5;7;1;31m"

ECHO	=	echo -e

## -------- COMPIL ----##

CC	=	ghc

## ------- DIR --------##
SRCDIR	=	./src

## -------- SRC -------##

SRC	=	$(SRCDIR)/main.hs

## ------- BIN ----------##

BINNAME	=	wolfram

## --------- RULES --------##

all:
	@make -s $(BINNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

$(BINNAME)	:
	@$(CC) -o $(BINNAME) $(SRC)

clean:
	@$(ECHO) $(TEAL) "Removing .hi......" $(DEFAULT)
	@rm -rf src/*.hi
	@$(ECHO) $(TEAL) "Removing .o......." $(DEFAULT)
	@rm -rf src/*.o
	@$(ECHO) $(TEAL) "Repository clean !" $(DEFAULT)

fclean:	clean
	@rm -rf $(BINNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

re:	fclean all
