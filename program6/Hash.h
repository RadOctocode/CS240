#ifndef HASH
#define HASH
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>        // std::tuple, std::get, std::tie, std::ignore
class Hash{
	private:
		std::vector<std::pair<std::string,std::string>> passwordVector;
		int currentSize;
	public:
		Hash(unsigned int size);
		//Should initialize an array to some static size. You can use a vector for this, but it should still have a static size (meaning you will need to initialize the vector to some start size).
		bool insert(std::string key, std::string value);
		//returns false is the hash is full
		bool remove(std::string key);
		//removes the entry from the hash
		//returns false if the key was not found
		std::string find(std::string key);
		//returns the correct value based on the key parameter
		//If the key is not found, returns an empty string
		bool empty();
		//returns true of the hash is empty
		int size(){return passwordVector.size();};
		//returns to max size of the hash (not the current number of items)
		void printHash();
		//prints out the index, key, and value of each element in the hash
		int hasher(std::string key);
		//hash function that determines an index based on the key parameter
		//You can develop whatever hash function you want, but should try to limit collisions

		
};
#endif
