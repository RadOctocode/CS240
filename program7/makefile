C_FLAG = -Wall -Wextra -g -std=c++14
PROGRAM_NAME= program3

all: Driver

Driver: $(PROGRAM_NAME).o Map.o City.o
	g++ $(C_FLAG) $^ -o $(PROGRAM_NAME)

$(PROGRAM_NAME).o: $(PROGRAM_NAME).cpp 
	g++ -c $(C_FLAG) $(PROGRAM_NAME).cpp -o $(PROGRAM_NAME).o

Map.o: Map.cpp
	g++ -c $(C_FLAG) Map.cpp -o Map.o

City.o: City.cpp
	g++ -c $(C_FLAG) City.cpp -o City.o

clean:
	rm *.o $(PROGRAM_NAME)

checkmem:
	valgrind ./$(PROGRAM_NAME)

run: Driver
	./$(PROGRAM_NAME)
	