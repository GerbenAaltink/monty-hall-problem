all: doors run

doors: doors.c
	gcc doors.c -o doors -Wall -Werror 

run:
	./doors 
