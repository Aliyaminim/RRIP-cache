
# program: main.o functions.o 
# 	gcc -o program main.o functions.o

# main.o: main.c functions.h
# 	gcc -c main.c

# functions.o: functions.c functions.h
# 	gcc -c functions.c

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=*.c
EXECUTABLE=a.out

all:
	@echo "testing"
	@$(CC) -g $(CFLAGS) -I./ $(SOURCES) -o $(EXECUTABLE)
	@./$(EXECUTABLE) < test.in