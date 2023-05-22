CC=gcc
CFLAGS= 
EXECUTABLE=program

program: main.o func_RRIP.o lru.o ht-linked-list.o ht-functions.o 
	@$(CC) -g $(CFLAGS) -o program main.o func_RRIP.o lru.o ht-linked-list.o ht-functions.o 

main.o: main.c ./lru/lru.h func_RRIP.h ./hash/ht-functions.h
	@$(CC) $(CFLAGS) -g -c main.c

func_RRIP.o: func_RRIP.c ./lru/lru.h func_RRIP.h ./hash/ht-linked-list.h ./hash/ht-functions.h
	@$(CC) $(CFLAGS) -g -c func_RRIP.c

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
	







