#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <cstring>
#include "Card.h"

class Player{
	private:
		int budget;
		std::string name;

		
	public:
		Card hand;
		Player(std::string myName, int myBudget);
		std::string getName(){return name;};
		int getBudget(){return budget;};
		bool bet(int amount);
		void collectWinnings(int amount);
		
		
};
#endif