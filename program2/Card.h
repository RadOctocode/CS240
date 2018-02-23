#ifndef CARD
#define CARD
#include <iostream>

class Card{
	private:
		int suit;
		int value;
	public:
		Card(int mySuit, int myValue);
		Card();
		int getValue()const{return value;};
		int getSuit()const{return suit;};
		bool operator==(const Card &other);
		
};
#endif