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

SRC	=	./string_init.c	\
		./string_assign.c	\
		./string_append.c	\
		./string_position.c	\
		./string_clear.c	\
		./string_size.c	\
		./string_compare.c	\
		./string_copy.c	\
		./string_empty.c	\
		./string_find.c	\
		./string_getbuffer.c	\
		./string_insert.c	\
		./string_to_int.c

SRCTEST	=	$(TESTDIR)/test_assign.c	\
			$(TESTDIR)/test_append.c	\
			$(TESTDIR)/test_position.c	\
			$(TESTDIR)/test_compare.c	\
			$(TESTDIR)/test_compare2.c	\
			$(TESTDIR)/test_copy.c	\
			$(TESTDIR)/test_c_str.c	\
			$(TESTDIR)/test_is_empty.c	\
			$(TESTDIR)/test_find.c	\
			$(TESTDIR)/test_find2.c	\
			$(TESTDIR)/test_insert.c	\
			$(TESTDIR)/test_insert2.c	\
			$(TESTDIR)/test_to_int.c	\
			$(TESTDIR)/test_clear.c	\
			$(TESTDIR)/test_size.c

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRCTEST:.c=.o)

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

LIBNAME	=	libstring.a

TEST_LIB	=	lib_test

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:
	@make -s $(LIBNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(LIBNAME) $(DEFAULT)

$(LIBNAME)	:	$(OBJ)
				@ar rc $(LIBNAME) $(OBJ)

%.o	:	%.c
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
			@./$(TEST_LIB) && \
			$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
			$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

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
