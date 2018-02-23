
C_FLAG = -Wall -Wextra -g -std=c++14

all: Driver

Driver: Sorter.h lab6.o
	g++ $(C_FLAG) $^ -o lab6

Lab5.o: lab6.cpp 
	g++ -c $(C_FLAG) lab6.cpp -o lab6.o

clean:
	rm *.o lab6

checkmem:
	valgrind ./lab6

run: Driver
	./lab6
