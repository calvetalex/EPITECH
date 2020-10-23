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

CC	=	g++
## -------- SRC -------##

TESTDIR	=	./tests

SRC	=	./ex00/Skat.cpp

SRCTEST	=	$(TESTDIR)/test_Skat.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST	=	$(SRCTEST:.cpp=.o)

## ------- FLAGS --------##

cflags.common	:=
cflags.debug	:=	-g -g3
cflags.release	:=
cflags.tests	:=	-lcriterion -lgcov  --coverage

ldflags.common	:=
ldflags.debug	:=
ldflags.release	:=
ldflags.tests	:=

CFLAGS	:=	${cflags.${BUILD}} ${cflags.common}
LDFLAGS	:=	${ldflags.${BUILD}} ${ldflags.common}

## ------- LIB ----------##

TEST_LIB	=	bin_test

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:
	@make tests_run

%.o	:	%.cpp
		@$(CC)  $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK] " $(DEFAULT) $(TEAL) $<  $(DEFAULT)  " -----> " $(GREEN) $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] can't find " $(YELLOW) $^ $(DEFAULT)

set_rules	:
			$(eval BUILD=tests)
			$(eval CFLAGS=${cflags.tests} $(cflags.common))
			$(eval LDFLAGS=${ldflags.tests} $(ldflags.common))


$(TEST_LIB)	:	set_rules $(OBJ_TEST) $(OBJ)
			@$(CC) -o $(TEST_LIB) $(OBJ_TEST) $(OBJ) $(CFLAGS) $(LDFLAGS) -I"./"

tests_run	:	set_rules $(TEST_LIB)
			@./$(TEST_LIB)

clean:
	@$(foreach i, $(OBJ), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(i)" $(DEFAULT);)
	@$(foreach k, $(OBJ_TEST), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(k)" $(DEFAULT);)
	@rm -rf $(OBJ_TEST)
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	@find -name "*.gcov" -delete && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

fclean:	clean
	@rm -rf $(LIBNAME); echo -e $(MAGENTA) "\tRemoved:  $(LIBNAME)" $(DEFAULT)
	@rm -rf $(TEST_LIB)

re:	fclean all
