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

## -------- SRC -------##

TESTDIR	=	./tests

SRC	=	./array.c		\
		./char.c		\
		./int.c			\
		./float.c		\
		./new.c			\
		./point.c		\
		./vertex.c

SRCTEST	=	$(TESTDIR)/test_vertex.c	\
			$(TESTDIR)/test_point.c		\
			$(TESTDIR)/test_int.c		\
			$(TESTDIR)/test_int2.c		\
			$(TESTDIR)/test_int3.c		\
			$(TESTDIR)/test_char.c		\
			$(TESTDIR)/test_char2.c		\
			$(TESTDIR)/test_char3.c		\
			$(TESTDIR)/test_float.c		\
			$(TESTDIR)/test_float2.c		\
			$(TESTDIR)/test_float3.c		\
			$(TESTDIR)/test_array.c


OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRCTEST:.c=.o)

## ------- FLAGS --------##

cflags.common	:= -Itest_files/rush1/include
cflags.debug	:=	-g -g3
cflags.release	:=
cflags.tests	:=	--coverage

ldflags.common	:=
ldflags.debug	:=
ldflags.release	:=
ldflags.tests	:= -lcriterion -lgcov

CFLAGS	:=	${cflags.${BUILD}} ${cflags.common}
LDFLAGS	:=	${ldflags.${BUILD}} ${ldflags.common}

## ------- LIB ----------##

TEST_BIN	=	Rush1_test

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:	$(TEST_BIN)
		@./$(TEST_BIN) && \
		$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
		$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(TEST_BIN) $(DEFAULT)

set_rules:
			$(eval BUILD=tests)
			$(eval CFLAGS=${cflags.tests} $(cflags.common))
			$(eval LDFLAGS=${ldflags.tests} $(ldflags.common))

$(TEST_BIN)	:	set_rules $(OBJ_TEST) $(OBJ)
			@$(CC) -o $(TEST_BIN) $(OBJ_TEST) $(OBJ) $(CFLAGS) $(LDFLAGS) -I"./"

%.o	:	%.c
		@$(CC)  $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK] " $(DEFAULT) $(TEAL) $<  $(DEFAULT)  " -----> " $(GREEN) $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] can't find " $(YELLOW) $^ $(DEFAULT)

tests_run:	set_rules $(TEST_BIN)
			@./$(TEST_BIN) && \
			$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
			$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(TEST_BIN) $(DEFAULT)

clean:
	@$(foreach i, $(OBJ), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(i)" $(DEFAULT);)
	@$(foreach k, $(OBJ_TEST), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(k)" $(DEFAULT);)
	@rm -rf $(OBJ_TEST)
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	@find -name "*.gcov" -delete && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(TEST_BIN) $(DEFAULT)

fclean:	clean
	@rm -rf $(TEST_BIN); echo -e $(MAGENTA) "\tRemoved:  $(TEST_BIN)" $(DEFAULT)

re:	fclean all
