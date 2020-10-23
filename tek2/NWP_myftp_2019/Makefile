##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make / clean / fclean / re
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

SRCCMD	=	./src/cmd

## -------- SRC -------##

MAIN	=	$(SRCDIR)/main.c

SRC	=	$(SRCDIR)/handle_cmd.c	\
		$(SRCDIR)/clt_connection.c	\
		$(SRCDIR)/str_to_word_array.c	\
		$(SRCCMD)/user_cmd.c	\
		$(SRCCMD)/pass_cmd.c	\
		$(SRCCMD)/quit_cmd.c	\
		$(SRCCMD)/cwd_cmd.c		\
		$(SRCCMD)/cdup_cmd.c	\
		$(SRCCMD)/pwd_cmd.c		\
		$(SRCCMD)/delet_cmd.c	\
		$(SRCCMD)/help_cmd.c	\
		$(SRCCMD)/noop_cmd.c	\
		$(SRCCMD)/list_cmd.c	\
		$(SRCDIR)/tools/custom_getline.c

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN	=	$(MAIN:.c=.o)

## ------- FLAGS --------##

cflags.common	:=	-W -Wall -Wextra -I./include/ -pedantic -D _GNU_SOURCE
cflags.debug	:=	-g -g3
cflags.release	:=

ldflags.common	:=
ldflags.debug	:=
ldflags.release	:=

CFLAGS	:=	${cflags.${BUILD}} ${cflags.common}
LDFLAGS	:=	${ldflags.${BUILD}} ${ldflags.common}

## ------- BIN ----------##

BINNAME	=	myftp

## ------- BUILD ----------##

BUILD   =   release

## --------- RULES --------##

all:
	@make -s $(BINNAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
	$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)

$(BINNAME)	:	$(OBJ) $(OBJ_MAIN)
				@$(CC) -o $(BINNAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LDFLAGS)

%.o	:	%.c
		@$(CC)  $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK] " $(DEFAULT) $(TEAL) $<  $(DEFAULT)  " -----> " $(GREEN) $@ $(DEFAULT) || \
		$(ECHO) $(ERROR) " [ERROR] can't find " $(YELLOW) $^ $(DEFAULT)

set_rules_debug	:
			$(eval BUILD=debug)
			$(eval CFLAGS=${cflags.debug} $(cflags.common))
			$(eval LDFLAGS=${ldflags.debug} $(ldflags.common))

debug		:	 set_rules_debug $(OBJ) $(OBJ_MAIN)
				@$(CC) -o $(BINNAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LDFLAGS) && \
				$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
				$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)


clean:
	@$(foreach i, $(OBJ), $(shell rm -rf $(i)) echo -e $(MAGENTA) "\tRemoved:  $(i)" $(DEFAULT);)
	@echo -e $(MAGENTA) "\tRemoved: $(OBJ_MAIN)" $(DEFAULT)
	@rm -rf $(OBJ_MAIN)
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	@find -name "*.gcov" -delete && \
		$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
		$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)


fclean:	clean
	@rm -rf $(BINNAME) && \
		$(ECHO) $(GREEN) "[OK]"$(TEAL)"  Done : " $@ $(DEFAULT)  || \
		$(ECHO) $(ERROR) "[ERROR]" $(YELLOW) $(BINNAME) $(DEFAULT)


re:	fclean all
