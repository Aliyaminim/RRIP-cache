program: main.o functions.o lru.o ht-linked-list.o ht-functions.o 
	gcc -o program main.o functions.o lru.o ht-linked-list.o ht-functions.o 

main.o: main.c ./lru/lru.h functions.h ./hash/ht-functions.h
	gcc -c main.c

functions.o: functions.c ./lru/lru.h functions.h ./hash/ht-linked-list.h ./hash/ht-functions.h
	gcc -c functions.c

lru.o: ./lru/lru.c ./lru/lru.h
	gcc -c ./lru/lru.c

ht-linked-list.o: ./hash/ht-linked-list.c ./hash/ht-linked-list.h
	gcc -c ./hash/ht-linked-list.c

ht-functions.o: ./hash/ht-functions.c ./hash/ht-functions.h
	gcc -c ./hash/ht-functions.c

test:

clean: 
	rm *.o program
	rm *.c~ program
	rm ./lru/*.c~ program