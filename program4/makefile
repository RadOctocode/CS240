
C_FLAG = -Wall -Wextra -g -std=c++14

all: Driver

Driver: BSTree.o lab7.o
	g++ $(C_FLAG) $^ -o lab7

Lab7.o: lab7.cpp 
	g++ -c $(C_FLAG) lab7.cpp -o lab7.o

BSTree.o: BSTree.cpp BSTree.h 
	g++ -c $(C_FLAG) BSTree.cpp -o BSTree.o

clean:
	rm *.o lab7

checkmem:
	valgrind ./lab7

run: Driver
	./lab7