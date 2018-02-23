C_FLAG = -Wall -Wextra -g -std=c++14
PROGRAM_NAME= program2

all: Driver

Driver: $(PROGRAM_NAME).o Heap.o Player.o Card.o Deck.o Table.o
	g++ $(C_FLAG) $^ -o $(PROGRAM_NAME)

program2.o: $(PROGRAM_NAME).cpp 
	g++ -c $(C_FLAG) $(PROGRAM_NAME).cpp -o $(PROGRAM_NAME).o

Heap.o: Heap.cpp
	g++ -c $(C_FLAG) Heap.cpp -o Heap.o

Player.o: Player.cpp 
	g++ -c $(C_FLAG) Player.cpp -o Player.o

Table.o: Table.cpp
	g++ -c $(C_FLAG) Table.cpp -o Table.o

Deck.o: Deck.cpp
	g++ -c $(C_FLAG) Deck.cpp -o Deck.o

Card.o: Card.cpp
	g++ -c $(C_FLAG) Card.cpp -o Card.o

clean:
	rm *.o $(PROGRAM_NAME)

checkmem:
	valgrind ./$(PROGRAM_NAME)

run: Driver
	./$(PROGRAM_NAME)