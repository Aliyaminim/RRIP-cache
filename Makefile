CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=*.c
EXECUTABLE=a.out

all:
	@echo "testing"
	@$(CC) -g $(CFLAGS) -I./ $(SOURCES) -o $(EXECUTABLE)
	@./$(EXECUTABLE) < test.in