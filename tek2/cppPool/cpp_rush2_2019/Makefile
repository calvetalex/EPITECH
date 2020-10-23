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
## -------- DIR -------##

TESTDIR	=	./tests

SRCDIR	=	./src

## -------- SRC -------##

MAIN_FILE	=	$(SRCDIR)/main.cpp

SRC	=	$(SRCDIR)/Conveyor/PapaXmasConveyorBelt.cpp \
		$(SRCDIR)/Object/Toy/LittlePony.cpp \
		$(SRCDIR)/Object/Toy/Teddy.cpp \
		$(SRCDIR)/Object/Wrap/AWrap.cpp \
		$(SRCDIR)/Object/Wrap/Box.cpp \
		$(SRCDIR)/Object/Wrap/GiftPaper.cpp \
		$(SRCDIR)/Object/AObject.cpp \
		$(SRCDIR)/Table/PapaXmasTable.cpp \
		$(SRCDIR)/Elf/AElf.cpp \
		$(SRCDIR)/Elf/Elf.cpp \
		$(SRCDIR)/Elf/Hand.cpp \
		$(SRCDIR)/Elf/PapaXmasElf.cpp \
		$(SRCDIR)/Elf/Santa.cpp \
		$(SRCDIR)/Xml/Xml.cpp \
		$(SRCDIR)/UnitTests/UnitTests.cpp

SRCTEST	=	$(TESTDIR)/test_Conveyor.cpp \

OBJ	=	$(SRC:.cpp=.o)

OBJ_MAIN	=	$(MAIN_FILE:.cpp=.o)

OBJ_TEST	=	$(SRCTEST:.cpp=.o)

## ------- FLAGS --------##

cflags.common	:=	-I"./include"
cflags.debug	:=	-g -g3
cflags.release	:=
cflags.tests	:=	-g3 -fprofile-arcs -ftest-coverage -lgtest -lgtest_main --coverage

ldflags.common	:=
ldflags.debug	:=
ldflags.release	:=
ldflags.tests	:=

CFLAGS	:=	${cflags.${BUILD}} ${cflags.common}
LDFLAGS	:=	${ldflags.${BUILD}} ${ldflags.common}

## ------- LIB ----------##

BINARY	=	santa

TEST_LIB	=	bin_test

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:
	@make -s $(BINARY) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT) || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINARY) $(DEFAULT)

$(BINARY)	:	$(OBJ) $(OBJ_MAIN)
			@$(CC) -o $(BINARY) $(OBJ_MAIN) $(OBJ) $(CFLAGS) $(LDFLAGS)

%.o	:	%.cpp
		@$(CC)  $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK] " $(DEFAULT) $(TEAL) $<  $(DEFAULT)  " -----> " $(GREEN) $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] can't find " $(YELLOW) $^ $(DEFAULT)

set_rules	:
			$(eval BUILD=tests)
			$(eval CFLAGS=${cflags.tests} $(cflags.common))
			$(eval LDFLAGS=${ldflags.tests} $(ldflags.common))


$(TEST_LIB)	:	set_rules $(OBJ_TEST) $(OBJ)
			@$(CC) -o $(TEST_LIB) $(OBJ_TEST) $(OBJ) $(CFLAGS) $(LDFLAGS) -I"./include"

tests_run	:	set_rules $(TEST_LIB)
			@./$(TEST_LIB)

set_rules_debug	:
		$(eval BUILD=debug)
		$(eval CFLAGS=${cflags.debug} $(cflags.common))
		$(eval LDFLAGS=${ldflags.debug} $(ldflags.common))

debug	:	set_rules_debug	$(OBJ) $(OBJ_MAIN)
		@$(CC) -o $(BINARY) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LDFLAGS) && \
		$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) "[ERROR]"$(YELLOW) $(BINARY) $(DEFAULT)

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
	@rm -rf $(BINARY)
	@rm -rf $(LIBNAME); echo -e $(MAGENTA) "\tRemoved:  $(LIBNAME)" $(DEFAULT)
	@rm -rf $(TEST_LIB)

re:	fclean all
