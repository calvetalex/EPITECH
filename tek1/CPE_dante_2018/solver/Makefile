##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make / clena / fclean / re
##

## ------- DIR --------##
SRCDIR	=	./src

TESTDIR	=	./tests

## -------- SRC -------##

SRCTEST	=	$(TESTDIR)/

MAIN	=	$(SRCDIR)/main.c

SRC	=  	$(SRCDIR)/get_next_line.c	\

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

## ------- FLAGS --------##

CFLAGS	+=	-W -Wextra -Wall -pedantic -I ./include/

LDFLAGS	=	-L./lib -lmy

LDFLAGS_TEST	=	-lcriterion -lgcov --coverage

## ------- BIN ----------##

BINNAME	=	solver

TEST_BIN	=	$(BINNAME)_test

## --------- RULES --------##

all:	$(BINNAME)

$(BINNAME):	$(OBJ)
	make -C ./lib/
	gcc -o $(BINNAME) $(OBJ) $(LDFLAGS)

tests_run: fclean
	make -C ./lib/
	gcc $(SRC) $(SRCTEST) $(CFLAGS) $(LDFLAGS) $(LDFLAGS_TEST) -o $(TEST_BIN)
	./$(TEST_BIN) --always-succeed

tests_rm: fclean
	rm -rf $(TEST_BIN)
	rm -rf *.gcno *.gcda

clean:
	make clean -C ./lib/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ./lib/
	rm -rf $(BINNAME)

debug: CFLAGS += -g -g3
debug: clean all

re:	fclean all
