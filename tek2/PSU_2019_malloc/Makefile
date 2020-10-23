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

CC	=	gcc

## ------- DIR --------##
SRCDIR	=	./src

## -------- SRC -------##

SRC	=	$(SRCDIR)/my_malloc.c	\
		$(SRCDIR)/my_free.c		\
		$(SRCDIR)/my_calloc.c	\
		$(SRCDIR)/my_realloc.c	\

SRCDEBUG	=	$(SRCDIR)/debug.c

OBJ	=	$(SRC:.c=.o)

OBJDEBUG	=	$(SRCDEBUG:.c=.o)

## ------- FLAGS --------##

cflags.common	:=	-W -Wall -Wextra -I./include/ -fPIC
cflags.debug	:=	-g -g3
cflags.release	:=
cflags.tests	:=

ldflags.common	:=
ldflags.debug	:=
ldflags.release	:=
ldflags.tests	:=

CFLAGS	:=	${cflags.${BUILD}} ${cflags.common}
LDFLAGS	:=	${ldflags.${BUILD}} ${ldflags.common}

## ------- BIN ----------##

BINNAME	=	libmy_malloc.so

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:
	@make -s $(BINNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

$(BINNAME)	:	$(OBJ)
				@$(CC) -shared -o $(BINNAME) $(OBJ)

%.o	:	%.c
		@$(CC)  $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK] " $(DEFAULT) $(TEAL) $<  $(DEFAULT)  " -----> " $(GREEN) $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] can't find " $(YELLOW) $^ $(DEFAULT)

clean:
	@$(foreach i, $(OBJ), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(i)" $(DEFAULT);)
	@$(foreach i, $(OBJDEBUG), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(i)" $(DEFAULT);)

fclean:	clean
	@rm -rf $(BINNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

set_rules:
		$(eval BUILD=debug)
		$(eval CFLAGS=${cflags.debug} $(cflags.common))

debug:	fclean set_rules $(OBJ) $(OBJDEBUG)
		@$(CC) -shared -o $(BINNAME) $(OBJ) $(OBJDEBUG)

re:	fclean all
