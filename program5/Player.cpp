#include "Player.h"
#include <iostream>
#include <cstring>


Player::Player(std::string myName, int myBudget){
	name=myName;
	budget=myBudget;
}

bool Player::bet(int amount){
	budget=budget-amount;
	return true;
	/*Removes a specified amount of money from the player’s budget*/
}

void Player::collectWinnings(int amount){
	budget= budget+amount;
	/*Adds a specified amount of money to the player’s budget*/
}