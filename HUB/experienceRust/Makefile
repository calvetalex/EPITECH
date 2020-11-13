##
## EPITECH PROJECT, 2020
## rustExperience
## File description:
## Makefile
##

all:	setup

setup:
ifeq ("$(wildcard ./myMorpionInRust)","")
	@rustc -o myMorpionInRust main.rs
endif

run:	setup
	@./myMorpionInRust

help:	setup
	@./myMorpionInRust --help

fclean:
	@rm -rf myMorpionInRust

re: fclean
	@rustc -o myMorpionInRust main.rs