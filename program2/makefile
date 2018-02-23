
C_FLAG = -Wall -Wextra -g -std=c++14

all: Driver

Driver: Node.h LinkedList.h Queue.h Lab5.o Card.o Deck.o
	g++ $(C_FLAG) $^ -o lab5

Lab5.o: Lab5.cpp 
	g++ -c $(C_FLAG) Lab5.cpp -o Lab5.o


Deck.o: Deck.cpp Deck.h 
	g++ -c $(C_FLAG) Deck.cpp -o Deck.o


Card.o: Card.cpp Card.h 
	g++ -c $(C_FLAG) Card.cpp -o Card.o

clean:
	rm *.o lab5

checkmem:
	valgrind ./lab5

run: Driver
	./lab5
