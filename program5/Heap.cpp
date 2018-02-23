#include "Heap.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>    // std::iter_swap
#include <typeinfo>

Heap::Heap(){

}

void Heap::bubbleDown(int index){
    int leftChild=2*index + 1;
    int rightChild=2*index + 2;
    int swap =index;

    if(!(leftChild >=playerVector.size())){
      int leftBudget=playerVector[leftChild].getBudget();

      if(playerVector[swap].getBudget()<leftBudget){
        swap=leftChild;


      }
    }//if left isnt a child

    if(!(rightChild>=playerVector.size())){
      int rightBudget=playerVector[rightChild].getBudget();

     if((playerVector[swap].getBudget()<rightBudget)){
        swap=rightChild;
      }
    }//if right isnt a child
      if(swap!=index){
        std::iter_swap(&playerVector[index],&playerVector[swap]);
        bubbleDown(swap);
      }
    //if this is not child 

}//end of bubbleDown



Heap::Heap(std::string filename){
	std::ifstream myfile (filename);
  	if (myfile.is_open()){
  		std::string line;
    	while ( getline (myfile,line) ){
            std::string myName= line;
            std::getline(myfile, line);  // then do whatever you want.
            int myBudget= stoi(line); 
            playerVector.push_back( Player(myName,myBudget));

    	}

    	myfile.close();
  	}

  else{
    std::cout << "Unable to open file";
  } 

  for(int i=playerVector.size(); i>=0; --i) {
    bubbleDown(i);
  }//end of the for

}//end of consrtructor



Heap::Heap(const Heap &copy){
  playerVector=copy.getArray();
}



Player Heap::getPlayer(){
//Removes the priority player (the player with the highest budget) from the heap. This should remove the player from the heap entirely.
//Remember that after removing the player, your heap still needs to be a heap
    Player removedPlayer=*(playerVector.begin());
    playerVector.erase(playerVector.begin());
    for(int j=playerVector.size(); j>=0; --j) {
      bubbleDown(j);
    }//end of the for
    return removedPlayer;
}//end of getPlayer

void Heap::addPlayer(Player newPlayer){
      playerVector.push_back(newPlayer);
      for(int j=playerVector.size(); j>=0; --j) {
        bubbleDown(j);
      }//end of the for
}//end of addPalyer
