#ifndef DECK
#define DECK
#include <iostream>
#include <vector>
#include "Card.h"

class Deck{
	private:
		std::vector<Card>  cardsQueue;

	public:
		Deck();
		Card draw();
		bool empty();
		void shuffle();
		
};
#endif