#ifndef DECK
#define DECK
#include <iostream>
#include "Queue.h"
#include "Card.h"

class Deck{
	private:
		 Queue<Card> cardsQueue;
	public:
		Deck();
		Card draw();
		bool empty();
		void shuffle();
		
};
#endif