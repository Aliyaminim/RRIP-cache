program: main.o functions.o lru.o
	gcc -o program main.o functions.o lru.o

main.o: main.c functions.h ./src/lru.h
	gcc -c main.c

functions.o: functions.c functions.h 
	gcc -c functions.c

lru.o: ./src/lru.c ./src/lru.h
	gcc -c ./src/lru.c
test:

clean: 
	rm *.o program