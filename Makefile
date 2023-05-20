program: main.o functions.o lru.o
	gcc -o program main.o functions.o lru.o

main.o: main.c functions.h ./lru/lru.h
	gcc -c main.c

functions.o: functions.c functions.h 
	gcc -c functions.c

lru.o: ./lru/lru.c ./lru/lru.h
	gcc -c ./lru/lru.c
test:

clean: 
	rm *.o program