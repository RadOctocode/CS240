#include "Table.h"

Table::Table(int numSeats, int myAnte){
	seats=numSeats;
	ante=myAnte;
}//end of constructor



bool Table::emptySeat(){
	bool retVal=true;

	if(seatVector.size()==seats){
		retVal=false;
	}

	return retVal;
}//end of emptySeat



void Table::addPlayer(Player newPlayer){
	seatVector.push_back(newPlayer);
}//end of addPlayer


void Table::printWinner(){
	std::cout<<winner<<'\n';

}//print winner




std::vector<Player> Table::playRound(){
	Deck myDeck=Deck();

	int bettingPool=0;
	myDeck.shuffle();
	int biggestCard=0;
	std::vector<Player> retVal;//return vector
	Player winnerPlayer=Player("noone",0);

	for(int i=0; i<seatVector.size();i++){

		if(seatVector[i].getBudget()>=ante){
			seatVector[i].bet(ante);
			bettingPool=bettingPool+ante;
			Card drawedCard=myDeck.draw();
			seatVector[i].hand=drawedCard;
		}

	}//everyone make a bet and take a card



	for(int j=0; j<seatVector.size();j++){

		if(seatVector[j].hand!=Card()){
			int cardVal=(seatVector[j].hand.getValue())*((seatVector[j].hand.getSuit())*13);
			if(cardVal>biggestCard){
				biggestCard=cardVal;
				winner=std::string(seatVector[j].getName());
				winnerPlayer=seatVector[j];


			}
		}

	}//find the winner




	winnerPlayer.collectWinnings(bettingPool);
	for(int i=0;i<seatVector.size();i++){
		if((seatVector[i].getName()!=winner)&&(seatVector[i].getBudget()>=ante)){
			retVal.push_back(seatVector[i]);
		}
	}	//also check losers to see if they hve enough to bet again if so put them in a loser list

	seatVector.clear();
	//remove everyone from the vectors
	return retVal;
}//end of playround



