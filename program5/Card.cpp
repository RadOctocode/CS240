#include "Card.h"
#include <iostream>
Card::Card(){
	suit=0;
	value=0;
}
Card::Card(int mySuit, int myValue){
	suit=mySuit;
	value=myValue;
}

bool Card::operator==(const Card &other){
	bool returnVal=true;
	if((other.getValue())!=this->value||(other.getSuit())!=this->suit){
		returnVal=false;
	}

	return returnVal;
}

bool Card::operator!=(const Card &other){
	bool returnVal=false;
	if((other.getValue())!=this->value||(other.getSuit())!=this->suit){
		returnVal=true;
	}

	return returnVal;
}