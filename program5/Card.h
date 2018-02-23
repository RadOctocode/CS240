#ifndef CARD
#define CARD
#include <iostream>

class Card{
	private:
		int suit;
		int value;
	public:
		Card();
		Card(int mySuit, int myValue);
		int getValue()const{return value;};
		int getSuit()const{return suit;};
		bool operator==(const Card &other);
		bool operator!=(const Card &other);
		
};
#endif