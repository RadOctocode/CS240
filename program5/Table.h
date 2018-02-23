#ifndef TABLE
#define TABLE
#include <iostream>
#include <cstring>
#include "Deck.h"
#include "Player.h"

class Table{
	private:
		int seats;
		int ante;
		std::vector<Player> seatVector;
		std::string winner;


		
	public:
		Table(int numSeats, int myAnte);
		bool emptySeat();
		void addPlayer(Player newPlayer);
		std::vector<Player> playRound();
		void printWinner();
		/*Returns a vector of the losers of the round
		The winner stays for the next round while the losers leave
		The players in this vector will be put back into the heap if they have enough money to cover the ante*/

		/*
			The 52 cards in the deck are shuffled (randomized).
			Each player ante’s (puts in a minimum bet)
			Then each player is given one card from the top of the deck. 
			Now each player’s card is evaluated and the winner is determined.
			The losers that still have enough money in their budget to cover an ante are placed back into the heap, and the next group of players sit at the table.

		*/
		
		
};
#endif