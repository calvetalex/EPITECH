.PHONY = help setup run clean

.DEFAULT_GOAL	=	help

PYTHON	=	python3

FILES	=	input	\
			output

EXECUTABLE	=	myApp

help:
	@echo "-----------------------DISCLAIMER-----------------------"
	@echo "   This Makefile is used for python projects"
	@echo "   Required: python3 and pip"
	@echo "--------------------------------------------------------"
	@echo
	@echo "-------------------------HELP---------------------------"
	@echo "   To setup the project type make setup"
	@echo "   To add requirements, create a requirements.txt file"
	@echo "   To run the project type make run"
	@echo "   To clean the project type make clean"
	@echo "--------------------------------------------------------"

setup:
	@echo "Checking current dir..."
	@[ -d project_files.project ] || (echo "No project found, generating..." && mkdir project_files.project)
	@$(foreach FILE, $(FILES), touch project_files.project/$(FILE).txt;)
	@echo "Checking dependencies..."
	@[ -f requirements.txt ] && (echo "Install dependencies" && pip install -r requirements.txt) || (echo "No requirement given")
	@echo "Directory up to date !"


run:	setup
ifneq ("$(wildcard ./myApp)", "")
	@[ -z "$(cmp myApp.py myApp.py.save)" ] && (echo "Nothing to do") || (cp myApp.py myApp.py.save && cp myApp.py $(EXECUTABLE))
	${PYTHON} ${EXECUTABLE}
else
	@echo "Making app..."
	@[ -f myApp.py.save ] || (cp myApp.py myApp.py.save && cp myApp.py $(EXECUTABLE))
	${PYTHON} ${EXECUTABLE}
endif

clean:
	@rm -rf *.project
	@rm -rf *.save
	@rm -r myApp