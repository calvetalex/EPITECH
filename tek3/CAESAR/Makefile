##
## EPITECH PROJECT, 2021
## CAESAR
## File description:
## Makefile
##

CHALLENGES	=	01	\
				02	\
				03	\
				04	\
				05	\
				06	\
				07	\
				08	\
				09	\
				10

.PHONY:	all	exe	clean	fclean	re

all:	exe

exe:
	@$(foreach CHALL, $(CHALLENGES), make -C ex$(CHALL) && cp ex$(CHALL)/challenge$(CHALL) .;)

fclean:
	@$(foreach CHALL, $(CHALLENGES), rm -rf challenge$(CHALL) && make fclean -C ex$(CHALL);)

re:	fclean all
