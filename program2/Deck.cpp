#include "Deck.h"
#include <stdlib.h>
#include <iostream>

	Deck::Deck(){
		for(int i=1;i<=4;++i){
			for(int j=2;j<=14;++j){
				Card myCard=Card(i,j);
				cardsQueue.enqueue(myCard);
			}
		}
	}

	Card Deck::draw(){
		return cardsQueue.dequeue();
	}

	bool Deck::empty(){
		return cardsQueue.empty();
	}

	void Deck::shuffle(){
		Card cardArray[52];
		int cardsAdded[52];
		int queuedCards=0;
		for(int i=0;i<52;++i){
			cardArray[i]=cardsQueue.dequeue();
		}
		while(queuedCards!=52){
			int randInt=rand()%52;
			if(cardArray[randInt].getValue()!=0){
				cardsQueue.enqueue(cardArray[randInt]);
				cardArray[randInt]=Card();
			}

			++queuedCards;
		}


	}

 