C_FLAG = -Wall -Wextra -g -std=c++14
PROGRAM_NAME= lab8

all: Driver

Driver: $(PROGRAM_NAME).o Hash.o
	g++ $(C_FLAG) $^ -o $(PROGRAM_NAME)

$(PROGRAM_NAME).o: $(PROGRAM_NAME).cpp 
	g++ -c $(C_FLAG) $(PROGRAM_NAME).cpp -o $(PROGRAM_NAME).o

Hash.o: Hash.cpp
	g++ -c $(C_FLAG) Hash.cpp -o Hash.o

clean:
	rm *.o $(PROGRAM_NAME)

checkmem:
	valgrind ./$(PROGRAM_NAME)

run: Driver
	./$(PROGRAM_NAME)
	
