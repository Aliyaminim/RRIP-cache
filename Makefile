CC=gcc
CFLAGS= 
EXECUTABLE=program

program: main.o functions.o lru.o ht-linked-list.o ht-functions.o 
	@$(CC) -g $(CFLAGS) -o program main.o functions.o lru.o ht-linked-list.o ht-functions.o 

main.o: main.c ./lru/lru.h functions.h ./hash/ht-functions.h
	@$(CC) $(CFLAGS) -g -c main.c

functions.o: functions.c ./lru/lru.h functions.h ./hash/ht-linked-list.h ./hash/ht-functions.h
	@$(CC) $(CFLAGS) -g -c functions.c

lru.o: ./lru/lru.c ./lru/lru.h
	@$(CC) $(CFLAGS) -g -c ./lru/lru.c

ht-linked-list.o: ./hash/ht-linked-list.c ./hash/ht-linked-list.h
	@$(CC) $(CFLAGS) -g -c ./hash/ht-linked-list.c

ht-functions.o: ./hash/ht-functions.c ./hash/ht-functions.h
	@$(CC) $(CFLAGS) -g -c ./hash/ht-functions.c

test:
	bash ./tests/bash.sh

clean: 
	rm *.o program
	rm *.c~ program
	







