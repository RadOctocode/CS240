#ifndef HEAP
#define HEAP
#include <iostream>
#include <cstring>
#include <vector>
#include "Player.h"

class Heap{
	private:
		std::vector<Player> playerVector;
		

		
	public:
		Heap();//default costructor
		Heap(std::string filename);//takes file and reads things
		void bubbleDown(int index);
		Player getPlayer();
		Heap(const Heap &copy);
		void addPlayer(Player newPlayer);
		unsigned int size(){return playerVector.size();};
		std::vector<Player> getArray() const {return playerVector;};
		bool empty(){return playerVector.empty();}
		//unsigned int size();

		
		
};
#endif