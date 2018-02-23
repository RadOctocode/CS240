#include "Deck.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream>

	Deck::Deck(){
		for(int i=1;i<=4;++i){
			for(int j=2;j<=14;++j){
				Card myCard=Card(i,j);
				cardsQueue.push_back(myCard);
			}
		}
	}

	Card Deck::draw(){
		Card removedCard=*(cardsQueue.begin());
		cardsQueue.erase(cardsQueue.begin());
		return removedCard;

	}

	bool Deck::empty(){
		return cardsQueue.empty();
	}

	void Deck::shuffle(){
		std::random_shuffle ( cardsQueue.begin(), cardsQueue.end() );


	}

 